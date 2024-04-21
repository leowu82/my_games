#include "Monster.h"

Monster::Monster() {}

Monster::Monster(string nameVal,string elementVal,int hp,int atk,int def): GameCharacter(nameVal, "Monster", elementVal, hp, atk, def) {}

bool Monster::triggerEvent(Object *player)
{ //when choose Fight Monster in interface
    Player *playerFight = dynamic_cast<Player*>(player);
    vector<Skill*> playerSkillSet = playerFight->getSkillSet();

    bool usedSkill = false;
    string option;
    int freeTurnOption;
    int size = playerSkillSet.size();
    if (this->checkIsDead() == false)
    { //if monster is not dead
        showStatus();
        cout<< endl;
        
        //Player Attacks Monster
        while (1) 
        {
            while (1)
            {
                //print actions
                cout<< "Choose your Action...\n"
                    << "a. Attack\n"
                    << "b. Retreat\n"
                    << "c. Show Status\n";

                char c = 'd';
                int selectionCount = 0;
                for (Skill *it: playerSkillSet)
                {
                    if (it->getIsUnlocked() && it->getCurAvailable() && playerFight->getMana()>=it->getManaCost())
                    {
                        cout<< c++ << ". " 
                            << it->getName() << " "
                            << "{Cost: " << it->getManaCost() << " Mana}";
                        
                        if (it->getIsFreeTurn()) {
                            cout<< " (Free of Turn)";
                        }
                        cout<< it->getDescription();
                        cout<< endl;
                        ++selectionCount;
                    }
                }

                cout<< "Option >";
                getline(cin, option);
                cout<< endl;
                if (IsValidInput(option,0,selectionCount+3)) 
                {
                    //if skill is free of turn
                    if (option!="a" && option!="b" && option!="c" && playerSkillSet[0]->getIsFreeTurn() && usedSkill == false) 
                    {
                        usedSkill = true;
                        freeTurnOption = option[0]-100;
                        //set cur available as false
                        playerSkillSet[freeTurnOption]->setCurAvailable(false);

                        playerSkillSet[freeTurnOption]->triggerEvent(playerFight);

                        playerFight->showStatus();
                    }

                    //if show status
                    else if (option == "c")
                    {
                        playerFight->showStatus();
                    }

                    else break;
                }
            }

            //retreat and reset
            if (option == "b")
            {
                for (int i = 0; i < size; i++) 
                {
                    if (playerSkillSet[i]->getIsFreeTurn())
                    {
                        playerSkillSet[i]->setCurAvailable(true);
                    }
                }
                playerFight->setCurAttack(playerFight->getAttack());
                playerFight->setDamageReduction(1.0);
                return false;
            }

            //attack
            else if (option == "a")  
            { 
                if (playerFight->getElementSet().size()!=0) 
                {
                    Elemental_Reaction *element = playerFight->useElementSet();
                    if (element->checkReaction(this->getElement())) 
                    {
                        cout<< "You have Induced an Elemental Reaction! Inflicting ";
                        cout<< this->takeDamage(playerFight->getCurAttack(),1.5);
                        cout<< " damage!\n\n";
                        break;
                    }
                    else 
                    {
                        cout<< "You have inflicted ";
                        cout<< this->takeDamage(playerFight->getCurAttack(),1.0);
                    }
                
                }
                else
                {
                    cout<< "You have inflicted ";
                    cout<< this->takeDamage(playerFight->getCurAttack(),1.0);
                }
                cout<< " damage!\n\n";
            }

            //skill (no free turn)
            else if (option!="a" && option!="b" && option!="c")
            {
                playerSkillSet[1]->triggerEvent(playerFight);
                cout<< "You have inflicted ";
                cout<< this->takeDamage(playerFight->getCurAttack(),1.0);
                cout<< " damage!\n\n";
            }

            break;
        }

        //Monster attacks Player
        cout<< this->getName() << " does ";
        cout<< playerFight->takeDamage(this->getCurAttack(),playerFight->getDamageReduction());
        cout<< " damage!\n\n";

        //Reset curAttack/curAvailable/damageReduction
        for (int i = 0; i < size; i++) 
        {
            if (playerSkillSet[i]->getIsFreeTurn())
            {
                playerSkillSet[i]->setCurAvailable(true);
            }
        }
        playerFight->setCurAttack(playerFight->getAttack());
        playerFight->setDamageReduction(1.0);

        return true;
    }

    //monster is dead
    else 
    {
        cout<< this->getName() 
            << " has 0 Health left...\n"
            << "You've Defeated it!\n";
        
        if (this->getName()[0] == '<') {
            cout<< "You are rewarded with: +200 Hp, +200 Mana, +100 money...\n";
            playerFight->increaseStates(0,200,0,0,200,100);
        }

        cout<< "========================================\n";


        //pop object
        playerFight->getCurrentRoom()->popObject(this);

        return false;
    }
}

void Monster::showStatus()
{
    cout<< this->getName() << endl
        << "Elemental Attribute: " << this->getElement() << endl
        << "Health:              " << this->getCurrentHealth() << '/' << this->getMaxHealth() << endl
        << "Attack:              " << this->getAttack() << endl
        << "Defense:             " << this->getDefense() << endl;
}
