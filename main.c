#include <stdio.h>
#include <stdlib.h>

// function prototypes
void showBoard();
int checker();
void restartgame();
// Global variables
char box[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main(){
    int player, input, status;
    char choice;
    do{
        player = 1;
        status = -1;
        restartgame(); // Reset the board at the start of each new game
        showBoard();

// Main game loop
        while (status == -1) {

            char mark = (player == 1) ? 'X' : 'O';
            printf("Player %d, enter your move: ", player);
            scanf("%d", &input);

            // Step 3: Validate the input
            if (input < 1 || input > 9 ) {
                printf("Invalid move! Please enter (1-9) number.\n");
                continue;
            } else if(box[input] == 'X' || box[input] == 'O'){
                printf("Invalid move! Please try again.\n");
                continue;
            }

            // Mark the board and update the status
            box[input] = mark;
            showBoard();
            status = checker();
            //Switch players if the game is still ongoing
          if (status == -1) {
                printf("%d", status);
                player = (player == 1) ? 2 : 1;
            }
        }
           // Announce the result

        if (status == 1) {
            printf("Player %d wins!\n", player);
        } else {
            printf("It's a draw!\n");
        }

        //Ask if players want to restart

        printf("Do you want to restart the game? (y/n): ");
        scanf(" %c", &choice);
    }while (choice == 'y' || choice == 'Y');
    return 0;
};

void showBoard() {
    system("cls"); // Clears the console screen
    printf("\n\n");
    printf("!!! Tic Tac Toe Game !!!!\n\n");
    printf("    |    |    \n");
    printf("  %c |  %c |  %c \n", box[1], box[2], box[3]);
    printf("____|____|____\n");
    printf("    |    |    \n");
    printf("  %c |  %c |  %c \n", box[4], box[5], box[6]);
    printf("____|____|____\n");
    printf("    |    |    \n");
    printf("  %c |  %c |  %c \n", box[7], box[8], box[9]);
    printf("    |    |    \n");
}

int checker() {
    if (
        (box[1] == box[2] && box[2] == box[3]) ||
        (box[4] == box[5] && box[5] == box[6]) ||
        (box[7] == box[8] && box[8] == box[9]) ||
        (box[1] == box[4] && box[4] == box[7]) ||
        (box[2] == box[5] && box[5] == box[8]) ||
        (box[3] == box[6] && box[6] == box[9]) ||
        (box[1] == box[5] && box[5] == box[9]) ||
        (box[3] == box[5] && box[5] == box[7])
    ) {
        return 1;
    }
    for (int i = 1; i <= 9; i++) {
        if (box[i] != 'X' && box[i] != 'O') {
            return -1; // Game still in progress
        }
    }
    return 0;
}

// Function to reset the game board
void restartgame() {
    for (int i = 1; i <= 9; i++) {
        box[i] = i + '0'; // Reset each box to its corresponding number
    }
}
