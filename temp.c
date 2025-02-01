#include <stdio.h>

int main() {
int array[100], i, n;


printf("Enter the number of elements: ");
scanf("%d", &n);


printf("Enter %d elements: ", n);
	for(i = 0; i < n; i++) {
    scanf("%d", &array[i]);
    }

 
printf("Output the same number:\n");
	for(i = 0; i < n; i++) {
    printf("%d ", array[i]);
    }

  
printf("\nReverse print:\n");
	for(i = n - 1; i >= 0; i--) {
        printf("%d ", array[i]);
    }

return 0;
}

~

