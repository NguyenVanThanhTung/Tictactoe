# ifndef _LOGICTICTACTOE___H
# define _LOGICTICTACTOE__H

#pragma once
#define BOARD_SIZE 15
#define EMPTY_CELL ' '
#define O_CELL 'o'
#define X_CELL 'x'

struct Tictactoe {
    char board[BOARD_SIZE][BOARD_SIZE];
    bool valuaBoard[BOARD_SIZE][BOARD_SIZE];
    char nextMove = O_CELL;
    char winner = '0';
    bool endGame = false;

    void init(){
         for (int i = 0; i < BOARD_SIZE; i++){
            for (int j = 0; j < BOARD_SIZE; j++){
                board[i][j] = EMPTY_CELL;
                valuaBoard[i][j] = false;
            }
         }
    }

    void move(int row, int col) {
        if ((row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) && !valuaBoard[row][col]){
            board[row][col] = nextMove;
            valuaBoard[row][col] = true;
            nextMove = (nextMove == O_CELL) ? X_CELL : O_CELL;
        }
    }

    void checkEndGame(){
        for(int i = 0; i< BOARD_SIZE; i++){
            for(int j = 0; j< BOARD_SIZE; j++){
                if(board[i][j] != EMPTY_CELL){
                    if(board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j] && board[i][j] == board[i+3][j] && board[i][j] == board[i+4][j]){
                        endGame = true;
                        winner = board[i][j];
                    }
                    if(board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2] && board[i][j] == board[i+3][j+3] && board[i][j] == board[i+4][j+4]){
                        endGame = true;
                        winner = board[i][j];
                    }
                    if(board[i][j] == board[i-1][j+1] && board[i][j] == board[i-2][j+2] && board[i][j] == board[i-3][j+3] && board[i][j] == board[i-4][j+4]){
                        endGame = true;
                        winner = board[i][j];
                    }
                    if(board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2] && board[i][j] == board[i][j+3] && board[i][j] == board[i][j+4]){
                        endGame = true;
                        winner = board[i][j];
                    }
                }
            }
        }
    }
};
#endif
