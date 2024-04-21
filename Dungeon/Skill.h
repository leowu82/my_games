#ifndef SKILL_H_INCLUDED
#define SKILL_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "Object.h"
#include "Player.h"
#include "Monster.h"
using namespace std;

class Skill: public Object
{
private:
    string description;
    int manaCost;
    int skillAttack;
    double atkPercent;
    double intakeDamagePercent;
    bool isFreeTurn;
    bool isCurAvailable;
    bool isUnlocked;
public:
    Skill(); 
    Skill(string); //tag only
    Skill(string,string,string,int,int,double,bool,bool);

    // Virtual function that you need to complete
    // In Item, this function should deal with the pick up action. You should add status to the player.
    bool triggerEvent(Object*);

    //setter
    void setDescription(string);
    void setManaCost(int);
    void setSkillAttack(int);
    void setAtkPercent(double);
    void setIntakeDamagePercent(double);
    void setIsFreeTurn(bool);
    void setCurAvailable(bool);
    void setIsUnlocked(bool);

    //getter
    string getDescription();
    int getManaCost();
    int getSkillAttack();
    double getAtkPercent();
    double getIntakeDamagePercent();
    bool getIsFreeTurn();
    bool getCurAvailable();
    bool getIsUnlocked();

    //Initialize basic skills
    void setSaberSkill();
    void setArcherSkill();
    void setCasterSkill();
    void setAssassinSkill();

    //Ult skill
    void setSaberUlt();
    void setArcherUlt();
    void setCasterUlt();
    void setAssassinUlt();

};


#endif // SKILL_H_INCLUDED