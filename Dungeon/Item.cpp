#include "Item.h"

Item::Item(): Object() {}

Item::Item(string nameVal,string tagVal,string script,int priceVal,int countVal)
    : Object(nameVal, tagVal) 
{
    description = script;
    price = priceVal;
    count = countVal;
}

void Item::addCount(int num)
{
    count = count + num;
}

//setter
void Item::setDescription(string script)
{
    description = script;
}

void Item::setPrice(int priceVal)
{
    price = priceVal;
}

void Item::setCount(int countVal)
{
    count = countVal;
}

//getter
string Item::getDescription()
{
    return description;
}

int Item::getPrice()
{
    return price;
}

int Item::getCount()
{
    return count;
}
