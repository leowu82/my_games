#include "Dungeon.h"

Dungeon::Dungeon() {}

void Dungeon::createPlayer() 
{
    //Input Name
    cout<< "Enter your name... \n>";
    string name;
    getline(cin, name);
    cout<< endl;

    //Decide Occupation
    string temp; 
    while (temp.empty() || !IsValidInput(temp,0,4))
    {
        cout<< "Choose your Occupation...\n"
            << "a. Saber \n"
            << "b. Archer \n" 
            << "c. Caster \n"
            << "d. Assassin \n"
            << "Option >";
        getline(cin, temp);
    }

    //Intialize player with occupation
    //Health/Attack/Def/Mana
    if (temp == "a")
    { // 1000, 500, 300, 500
        player = Player(name, "Saber", 1000, 500, 300, 600);
    }
    else if (temp == "b")

    {
        player = Player(name, "Archer", 700,700, 150, 900);
    }
    else if (temp == "c")
    {
        player = Player(name, "Caster", 500, 800, 100, 1200);
    }
    else if (temp == "d")
    {
        player = Player(name, "Assassin", 800, 600, 200, 800);
    }
    else 
    {
        cout<< "Bug, Error in createPlayer\n";
        exit(1);
    }

    //Set skills
    player.initializeSkills();

    //Set Start Room 
    player.setMoney(5000);
    player.setAttack(50000);
    player.setCurrentRoom(&rooms[17]);

    //show status
    cout<< "\nYou have chosen " << player.getOccupation() << "...\n";
    if (player.triggerEvent(&player)) 
    {
        player.showStatus();
        player.showSkills();
    }

    else cout<< "Fail to show status";
    
}

