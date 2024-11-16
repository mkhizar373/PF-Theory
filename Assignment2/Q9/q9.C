#include <stdio.h>

void upDown(char grid[][5], int *p1, int *p2, int *item, char direction);
void leftRight(char grid[][5], int *p1, int *p2, int *item, char direction);
void printGrid(char grid[5][5]);

int main() {
    char grid[5][5] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    printf("Welcome to Grid Adventure Game.\n\n");
    printf("Enter the following keys to play\nW: up\nS: down\nA: Left\nD: Right\nQ: Quit.\n\n");
    printf("Let's Start\n");

    int p1 = 4, p2 = 4, item = 0;
    char a;

    while (1) {
        printGrid(grid);
        printf("\nEnter your move: ");
        scanf(" %c", &a);

        if (a == 'W') {
            upDown(grid, &p1, &p2, &item, 'W');
        } else if (a == 'S') {
            upDown(grid, &p1, &p2, &item, 'S');
        } else if (a == 'A') {
            leftRight(grid, &p1, &p2, &item, 'A');
        } else if (a == 'D') {
            leftRight(grid, &p1, &p2, &item, 'D');
        } else if (a == 'Q') {
            printf("\nThe game has ended\n");
            printf("Collected items: %d\n", item);
            break;
        } else {
            printf("Invalid Input\n");
        }
    }

    return 0;
}

void printGrid(char grid[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("|'%c'", grid[i][j]);
        }
        printf("|\n");
    }
}

void upDown(char grid[][5], int *p1, int *p2, int *item, char direction) {
    int newRow = *p1;

    if (direction == 'W') {
        newRow = *p1 - 1;
    } else if (direction == 'S') {
        newRow = *p1 + 1;
    }

    if (newRow >= 0 && newRow < 5 && grid[newRow][*p2] != 'X') {
        if (grid[newRow][*p2] == 'I') {
            (*item)++;
        }
        grid[*p1][*p2] = ' ';
        grid[newRow][*p2] = 'P';
        *p1 = newRow;
    } else {
        printf("Invalid move.\n");
    }
}

void leftRight(char grid[][5], int *p1, int *p2, int *item, char direction) {
    int newCol = *p2;

    if (direction == 'A') {
        newCol = *p2 - 1;
    } else if (direction == 'D') {
        newCol = *p2 + 1;
    }

    if (newCol >= 0 && newCol < 5 && grid[*p1][newCol] != 'X') {
        if (grid[*p1][newCol] == 'I') {
            (*item)++;
        }
        grid[*p1][*p2] = ' ';
        grid[*p1][newCol] = 'P';
        *p2 = newCol;
    } else {
        printf("Invalid move.\n");
    }
}
