
#ifndef EVAL_H
#define EVAL_H
#include <math.h>
#include <stdlib.h>
typedef struct Stack {
    double *data;
    int top;
    int capacity;
} Stack;
void processOperator(Stack *st, char op, int *fl);
void push(Stack *s, double value);
double pop(Stack *s);
double eval(char *A, int size, double x);
void freeStack(Stack *s);
int isEmpty(struct Stack *stack);
#endif
