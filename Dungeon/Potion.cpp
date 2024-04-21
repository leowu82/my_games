#include "Potion.h"

Potion::Potion() {}

Potion::Potion(string nameVal,string tagVal,string script,int priceVal,int countVal,int maxHp,int Hp,int atk,int def,int mana)
    : Item(nameVal,tagVal,script,priceVal,countVal)
{
    potionMaxHp = maxHp;
    potionHp = Hp;
    potionAtk = atk;
    potionDef = def;
    potionMana = mana;
}

bool Potion::triggerEvent(Object *obj)
{
    Player *player = dynamic_cast<Player*>(obj);

    if (this->getCount() == 0)
    {
        cout<< "You ran out of it!\n";
        return false;
    }

    if (getName()[0] != '<') this->addCount(-1);

    player->increaseStates(potionMaxHp,potionHp,potionAtk,potionDef,potionMana,0);
    player->showStatus();

    if (getName()[0] == '<') {
        delete this;
        return true;
    }

    return false;
}

//setter
void Potion::setPotionMaxHp(int maxHp)
{
    potionMaxHp = maxHp;
}

void Potion::setPotionHp(int Hp)
{
    potionHp = Hp;
}

void Potion::setPotionAtk(int atk)
{
    potionAtk = atk;
}

void Potion::setPotionDef(int def)
{
    potionDef = def;
}

void Potion::setPotionMana(int mana)
{
    potionMana = mana;
}

//getter
int Potion::getPotionMaxHp()
{
    return potionMaxHp;
}

int Potion::getPotionHp()
{
    return potionHp;
}

int Potion::getPotionAtk()
{
    return potionAtk;
}

int Potion::getPotionDef()
{
    return potionDef;
}

int Potion::getPotionMana()
{
    return potionMana;
}
