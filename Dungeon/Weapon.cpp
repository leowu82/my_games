#include "Weapon.h"

Weapon::Weapon() {}

Weapon::Weapon(string nameVal,string tagVal,string script,int priceVal,int countVal,int hp,int atk,int def)
    : Item(nameVal,tagVal,script,priceVal,countVal)
{
    weaponHealth = hp;
    weaponAttack = atk;
    weaponDefense = def;
}

bool Weapon::triggerEvent(Object *obj)
{
    Player *player = dynamic_cast<Player*>(obj);
    

    if (this->getTag() == "Artifact")
    {
        cout<< "You have equipped " << getName() << "!\n";
        player->increaseStates(weaponHealth,weaponHealth,weaponAttack,weaponDefense,0,0);
        this->addCount(-1);
        return true;
    }

    else if (hasEffect(player))
    {
        cout<< "You have equipped " << getName() << "!\n";
        player->increaseStates(weaponHealth,weaponHealth,weaponAttack,weaponDefense,0,0);
        this->addCount(-1);
        return true;
    }

    else 
    {
        cout<< "Weapon not compatible...\n";
    }

    return false;
}

bool Weapon::hasEffect(Player *player)
{
    if (this->getName()=="[Excalibur]" && player->getOccupation()=="Saber") 
    {
        player->getSkillSet()[1]->setIsUnlocked(true);
        return true;
    }

    else if (this->getName()=="['A Very Big Bow']" && player->getOccupation()=="Archer") 
    {
        player->getSkillSet()[1]->setIsUnlocked(true);
        return true;
    }

    else if (this->getName()=="[Calculus Textbook]" && player->getOccupation()=="Caster") 
    {
        player->getSkillSet()[1]->setIsUnlocked(true);
        return true;
    }

    else if (this->getName()=="[Mom's Slippers]" && player->getOccupation()=="Assassin") 
    {
        player->getSkillSet()[1]->setIsUnlocked(true);
        return true;
    }

    return false;
}

//setter
void Weapon::setWeaponHealth(int hp)
{
    weaponHealth = hp;
}

void Weapon::setWeaponAttack(int atk)
{
    weaponAttack = atk;
}

void Weapon::setWeaponDefense(int def)
{
    weaponDefense = def;
}

//getter
int Weapon::getWeaponHealth()
{
    return weaponHealth;
}

int Weapon::getWeaponAttack()
{
    return weaponAttack;
}

int Weapon::getWeaponDefense()
{
    return weaponDefense;
}

