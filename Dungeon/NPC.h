#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "Object.h"
#include "Player.h"
#include "Item.h"
using namespace std;

class NPC: public Object
{
private:
    string script;
    int itemCount;
    vector<Object*> commodity;
public:
    NPC();
    NPC(string,vector<Object*>);
    void listCommodity(); //print all the Items in this NPC

    // Virtual function that you need to complete
    // In NPC, this function should deal with the transaction in easy implementation
    virtual bool triggerEvent(Object*) = 0;
    virtual int printNPC() = 0;

    //setter
    void setScript(string);
    void setCommodity(vector<Object*>);

    // getter
    string getScript();
    vector<Object*> getCommodity();
    
};


#endif // NPC_H_INCLUDED
