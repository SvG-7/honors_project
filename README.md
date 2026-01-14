# CSE 3318 Honors Project – Convex Hull (Graham’s Scan)

**Student:** Saish Vinod Gondkar  
**UTA ID:** 1002215640  
**Faculty:** Alexandra Stefan  
**Course:** CSE 3318-002 — Algorithms & Data Structures  

---

## Code Structure

The project is modularized into separate C source and header files:

### 1) `main.c`
- Acts as the program’s entry point.
- Prompts user for an input filename.
- Calls `readPoints()` to load data from file.
- Calls `convexHull()` to compute and print the convex hull.
- Prints results to console and terminates.

### 2) `io.c` / `io.h`
- Handles all input operations.
- Function: `readPoints(Point points[], const char *filename)`
- Reads number of points and their coordinates from a text file.
- Returns total number of points read.

### 3) `convex_hull.c` / `convex_hull.h`
- Implements the Convex Hull algorithm using Graham’s Scan.
- Functions:
  - `orientation()` → determines clockwise/counterclockwise turns  
  - `distSq()` → computes squared distance  
  - `swap()` → swaps two points  
  - `comparePoints()` → comparator used by `qsort_s` by polar angle w.r.t the pivot and distance from the pivot  
  - `sortByAngle()` → calls `qsort_s` to sort all points by the polar angle  
  - `convexHull()` → builds and outputs final hull  
- Outputs both console display and `hull_output.txt`.

### 4) Input files
- `points_10.txt`
- `points_50.txt`
- `points_1000.txt`
- `special_cases.txt`

Each file follows the format:

### 5) `hull_output.txt`
- Generated automatically.
- Contains only the points on the convex hull in counterclockwise order.

---

## To Compile and To Run

```bash
gcc main.c io.c convex_hull.c -o convex_hull -lm
./convex_hull
./convex_hull

