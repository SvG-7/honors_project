#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePointsFile(const char *filename, int n, int maxRange) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("Error opening file %s\n", filename);
        return;
    }

    fprintf(f, "%d\n", n);
    for (int i = 0; i < n; i++) {
        int x = rand() % maxRange;
        int y = rand() % maxRange;
        fprintf(f, "%d %d\n", x, y);
    }

    fclose(f);
    printf("Generated file: %s with %d points\n", filename, n);
}

int main() {
    srand(time(NULL));  

    generatePointsFile("points_10.txt", 10, 100);
    generatePointsFile("points_30.txt", 30, 100);
    generatePointsFile("points_1000.txt", 1000, 1000);

    generatePointsFile("points_50.txt", 50, 500);

    printf("Random point files generated successfully!\n");
    return 0;
}
