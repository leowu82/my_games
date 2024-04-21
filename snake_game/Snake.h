#include <iostream>

using namespace std;

class Snake 
{
private:
    int length;
    string body_part;
    pair<short,short> headPos, tailPos, prevPos;

public:
    Snake();
    Snake(int len, string part);

    void setLength(int len);
    void setBodyPart(string part);

    int getLength();
    string getBodyPart();

    void updateLength(int increment);

    bool isHitWall(int row, int col);

};