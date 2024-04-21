#include "Player.h"

Player::Player(): GameCharacter() {}

Player::Player(string nameVal,string occup,int maxHealthVal,int attackVal,int defenseVal,int manaVal)
    : GameCharacter(nameVal, "Player", "None", maxHealthVal, attackVal, defenseVal)
{
    occupation = occup;
    money = 0;
    mana = manaVal;
}

void Player::addInventory(Object *stuff)
{
    int size = inventory.size();
    for (int i = 0; i < size; i++)
    {
        if (inventory[i]->getName() == stuff->getName())
        { //if inventory alrdy have it
            Item *item = dynamic_cast<Item*>(inventory[i]);
            Item *addItem = dynamic_cast<Item*>(stuff);
            item->addCount(addItem->getCount());
            return;
        }
    }
    inventory.push_back(stuff);
}

void Player::increaseStates(int maxHp,int curHp,int atk,int def,int manaVal,int moneyVal)
{
    setMaxHealth(getMaxHealth() + maxHp);

    if (getCurrentHealth() + curHp >= getMaxHealth())
    {
        setCurrentHealth(getMaxHealth());
    }
    else setCurrentHealth(getCurrentHealth() + curHp);

    setAttack(getAttack() + atk);
    setDefense(getDefense() + def);
    mana = mana + manaVal;
    money = money + moneyVal;
}

void Player::changeRoom(Room *room)
{
    previousRoom = currentRoom;
    currentRoom = room;
}

bool Player::triggerEvent(Object *obj)
{
    return true;
}

//Show status
void Player::showStatus()
{
    cout<< "Here is your current status...\n"
        << "[" << this->getName() << "]\n"
        << "Occupation: " << this->getOccupation() << endl
        << "Health:     " << this->getCurrentHealth() << '/'
        << this->getMaxHealth() << endl
        << "Attack:     " << this->getCurAttack() << endl
        << "Defense:    " << this->getDefense() << endl
        << "Mana:       " << mana << endl
        << "Money:      " << money << endl;

    cout<< endl;
}

//setter
void Player::setCurrentRoom(Room *cur)
{
    currentRoom = cur;
}

void Player::setPreviousRoom(Room *prev)
{
    previousRoom = prev;
}

void Player::setInventory(vector<Object*> stuff)
{
    inventory = stuff;
}

void Player::setSkillSet(vector<Skill*> skills)
{
    skillSet = skills;
}

void Player::setElementSet(vector<Elemental_Reaction*> elements)
{
    elementSet = elements;
}

void Player::setOccupation(string name)
{
    occupation = name;
}

void Player::setMoney(int moneyVal)
{
    money = moneyVal;
}

void Player::addMoney(int moneyVal)
{
    money = money + moneyVal;
}

void Player::setMana(int sp)
{
    mana = sp;
}

void Player::addMana(int manaCost)
{
    mana = mana + manaCost;
}

//getter
Room *Player::getCurrentRoom()
{
    return currentRoom;
}

Room *Player::getPreviousRoom()
{
    return previousRoom;
}

vector<Object*> Player::getInventory()
{
    return inventory;
}

vector<Skill*> Player::getSkillSet()
{
    return skillSet;
}

vector<Elemental_Reaction*> Player::getElementSet()
{
    return elementSet;
}

string Player::getOccupation()
{
    return occupation;
}

int Player::getMoney()
{
    return money;
}

int Player::getMana()
{
    return mana;
}

//Show/Use Inventory
int Player::showInventory()
{
    if (inventory.size() == 0) 
    {
        cout<< "You got nothing bruh.\n\n";
        return 0;
    }

    char count = 'a';
    cout<< "Here is your Inventory...\n";
    int size = inventory.size();
    for (int i = 0; i < size; i++)
    {
        Item *item = dynamic_cast<Item*>(inventory[i]);
        if (item->getCount() >= 0)
        {
            cout<< count++ << ". "
                << item->getName() << ": "
                << item->getDescription();
            if (item->getTag() != "Weapon") {    
                cout<< " --- "
                    << item->getCount() << " left";
            }
            cout<< endl;
        }
    }
    return (count-97);
}

void Player::useInventory()
{
    if (inventory.size() == 0) return;

    while (1)
    {
        cout<< "\nDo you want to use any items? ...\n";
        cout<< "a. Yes\n" << "b. No\n";
        cout<< "Option >";
        string option;
        getline(cin, option);
        cout<< endl;
        if (IsValidInput(option,0,2)) 
        {
            if (option[0]=='a') 
            {
                while (1) 
                {
                cout<< "Which item do you want to use? ...\n";
                int optionCount = showInventory();
                cout<< "Option >";
                getline(cin, option);
                cout<< endl;
                if (IsValidInput(option,0,optionCount))
                {
                    if (inventory[option[0]-97]->triggerEvent(this))
                    {
                        inventory.erase(inventory.begin()+(option[0]-97));
                    }
                    return;
                } 
                }
            }
            else return;
        }
    }
    cout<< endl;
}

//initialize occupation skill
void Player::initializeSkills()
{
    Skill *skill = new Skill("Skill");
    Skill *skillUlt = new Skill("Skill");
    if (this->getOccupation() == "Saber")
    {
        skill->setSaberSkill();
        skillSet.push_back(skill);
        skillUlt->setSaberUlt();
        skillSet.push_back(skillUlt);
    }

    else if (this->getOccupation() == "Archer")
    {
        skill->setArcherSkill();
        skillSet.push_back(skill);
        skillUlt->setArcherUlt();
        skillSet.push_back(skillUlt);
    }

    else if (this->getOccupation() == "Caster")
    {
        skill->setCasterSkill();
        skillSet.push_back(skill);
        skillUlt->setCasterUlt();
        skillSet.push_back(skillUlt);
    }

    else if (this->getOccupation() == "Assassin")
    {
        skill->setAssassinSkill();
        skillSet.push_back(skill);
        skillUlt->setAssassinUlt();
        skillSet.push_back(skillUlt);
    }

    else cout<< "Occupation not set! //initializeSkills()\n";
}

void Player::addSkills(Skill *skills)
{
    for (Skill *it: skillSet)
    {
        if (it->getName() != skills->getName())
            skillSet.push_back(skills);
            return;
    }
}

void Player::showSkills()
{
    char c = 'a';
    cout<< "Skills Obtained: \n";
    for (Skill *it: skillSet)
    {
        if (it->getIsUnlocked()) {
            cout<< c++ << ". " 
                << it->getName() << " "
                << "{Cost: " << it->getManaCost() << " Mana}";
            
            if (it->getIsFreeTurn()) {
                cout<< " (Free of Turn)";
            }
            cout<< it->getDescription();
            cout<< endl;
        }
    }
    cout<< endl;
}

void Player::addElementSet(Elemental_Reaction *obj)
{
    elementSet.push_back(obj);
}

void Player::showElementSet()
{
    char c = 'a';
    int size = elementSet.size();

    cout<< "Element learnt: \n";

    if (size == 0) 
    {
        cout<< "None!\n";
        return;
    }
    
    for (int i = 0; i < size; i++) 
    {
        cout<< c++ << ". "
            << elementSet[i]->getName() << endl;
    }
}

Elemental_Reaction* Player::useElementSet()
{
    string option;
    int size = elementSet.size();

    Elemental_Reaction info;
    info.printReactInfo();


    while (1)
    {
        cout<< "Choose the Element you wish to apply to your attack!\n";

        showElementSet();
        
        cout<< "Option >";
        getline(cin,option);
        cout<< endl;
        if(IsValidInput(option,0,elementSet.size())) break;
    }

    return elementSet[option[0]-97];
}
