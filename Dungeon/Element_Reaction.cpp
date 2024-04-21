#include "Element_Reaction.h"

Elemental_Reaction::Elemental_Reaction() {}

Elemental_Reaction::Elemental_Reaction(string elementVal,string script,double percent)
    : Object(elementVal,"Element")
{
    description = script;
    attackIncreasePerent = percent;
    isReact = false;
}

bool Elemental_Reaction::triggerEvent(Object *obj)
{
    return false;
}

void Elemental_Reaction::setDescription(string script)
{
    description = script;
}

void Elemental_Reaction::setIncreasePercent(double percent)
{
    attackIncreasePerent = percent;
}

void Elemental_Reaction::setIsReact(bool react)
{
    isReact = react;
}

string Elemental_Reaction::getDescription()
{
    return description;
}

double Elemental_Reaction::setIncreasePercent()
{
    return attackIncreasePerent;
}

bool Elemental_Reaction::getIsReact()
{
    return isReact;
}

void Elemental_Reaction::printReactInfo()
{
    cout<< "Note: \n" 
        << "- Fire counters Grass (Attack *1.5)\n"
        << "- Water counters Fire (Attack *1.5)\n"
        << "- Grass counters Water (Attack *1.5)\n\n";
}

bool Elemental_Reaction::checkReaction(string defend)
{
    if (this->getName() == "Fire" && defend == "Grass") return true;
    else if (this->getName() == "Water" && defend == "Fire") return true;
    else if (this->getName() == "Grass" && defend == "Water") return true;
    else return false;
}
