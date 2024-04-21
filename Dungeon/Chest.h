#ifndef CHEST_H_INCLUDED
#define CHEST_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "Item.h"
#include "Potion.h"
#include "Weapon.h"
using namespace std;

class Chest: public Item
{
private:
    int rewardMoney;
    vector<Object*> chest;
public:
    Chest();
    Chest(string,string);
    Chest(string,string,string,int,int);

    // Virtual function that you need to complete
    // In Item, this function should deal with the pick up action. You should add status to the player.
    bool triggerEvent(Object*);

    //print chest content
    void printChest();

    //setter
    void setRewardMoney(int);
    void setChest(vector<Object*>);

    //getter
    int getRewardMoney();
    vector<Object*> getChest();

    //Types of chest
    void setNormalChest();
    void setDeluxeChest();
    void setAlotChest();

    void addChestItem(Object*);
};

#endif // CHEST_H_INCLUDED