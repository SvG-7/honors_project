# CSE 3318 Honors Project – Convex Hull (Graham’s Scan)

**Student:** Saish Vinod Gondkar  
**Instructor:** Alexandra Stefan  
**Course:** CSE 3318-002 — Algorithms & Data Structures  
**Institution:** The University of Texas at Arlington  

---

## Project Overview

This project implements the **Convex Hull** algorithm using **Graham’s Scan** in **C** to compute the outer boundary of a set of 2D points. The program supports reading point data from input files, handling special/edge cases, and generating output that lists the hull points in **counterclockwise order**.

---

## Code Structure

The project is modularized into separate C source and header files:

### 1) `main.c`
- Acts as the program’s entry point.
- Prompts the user for an input filename.
- Calls `readPoints()` to load point data from a file.
- Calls `convexHull()` to compute and print the convex hull.
- Prints results to the console and terminates.

### 2) `io.c` / `io.h`
- Handles all input operations.
- Function:
  ```c
  int readPoints(Point points[], const char *filename);
Reads the number of points and their coordinates from a text file.

Returns the total number of points read.

3) convex_hull.c / convex_hull.h
Implements the Convex Hull algorithm using Graham’s Scan.

Functions:

orientation() → determines clockwise/counterclockwise turns

distSq() → computes squared distance

swap() → swaps two points

comparePoints() → comparator used by qsort_s (sorts by polar angle w.r.t. the pivot, and by distance as a tie-breaker)

sortByAngle() → calls qsort_s to sort all points by polar angle

convexHull() → builds and outputs the final hull

Outputs results to:

the console

hull_output.txt

Input Files
Included input datasets:

points_10.txt

points_50.txt

points_1000.txt

special_cases.txt

Input Format
Each input file follows this format:

python-repl
Copy code
n
x1 y1
x2 y2
...
xn yn
Output
hull_output.txt
Generated automatically.

Contains only the points on the convex hull in counterclockwise order.

Console Output
Prints the convex hull points to the screen.

Compilation & Execution
To Compile
bash
Copy code
gcc main.c io.c convex_hull.c -o convex_hull -lm
To Run
bash
Copy code
./convex_hull
Files Included
main.c

io.c, io.h

convex_hull.c, convex_hull.h

points_10.txt, points_50.txt, points_1000.txt, special_cases.txt

generate_randomnumbers.c

graphs.ipynb

Expected Output
Prints convex hull points on screen.

Creates hull_output.txt containing the hull points.

Performance
Total Time Complexity: O(n log n) (dominated by sorting)
