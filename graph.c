#include <stdio.h>

#include "input.h"
#include "polka.h"
#include "rendering_image.h"

// all numbers with infix '-' should be in (brackets) if there is an operator nearby.
// there should be a space after using '-' as a standalone operator, or the operand must be in (brackets)
// tangent = tan()
// ctangent = ctg()
// square root = sqrt()
// ln()
int main() {
    char infix[MAX_SIZE];

    char **matrix = malloc(HEIGHT * (sizeof(char *)));
    for (int i = 0; i < HEIGHT; i++) matrix[i] = malloc(WIDTH * (sizeof(char)));

    printf("Введите инфиксное выражение: ");

    if (input(infix, MAX_SIZE)) {
        char postfix[MAX_SIZE];
        infix_to_postfix(infix, postfix);
        printf("%s\n", postfix);
        int graphic_matrix[HEIGHT][WIDTH];
        fill_graph(graphic_matrix);
        create_graphic(graphic_matrix, postfix, MAX_SIZE);
        print_graph(graphic_matrix);
    } else {
        printf("Wrong input");
    }

    for (int i = 0; i < HEIGHT; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
