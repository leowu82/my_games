#ifndef GAMBLER_H_INCLUDED
#define GAMBLER_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include "NPC.h"
#include "Potion.h"

class Gambler: public NPC
{
private:
    vector<int> tempInt;
public:
    Gambler();
    Gambler(string,vector<Object*>);

    virtual bool triggerEvent(Object*);
    virtual int printNPC();

    //initialize
    void setGambler();
    
};




#endif // GAMBLER_H_INCLUDED