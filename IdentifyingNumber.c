#include <stdio.h>
#include <string.h>

// Function to check if a string is a number
int isNumber(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0; // Not a number
        }
    }
    return 1; // Is a number
}

int main(void) {
    char input[20];
    printf("Enter a string: ");
    scanf("%s", input);

    if (isNumber(input)) {
        printf("'%s' is a number.\n", input);
    } else {
        printf("'%s' is not a number.\n", input);
    }

    return 0;
}

