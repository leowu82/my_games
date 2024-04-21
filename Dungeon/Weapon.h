#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "Item.h"
using namespace std;

class Weapon: public Item 
{
private:
    int weaponHealth; 
    int weaponAttack;
    int weaponDefense;
public:
    Weapon(); 
    Weapon(string,string,string,int,int,int,int,int);

    // Virtual function that you need to complete
    // In Item, this function should deal with the pick up action. You should add status to the player.
    bool triggerEvent(Object*);

    //check weapon effect
    bool hasEffect(Player*);

    //setter
    void setWeaponHealth(int);
    void setWeaponAttack(int);
    void setWeaponDefense(int);

    //getter
    int getWeaponHealth();
    int getWeaponAttack();
    int getWeaponDefense();

};


#endif // WEAPON_H_INCLUDED