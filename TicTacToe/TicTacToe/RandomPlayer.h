#ifndef RandomPlayer_h
#define RandomPlayer_h
#include "TicTacToe.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>

using namespace std;

class RandomPlayer : public Player{
public:
    void getXOMove(TicTacToe board, int &r, int &c) override{
        do {
            r = rand() % 3;
            c = rand() % 3;
        } while (!board.isValidMove(r, c));
        return;
    }
};

#endif
