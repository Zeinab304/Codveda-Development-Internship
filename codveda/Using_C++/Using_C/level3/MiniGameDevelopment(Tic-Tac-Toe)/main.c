#include <stdio.h>
#include <stdlib.h>

typedef enum {False,True}Bool;

char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };

void displayBoard() {
    printf("\n----- Tic Tac Toe Game -----\n\n");
    printf("\t-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("\t| ");
        for (int j = 0; j < 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n\t-------------\n");
    }
}

Bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return True;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return True;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return True;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return True;
    }
    return False;
}

int main() {
    int player = 1;
    int choice;
    int moves = 0;
    char mark;

    while (True) {
        displayBoard();
        player = (player % 2) ? 1 : 2;

        printf("\nPlayer %d, enter a number (1-9): ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9) {
            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = mark;

                if (checkWin()) {
                    displayBoard();
                    printf("\nCONGRATULATIONS! Player %d wins!\n", player);
                    break;
                }

                moves++;
                if (moves == 9) {
                    displayBoard();
                    printf("\nGAME OVER! It's a Draw.\n");
                    break;
                }
                player++;
            } else {
                printf("\nCell already occupied! Try again.\n");
            }
        } else {
            printf("\nInvalid input! Please enter a number between 1 and 9.\n");
        }
    }
    return 0;
}
