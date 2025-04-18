#ifndef KEYWORD_CHECK_H
#define KEYWORD_CHECK_H

#include <string.h>

const char* KEYWORDS[] = {
    "int", "float", "double", "char", "void",
    "if", "else", "for", "while", "return",
    "switch", "case", "break", "continue", "struct"
};

int isKeyword(const char* str) {
    int totalKeywords = sizeof(KEYWORDS) / sizeof(KEYWORDS[0]);
    for (int i = 0; i < totalKeywords; i++) {
        if (strcmp(KEYWORDS[i], str) == 0) {
            return 1;
        }
    }
    return 0;
}

#endif // KEYWORD_CHECK_H
#include <stdio.h>


int main(void) {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (isKeyword(input)) {
        printf("%s is a keyword.\n", input);
    } else {
        printf("%s is not a keyword.\n", input);
    }
    return 0;
}

