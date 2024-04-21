#include "Board.h"

Board::Board(int i, int j)
{
    row = i, col = j;
    board.resize(i,vector<int>(j,0));
    isMovable = true;
    highest = 0;
    fillCount = 0;
    isGameOver = false;
}

void Board::addRandom(int power)
{
    if (!checkMovable()) return;
    //randomly generate 2 or 4
    srand(time(0));
    int num = pow(2,(rand()%power + 1));

    //randomly generate coordinate i and j
    int i, j;
    while (board[i = rand()%4][j = rand()%4] != 0);

    board[i][j] = num;
    fillCount++;
}

void Board::printBoard()
{
    //upper boundary
    cout<< "   #===";
    for (int i=0; i<col; i++) {
        cout<< "=====";
    }
    cout<< "=#\n";

    //board
    for (int i=0; i<row; i++) {
        cout<< "   ||  ";
        for (int j=0; j<col; j++) {
            cout<< board[i][j];
            // if (j == col-1) break;
            if (board[i][j] < 10) {
                cout<< "    "; //4 space
            }
            else if (board[i][j] < 100) {
                cout<< "   "; //3 space
            }
            else if (board[i][j] < 1000) {
                cout<< "  "; //2 space
            }
            else {
                cout<< " "; //1 space
            }
        }
        cout<< "||\n";
    }

    //lower boundary
    cout<< "   #===";
    for (int i=0; i<col; i++) {
        cout<< "=====";
    }
    cout<< "=#\n";
}

void Board::moveUp()
{
    for (int j=0; j<col; j++) {
        vector<bool> isMerged(row,0);
        for (int i=1; i<row; i++) {
            if (board[i][j]) {
                merge_Up(i,j,isMerged);
            }
        }
    }
}

void Board::moveDown()
{
    for (int j=0; j<col; j++) {
        vector<bool> isMerged(row,0);
        for (int i=row-2; i>=0; i--) {
            if (board[i][j]) {
                merge_Down(i,j,isMerged);
            }
        }
    }
}

void Board::moveLeft()
{
    for (int i=0; i<row; i++) {
        vector<bool> isMerged(col,0);
        for (int j=1; j<col; j++) {
            if (board[i][j]) {
                merge_Left(i,j,isMerged);
            }
        }
    }
}

void Board::moveRight()
{
    for (int i=0; i<row; i++) {
        vector<bool> isMerged(col,0);
        for (int j=col-2; j>=0; j--) {
            if (board[i][j]) {
                merge_Right(i,j,isMerged);
            }
        }
    }
}

void Board::merge_Up(int i, int j, vector<bool> &isMerged)
{
    for (int cur = i-1; cur >= 0; cur--) {
        if (board[cur][j] == 0) {
            board[cur][j] = board[cur+1][j];
            board[cur+1][j] = 0;
            isMovable = true;
        }
    
        else if (board[cur][j] == board[cur+1][j] && !isMerged[cur]) {
            board[cur][j] *= 2;
            board[cur+1][j] = 0;
            isMerged[cur] = true;
            fillCount--;
            isMovable = true;
            return;
        }

        else return;
    }
}

void Board::merge_Down(int i, int j, vector<bool> &isMerged)
{
    for (int cur = i+1; cur < row; cur++) {
        if (board[cur][j] == 0) {
            board[cur][j] = board[cur-1][j];
            board[cur-1][j] = 0;
            isMovable = true;
        }
        
        else if (board[cur][j] == board[cur-1][j] && !isMerged[cur]) {
            board[cur][j] *= 2;
            board[cur-1][j] = 0;
            isMerged[cur] = true;
            fillCount--;
            isMovable = true;
            return;
        }

        else return;
    }
}

void Board::merge_Left(int i, int j, vector<bool> &isMerged)
{
    for (int cur = j-1; cur >= 0; cur--) {
        if (board[i][cur] == 0) {
            board[i][cur] = board[i][cur+1];
            board[i][cur+1] = 0;
            isMovable = true;
        }

        else if (board[i][cur] == board[i][cur+1] && !isMerged[cur]) {
            board[i][cur] *= 2;
            board[i][cur+1] = 0;
            isMerged[cur] = true;
            fillCount--;
            isMovable = true;
            return;
        }

        else return;
    }
}

void Board::merge_Right(int i, int j, vector<bool> &isMerged)
{
    for (int cur = j+1; cur < col; cur++) {
        if (board[i][cur] == 0) {
            board[i][cur] = board[i][cur-1];
            board[i][cur-1] = 0;
            isMovable = true;
        }

        else if (board[i][cur] == board[i][cur-1] && !isMerged[cur]) {
            board[i][cur] *= 2;
            board[i][cur-1] = 0;
            isMerged[cur] = true;
            fillCount--;
            isMovable = true;
            return;
        }

        else return;
    }
}

void Board::setMovable(bool state)
{
    isMovable = state;
}

bool Board::getMovable()
{
    return isMovable;
}

bool Board::checkMovable()
{
    if (!isMovable) {
        isMovable = true;
        return false;
    }
    return true;
}

void Board::setHighest(int val)
{
    highest = val;
}

void Board::setFillCount(int val)
{
    fillCount = val;
}

void Board::setIsGameOver(bool state)
{
    isGameOver = state;
}

int Board::getHighest()
{
    return highest;
}

int Board::getFillCount()
{
    return fillCount;
}

bool Board::getIsGameOver()
{
    if (fillCount >= row*col) isGameOver = true;
    return isGameOver;
}
