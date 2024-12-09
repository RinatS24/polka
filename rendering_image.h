#ifndef RENDERING_IMAGE_H
#define RENDERING_IMAGE_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEIGHT 25
#define WIDTH 80

void fill_graph(int matrix[HEIGHT][WIDTH]);
void create_graphic(int matrix[HEIGHT][WIDTH], char* A, int size);
void print_graph(int matrix[HEIGHT][WIDTH]);

#endif
