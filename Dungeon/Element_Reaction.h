#ifndef ELEMENTAL_REACTION_H
#define ELEMENTAL_REACTION_H

#include <iostream>
#include <vector>
#include <string>
#include "Object.h"

class Elemental_Reaction: public Object
{
private:
    string description;
    double attackIncreasePerent;
    bool isReact;
public:
    Elemental_Reaction();
    Elemental_Reaction(string,string,double);

    bool triggerEvent(Object*);

    //setter
    void setDescription(string);
    void setIncreasePercent(double);
    void setIsReact(bool);

    //getter
    string getDescription();
    double setIncreasePercent();
    bool getIsReact();

    //print reaction info
    void printReactInfo();

    //check reaction
    bool checkReaction(string);
};




#endif // ELEMENTAL_REACTION_H