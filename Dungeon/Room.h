#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "Object.h"

using namespace std;

class Room
{
private:
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    Room* upStairs;
    Room* downStairs;
    int index;
    int floor;

    bool isExit;
    
    vector<Object*> objects; //contain 1 or multiple objects, including monster, npc, etc
public:
    Room();
    //isExit, index, floor, objects
    Room(bool,int,int,vector<Object*>);
    bool popObject(Object*); //pop out the specific object, used when the interaction is done

    //setter
    void setUpRoom(Room*);
    void setDownRoom(Room*);
    void setLeftRoom(Room*);
    void setRightRoom(Room*);
    void setUpStairs(Room*);
    void setDownStairs(Room*);
    void setIndex(int);
    void setFloor(int);
    void setIsExit(bool);
    void setObjects(vector<Object*>);
    
    //getter
    Room* getUpRoom();
    Room* getDownRoom();
    Room* getLeftRoom();
    Room* getRightRoom();
    Room* getUpStairs();
    Room* getDownStairs();
    int getIndex();
    int getFloor();
    bool getIsExit();
    vector<Object*> getObjects();

    //get room name 
    void printRoomName();

    //set all roooms function
    void setRoom(Room*,Room*,Room*,Room*,Room*,Room*);

    //check room available 
    vector<Room*> checkRoom();


};

#endif // ROOM_H_INCLUDED
