
#include "polka.h"
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == 's' || op == 'c' || op == 't' || op == 'g' || op == 'q' || op == 'l') return 3;
    return 0;
}

int is_digit(char c) { return c >= '0' && c <= '9'; }

void infix_to_postfix(char *infix, char *postfix) {
    char stack[MAX_SIZE] = "";
    int top = -1;
    int i, j;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (token != ' ') {
            if (is_digit(token) || token == 'x' || token == '.' ||
                (token == '-' && (is_digit(infix[i + 1]) || infix[i + 1] == 'x'))) {
                postfix[j++] = token;
                if (((is_digit(token) || token == 'x') && !is_digit(infix[i + 1]))) {
                    postfix[j++] = ' ';
                }
            } else if (token == 's' || token == 'c' || token == 'q' || token == 't' || token == 'g' ||
                       token == 'l') {
                stack[++top] = token;
            } else if (token == '(') {
                stack[++top] = token;
            } else if (token == ')') {
                while (top != -1 && stack[top] != '(') {
                    postfix[j++] = stack[top--];
                    postfix[j++] = ' ';
                }
                top--;
            } else {
                while (top != -1 && precedence(stack[top]) >= precedence(token)) {
                    postfix[j++] = stack[top--];
                    postfix[j++] = ' ';
                }
                stack[++top] = token;
            }
        }
    }

    while (top >= 0) {
        postfix[j++] = stack[top--];
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
}
