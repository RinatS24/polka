#include <math.h>
#include <stdio.h>

#include "eval.h"
#include "rendering_image.h"
void fill_graph(int matrix[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            matrix[i][j] = '.';
        }
    }
}

void create_graphic(int matrix[HEIGHT][WIDTH], char *A, int size) {
    for (int i = 0; i < WIDTH; i++) {
        double x = (i * 4.0 * 3.14) / (WIDTH - 1);
        double res = eval(A, size, x);
        int y = round((res + 1) * (HEIGHT - 1) / 2);
        if (y >= 0 && y < HEIGHT) {
            matrix[y][i] = '*';
        }
    }
}

void print_graph(int matrix[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}
