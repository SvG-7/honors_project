#ifndef CONVEX_HULL_H
#define CONVEX_HULL_H

// Structure to represent a 2D point
typedef struct {
    int x;
    int y;
} Point;

// Function declarations
int orientation(Point p, Point q, Point r);
int distSq(Point p1, Point p2);
void swap(Point *a, Point *b);
int comparePoints(void *context, const void *a, const void *b);
void sortByAngle(Point points[], int n, Point pivot);
void convexHull(Point points[], int n);

#endif
