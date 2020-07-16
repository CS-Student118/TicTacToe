#include <stdio.h>
#include <stdlib.h>

/************************************************************
TicTacToe game
*************************************************************/

// Global variables that will be used throughout this program.
int x;
int y;
int winner = 0;
int xCheckHorizontal = 0;
int oCheckHorizontal = 0;
int xCheckVertical = 0;
int oCheckVertical = 0;
int oCheckDiagonal = 0;
int xCheckDiagonal = 0;
int opponentXVertical;
int opponentYVertical;
int opponentX;
int opponentY;


//  Prototypes(methods) that will be used.
void opponentMove();
void checkHorizontal();
void checkVertical();
char checkWinner();
void checkDiagonal();
char checkDraw();
char opponentMoveWin();


//  The game board
char board[3][8]  = {
        {'_','|','_','|','_'},
        {'_','|','_','|','_'},
        {' ','|',' ','|',' '},
    };

//  This method will print the board to the screen.
void printBoard(){

    int i;
    int j;

    //  For loop to iterate over each character of the board and print it.
    for(i = 0; i < 3; i++){

        for(j = 0; j < 8; j++){

            printf("%c",board[i][j]);
        }
        printf("\n");
    }


}

//  This method will start the game.
void playGame()
{

    //  This loop ensures the game keeps running until there is a winner or a draw.
    while(winner < 1){

        printf("Enter your move with the x and y co-ordinates");

        scanf("%d, %d", &x,&y);

        //  Ensures users input is within the range.
        if(x < 1 || x > 3){

            fflush(stdin);

            printf("Input out of range, try again\n");

            continue;

        }

        if(y < 1 || y > 3){

            fflush(stdin);

            printf("Input out of range, try again\n");

            continue;
        }

        //  Converts y to fit the proper range within the board array.
        if(y == 1){

            y = 0;

        }else if (y == 3){

            y = 4;
        }

        //  Ensures that the user cannot overwrite square that is already taken.
        if (board[x - 1][y] == 'O'){

            printf("That co-ordinate is taken, try again\n");

            continue;

        }else{

            board[x - 1][y] = 'X';
        }

        opponentMove();

        printBoard();

        //  Checks if there is a winner or a draw. If there is then it increments winner in order to end the loop.
        if(checkWinner() == 'X'){

            printf("You won!\n");

            winner++;

        }else if(checkWinner() == 'O'){

            printf("You lost\n");

            winner++;

        }else if(checkDraw() == 'D'){

            printf("It's' a draw\n");

            printBoard();

            winner++;
        }

    }

    printf("Game over");


}


//  Checks if the board has been filled and confirms that there is no winner, thus there is a draw.
char checkDraw(){

    int firstCheck;

    int secondCheck;

    //  Confirms that there is no winner.
    if(checkWinner() != 'X' || checkWinner != 'O'){

        //  For loop to iterate over the board to ensure that it is full.
        for(firstCheck = 0; firstCheck < 3; firstCheck++){

            for(secondCheck= 0; secondCheck < 5; secondCheck++){

            if(board[firstCheck][secondCheck] == '_' || board[firstCheck][secondCheck] == ' '){

                    return;
            }
        }
    }


    //  If board is full and it is a draw, it returns D.
     return 'D';
}
}

//  Checks if there is a winner.
char checkWinner(){

    // Checks if a pattern of three shapes X or O has been formed horizontally, vertically or diagonally.
    checkHorizontal();

    checkVertical();

    checkDiagonal();

    //  If X has formed the pattern, then it returns X.
    if(xCheckHorizontal == 3 || xCheckVertical == 3 || xCheckDiagonal == 3){

        return 'X';
    }

    //  If O has formed it, then it returns O.
    if(oCheckHorizontal == 3 || oCheckVertical == 3 || oCheckDiagonal == 3){

        return 'O';
    }

    return;
}

