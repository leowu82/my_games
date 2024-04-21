#include "PetShop.h"

PetShop::PetShop() {}

PetShop::PetShop(string nameVal,vector<Object*> items)
    : NPC(nameVal,items) {}

bool PetShop::triggerEvent(Object *obj)
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
        cout<< "Sorry! She's is currently out of stock! :( \n";
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

int PetShop::printNPC()
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
                cout<< c++ << ". "
                    << item->getName() << " --- " 
                    << item->getPrice() << " coins\n   "
                    << item->getDescription() << " ("
                    << item->getCount() << " left)\n";
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

void PetShop::setPetShop()
{
    this->setScript("\n----------------------------------------\n""Hi hi~ Care to buy these ADORABLE creatures? <3 \n");

    Object *temp;
    vector<Object*> commodity;

    temp = new Potion("<Pet> [Gras-saurus!]","Potion","{Attacks enemy along with you -> Deals 500 ATK per attack}",500,1,0,0,500,0,0);
    commodity.push_back(temp);
    itemCount.push_back(1);

    temp = new Potion("<Pet> [Monkey]","Potion","{Attacks enemy along with you -> Deals 500 ATK per attack}",500,1,0,0,500,0,0);
    commodity.push_back(temp);
    itemCount.push_back(1);

    temp = new Potion("<Pet> [Noisy Roommate]","Potion","{Attacks enemy along with you -> Deals 500 ATK per attack}",500,1,0,0,500,0,0);
    commodity.push_back(temp);
    itemCount.push_back(1);

    temp = new Potion("<Pet> [Red Squiggly Line]","Potion","{Attacks enemy along with you -> Deals 500 ATK per attack}",500,1,0,0,500,0,0);
    commodity.push_back(temp);
    itemCount.push_back(1);

    this->setCommodity(commodity);
}
