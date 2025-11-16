
#include <stdio.h>

char board[9] = {'1','2','3','4','5','6','7','8','9'};

void displayBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}

int checkWinner() {
    
    if (board[0]==board[1] && board[1]==board[2]) return 1;
    if (board[3]==board[4] && board[4]==board[5]) return 1;
    if (board[6]==board[7] && board[7]==board[8]) return 1;

    
    if (board[0]==board[3] && board[3]==board[6]) return 1;
    if (board[1]==board[4] && board[4]==board[7]) return 1;
    if (board[2]==board[5] && board[5]==board[8]) return 1;

    
    if (board[0]==board[4] && board[4]==board[8]) return 1;
    if (board[2]==board[4] && board[4]==board[6]) return 1;

    return 0; 
}

int main() {
    int player = 1, choice;
    char mark;
    int moves = 0;

    while (1) {
        displayBoard();

        player = (moves % 2 == 0) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d (%c), enter position (1-9): ", player, mark);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9 || board[choice - 1] == 'X' || board[choice - 1] == 'O') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[choice - 1] = mark;
        moves++;

        if (checkWinner()) {
            displayBoard();
            printf("?? Player %d wins!\n", player);
            break;
        }

        if (moves == 9) {
            displayBoard();
            printf("It's a tie!\n");
            break;
        }
    }

    return 0;
}