void Dungeon::createMap() 
{ //done
    int index = 0;
    vector<Object*> v; //Objects in room
    Object *temp; //temp to store obj
    Chest *tempChest; //temp to store chest

    //create room first
    while(1)
    {
    //Room 10: Start
    v.clear(); //empty room
    rooms.push_back(Room(false,10,1,v)); //check

    //Room 11: Water Slime
    temp = new Monster("[Water Slime]","Water",1000,100,10);
    v.push_back(temp);
    rooms.push_back(Room(false,11,1,v));
    temp = NULL; v.clear();

    //Room 12: Chest
    tempChest = new Chest("[Normal Chest]","Chest"); 
    tempChest->setNormalChest();
    v.push_back(tempChest);
    rooms.push_back(Room(false,12,1,v));
    tempChest = NULL; v.clear();

    //Room 13: Fire Spirit
    temp = new Monster("[Fire Spirit]","Fire",1500,200,50);
    v.push_back(temp);
    rooms.push_back(Room(false,13,1,v));
    temp = NULL; v.clear();

    //Room 14: Elemental Master
    Elemental_Master *ElementalMaster = new Elemental_Master("[Elemental Master]",vector<Object*>(0));
    ElementalMaster->setElementalMaster();
    v.push_back(ElementalMaster);
    rooms.push_back(Room(false,14,1,v));
    ElementalMaster = NULL; v.clear();

    //Room 15: <BOSS> [Gras-saurus!]
    temp = new Monster("<BOSS> [Gras-saurus!]","Grass",2000,350,100);
    v.push_back(temp);
    rooms.push_back(Room(false,15,1,v));
    temp = NULL; v.clear();

    //Room 20: Start
    rooms.push_back(Room(false,20,2,v));

    //Room 21: Lake Elf
    temp = new Monster("[Lake Elf]","Water",1600,300,100);
    v.push_back(temp);
    rooms.push_back(Room(false,21,2,v));
    temp = NULL; v.clear();

    //Room 22: Wood Dwarf
    temp = new Monster("[Wood Dwarf]","Grass",3000,100,300);
    v.push_back(temp);
    rooms.push_back(Room(false,22,2,v));
    temp = NULL; v.clear();
    
    //Room 23: Empty
    rooms.push_back(Room(false,23,2,v));

    //Room 24: Empty
    rooms.push_back(Room(false,24,2,v));

    //Room 25: 'Slighty more Deluxe' Chest
    tempChest = new Chest("['Slighty more Deluxe' Chest]","Chest");
    tempChest->setDeluxeChest();
    v.push_back(tempChest);
    rooms.push_back(Room(false,25,2,v));
    tempChest = NULL; v.clear();

    //Room 26: Mysterious Merchant
    Merchant *merchant = new Merchant("[Mysterious Merchant]",vector<Object*>(0));
    merchant->setMerchant(); 
    v.push_back(merchant);
    rooms.push_back(Room(false,26,2,v));
    merchant = NULL; v.clear();

    //Room 27: Dark Flame Master
    temp = new Monster("[Dark Flame Master]","Fire",2000,500,200);
    v.push_back(temp);
    rooms.push_back(Room(false,27,2,v));
    temp = NULL; v.clear();

    //Room 28: <BOSS> ['Very scary Monster!']
    temp = new Monster("<BOSS> ['Very Scary' Monster!]","None",3000,600,300);
    v.push_back(temp);
    rooms.push_back(Room(false,28,2,v));
    temp = NULL; v.clear();

    //Room 30: Start
    rooms.push_back(Room(false,30,3,v));

    //Room 31: Monkey
    temp = new Monster("[Monkey]","Grass",2500,550,250);
    v.push_back(temp);
    rooms.push_back(Room(false,31,3,v));
    temp = NULL; v.clear();

    //Room 32: Gambler
    Gambler *gambler = new Gambler("[The Gambler]",vector<Object*>(0));
    gambler->setGambler(); 
    v.push_back(gambler);
    rooms.push_back(Room(false,32,3,v));
    gambler = NULL; v.clear();

    //Room 33: Hot-Dogs
    temp = new Monster("[Hot-Dogs]","Fire",3500,600,300);
    v.push_back(temp);
    rooms.push_back(Room(false,33,3,v));
    temp = NULL; v.clear();

    //Room 34: Bing-Qi-Ling
    temp = new Monster("[Bing-Qi-Ling]","Water",4000,700,400);
    v.push_back(temp);
    rooms.push_back(Room(false,34,3,v));
    temp = NULL; v.clear();

    //Room 35: 'A Lot of Stuff Inside This' Chest!
    tempChest = new Chest("['A Lot of Stuff Inside This' Chest!]","Chest");
    tempChest->setAlotChest();
    v.push_back(tempChest);
    rooms.push_back(Room(false,35,3,v));
    tempChest = NULL; v.clear();

    //Room 36: Pet Shop
    PetShop *petShop = new PetShop("[Pet Shop]",vector<Object*>(0));
    petShop->setPetShop(); 
    v.push_back(petShop);
    rooms.push_back(Room(false,36,3,v));
    petShop = NULL; v.clear();

    //Room 37: Empty
    rooms.push_back(Room(false,37,3,v));

    //Room 38: 'Slighty more Deluxe' Chest
    tempChest = new Chest("['Slighty more Deluxe' Chest]","Chest");
    tempChest->setDeluxeChest();
    v.push_back(tempChest);
    rooms.push_back(Room(false,38,3,v));
    tempChest = NULL; v.clear();

    //Room 39: <BOSS> [COMPILE ERROR]
    temp = new Monster("<BOSS> [COMPILE ERROR]","None",5000,800,500);
    v.push_back(temp);
    rooms.push_back(Room(true,39,3,v));
    temp = NULL; v.clear();

    break;
    }

    //Now Link the rooms
    //vector<Room> rooms;
    while(1)
    {
        //up,down,left,right,upStairs,downStairs
        //Floor 1 (0~5)
        rooms[0].setRoom(&rooms[1],NULL,NULL,NULL,NULL,NULL);
        rooms[1].setRoom(NULL,&rooms[0],NULL,&rooms[2],NULL,NULL);
        rooms[2].setRoom(&rooms[3],NULL,&rooms[1],NULL,NULL,NULL);
        rooms[3].setRoom(NULL,&rooms[2],&rooms[5],&rooms[4],NULL,NULL);
        rooms[4].setRoom(NULL,NULL,&rooms[3],NULL,NULL,NULL);
        rooms[5].setRoom(NULL,NULL,NULL,&rooms[3],&rooms[6],NULL);
        //Floor 2 (6~14)
        rooms[6].setRoom(&rooms[7],NULL,NULL,NULL,NULL,&rooms[5]);
        rooms[7].setRoom(NULL,&rooms[6],&rooms[8],NULL,NULL,NULL);
        rooms[8].setRoom(NULL,NULL,&rooms[9],&rooms[7],NULL,NULL);
        rooms[9].setRoom(&rooms[13],&rooms[10],&rooms[12],&rooms[8],NULL,NULL);
        rooms[10].setRoom(&rooms[9],NULL,NULL,&rooms[11],NULL,NULL);
        rooms[11].setRoom(NULL,NULL,&rooms[10],NULL,NULL,NULL);
        rooms[12].setRoom(NULL,NULL,NULL,&rooms[9],NULL,NULL);
        rooms[13].setRoom(NULL,&rooms[9],NULL,&rooms[14],NULL,NULL);
        rooms[14].setRoom(NULL,NULL,&rooms[13],NULL,&rooms[15],NULL);
        //Floor 3 (15~24)
        rooms[15].setRoom(NULL,&rooms[16],NULL,&rooms[18],NULL,&rooms[14]);
        rooms[16].setRoom(&rooms[15],&rooms[17],NULL,NULL,NULL,NULL);
        rooms[17].setRoom(&rooms[16],&rooms[23],NULL,NULL,NULL,NULL);
        rooms[18].setRoom(NULL,&rooms[19],&rooms[15],NULL,NULL,NULL);
        rooms[19].setRoom(&rooms[18],&rooms[21],NULL,&rooms[20],NULL,NULL);
        rooms[20].setRoom(NULL,NULL,&rooms[19],NULL,NULL,NULL);
        rooms[21].setRoom(&rooms[19],&rooms[22],NULL,NULL,NULL,NULL);
        rooms[22].setRoom(&rooms[21],NULL,&rooms[23],&rooms[24],NULL,NULL);
        rooms[23].setRoom(&rooms[17],NULL,NULL,&rooms[22],NULL,NULL);
        rooms[24].setRoom(NULL,NULL,&rooms[22],NULL,NULL,NULL);

        break;
    }

}

