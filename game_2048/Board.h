#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class Board 
{
private:
    vector<vector<int> > board;
    int row, col;
    bool isMovable;
    int highest, fillCount;
    bool isGameOver;
    
public:
    Board() {}
    Board(int i, int j);

    void addRandom(int power);

    void printBoard();

    // 0/1/2/3 -> U/D/L/R
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void merge_Up(int i, int j, vector<bool> &isMerged);
    void merge_Down(int i, int j, vector<bool> &isMerged);
    void merge_Left(int i, int j, vector<bool> &isMerged);
    void merge_Right(int i, int j, vector<bool> &isMerged);

    void setMovable(bool state);
    bool getMovable();
    bool checkMovable();

    void setHighest(int val);
    void setFillCount(int val);
    void setIsGameOver(bool state);
    
    int getHighest();
    int getFillCount();
    bool getIsGameOver();
};