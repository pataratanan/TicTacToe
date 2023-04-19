/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from any other student’s work or from any other source. No part of the code has been written/produced for me by another person or copied from any other source.
  
I hold a copy of this assignment that I can produce if the original is lost or damaged.
**************************/
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "NineBoard.h"
#include "TicTacToe.h"
#include "NBGame.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "Player.h"

using namespace std;

int main() {
    srand((unsigned int)time(nullptr));
    
    //RandomPlayer* Xplayer = new RandomPlayer;
    //HumanPlayer* Oplayer = new HumanPlayer;
    
    //NBGame G1(Xplayer, Xplayer);
    //NBGame G2(Xplayer, Oplayer);
    //NBGame G3(Oplayer, Oplayer);
    
    //G1.play();
    //G2.play();
    //G2.play();
    
    NineBoard N;
    N.play();
    
    return 0;
}
