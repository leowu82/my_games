#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Player.h"
using namespace std;

class Item: public Object
{
private:
    string description;
    int price;
    int count;
public:
    Item();
    Item(string,string,string,int,int);
    void addCount(int);

    virtual bool triggerEvent(Object*) = 0;

    //setter and getter
    void setDescription(string);
    void setPrice(int);
    void setCount(int);
    
    string getDescription();
    int getPrice();
    int getCount();

};

#endif // ITEM_H_INCLUDED
