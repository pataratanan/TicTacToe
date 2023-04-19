#ifndef HumanPlayer_h
#define HumanPlayer_h
#include "TicTacToe.h"
#include <iostream>

using namespace std;

class HumanPlayer : public Player{
public:
    void getXOMove(TicTacToe board, int &r, int &c) override{        
            do {
                cout << "Player " << 'O' << " enter move: ";
                cin >> r >> c;
                cout << std::endl;
            } while (!board.isValidMove(r - 1, c - 1));
            r--;
            c--;
        return;
    }
};

#endif
