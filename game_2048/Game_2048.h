#include <iostream>
#include "Board.h"

using namespace std;

class Game_2048 
{
private:
    Board board;
    int score, power;

public:
    Game_2048() {}

    void initializeSetting(int i, int j);
    void handleMovement();
    void printBoard();

    bool isGameOver(int max);
    void run_2048();

    char getInput();
};