#ifndef POTION_H_INCLUDED
#define POTION_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "Item.h"
using namespace std;

class Potion: public Item 
{
private:
    int potionMaxHp, potionHp, potionAtk, potionDef, potionMana;
public:
    Potion(); 
    Potion(string,string,string,int,int,int,int,int,int,int);

    // Virtual function that you need to complete 
    // In Item, this function should deal with the pick up action. You should add status to the player.
    bool triggerEvent(Object*);

    //setter
    void setPotionMaxHp(int);
    void setPotionHp(int);
    void setPotionAtk(int);
    void setPotionDef(int);
    void setPotionMana(int);

    //getter
    int getPotionMaxHp();
    int getPotionHp();
    int getPotionAtk();
    int getPotionDef();
    int getPotionMana();

};


#endif // POTION_H_INCLUDED