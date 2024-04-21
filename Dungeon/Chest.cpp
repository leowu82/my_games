#include "Chest.h"

Chest::Chest(): Item() {}

Chest::Chest(string nameVal,string tagVal)
    : Item(nameVal,tagVal,"",0,1) {}

Chest::Chest(string nameVal,string tagVal,string script,int countVal,int moneyVal)
    : Item(nameVal,tagVal,script,0,countVal) 
{
    rewardMoney = moneyVal;
}

bool Chest::triggerEvent(Object *obj)
{
    Player *player = dynamic_cast<Player*>(obj);
    Potion *potion;

    cout<< "You got a "
        << this->getName() << "!\n";
    //print chest content
    printChest();

    int size = chest.size();
    for (int i = 0; i < size; i++)
    {
        if (chest[i]->getName() == "[Health Potion]")
        {
            player->addInventory(chest[i]);
        }

        else if (chest[i]->getName() == "[Banana]")
        {
            player->addInventory(chest[i]);
        }

        else if (chest[i]->getName() == "[Money] +200 coins")
        {
            player->increaseStates(0,0,0,0,0,200);
        }

        else if (chest[i]->getName() == "[Money] +300 coins")
        {
            player->increaseStates(0,0,0,0,0,300);
        }

        else if (chest[i]->getName() == "[Money] +500 coins")
        {
            player->increaseStates(0,0,0,0,0,500);
        }

        else if (chest[i]->getName() == "[Geo Artifact]")
        {
            player->addInventory(chest[i]);
        }

        else if (chest[i]->getName() == "[Electro Artifact]")
        {
            player->addInventory(chest[i]);
        }
    }
    cout<< endl;
    
    //pop object
    player->getCurrentRoom()->popObject(this);
    return false;
}

void Chest::printChest()
{
    cout<< "What's inside: \n";
    char c = 'a';
    int size = chest.size();
    for (int i = 0; i < size; i++)
    {
        Item *item = dynamic_cast<Item*>(chest[i]);
        cout<< c++ << ". "
            << item->getName() << ' '
            << item->getDescription() << " (x"
            << item->getCount() << ")\n";
    }
}

// setter
void Chest::setRewardMoney(int moneyVal)
{
    rewardMoney = moneyVal;
}

void Chest::setChest(vector<Object*> obj)
{
    chest = obj;
}

//getter
int Chest::getRewardMoney()
{
    return rewardMoney;
}

vector<Object*> Chest::getChest()
{
    return chest;
}

//set Types of Chest
void Chest::setNormalChest()
{
    this->setName("Normal Chest");
    this->setTag("Chest");

    vector<Object*> content;
    Object *temp;

    temp = new Potion("[Health Potion]","Potion","+200 Hp",0,1,0,200,0,0,0);
    content.push_back(temp);
    
    temp = new Potion("[Banana]","Potion","+200 Mana",0,2,0,0,0,0,200);
    content.push_back(temp);
    
    temp = new Chest("[Money] +200 coins","Chest","",1,200);
    content.push_back(temp);

    chest = content;

    temp = NULL;
    delete temp;
}

void Chest::setDeluxeChest()
{
    this->setName("'Slightly More Deluxe' Chest");
    this->setTag("Chest");

    vector<Object*> content;
    Object *temp;

    temp = new Potion("[Health Potion]","Potion","+200 Hp",0,2,0,200,0,0,0);
    content.push_back(temp);
    
    temp = new Potion("[Banana]","Potion","+200 Mana",0,3,0,0,0,0,200);
    content.push_back(temp);
    
    temp = new Chest("[Money] +300 coins","Chest","",1,300);
    content.push_back(temp);

    temp = new Weapon("[Geo Artifact]","Artifact","+200 Max Hp, +100 Def",0,1,200,0,100); //max hp +200; def +100
    content.push_back(temp);

    chest = content;

    temp = NULL;
    delete temp;
}

void Chest::setAlotChest()
{
    this->setName("'Alot of Stuff in This' Chest");
    this->setTag("Chest");

    vector<Object*> content;
    Object *temp;

    temp = new Potion("[Health Potion]","Potion","+200 Hp",0,3,0,200,0,0,0);
    content.push_back(temp);
    
    temp = new Potion("[Banana]","Potion","+200 Mana",0,5,0,0,0,0,200);
    content.push_back(temp);
    
    temp = new Chest("[Money] +500 coins","Potion","",1,500);
    content.push_back(temp);

    temp = new Weapon("[Geo Artifact]","Artifact","+200 Max Hp, +100 Def",0,1,200,0,100); //max hp +200; def +100
    content.push_back(temp);

    temp = new Weapon("[Electro Artifact]","Artifact","+200 Atk",0,1,0,200,0); //Atk +200
    content.push_back(temp);

    chest = content;

    temp = NULL;
    delete temp;
}

void Chest::addChestItem(Object *obj)
{
    chest.push_back(obj);
}
