#ifndef NineBoard_h
#define NineBoard_h

#include <iostream>
#include "TicTacToe.h"
#include "BoardCoordinate.h"

using namespace std;

class NineBoard{
    public:
        NineBoard();
        void play();
        void displayBoards();
        
        TicTacToe* getTicTacToe(int i, int j) const{
            return grid[i][j];
        }
        TicTacToe* getFocusBoard() const{
            return grid[focus.row][focus.col];
        }
        void setFocus(int x, int y){
            focus.row = x;
            focus.col = y;
        }
        void resetFocus();
        BoardCoordinate getFocus(){
            return focus;
        }
        bool isDrawGame();
        char addMove(char playerSymbol, int x, int y);
private:
    TicTacToe* grid[3][3];
    BoardCoordinate focus;
};

NineBoard::NineBoard(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            grid[i][j] = new TicTacToe;
        }
    }
    focus.row = rand() % 3;
    focus.col = rand() % 3;
}


bool NineBoard::isDrawGame(){
    for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
        if(!grid[3][3]->isFull())
            return false;
    }
}
    return true;
}

void NineBoard::resetFocus(){
     for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(!grid[3][3]->isFull()){
                setFocus(i, j);
            }
        }
    }
}

char NineBoard::addMove(char playerSymbol, int x, int y){
    grid[focus.row][focus.col]->addMove(playerSymbol, x, y);
    char gStatus = grid[focus.row][focus.col]->gameStatus();
    
    if (gStatus == 'C')
        setFocus(x, y);
    
    if (gStatus == 'D' && !isDrawGame()){
        gStatus = 'C';
    }
    
    return gStatus;
}


void NineBoard::displayBoards() {
    
    cout << endl;
    cout << " ";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == focus.row && j == focus.col)
                cout << "  * * * * *  ";
            else
                cout << "  - - - - -  ";
        }
        cout << endl;
        for(int row = 0; row < 3; row++){
            for(int j = 0; j < 3; j++){
                for(int col = 0; col < 3; col++){
                    if(i == focus.row && j == focus.col && col == 0)
                        cout << "* " << grid[i][j]->getGrid(row, col) << " ";
                    else
                        cout << "| " << grid[i][j]->getGrid(row, col) << " ";
                    
                    if(col == 2){
                        if(i == focus.row && j == focus.col)
                            cout << "*";
                        else
                            cout << "|";
                    }
                }
            }
        cout << endl;
        if(row != 2)
        for(int j = 0; j < 3; j++){
                if(i == focus.row && j == focus.col)
                    cout << "* -   -   - *";
                else
                    cout << "| -   -   - |";
            }
            cout << endl;
    }
        for(int j = 0; j < 3; j++){
            if(i == focus.row && j == focus.col)
                cout << "  * * * * *  ";
            else
                cout << "  - - - - -  ";
        }
            cout << endl;
    }
}

void NineBoard::play(){
    
         bool done = false;
         while (!done) {
         NineBoard::isDrawGame();
             
             int  row;
             int  col;
             NineBoard::displayBoards();
             
         getFocusBoard()->getXMove('X',row, col);
         done = getFocusBoard()->addMove('X', row, col);
             
             focus.row = rand() % 3;
             focus.col = rand() % 3;
             
         NineBoard::displayBoards();
             
              if(done == true ) //stop loop
              break;
                                    
         getFocusBoard()->getOMove('O',row, col);
         done = getFocusBoard()->addMove('O',row, col);
             
             focus.row = rand() % 3;
             focus.col = rand() % 3;
             
         NineBoard::displayBoards();
             
              if(done == true )
              break;
             
  }
}
#endif
