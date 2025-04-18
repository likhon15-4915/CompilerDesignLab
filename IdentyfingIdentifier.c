#include <stdio.h>
#include <string.h>
#include <ctype.h>  // For isalpha, isalnum

// Simple keyword check function
// Returns 1 if str is a C keyword, 0 otherwise
int isKeyword(const char *str) {
    // List of some common C keywords
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "inline", "int", "long", "register", "restrict", "return",
        "short", "signed", "sizeof", "static", "struct", "switch",
        "typedef", "union", "unsigned", "void", "volatile", "while",
        "_Bool", "_Complex", "_Imaginary"
    };
    int n_keywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < n_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1; // It's a keyword
        }
    }
    return 0; // Not a keyword
}

// Function to check if a string is a valid identifier
// Returns 1 if valid, 0 if invalid
int isIdentifier(const char *str) {
    if (str == NULL || str[0] == '\0') {
        return 0; // Empty string is invalid
    }

    // First character must be underscore or letter
    if (!(str[0] == '_' || isalpha((unsigned char)str[0]))) {
        return 0;
    }

    // Check if it is a keyword
    if (isKeyword(str)) {
        return 0;
    }

    // Remaining characters must be underscore, letter, or digit
    for (int i = 1; str[i] != '\0'; i++) {
        if (!(str[i] == '_' || isalnum((unsigned char)str[i]))) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[256];

    printf("Enter strings to check if they are valid identifiers (type 'exit' to quit):\n");

    while (1) {
        printf("Input: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // EOF or error
        }

        // Remove trailing newline
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        if (strcmp(input, "exit") == 0) {
            break;
        }

        if (isIdentifier(input)) {
            printf("'%s' is a valid identifier.\n", input);
        } else {
            printf("'%s' is NOT a valid identifier.\n", input);
        }
    }

    printf("Exiting program.\n");
    return 0;
}
