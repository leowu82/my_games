#ifndef PETSHOP_H
#define PETSHOP_H

#include <iostream>
#include <vector>
#include <string>
#include "NPC.h"
#include "Potion.h"

class PetShop: public NPC
{
private:
    vector<int> itemCount;
public:
    PetShop();
    PetShop(string,vector<Object*>);

    virtual bool triggerEvent(Object*);
    virtual int printNPC();

    //initialize
    void setPetShop();
    
};




#endif // PETSHOP_H