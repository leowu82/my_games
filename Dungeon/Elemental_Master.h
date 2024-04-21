#ifndef ELEMENTAL_MASTER_H
#define ELEMENTAL_MASTER_H

#include <iostream>
#include <vector>
#include <string>
#include "NPC.h"
#include "Element_Reaction.h"

class Elemental_Master: public NPC
{
private:
    vector<int> itemCount;
public:
    Elemental_Master();
    Elemental_Master(string,vector<Object*>);

    virtual bool triggerEvent(Object*);
    virtual int printNPC();

    //setter
    void setItemCount(vector<int>);

    //getter
    vector<int> getItemCount();
    
    //initialize 
    void setElementalMaster();
};




#endif // ELEMENTAL_MASTER_H