#include "Game_2048.h"

void Game_2048::initializeSetting(int i, int j)
{
    board = Board(i,j);
    score = 0, power = 2;
    board.addRandom(power);
}

void Game_2048::handleMovement()
{
    char command = getInput();
    board.setMovable(false);

    switch(command) 
    {
        case('w'):
            board.moveUp();
            break;
        case('s'):
            board.moveDown();
            break;
        case('a'):
            board.moveLeft();
            break;
        default: 
            board.moveRight();
            break;
    }
}

void Game_2048::printBoard()
{
    board.printBoard();
}

bool Game_2048::isGameOver(int max)
{
    if (board.getHighest() >= max) {
        printBoard();
        cout<< "Congratulations You Won!\n";
        return true;
    } 

    if (board.getIsGameOver()) {
        printBoard();
        cout<< "Oh No... You Lost!\n";
        return true;
    }

    return false;
}

void Game_2048::run_2048()
{
    cout<< "\nWelcome to the 2048 game! \nControls: w(up), s(down), a(left), d(right) \n...\n";
    
    initializeSetting(4,4);

    while(!isGameOver(2048)) {
        board.addRandom(power);
        printBoard();
        handleMovement();
    }
}

char Game_2048::getInput()
{
    string input;
    while(1) {
        cout<< "Input >";
        cin>> input;
        if (input == "w" || input == "s" || input == "d" || input == "a") {
            break;
        }
        cout<< "Invalid input\n";
    }
    cout<< endl;
    return input[0];
}