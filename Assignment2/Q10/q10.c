#include <stdio.h>

/*
 * Star Pattern Description:
 * The program prints a star pattern for any odd integer N where N represents the size of the pattern. 
 * The pattern consists of stars (*) and spaces, and its structure has three distinct parts:
 * 1. The top part consists of stars printed at increasing distances from the center.
 * 2. The middle part contains a solid line of stars, representing the center of the pattern.
 * 3. The bottom part mirrors the top part.
 *
 * N represents the length of the sides of the largest rectangle formed in the pattern. The center of the
 * pattern is the middle row of stars. The input value of N should always be an odd integer.
 * The pattern will adjust based on the input value of N, producing star patterns for any odd-sized input.
 * Example for N=5:
 *    *  
 *   * *  
 *  *   *  
 * *******
 * *   *  
 * * *  
 *    *  
*/

int main() {
    int space, a, spaceinner, i, j, l;

    // Prompt the user for an odd number input
    printf("Enter an odd number: ");
    scanf("%d", &a);

    // Ensure the number is odd, otherwise, prompt again
    if (a % 2 == 0) {
        printf("Please enter an odd number.\n");
        return 1;  // Exit the program if the input is not odd
    }

    // Initialize variables for spaces
    space = (a * 2) - 2;
    spaceinner = 0;

    // Top part of the pattern
    for(i = 0; i < a - 1; i++) {
        // Print leading spaces
        for(j = 0; j < space; j++) {
            printf(" ");
        }
        printf("*");

        // Print inner spaces
        for(l = 0; l < spaceinner; l++) {
            printf(" ");
        }

        // Print second star if there are inner spaces
        if (l != 0)
            printf("*");

        printf("\n");

        space--;
        if(i == 0)
            spaceinner++;
        else
            spaceinner += 2;
    }

    // Print the middle line of stars
    for(i = 0; i < a; i++) {
        printf("*");
    }

    // Print spaces in the middle of the line
    for(i = 0; i < spaceinner; i++) {
        printf(" ");
    }

    // Print the second part of the middle line
    for(i = 0; i < a; i++) {
        printf("*");
    }

    printf("\n");

    // Update spaceinner and space for the lower half of the pattern
    spaceinner = (spaceinner * 2) - 1;
    space = 1;

    // Bottom part of the pattern
    for(i = 0; i < a - 1; i++) {
        // Print leading spaces
        for(j = 0; j < space; j++) {
            printf(" ");
        }
        printf("*");

        // Print the space between the stars
        for(l = 0; l < spaceinner; l++) {
            printf(" ");
        }
        printf("*");
        printf("\n");

        spaceinner -= 2;
        space++;
    }

    // Bottom most line of stars
    space = a - 2;
    spaceinner = 1;
    for(i = 0; i < a - 2; i++) {
        // Print leading spaces
        for(j = 0; j < space; j++) {
            printf(" ");
        }
        printf("*");

        // Print space between the stars
        for(l = 0; l < space; l++) {
            printf(" ");
        }
        printf("*");

        // Print the inner spaces between the middle stars
        for(j = 0; j < spaceinner; j++) {
            printf(" ");
        }
        printf("*");

        // Print spaces after the inner star
        for(j = 0; j < space; j++) {
            printf(" ");
        }
        printf("*");
        printf("\n");

        space--;
        spaceinner += 4;
    }

    // Final part of the pattern
    spaceinner += 2;
    printf("*");
    for(j = 0; j < spaceinner; j++) {
        printf(" ");
    }
    printf("*");

    return 0;
}
