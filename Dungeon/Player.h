#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "IsValidInput.h"
#include "GameCharacter.h"
#include "Room.h"
#include "Skill.h"
#include "Item.h"
#include "Element_Reaction.h"
using namespace std;

class Item;
class Skill;

class Player: public GameCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    vector<Object*> inventory;
    vector<Skill*> skillSet;
    vector<Elemental_Reaction*> elementSet; 
    string occupation;
    int money, mana;
public:
    Player();
    Player(string,string,int,int,int,int);
    void increaseStates(int,int,int,int,int,int);
    void changeRoom(Room*);

    //Virtual function that you need to complete
    //In Player, this function should show the status of player
    bool triggerEvent(Object*);

    //Show status
    void showStatus();

    //setter
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setInventory(vector<Object*>);
    void setSkillSet(vector<Skill*>);
    void setElementSet(vector<Elemental_Reaction*>);
    void setOccupation(string);
    void setMoney(int);
    void addMoney(int);
    void setMana(int);
    void addMana(int);

    //getter
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    vector<Object*> getInventory();
    vector<Skill*> getSkillSet();
    vector<Elemental_Reaction*> getElementSet();
    string getOccupation();
    int getMoney();
    int getMana();

    //Show/Use Inventory
    void addInventory(Object*);
    int showInventory();
    void useInventory();

    //Occupations and their skills
    void initializeSkills();
    void addSkills(Skill*);
    void showSkills();

    //show/use Element
    void addElementSet(Elemental_Reaction*);
    void showElementSet();
    Elemental_Reaction* useElementSet();
    
    
};

#endif // PLAYER_H_INCLUDED
