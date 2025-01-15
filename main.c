#include <stdio.h>
#include <stdlib.h>

void showBoard();
int checkWin();
void clearScreen() { /*Conditional Compilation || operating system*/
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

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
         if (input < 1 || input > 9){
                 printf("Please choose 1-9 number.\n");
                 continue; // It's use to give two messages for users
        } else if ( board[input] == 'X' || board[input] == 'O'){
            printf("Invalid input. Don't use some input.\n");
                continue; // It's use to give two messages for users
        }
    board[input] = mark;
    showBoard();

    int result = checkWin();

    if(result ==1){
        printf("Player %d winner", player);
        return ;
    }else if(result==0){
        printf("draw");
        return ;
    }
    player++;
    }
}

void showBoard(){
    clearScreen();
    printf("\n\n");
    printf("!!! Tic Tac Toe Game !!!!\n\n");
    printf("    |    |    \n");
    printf("  %c |  %c | %c \n", board[1],board[2],board[3]);
    printf("____|____|____\n");
    printf("    |    |    \n");
    printf("  %c |  %c |  %c \n", board[4],board[5],board[6]);
    printf("____|____|____\n");
    printf("    |    |    \n");
    printf("  %c |  %c |  %c \n", board[7],board[8],board[9]);
    printf("    |    |    \n");
}

int checkWin(){
if(board[1]==board[2] && board[2]==board[3]){
    return 1;
}
if(board[1]==board[4] && board[4]==board[7]){
    return 1;
}
if(board[7]==board[8] && board[8]==board[9]){
    return 1;
}
if(board[3]==board[6] && board[6]==board[9]){
    return 1;
}
if(board[1]==board[5] && board[5]==board[9]){
    return 1;
}
if(board[3]==board[5] && board[5]==board[7]){
    return 1;
}
if(board[2]==board[5] && board[5]==board[8]){
    return 1;
}
if(board[4]==board[5] && board[5]==board[6]){
    return 1;
}
int count = 0;
for (int i = 1; i<=9; i++){
    if(board[i]=='X' || board[i]=='O'){
        count++;
    }
}
if(count==9){
    return 0;
}
return -1;
}
