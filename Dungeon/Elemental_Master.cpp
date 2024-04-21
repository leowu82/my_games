#include "Elemental_Master.h"

Elemental_Master::Elemental_Master() {}

Elemental_Master::Elemental_Master(string nameVal,vector<Object*> items)
    : NPC(nameVal,items) {}

bool Elemental_Master::triggerEvent(Object *obj)
{
    Player *player = dynamic_cast<Player*>(obj);
    //print product
    int select = printNPC();
    if (select == -1) return false;

    Elemental_Reaction *element = dynamic_cast<Elemental_Reaction*>(getCommodity()[select]);

    //if no money
    if (player->getMoney() < 100) {
        cout<< "... You got no money! \nVanish! Human!\n";
        return false;
    }

    //if already learnt
    if (itemCount[select] == 0) {
        cout<< "You've already learnt this Element!\n";
        return false;
    }

    //buy product and add
    player->addElementSet(element);
    player->addMoney(-100);

    //deduct product
    itemCount[select] = 0;

    cout<< "You've mastered the powers of the element of " 
        << element->getName() << "!\n";
    
    return false;
}

int Elemental_Master::printNPC()
{
    string option;
    int size = this->getCommodity().size();
    while (1)
    {
        //print script
        //print product
        cout<< this->getScript();
        char c = 'a';
        int size = getCommodity().size();
        for (int i = 0; i < size; i++) 
        {
            if (1) {
                cout<< c++ << ". " << (getCommodity()[i])->getName() << ' '
                << dynamic_cast<Elemental_Reaction*>(getCommodity()[i])->getDescription() << endl; 
            }
        }
        cout<< c << ". Uh actually no thanks\n";
        
        cout<< "Option >";
        getline(cin,option);
        cout<< endl;
        if (option[0] == c) return -1;
        if (IsValidInput(option,0,(c-97))) break;
    }
    return (option[0]-97);
}

void Elemental_Master::setItemCount(vector<int> vec)
{
    itemCount = vec;
}

vector<int> Elemental_Master::getItemCount()
{
    return itemCount;
}

void Elemental_Master::setElementalMaster()
{
    this->setScript("\n----------------------------------------\n""Behold! ... \n"
    "Human! ... \nFear me! ... \n"
    "For I am the Lengendary Elemental Master... \n"
    "Kneel before me and give me some goodies... \n"
    "and perhaps I'll consider teaching you some basic spells... \n\n"
    "> Spend 100 coins learning one of the following Elements?: \n");

    Object *temp;
    vector<Object*> commodity;
    temp = new Elemental_Reaction("Fire","- Fire counters Grass (Attack *1.5)",1.5);
    commodity.push_back(temp);
    itemCount.push_back(1);

    temp = new Elemental_Reaction("Water","- Water counters Fire (Attack *1.5)",1.5);
    commodity.push_back(temp);
    itemCount.push_back(1);

    temp = new Elemental_Reaction("Grass","- Grass counters Water (Attack *1.5)",1.5);
    commodity.push_back(temp);
    itemCount.push_back(1);

    this->setCommodity(commodity);

}
