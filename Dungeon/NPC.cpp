#include "NPC.h"

NPC::NPC() {}

NPC::NPC(string nameVal,vector<Object*> items)
    : Object(nameVal,"NPC") 
{
    commodity = items;
}

void NPC::listCommodity()
{
    char c = 'a';
    for (vector<Object*>::iterator it = commodity.begin(); it != commodity.end(); ++it) 
    {
        cout<< c++ << ". " << (*it)->getName() << ' '
        << dynamic_cast<Item*>(*it)->getDescription() << endl; 
    }
}

void NPC::setScript(string talk)
{
    script = talk;
}

void NPC::setCommodity(vector<Object*> items)
{
    commodity = items;
}

string NPC::getScript()
{
    return script;
}

vector<Object*> NPC::getCommodity()
{
    return commodity;
}

