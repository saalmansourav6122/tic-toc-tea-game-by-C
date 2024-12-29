#include <stdio.h>
#include <stdlib.h>

void showBoard();
char board[]={'0','1','2','3','4','5','6','7','8','9'};

void main(){
    int player = 1, input, status =-1;
     showBoard();

    while (status == -1)
    {
        player =(player%2==0)? 2: 1;
        char mark = (player==1) ? 'X':'O';
        printf("Please enter Number for player %d \n", player);
        scanf("%d",&input);
    if(input<1 || input>9){
        printf("invalid input");
    }
    board[input] = mark;
    showBoard();
    player++;
    }
}

void showBoard(){
    printf("\n\n");
    printf("!!! Tic Tac Toe Game !!!!\n\n");
    printf("    |    |    \n");
    printf("  %c | %c  | %c  \n", board[1],board[2],board[3]);
    printf("____|____|____\n");
    printf("    |    |    \n");
    printf("  %c |  %c |  %c \n", board[4],board[5],board[6]);
    printf("____|____|____\n");
    printf("    |    |    \n");
    printf("  %c |  %c |  %c \n", board[7],board[8],board[9]);
    printf("    |    |    \n");
}
