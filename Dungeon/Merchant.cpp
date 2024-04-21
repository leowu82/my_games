#include "Merchant.h"

Merchant::Merchant() {}

Merchant::Merchant(string nameVal, vector<Object*> items)
    : NPC(nameVal,items) {}

bool Merchant::triggerEvent(Object *obj)
{
    Player *player = dynamic_cast<Player*>(obj);
    //print product
    int select = printNPC();
    if (select == -1) return false;

    //if no money
    if(player->getMoney() < (dynamic_cast<Item*>(getCommodity()[select])->getPrice()))
    {
        cout<< "Whoopsie... \nIt seems like you don't have enough money :( ...\n";
        return false;
    }

    Item *item = dynamic_cast<Item*>(getCommodity()[select]);

    //if sold out
    if (itemCount[select] <= 0) {
        cout<< "Sorry! That product is currently out of stock! :( \n";
        return false;
    }

    //buy product and add
    player->addInventory(getCommodity()[select]);
    player->addMoney(-(item->getPrice()));

    //deduct product count
    itemCount[select] -= 1;

    cout<< "You've bought a(n) " << getCommodity()[select]->getName()
        << "!\n\n";
    cout<< "Thank you for your Purchase!\n";

    return false;
}

int Merchant::printNPC()
{
    string option;
    int size = this->getCommodity().size();
    while (1)
    {
        //print script
        cout<< this->getScript();
        //print product
        char c = 'a';
        for (int i = 0; i < size; i++)
        {
            Item *item = dynamic_cast<Item*>(getCommodity()[i]);

                if (1) {
                    cout<< c++ << ". " << item->getName() << endl
                        << "   " << item->getDescription() << endl
                        << "   - " << item->getPrice() << " coins"
                        << " (" << itemCount[i] << " left)" << endl;
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

void Merchant::setItemCount(vector<int> count)
{
    itemCount = count;
}

vector<int> Merchant::getItemCount()
{
    return itemCount;
}

void Merchant::setMerchant()
{
    this->setScript("\n----------------------------------------\n""Hello there, traveler :) ... \n"
    "Here are some goodies that may help you on your journey... \n");

    Object *temp;
    vector<Object*> commodity;
    temp = new Weapon("[Excalibur]","Weapon","{+800 ATK when equipped by Saber}",200,1,0,800,0);
    commodity.push_back(temp);
    itemCount.push_back(1);

    temp = new Weapon("['A Very Big Bow']","Weapon","{+1000 ATK when equipped by Archer}",200,1,0,1000,0);
    commodity.push_back(temp);
    itemCount.push_back(1);

    temp = new Weapon("[Calculus Textbook]","Weapon","{+700 ATK when equipped by Caster}",200,1,0,700,0);
    commodity.push_back(temp);
    itemCount.push_back(1);

    temp = new Weapon("[Mom's Slippers]","Weapon","{+600 ATK when equipped by Assassin}",200,1,0,600,0);
    commodity.push_back(temp);
    itemCount.push_back(1);

    temp = new Potion("[Health Potion]","Potion","{+300 HP}",50,1,0,300,0,0,0);
    commodity.push_back(temp);
    itemCount.push_back(5);

    temp = new Potion("[Banana]","Potion","{+200 Mana}",50,1,0,0,0,0,200);
    commodity.push_back(temp);
    itemCount.push_back(5);

    this->setCommodity(commodity);
}