#include "Room.h"
#include <iterator>

Room::Room() {}

Room::Room(bool isExitVal,int indexVal,int floorVal,vector<Object *> vObj)
{
    isExit = isExitVal;
    index = indexVal;
    floor = floorVal;
    objects = vObj;
}

bool Room::popObject(Object *obj)
{
    int size = objects.size();
    for (int i = 0; i < size; i++) 
    {
        if (objects[i] == obj) 
        {
            objects.erase(objects.begin()+i);
            delete obj;
            //after erasing
            //if there are still other objects, pass true
            if (objects.size() != 0) return true;
        } 
    }
    return false;
}

// setter
void Room::setUpRoom(Room *upRoomVal)
{
    upRoom = upRoomVal;
}

void Room::setDownRoom(Room *downRoomVal)
{
    downRoom = downRoomVal;
}

void Room::setLeftRoom(Room *leftRoomVal) 
{
    leftRoom = leftRoomVal;
}

void Room::setRightRoom(Room *rightRoomVal)
{
    rightRoom = rightRoomVal;
}

void Room::setUpStairs(Room *upStairsVal)
{
    upStairs = upStairsVal;
}

void Room::setDownStairs(Room *downStairsVal)
{
    downStairs = downStairsVal;
}

void Room::setIndex(int indexVal)
{
    index = indexVal;
}

void Room::setFloor(int floorVal)
{
    floor = floorVal;
}

void Room::setIsExit(bool isExitVal)
{
    isExit = isExitVal;
}

void Room::setObjects(vector<Object *> vObj)
{
    objects = vObj;
}

//getter
Room *Room::getUpRoom()
{
    return upRoom;
}

Room *Room::getDownRoom()
{
    return downRoom;
}

Room *Room::getLeftRoom()
{
    return leftRoom;
}

Room *Room::getRightRoom()
{
    return rightRoom;
}

Room *Room::getUpStairs()
{
    return upStairs;
}

Room *Room::getDownStairs()
{
    return downStairs;
}

int Room::getIndex()
{
    return index;
}

int Room::getFloor()
{
    return floor;
}

bool Room::getIsExit()
{
    return isExit;
}

vector<Object *> Room::getObjects()
{
    return objects;
}

void Room::printRoomName()
{
    int fl = index / 10;
    int no = index % 10;
    cout<< "\nYou are at [Floor " << fl 
        << ": Room " << no << "]\n";
}

void Room::setRoom(Room *up, Room *down, Room *left, Room *right, Room *upStairsVal, Room *downStairsVal)
{
    upRoom = up;
    downRoom = down;
    leftRoom = left;
    rightRoom = right;
    upStairs = upStairsVal;
    downStairs = downStairsVal;
}

vector<Room*> Room::checkRoom()
{
    vector<Room*> validRoom;
    char c='a';

    if (upRoom != NULL) 
    {
        validRoom.push_back(upRoom);
        cout<< c << ". " 
            << "Up\n";
        ++c;
    }
    
    if (downRoom != NULL) 
    {
        validRoom.push_back(downRoom);
        cout<< c << ". " 
            << "Down\n";
        ++c;
    }

    if (leftRoom != NULL) 
    {
        validRoom.push_back(leftRoom);
        cout<< c << ". " 
            << "Left\n";
        ++c;
    }

    if (rightRoom != NULL) 
    {
        validRoom.push_back(rightRoom);
        cout<< c << ". " 
            << "Right\n";
        ++c;
    }

    if (upStairs != NULL) 
    {
        validRoom.push_back(upStairs);
        cout<< c << ". " 
            << "Go Up Stairs\n";
        ++c;
    }

    if (downStairs != NULL) 
    {
        validRoom.push_back(downStairs);
        cout<< c << ". " 
            << "Go Down Stairs\n";
        ++c;
    }
    
    return validRoom;
}
