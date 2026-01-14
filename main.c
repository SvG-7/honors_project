#include <stdio.h>
#include "convex_hull.h"
#include "io.h"

// Main entry point
int main() {
    Point points[10000];
    char filename[50];

    printf("Enter input file name (e.g., points_10.txt): ");
    scanf("%s", filename);

    int n = readPoints(points, filename);
    
    if (n == 0) return 1;

    printf("\nRead %d points successfully!\n", n);
    printf("Computing convex hull...\n");

    convexHull(points, n);

    printf("\nDone!\n");
    return 0;
}

/*
    Let n be the number of points read from the input file.
    1. readPoints() → O(n)
       - This function reads n points from the input file.
       - Each line is processed exactly once using fscanf() and each line contains one (x,y) coordinate pair.
       - Total cost grows linearly with number of points.

    2. convexHull() → O(n log n) ---from convex_hull.c
         - This function computes the convex hull using the Graham scan algorithm.
         - Key steps:
            a. Finding pivot point → O(n)
            b. Sorting points by angle → O(n log n)
            c. Removing collinear points → O(n)
            d. Building hull using stack logic → O(n)
            e. Outputting hull points → O(h) where h is number of hull points
            f. Writing hull to file → O(h)
            - Dominant term is the sorting step → O(n log n)

    Total Program Time Complexity:
    T(n) = O(n) + O(n log n) = O(n log n)
*/