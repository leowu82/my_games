#ifndef MERCHANT_H
#define MERCHANT_H

#include <iostream>
#include <vector>
#include <string>
#include "IsValidInput.h"
#include "NPC.h"
#include "Weapon.h"
#include "Potion.h"

class Merchant: public NPC
{
private:
    vector<int> itemCount;
public:
    Merchant();
    Merchant(string,vector<Object*>);

    virtual bool triggerEvent(Object*);
    //print product; include price/items left
    virtual int printNPC();

    //setter
    void setItemCount(vector<int>);

    //getter
    vector<int> getItemCount();
    
    //initialize
    void setMerchant();
};




#endif // MERCHANT_H