#include <stdio.h>
#include "io.h"

int readPoints(Point points[], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }

    int n;
    fscanf(file, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d %d", &points[i].x, &points[i].y);
    }
    fclose(file);
    return n;
}

/* readPoints():
This function performs the following steps:

1. fopen()  
   - Opening a file is done once → O(1)

2. fscanf() to read n  
   - Reading the integer n from the file → O(1)

3. Loop from i = 0 to n-1:
   - Each iteration reads one (x, y) coordinate pair.
   - Each fscanf() is O(1)
   - The loop iterates exactly n times

   → Total loop cost = n * O(1) = O(n)

4. fclose(file)  
   - Closing the file is constant time → O(1)

Therefore:
   - We read n points from file → O(n)
   - Each read uses fscanf() once per line.

   So, T(n) = O(1) + O(1) + O(n) + O(1) = O(n)
*/