//  This checks to see if a vertical pattern of 3 has been made by either the X or the O.
void checkVertical(){

    //  If a vertical pattern has been made, then this changes the variable to 3 accordingly.
    if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X'){

        xCheckVertical = 3;

    }else if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X'){

        xCheckVertical = 3;

    }else if(board[0][4] == 'X' && board[1][4] == 'X' && board[2][4] == 'X'){

        xCheckVertical = 3;

    }else if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O'){

        oCheckVertical = 3;

    }else if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'){

        oCheckVertical = 3;

    }else if(board[0][4] == 'O' && board[1][4] == 'O' && board[2][4] == 'O'){

        oCheckVertical = 3;
    }
}

//  Checks if a horizontal pattern of 3 has been made by X or O.
void checkHorizontal(){

int firstChecker;

int secondChecker;

    //  Loops through the board to look for a pattern and increments the checkers accordingly.
    for(firstChecker = 0; firstChecker < 3; firstChecker++){

        xCheckHorizontal = 0;

        oCheckHorizontal = 0;

        for(secondChecker = 0; secondChecker < 5; secondChecker++){

            if(board[firstChecker][secondChecker] == 'X'){

                xCheckHorizontal++;

            }
            if(board[firstChecker][secondChecker] == 'O'){

                oCheckHorizontal++;

            }

            if(xCheckHorizontal == 3 || oCheckHorizontal == 3){

                return;
            }
        }
    }
}

//   Checks if a diagonal pattern of 3 has been made by X or O.
void checkDiagonal(){

    //  Sets the diagonal variable accordingly if a pattern of 3 has been found.
    if(board[0][0] == 'X' && board[1][2] == 'X' && board[2][4] == 'X'){

            xCheckDiagonal = 3;
            return;

    }else if(board[0][4] == 'X' && board[1][2] ==  'X' && board[2][0] == 'X'){

            xCheckDiagonal = 3;
            return;

    }else if(board[0][0] == 'O' && board[1][2] == 'O' && board[2][4] == 'O'){

            oCheckDiagonal = 3;
            return;
    }else if(board[0][4] == 'O' && board[1][2] ==  'O' && board[2][0] == 'O'){

            oCheckDiagonal = 3;
            return;
    }

}

//  This method automates the opponents move.
void opponentMove()
{
    int xCounter;
    int xCounterVertical;
    int validInput = 0;

    //  If the opponent move win method has already done its move, then this will return in order to prevent the computer from
    //  doing 2 moves in one turn.
    if(opponentMoveWin() == 'M'){

        return;
    }

    //  This loops through the board to see if there is an almost finished horizontal pattern for X, if there is then it places an O to block it.
    for(opponentX = 0; opponentX < 3; opponentX++){

        xCounter = 0;

        for(opponentY = 0; opponentY < 5; opponentY++){

            if(board[opponentX][opponentY] == 'X'){

                xCounter++;
            }

            if(xCounter == 2){

                for(opponentY = 0; opponentY < 5; opponentY++){

                    if(board[opponentX][opponentY] == '_' || board[opponentX][opponentY] == ' '){

                        board[opponentX][opponentY] = 'O';

                        return;

                    }
                }
            }
        }
    }

    //  This loops through the board to see if there is an almost finished vertical pattern for X, if there is then it places an O to block it.
    for(opponentYVertical = 0; opponentYVertical < 5; opponentYVertical = opponentYVertical + 2){

        xCounterVertical = 0;

        for(opponentXVertical = 0; opponentXVertical < 3; opponentXVertical++){

            if(board[opponentXVertical][opponentYVertical] == 'X'){

                xCounterVertical++;
            }

            if(xCounterVertical == 2){

                for(opponentXVertical = 0; opponentXVertical < 3; opponentXVertical++){

                    if(board[opponentXVertical][opponentYVertical] == '_' || board[opponentXVertical][opponentYVertical] == ' '){

                        board[opponentXVertical][opponentYVertical] = 'O';

                        return;
                    }
                }
            }

        }

    }

    //  This iterates through the board to see if there is an almost finished diagonal pattern for X, if there is then it places an O to block it.
    if(board[0][0] == 'X' && board[1][2] == 'X'){

            if(board[2][4] == ' '){

                board[2][4] = 'O';

                return;
            }

    }else if(board[0][4] == 'X' && board[1][2] == 'X'){

            if(board[2][0] == ' '){

                board[2][0] == 'O';

                return;

            }

    }else if(board[2][0] == 'X' && board[1][2] ==  'X'){

            if(board[0][4] == '_'){

                board[0][4] = 'O';

                return;
            }

    }else if(board[2][4] == 'X' && board[1][2] == 'X'){

            if(board[0][0] == '_'){

                board[0][0] = 'O';

                return;

            }
    }

    // This ensures that it is not a draw and thus there is still room for another move.
    if(checkDraw() == 'D'){

     return;

    }

    //  This keeps coming up with random numbers until it finds one that corresponds to an available position on the board, it then writes O on that position.
    while(validInput < 1){

        int xValue = rand() % 4;

        int yValue = rand() % 5;

        if(yValue == 1){

            yValue = 0;

        }else if (yValue == 3){

            yValue = 4;
        }

        if(board[xValue][yValue] == '_' || board[xValue][yValue] == ' '){

            board[xValue][yValue] = 'O';

            validInput++;
        }

    }

    return;

}

