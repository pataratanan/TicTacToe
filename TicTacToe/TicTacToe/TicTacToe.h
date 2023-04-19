#ifndef TicTacToe_h
#define TicTacToe_h

#include <iostream>
#include <array>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "BoardCoordinate.h"

using namespace std;

class TicTacToe{
private:
    char board[3][3];
    int noOfMoves;
    enum status{
        WIN,DRAW,CONTINUE
    };
    int row;
    int col;
public:
    TicTacToe(){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
               board[i][j] = ' ';
               noOfMoves = 0;
            }
        }
        row = rand() % 3;
        col = rand() % 3;
    }
    TicTacToe(const TicTacToe& cboard){
        for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[row][col] = cboard.board[row][col];
            noOfMoves = cboard.noOfMoves;
    }
    
char getGrid(int i, int j){
        return board[i][j];
    }

bool isFull(){
        return (noOfMoves >= 81);
    }
    
bool isValidMove(int r, int c){
    if (r < 0 || r > 2)
    {
        cout << "That is an illegal move! stop trying to cheat!" << endl;
        return false;
    }
    if (c < 0 || c > 2)
    {
        cout << "That is an illegal move! stop trying to cheat!" << endl;
        return false;
    }
    if(getGrid(r, c) == 'X' || getGrid(r, c) == 'O' )
    {
        cout << "That space is not empty try another move!" << endl;
        return false;
    }

    return true;
}
    
void displayBoard() const{
    cout << "   1    2   3" << endl << endl;
    for (int row = 0; row < 3; row++){
        cout << row + 1;
        for (int col = 0; col < 3; col++){
            cout << setw(3) << board[row][col];
            
            if (col != 2)
                cout << " |";
        }
        
        cout << endl;
        
        if (row != 2)
            cout << " ____|____|____" << endl << "     |    |    " << endl;
    }
    
    cout << endl;
}
    
void getXMove(char player, int& r, int& c){
    do {
        r = rand() % 3;
        c = rand() % 3;
    } while (!isValidMove(r, c));
    
    cout << "Player " << player << "'s move: " << "(" << (r + 1) << ", " << (c + 1) << ")" << endl;
}

void getOMove(char player, int& r, int& c){
        do {
            std::cout << "Player " << 'O' << " enter move: ";
            std::cin >> r >> c;
            std::cout << std::endl;
        } while (!isValidMove(r - 1, c - 1));
        r--;
        c--;
    cout << "Player " << 'O' << "'s move: " << "(" << (r + 1) << ", " << (c + 1) << ")" << endl;
    }

bool addMove(char player,int r, int c){
    
    board[r][c] = player;
    noOfMoves++;
    status gStatus = gameStatus();
    
    if (gStatus == WIN) {
        cout << "Player " << player << " wins!" << endl;
        return true;
    }
    else if (gStatus == DRAW) {
        cout << "This game is a draw!" << endl;
        return true;
    }
    else if (noOfMoves >= 81) {
        return true;
    }
    else
        return false;
}
    
status gameStatus(){
        //checking first row
                          if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
                          {
                              return WIN;
                          }
                          if (board[0][0] == 'O' && board[0][1] == 'O' & board[0][2] == 'O')
                          {
                              return WIN;
                          }
                          //checking second row
                          if (board[1][0] == 'X' && board[1][1] == 'X' & board[1][2] == 'X')
                          {
                              return WIN;
                          }
                          if (board[1][0] == 'O' && board[1][1] == 'O' & board[1][2] == 'O')
                          {
                              return WIN;
                          }
                          //checking third row
                          if (board[2][0] == 'X' && board[2][1] == 'X' & board[2][2] == 'X')
                          {
                              return WIN;
                          }
                          if (board[2][0] == 'O' && board[2][1] == 'O' & board[2][2] == 'O')
                          {
                              return WIN;
                          }

                          //checking first colum
                          if (board[2][0] == 'X' && board[1][0] == 'X' & board[2][0] == 'X')
                          {
                              return WIN;
                          }
                          if (board[2][0] == 'O' && board[1][0] == 'O' & board[2][0] == 'O')
                          {
                              return WIN;
                          }
                          //checking second colum
                          if (board[0][1] == 'X' && board[1][1] == 'X' & board[2][1] == 'X')
                          {
                              return WIN;
                          }
                          if (board[0][1] == 'O' && board[1][1] == 'O' & board[2][1] == 'O')
                          {
                              return WIN;
                              //checking third colum
                          }if (board[0][2] == 'X' && board[1][2] == 'X' & board[2][2] == 'X')
                          {
                              return WIN;
                          }
                          if (board[0][2] == 'O' && board[1][2] == 'O' & board[2][2] == 'O')
                          {
                              return WIN;
                          }

                          //checking digonal 1
                          if (board[0][0] == 'X' && board[1][1] == 'X' & board[2][2] == 'X')
                          {
                              return WIN;
                          }
                          if (board[0][0] == 'O' && board[1][1] == 'O' & board[2][2] == 'O')
                          {
                              return WIN;
                          }
                          //checking digonal 2
                          if (board[0][2] == 'X' && board[1][1] == 'X' & board[2][0] == 'X')
                          {
                              return WIN;
                          }
                          if (board[0][2] == 'O' && board[1][1] == 'O' & board[2][0] == 'O')
                          {
                              return WIN;
                          }

                          //Checking DRAW
                          if (noOfMoves >= 81)
                          {
                              return DRAW;
                          }

                  return CONTINUE;
    }

void play(){
           bool done = false;
           displayBoard();
           
           while (!done) {
           int row;
           int col;
                    
           getXMove('X',row, col);
           done = addMove('X', row, col);
           displayBoard();
                if(done == true ) //stop loop
                break;
                    
                    
           getOMove('O',row, col);
           done = addMove('O',row, col);
           displayBoard();
                if(done == true )
                break;
               
    }
  }
};

#endif
