#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "IsValidInput.h"
#include "Player.h"
#include "Monster.h"
#include "Chest.h"
#include "Room.h"
#include "Elemental_Master.h"
#include "Merchant.h"
#include "Gambler.h"
#include "PetShop.h"

using namespace std;

class Dungeon{
private:
    Player player;
    vector<Room> rooms;
public:
    Dungeon();

    void createPlayer();

    void createMap();

    void handleMovement();

    void handleRetreat();

    void handleEvent(Object*);

    void chooseAction(vector<Object*>);

    bool checkGameLogic();

    void startGame();

    void runDungeon();

    // void mapFloor1();
    // void mapFloor2();
    // void mapFloor3();
};


#endif // DUNGEON_H_INCLUDED