void Dungeon::handleMovement() 
{ //done
    string option;
    while (1)
    {
        cout<< "Where do you want to go? \n";
        vector<Room*> validRoom = player.getCurrentRoom()->checkRoom(); //prints options
        cout<< "Option >";
        getline(cin, option);
        cout<< endl;
        if (IsValidInput(option,0,validRoom.size()))
        {
            player.changeRoom(validRoom[option[0]-97]);
            break;
        }
    }

}

void Dungeon::handleRetreat() 
{ 
    player.setCurrentRoom(player.getPreviousRoom());
}

void Dungeon::handleEvent(Object* obj) 
{
    string option;
    
    //Monster
    if (obj->getTag() == "Monster") 
    {
        Monster *monster = dynamic_cast<Monster*>(obj);
        while (1)
        {
            cout<< "Do you want to Fight "
                << monster->getName() << "?\n";
            cout<< "a. Bring it on!\n"
                << "b. Ew no.\n";
            cout<< "Option >";
            getline(cin,option);
            cout<< endl;
            if (IsValidInput(option,0,2)) break;
        }
    }

    //NPC
    else if (obj->getTag() == "NPC") 
    {
        NPC *npc = dynamic_cast<NPC*>(obj);
        while (1)
        {
            cout<< "Do you want to talk with "
                << npc->getName() << "?\n";
            cout<< "a. Yeah sure~\n"
                << "b. Nah\n";
            cout<< "Option >";
            getline(cin,option);
            cout<< endl;
            if (IsValidInput(option,0,2)) break;
        }
    }

    //Chest
    else if (obj->getTag() == "Chest") 
    {
        option = "a";
    }

    if (option == "a")
    {
        while(obj->triggerEvent(&player));
    }

    else handleRetreat();
}

