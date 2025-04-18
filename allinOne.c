#include <stdio.h>
#include <string.h>
#include <ctype.h>


const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "inline", "int", "long", "register", "restrict", "return",
    "short", "signed", "sizeof", "static", "struct", "switch",
    "typedef", "union", "unsigned", "void", "volatile", "while"
};
int n_keywords = sizeof(keywords) / sizeof(keywords[0]);


const char operators[] = "+-*/%=<>!&|^~?:[](){};,.#";

// Check if string is a C keyword
int isKeyword(const char *str) {
    for (int i = 0; i < n_keywords; ++i) {
        if (strcmp(str, keywords[i]) == 0) return 1;
    }
    return 0;
}

int isIdentifier(const char *str) {
    if (!str || !str[0]) return 0;
    if (!(isalpha(str[0]) || str[0] == '_')) return 0;
    if (isKeyword(str)) return 0;
    for (int i = 1; str[i]; ++i) {
        if (!(isalnum(str[i]) || str[i] == '_')) return 0;
    }
    return 1;
}


int isNumber(const char *str) {
    if (!str || !str[0]) return 0;
    for (int i = 0; str[i]; ++i) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}


int isOperator(char ch) {
    for (int i = 0; operators[i]; ++i) {
        if (ch == operators[i]) return 1;
    }
    return 0;
}

int main() {
    char input[256];

    printf("Enter anything (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        if (!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\n")] = 0; // Remove newline

        if (strcmp(input, "exit") == 0) break;

        if (strlen(input) == 1 && isOperator(input[0])) {
            printf("Operator: %c\n", input[0]);
        }
        else if (isKeyword(input)) {
            printf("Keyword: %s\n", input);
        }
        else if (isIdentifier(input)) {
            printf("Valid Identifier: %s\n", input);
        }
        else if (isNumber(input)) {
            printf("Number: %s\n", input);
        }
        else {
            printf("Unknown/Invalid: %s\n", input);
        }
    }

    printf("Goodbye!\n");
    return 0;
}