//  This method checks to see if there is a winning move avaiable for O. If there is then it executes it.
char opponentMoveWin(){

    int oCounter;
    int oCounterVertical;
     //  This loops through to see if there is an almost finished horizontal pattern for O, if there is then it finishes it to win the game.
     for(opponentX = 0; opponentX < 3; opponentX++){

        oCounter = 0;

        for(opponentY = 0; opponentY < 5; opponentY++){

            if(board[opponentX][opponentY] == 'O'){

                oCounter++;
            }

            if(oCounter == 2){

                for(opponentY = 0; opponentY < 5; opponentY++){

                    if(board[opponentX][opponentY] == '_' || board[opponentX][opponentY] == ' '){

                        board[opponentX][opponentY] = 'O';

                        return 'M';

                    }
                }
            }
        }
    }

    //  This loops through to see if there is an almost finished vertical pattern for O, if there is then it finishes it to win the game.
    for(opponentYVertical = 0; opponentYVertical < 5; opponentYVertical = opponentYVertical + 2){

        oCounterVertical = 0;

        for(opponentXVertical = 0; opponentXVertical < 3; opponentXVertical++){

            if(board[opponentXVertical][opponentYVertical] == 'O'){

                oCounterVertical++;
            }

            if(oCounterVertical == 2){

                for(opponentXVertical = 0; opponentXVertical < 3; opponentXVertical++){

                    if(board[opponentXVertical][opponentYVertical] == '_' || board[opponentXVertical][opponentYVertical] == ' '){

                        board[opponentXVertical][opponentYVertical] = 'O';

                        return 'M';
                    }
                }
            }

        }

    }

    //  Loops through to see if there is an almost finished diagonal pattern for O, if there is then it finishes it to win.
    if(board[0][0] == 'O' && board[1][2] == 'O'){

            if(board[2][4] == ' '){

                board[2][4] = 'O';

                return 'M';
            }

    }else if(board[0][4] == 'O' && board[1][2] == 'O'){

            if(board[2][0] == ' '){

                board[2][0] == 'O';

                return 'M';

            }

    }else if(board[2][0] == 'O' && board[1][2] ==  'O'){

            if(board[0][4] == '_'){

                board[0][4] = 'O';

                return 'M';
            }

    }else if(board[2][4] == 'O' && board[1][2] == 'O'){

            if(board[0][0] == '_'){

                board[0][0] = 'O';

                return 'M';

            }
    }

    //  Returns N if no winning patterns were found.
   return 'N';
}

int main()
{
    // Prompts the user to enter their name.
    char name[30];

    printf("What is your name?");

    // Only accepts inputs with lowercase letters, uppercase letters and spaces.
    scanf("%[a-zA-Z ]s",name);

    fflush(stdin);

    //  Welcome message for the user.
    printf("Welcome %s\nLet's play Tic Tac Toe\n", name);

    printf("You = X | Computer = O\n");

    printBoard();

    //  Starts the game.
    playGame();

    return 0;
}