void Dungeon::chooseAction(vector<Object*> roomObj) 
{ //Base interface
    int optionCount = 3;
    bool hasMonster = false;
    string option;

    //print available actions
    while (1)
    {
        char c = 'c';
        player.getCurrentRoom()->printRoomName();
        cout<< "What do you want to do? \n";
        cout<< "a. Move \n";
        cout<< "b. Check Status \n";
        cout<< "c. Check Inventory \n";
        if (roomObj.size() != 0)
        { 
            for (Object *it: roomObj) 
            {
                cout<< ++c << ". ";

                if (it->getTag() == "Monster")
                {
                    cout<< "Fight Monster\n";
                    hasMonster = true;
                }
                if (it->getTag() == "NPC")
                {
                    cout<< "Talk with the NPC\n";
                }
                if (it->getTag() == "Chest")
                {
                    cout<< "Open Chest\n";
                }
                ++optionCount;
            }
        }
        cout<< "Option >";

        getline(cin, option);
        cout<< endl;

        if (IsValidInput(option,0,optionCount)) break;
    }

    if (option[0] == 'a')
    { //move
        if (hasMonster) 
        {
            cout<< "Bro, the monster is literally standing in the exit...\n"
                << "You gotta defeat it first...\n";
            cout<< "Or perhaps... you want to run away?\n";

            while (1) 
            {
                cout<< "Do you want to retreat? (go back to previous room)\n";
                cout<< "a. Yes, I'm scared ;-;\n"
                    << "b. No thanks,\n";
                cout<< "Option >";
                getline(cin,option);
                if (IsValidInput(option,0,2)) break;
            }

            if (option == "a") handleRetreat();
            return;
        }
        else handleMovement();
    }

    else if (option[0] == 'b')
    { //show status
        cout<< "----------------------------------------\n";
        player.showStatus();
        player.showSkills();
        player.showElementSet();
        cout<< "----------------------------------------\n";
    }
    
    else if (option[0] == 'c')
    { //show inventory
        player.showInventory();
        // show and ask whether want to use item
        player.useInventory();
        // run useInventory function in player
    }

    else 
    { //trigger object in room
        Object *obj = roomObj[option[0]-100];

        handleEvent(obj);

        // //pop object
        // player->getCurrentRoom()->popObject(obj);
    }
}

bool Dungeon::checkGameLogic() 
{
    if (player.checkIsDead()) 
    {
        cout<< "You have 0 Health left...\n"
            << "You Died!\n\n\n";
        
        exit(1);
    } 

    //if room is exit and object cleared, can exit
    else if (player.getCurrentRoom()->getIsExit() && player.getCurrentRoom()->getObjects().size() == 0) 
    {
        cout<< "\n\nPhew! What a spectacular battle! ... \nCongratulations! U defeated the final boss! \nPerhaps the Tower was not so dangerous afterall...\n\n\n";



        exit(1);
    }

    else return true;
}

//Include createPlayer, createMap
void Dungeon::startGame() 
{ 
    string option;
    while (1) 
    {
        cout<< endl << "Welcome to the 'Very Dangerous Tower'...\n";
        cout<< "a. Enter...\n"
            << "b. Run away...\n"
            << "c. Why u even here then...\n"
            << "Option >";
        getline(cin, option);

        if (option == "a" || option == "A") 
        {
            cout<< endl << "------------------------------\n" 
                << "I see... So this is what you've chosen... \n"
                << "I commend your bravery... \n"
                << "Behold! The 'Very Dangerous Tower', also known as the 'Tower of Many Dangers'... \n"
                << "Be prepared... \nFor you shall face many dangers... \n"
                << "I wish you the best of luck... \n" 
                << "------------------------------\n\n";
            break;
        }
        
        else if (option == "b" || option == "B") 
        {
            cout<< "No, u actually have no choice, choose option A\n";
        }

        else if (option == "c" || option == "C") 
        {
            cout<< "Bruh...\n";
            exit(1);
        }

        else 
        {
            cout<< "Invalid input...\n";
        }
    }

    createMap();
    createPlayer();
}

void Dungeon::runDungeon() 
{
    startGame();

    //Game Loops Here
    while (checkGameLogic()) 
    {
        chooseAction(player.getCurrentRoom()->getObjects());
    }
}

