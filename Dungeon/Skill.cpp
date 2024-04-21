#include "Skill.h"

Skill::Skill() {}

Skill::Skill(string tagVal) 
    : Object("",tagVal) 
{
    intakeDamagePercent = 1.0;
    isCurAvailable = true;
}

Skill::Skill(string nameVal,string tagVal,string script,int manaCostVal,int skillAttackVal,double percent,bool isFree,bool isUnlock)
    : Object(nameVal,tagVal) 
{
    description = script;
    manaCost = manaCostVal;
    skillAttack = skillAttackVal;
    atkPercent = percent;
    intakeDamagePercent = 1.0;
    isFreeTurn = isFree;
    isCurAvailable = true;
    isUnlocked = isUnlock;
}

bool Skill::triggerEvent(Object *character)
{
    Player *player = dynamic_cast<Player*>(character);
    player->modifyCurAttack(skillAttack,atkPercent);
    player->setDamageReduction(intakeDamagePercent);
    //deduct mana
    player->addMana(-this->getManaCost());

    return true;
}

// setter
void Skill::setDescription(string script)
{
    description = script;
}

void Skill::setManaCost(int mana)
{
    manaCost = mana;
}

void Skill::setSkillAttack(int atk)
{
    skillAttack = atk;
}

void Skill::setAtkPercent(double atk)
{
    atkPercent = atk;
}

void Skill::setIntakeDamagePercent(double percent)
{
    intakeDamagePercent = percent;
}

void Skill::setIsFreeTurn(bool isFree)
{
    isFreeTurn = isFree;
}

void Skill::setCurAvailable(bool isFree)
{
    isCurAvailable = isFree;
}

void Skill::setIsUnlocked(bool isUnlock)
{
    isUnlocked = isUnlock;
}

// getter
string Skill::getDescription()
{
    return description;
}

int Skill::getManaCost()
{
    return manaCost;
}

int Skill::getSkillAttack()
{
    return skillAttack;
}

double Skill::getAtkPercent()
{
    return atkPercent;
}

double Skill::getIntakeDamagePercent()
{
    return intakeDamagePercent;
}

bool Skill::getIsFreeTurn()
{
    return isFreeTurn;
}

bool Skill::getCurAvailable()
{
    return isCurAvailable;
}

bool Skill::getIsUnlocked()
{
    return isUnlocked;
}

//Basic skill initialize
void Skill::setSaberSkill()
{
    this->setName(string("[Holy Blessing]"));
    description = "\n   - +50% Atk";
    manaCost = 100;
    skillAttack = 0;
    atkPercent = 1.5;
    intakeDamagePercent = 1;
    isFreeTurn = true;
    isUnlocked = true;
}

void Skill::setArcherSkill()
{
    this->setName("['Shooting From Very Far Away']");
    description = "\n   - Damage received -50%\n   - +200 Atk";
    manaCost = 100;
    skillAttack = 200;
    atkPercent = 1.0;
    intakeDamagePercent = 0.5;
    isFreeTurn = true;
    isUnlocked = true;
}

void Skill::setCasterSkill()
{
    this->setName("[Full Counter]");
    description = "\n   - Ignore enemy attack once\n   - +100 Atk";
    manaCost = 100;
    skillAttack = 100;
    atkPercent = 1.0;
    intakeDamagePercent = 0.0;
    isFreeTurn = true;
    isUnlocked = true;
}

void Skill::setAssassinSkill()
{
    this->setName("['You can't see me']");
    description = "\n   - Damage received -50%\n   - +400 Atk";
    manaCost = 100;
    skillAttack = 400;
    atkPercent = 1.0;
    intakeDamagePercent = 0.5;
    isFreeTurn = true;
    isUnlocked = true;
}

//Initialize ULT skill
void Skill::setSaberUlt()
{
    this->setName("[Ex--Curry-BANG!]");
    description = "\n   - Inflict Atk * 5 worth of damage onto enemy";
    manaCost = 200;
    skillAttack = 0;
    atkPercent = 5.0;
    intakeDamagePercent = 1.0;
    isFreeTurn = false;
    isUnlocked = false;
}

void Skill::setArcherUlt()
{
    this->setName("['A Very Powerful Shot!']");
    description = "\n   - Inflict Atk * 4 worth of damage onto enemy";
    manaCost = 200;
    skillAttack = 0;
    atkPercent = 4.0;
    intakeDamagePercent = 1.0;
    isFreeTurn = false;
    isUnlocked = false;
}

void Skill::setCasterUlt()
{
    this->setName("[Ex--PLOSION!]");
    description = "\n   - Inflict Atk * 4 worth of damage onto enemy";
    manaCost = 200;
    skillAttack = 0;
    atkPercent = 4.0;
    intakeDamagePercent = 1.0;
    isFreeTurn = false;
    isUnlocked = false;
}

void Skill::setAssassinUlt()
{
    this->setName("[Shadow Clone Jutsu]");
    description = "\n   - Inflict Atk * 4 worth of damage onto enemy";
    manaCost = 150;
    skillAttack = 0;
    atkPercent = 4.0;
    intakeDamagePercent = 1.0;
    isFreeTurn = false;
    isUnlocked = false;
}
