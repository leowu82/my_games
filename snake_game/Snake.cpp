#include "Snake.h"

Snake::Snake() {}

Snake::Snake(int len, string part)
{
    length = len;
    body_part = part;
}

void Snake::setLength(int len)
{
    length = len;
}

void Snake::setBodyPart(string part)
{
    body_part = part;
}

int Snake::getLength()
{
    return length;
}

string Snake::getBodyPart()
{
    return body_part;
}

void Snake::updateLength(int increment)
{
    length += increment;
}

bool Snake::isHitWall(int row, int col)
{
    if (headPos.first < 0 || headPos.first >= row || headPos.second < 0 || headPos.second >= col) {
        return true;
    }
    return false;
}
