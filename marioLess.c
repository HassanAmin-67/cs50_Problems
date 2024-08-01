#include <stdio.h>

// Function to get a valid integer input between 1 and 8
int get_valid_height() {
    int n;
    int result;

    while (1) {
        printf("\nEnter a number between 1 and 8: ");
        result = scanf("%d", &n);

        if (result != 1) {
            printf("\nInvalid input. Please enter an integer.\n");
            continue;
        }

        if (n >= 1 && n <= 8) {
            break;
        } else {
            printf("\nInvalid input. Please enter an integer between 1 and 8.\n");
        }
    }

    return n;
}
int main() {
    int n, i, j;

    n = get_valid_height();

    for (i = 1; i <= n; i++) {
        // Spaces for left pyramid
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Hashes for left pyramid
        for (j = 1; j <= i; j++) {
            printf("#");
        }
        // Moving to the next line
        printf("\n");
    }

    return 0;
}
