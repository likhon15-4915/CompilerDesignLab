#ifndef OPERATOR_CHECK_H
#define OPERATOR_CHECK_H

const char OPERATORS[] = {'+', '-', '*', '/', '%', '=', '<', '>', '!', '&', '|', '^', '~', '?', ':', '[', ']', '(', ')', '{', '}', ',', ';', '.', '#'};

int isOperator(char ch) {
    for (int i = 0; i < sizeof(OPERATORS) / sizeof(OPERATORS[0]); i++) {
        if (OPERATORS[i] == ch) {
            return 1;
        }
    }
    return 0;
}

#endif 

#include <stdio.h>

int main(void) {
    char testChar; 
    printf("Enter a character: ");
    scanf(" %c", &testChar); // Added space before %c to consume any leftover newline
    if (isOperator(testChar)) {
        printf("%c is an operator.\n", testChar);
    } else {
        printf("%c is not an operator.\n", testChar);
    }
    return 0;
}
