#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "IsValidInput.h"
#include "Object.h"
#include "GameCharacter.h"
#include "Player.h"
#include "Skill.h"
using namespace std;

class Monster: public GameCharacter
{
private:

public:
    Monster();
    Monster(string,string,int,int,int);

    // Virtual function that you need to complete 
    // In Monster, this function should deal with the combat system.
    bool triggerEvent(Object*);

    //show monster status
    void showStatus();
};


#endif // ENEMY_H_INCLUDED
