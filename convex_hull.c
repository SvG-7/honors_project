#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "convex_hull.h"

/*Definitions:
    Let n = number of input points.
    Let h = number of points on the final convex hull (h ≤ n).
*/

// Function 1: orientation()
// Determines the turn direction for three points
// Performs a constant number of arithmetic operations
// TC: O(1)
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;               // 0=collinear
    return (val > 0) ? 1 : 2;   // 1=clockwise, 2=counterclockwise
}

// Function 2: distSq()
// Returns squared distance between two points
// Has same number of multiplications and additions
// TC: O(1)
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

// Function 3: swap()
// Swaps two points
// TC: O(1)
void swap(Point *a, Point *b) {
    Point temp = *a;
    *a = *b;
    *b = temp;
}

/* 
Function 4: comparePoints()
    Operations inside this function:
    orientation(pivot, p1, p2)  
          - constant number of arithmetic ops  
          - TC = O(1)

    If collinear:
          - distSq(pivot, p1)
          - distSq(pivot, p2)
          - each is constant arithmetic
          - TC = O(1)

    Final conditional return statement
          - constant-time branching
          - TC = O(1)

Therefore:
        Time per comparison = O(1)
*/
int comparePoints(void *userdata, const void *a, const void *b) {
    Point pivot = *(Point*)userdata;

    Point p1 = *(Point*)a;
    Point p2 = *(Point*)b;

    int o = orientation(pivot, p1, p2);

    if (o == 0) {
        return distSq(pivot, p1) - distSq(pivot, p2);
    }

    return (o == 2) ? -1 : 1;
}

/*  
Function 5: sortByAngle()
    - qsort_s() is called on (n - 1) points:

    - qsort_s() is a comparison-based sorting algorithm.
      All comparison-based sorts have a lower bound of:
            O(k log k) where k = number of elements
            Here, k = n - 1  which is asymptotically the same as n.

    Cost of each comparison:
    - comparePoints() runs in O(1)
      (orientation + optional distSq, constant work)

    Total sorting cost:
    qsort_s() performs O(n log n) comparisons
    Each comparison costs O(1)

    Therefore:
    Time for sortByAngle = O(n log n)
*/
void sortByAngle(Point points[], int n, Point pivot) {
    qsort_s(&points[1], n - 1, sizeof(Point), comparePoints, &pivot);
}

// Function 6: convexHull()
void convexHull(Point points[], int n) {
    if (n < 3) {
        printf("Convex hull not possible (less than 3 points)\n");
        return;
    }

    // STEP 1: Finding pivot (lowest y, then lowest x) → O(n) 
    // Just scanning all points once
    // TC = O(n)
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < points[minIndex].y) ||
            (points[i].y == points[minIndex].y && points[i].x < points[minIndex].x))
            minIndex = i;
    }

    swap(&points[0], &points[minIndex]);
    Point pivot = points[0];

    // STEP 2: Sorting remaining points by angle → O(n log n) 
    sortByAngle(points, n, pivot);

    // STEP 3: Removing collinear points → O(n) 
    int m = 1;
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && orientation(pivot, points[i], points[i + 1]) == 0)
            i++;
        points[m++] = points[i];
    }

    if (m < 3) {
        printf("Convex hull not possible (all points collinear)\n");
        return;
    }

    // STEP 4: Building hull using stack → O(n) 
    /*  - Each point is pushed onto the stack once.
        - A point can be popped at most once during the process.
        - Therefore the full loop is linear in m (and m ≤ n).
        Therefore, Time Complexity = O(n)
    */
    Point *stack = malloc(m * sizeof(Point));
    if (!stack) {
        printf("Memory allocation failed.\n");
        return;
    }
    int top = 2;
    stack[0] = points[0];
    stack[1] = points[1];
    stack[2] = points[2];

    for (int i = 3; i < m; i++) {
        while (top >= 2 && orientation(stack[top - 1], stack[top], points[i]) != 2)
            top--;
        top++;
        stack[top] = points[i];
    }

    // STEP 5: Printing hull → O(h) 
    printf("\nConvex Hull Points (counterclockwise):\n");
    for (int i = 0; i <= top; i++)
        printf("(%d, %d)\n", stack[i].x, stack[i].y);

    // STEP 6: Writing hull → O(h) 
    FILE *fout = fopen("hull_output.txt", "w");
    if (fout) {
        for (int i = 0; i <= top; i++)
            fprintf(fout, "%d %d\n", stack[i].x, stack[i].y);
        fclose(fout);
        printf("\nHull points written to hull_output.txt\n");
    } else {
        printf("Error writing hull_output.txt\n");
    }

    free(stack);
}
/* Final Time Complexity, T(n) = 
    Pivot selection          = O(n)
    Sorting by angle         = O(n log n)
    Removing collinear       = O(n)
    Building hull (stack)    = O(n)
    Output hull              = O(h), where h ≤ n
    Writing hull to file     = O(h)
    Since h ≤ n, O(h) ⊆ O(n).
    Therefore, the dominant term is O(n log n).
    FINAL COMPLEXITY = O(n) + O(n log n) + O(n) + O(n) + O(h) + O(h) = O(n log n)
*/
