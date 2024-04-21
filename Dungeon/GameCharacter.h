#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

//including Player, Monster
//this is an abstract class
class GameCharacter: public Object
{
private:
    string element;
    int maxHealth;
    int currentHealth;
    int attack;
    int curAttack;
    int defense;
    double damageReduction;
public:
    GameCharacter();
    GameCharacter(string,string,string,int,int,int);
    bool checkIsDead();
    int takeDamage(int,double);

    virtual bool triggerEvent(Object*) = 0;

    /* Set & Get function*/
    void setElement(string);
    void setMaxHealth(int);
    void setCurrentHealth(int);
    void setAttack(int);
    void setCurAttack(int);
    void setDefense(int);
    void setDamageReduction(double);

    string getElement();
    int getMaxHealth();
    int getCurrentHealth();
    int getAttack();
    int getCurAttack();
    int getDefense();
    double getDamageReduction();

    //modify curAttack (skillAttack,atkPercent)
    void modifyCurAttack(int,double);
};
#endif // GAMECHARACTER_H_INCLUDED
