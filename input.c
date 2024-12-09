#include "input.h"

#include <stdio.h>

#include "parser.h"

int len(char* infix) {
    int len = 0;
    while (*infix != '\0') {
        len++;
        infix++;
    }
    return len;
}
int arif_operator(char curret) {
    if (curret == 'c' || curret == 's' || curret == 't' || curret == 'g' || curret == 'l' || curret == 'q' ||
        curret == 'x')
        return 1;
    return 0;
}
int operator(char curret) {
    if (curret == '+' || curret == '-' || curret == '*' || curret == '/') return 1;
    return 0;
}
int input(char* infix, int MAX_SIZE) {
    int flag = 1;
    int count_bracket = 0;
    fgets(infix, MAX_SIZE, stdin);
    parser(infix);

    int lenght = len(infix);

    for (int i = 0; i < lenght; i++) {
        if (arif_operator(infix[i]) && arif_operator(infix[i + 1])) flag = 0;
        if (operator(infix[i]) && operator(infix[i + 1])) flag = 0;
        if (infix[i] >= 'a' && infix[i] <= 'z' && infix[i] != 's' && infix[i] != 'c' && infix[i] != 't' &&
            infix[i] != 'g' && infix[i] != 'l' && infix[i] != 'q' && infix[i] != 'x')
            flag = 0;
        if (infix[i] == '(') {
            count_bracket++;
        } else if (infix[i] == ')')
            count_bracket--;
    }
    if (count_bracket != 0) flag = 0;

    return flag;
}
