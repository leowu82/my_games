#include "Snake.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <unistd.h>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

class Snake_Game
{
private:
    int row, col;
    char direction;
    int score;

public:
    Snake_Game();

    void initializeSetting(int i, int j);
    void handleMovement();
    void printBoard();
    void wait(double second);
    void run_Snake_Game();
    bool isGameOver();

    char getInput();
};
