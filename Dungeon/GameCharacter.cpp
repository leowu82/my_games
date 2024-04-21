#include "GameCharacter.h"

GameCharacter::GameCharacter() {}

GameCharacter::GameCharacter(string nameVal, string tagVal, string elementVal, int maxHealthVal, int attackVal, int defenseVal): Object(nameVal, tagVal)
{
    element = elementVal;
    maxHealth = maxHealthVal;
    currentHealth = maxHealthVal;
    attack = attackVal;
    curAttack = attackVal;
    defense = defenseVal;
    damageReduction = 1.0;
}

bool GameCharacter::checkIsDead() 
{
    return (currentHealth <= 0);
}

int GameCharacter::takeDamage(int dmg,double intakeDamagePercent) 
{ 
    //deducts currentHealth already
    int resultDamage = (dmg * intakeDamagePercent) - defense;
    if (resultDamage > 0) {
        currentHealth = currentHealth - resultDamage;
        return resultDamage;
    } 
    else return 0;
}

//setter
void GameCharacter::setElement(string e)
{
    element = e;
}

void GameCharacter::setMaxHealth(int hp) 
{
    maxHealth = hp;
}

void GameCharacter::setCurrentHealth(int hp) 
{
    currentHealth = hp;
}

void GameCharacter::setAttack(int atk) 
{
    attack = atk;
    setCurAttack(atk);
}

void GameCharacter::setCurAttack(int curAtk)
{
    curAttack = curAtk;
}

void GameCharacter::setDefense(int def) 
{
    defense = def;
}

void GameCharacter::setDamageReduction(double percent)
{
    damageReduction = percent;
}

//getter
string GameCharacter::getElement()
{
    return element;
}

int GameCharacter::getMaxHealth() 
{
    return maxHealth;
}

int GameCharacter::getCurrentHealth() 
{
    return currentHealth;
}

int GameCharacter::getAttack() 
{
    return attack;
}

int GameCharacter::getCurAttack()
{
    return curAttack;
}

int GameCharacter::getDefense() 
{
    return defense;
}

double GameCharacter::getDamageReduction()
{
    return damageReduction;
}

void GameCharacter::modifyCurAttack(int skillAttack,double atkPercent)
{
    curAttack = (curAttack + skillAttack) * atkPercent;
}
