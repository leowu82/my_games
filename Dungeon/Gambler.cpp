#include "Gambler.h"

Gambler::Gambler() {}

Gambler::Gambler(string nameVal, vector<Object*> items)
    : NPC(nameVal,items) {}

bool Gambler::triggerEvent(Object *obj)
{
    Player *player = dynamic_cast<Player*>(obj);
    //print product
    int select = printNPC();
    if (select == -1) return false;

    //if no money
    if(player->getMoney() < (dynamic_cast<Item*>(getCommodity()[tempInt[select]])->getPrice()))
    {
        cout<< "... Gambling without money is like eating French Fries without Ketchup! \nUNACCEPTABLE!!! -_-* \n";
        return false;
    }

    //buy product and add
    if (getCommodity()[tempInt[select]]->getTag() != "Nothing")
    {
        player->addInventory(getCommodity()[tempInt[select]]);
    }
    Item *item = dynamic_cast<Item*>(getCommodity()[tempInt[select]]);
    player->addMoney(-(item->getPrice()));

    //print description
    if (getCommodity()[tempInt[select]]->getTag() == "Nothing") 
    {
        cout<< "Congratulations! You've got Nothing! Haha~ :>\n";
    }
    else cout<< "Congratulations! You've got " << getCommodity()[tempInt[select]]->getName() << "!\n";

    return false;
}

int Gambler::printNPC()
{
    string option;
    int size = this->getCommodity().size();

    while (1) 
    { //ask want to play?
        cout<< this->getScript();
        cout<< "Option >";
        getline(cin,option);
        cout<< endl;
        if (IsValidInput(option,0,2)) 
        {
            if (option == "a") break;
            else return -1;
        }
    }

    vector<string> selection = {"'Nothing here' Box","'This one?' Box","'Definitely Here!' Box"};

    srand(time(0));
    int temp1 = rand() % 3;
    tempInt.push_back(temp1);
    int temp2;
    while ((temp2 = rand() % 3) == temp1); 
    tempInt.push_back(temp2);
    int temp3 = temp1;
    while (!((temp3 = rand() % 3) != temp1 && (temp3) != temp2)); 
    tempInt.push_back(temp3);

    while (1)
    {

        //print product
        char c = 'a';
        for (int i = 0 ; i < size; i++)
        {
            cout<< c++ << ". "
                << selection[tempInt[i]] << endl;
        }
        
        cout<< "Option >";
        getline(cin,option);
        cout<< endl;
        if (IsValidInput(option,0,size)) break;
    }
    return (option[0]-97);
}

void Gambler::setGambler()
{
    this->setScript("\n----------------------------------------\n""Hey, HEY you! ...\n"
    "Yes! YOU right there! ... wanna play a game? :> \n"
    "> Spend 100 coins and play a game with the Gambler... \n"
    "a. Sure~ \n"
    "b. Ew no thanks. \n");

    Object *temp;
    vector<Object*> commodity;

    temp = new Potion("[Enhance Attack Potion]","Potion","+500 ATK",100,1,0,0,500,0,0);
    commodity.push_back(temp);

    temp = new Potion("[Banana]","Potion","+200 Mana",100,1,0,0,0,0,200);
    commodity.push_back(temp);

    temp = new Potion("Nothing! Haha~ :>","Nothing","",100,1,0,0,0,0,0);
    commodity.push_back(temp);

    this->setCommodity(commodity);
}

