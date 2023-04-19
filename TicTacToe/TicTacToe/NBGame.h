#ifndef NBGame_h
#define NBGame_h

#include <iostream>
#include <vector>
#include "TicTacToe.h"
#include "NineBoard.h"
#include "Player.h"
#include "BoardCoordinate.h"

using namespace std;

class NBGame{
     NineBoard* board;
     Player* player[2];
     TicTacToe ttt;
public:
    NBGame(Player* p1, Player* p2){
        player[0] = p1;
        player[1] = p2;
    }
    void play(){
        bool done = false;
        board->displayBoards();
        char playerSymbol = 'X';
        while (!done) {
                int r;
                int c;
            //player[0]->getXOMove(board,r,c);
            done = ttt.addMove(playerSymbol,r, c);
            board->displayBoards();
                    if(done == true ) //stop loop
                        break;
            
            //player[1]->getXOMove(board, r, c);
            done = ttt.addMove(playerSymbol,r, c);
            board->displayBoards();
                    if(done == true )
                        break;
           }
    };
};


#endif
