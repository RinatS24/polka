#include "eval.h"

#include <math.h>
#include <stdio.h>
#include <string.h>
void initStack(Stack *s, int capacity) {
    s->data = (double *)malloc(sizeof(double) * capacity);
    s->top = -1;
    s->capacity = capacity;
}
int isEmpty(struct Stack *stack) { return stack->top == -1; }
void push(Stack *s, double value) { s->data[++s->top] = value; }

double pop(Stack *s) {
    if (isEmpty(s) == 1) printf("Неверный формат ввода!");
    return s->data[s->top--];
}
void freeStack(Stack *s) {
    free(s->data);
    s->data = NULL;
    s->top = -1;
}
void processOperator(Stack *st, char op, int *fl) {
    double b = pop(st);
    switch (op) {
        case '+':
            push(st, pop(st) + b);
            break;
        case '-':
            push(st, pop(st) - b);
            break;
        case '*':
            push(st, pop(st) * b);
            break;
        case '/':
            if (b != 0.0)
                push(st, pop(st) / b);
            else
                *fl = 1;
            break;
        case 's':
            push(st, sin(b));
            break;
        case 'c':
            push(st, cos(b));
            break;
        case 't':
            if (b != M_PI)
                push(st, tan(b));
            else
                *fl = 1;
            break;
        case 'g':
            if (b != 0.0)
                push(st, 1.0 / tan(b));
            else
                *fl = 1;
            break;
        case 'l':
            if (b >= 0)
                push(st, log(b));
            else
                *fl = 1;
            break;
        case 'q':
            if (b >= 0)
                push(st, sqrt(b));
            else
                *fl = 1;
            break;
    }
}

double eval(char *A, int size, double x) {
    Stack st;
    int fl = 0, numIndex = 0;
    double res;
    initStack(&st, size);
    char numBuffer[1000];
    for (int i = 0; i < (int)strlen(A); i++) {
        char *p = &A[i];
        if (*p != ' ' && *p != '\n' && fl != 1 && *p != '\0') {
            if ((*p >= '0' && *p <= '9') || (*p == '.' && numIndex > 0) ||
                (*p == '-' && (*(p + 1) >= '0') && (*(p + 1) <= '9') && numIndex == 0)) {
                numBuffer[numIndex++] = *p;
            }
            if ((numIndex > 0) && (*(p + 1) == ' ') && (*(p + 2) != '.')) {
                numBuffer[numIndex] = '\0';
                push(&st, (double)atof(numBuffer));
                numIndex = 0;
            } else if (*p == 'x') {
                if (numIndex > 0) {
                    x = x * (-1.0);
                    numIndex = 0;
                }
                push(&st, (double)x);
            } else if ((!(*p == '-' && ((*(p + 1) >= '0' && *(p + 1) <= '9') || *(p + 1) == 'x'))) &&
                       ((*p == '*') || (*p == '-') || (*p == '/') || (*p == 's') || (*p == 'c') ||
                        (*p == 't') || (*p == 'g') || (*p == 'l') || (*p == 'q')))
                processOperator(&st, *p, &fl);
        }
    }

    if (fl != 1) {
        res = pop(&st);
    } else {
        res = 99999.99;
    }
    freeStack(&st);
    return res;
}
