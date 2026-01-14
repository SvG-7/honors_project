CSE 3318 Honors Project – Convex Hull (Graham’s Scan)

Student: Saish Vinod Gondkar
UTA ID: 1002215640
Faculty: Alexandra Stefan
Course: CSE 3318-002-Algorithms & Data Structures

CODE STRUCTURE
-------------------------------------------------------------------

The project is modularized into separate C source and header files:

1. main.c
   - Acts as the program’s entry point.
   - Prompts user for an input filename.
   - Calls readPoints() to load data from file.
   - Calls convexHull() to compute and print the convex hull.
   - Prints results to console and terminates.

2. io.c / io.h
   - Handles all input operations.
   - Function: readPoints(Point points[], const char *filename)
   - Reads number of points and their coordinates from a text file.
   - Returns total number of points read.

3. convex_hull.c / convex_hull.h
   - Implements the Convex Hull algorithm using Graham’s Scan.
   - Functions:
      orientation() → determines clockwise/counterclockwise turns
      distSq() → computes squared distance
      swap() → swaps two points
      comparePoints() → Comparator used by qsort_s by polar angle w.r.t the pivot and distance from the pivot
      sortByAngle() → calls qsort_s to sort all points by the polar angle
      convexHull() → builds and outputs final hull
   - Outputs both console display and “hull_output.txt”.


4. points_10.txt / points_50.txt / points_1000.txt / special_cases.txt
   - Input datasets.
   - Each file followed the format:
      n
      x1 y1
      x2 y2
      ...
      xn yn

5. hull_output.txt
   - Generated automatically.
   - Contains only the points on the convex hull in counterclockwise order.


To Compile:
gcc main.c io.c convex_hull.c -o convex_hull -lm
To Run:
./convex_hull

Files Included:
main.c, io.c, io.h, convex_hull.c, convex_hull.h, points_10.txt, points_50.txt, points_1000.txt, special_cases.txt, generate_randomnumbers.c, graphs.ipynb

Expected Output:
- Prints convex hull points on screen.
- Creates hull_output.txt containing the hull points.

Total Time Complexity: O(n log n)

