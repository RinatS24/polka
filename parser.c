#include "parser.h"

int equal(char a, char b) {
    if (((int)a == (int)b) || ((int)a + 32 == (int)b)) {
        return 1;
    }
    return 0;
}
void removeSpaces(char *str) {
    if (*str == '\0') return;
    char *back = str;
    char *front = str + 1;
    while (*front != '\0') {
        if (*front != ' ' || *back != ' ') *(++back) = *front;
        front++;
    }
    *(back + 1) = '\0';
}
void parser(char *infix) {
    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];
        char token2 = infix[i + 1];
        char token3 = infix[i + 2];
        char token4 = infix[i + 3];
        if (equal(token, 's') && equal(token2, 'i') && equal(token3, 'n')) {
            infix[i] = 's';
            infix[i + 1] = ' ';
            infix[i + 2] = ' ';
        } else if (equal(token, 'c') && equal(token2, 'o') && equal(token3, 's')) {
            infix[i] = 'c';
            infix[i + 1] = ' ';
            infix[i + 2] = ' ';
        } else if (equal(token, 't') && equal(token2, 'a') && equal(token3, 'n')) {
            infix[i] = 't';
            infix[i + 1] = ' ';
            infix[i + 2] = ' ';
        } else if (equal(token, 'c') && equal(token2, 't') && equal(token3, 'g')) {
            infix[i] = 'g';
            infix[i + 1] = ' ';
            infix[i + 2] = ' ';
        } else if (equal(token, 'l') && equal(token2, 'n')) {
            infix[i] = 'l';
            infix[i + 1] = ' ';
        } else if (equal(token, 's') && equal(token2, 'q') && equal(token3, 'r') && equal(token4, 't')) {
            infix[i] = 'q';
            infix[i + 1] = ' ';
            infix[i + 2] = ' ';
            infix[i + 3] = ' ';
        }
    }
    removeSpaces(infix);
}