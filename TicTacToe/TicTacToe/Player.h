#ifndef Player_h
#define Player_h

#include "TicTacToe.h"
#include "NineBoard.h"
class Player{
public:
    virtual void getXOMove(TicTacToe board, int &r, int &c) = 0;
};

#endif

