#include "Dungeon.hpp"

Dungeon::Dungeon(){
    
}

/* Create a new player, and give him/her basic status */
void Dungeon::createPlayer(){
    int age;
    cout << "Nice to meet you! Let's get you a perfect character" << endl;
    cout << "How old are you?" << endl;
    cin >> age;
    if (age < 18) {
        Player* p = new Player("媽寶", 100, 50, 50, 200);
        player = *p;
        //player = Player("媽寶", 100, 50, 50, 200);
        player.setMaxHealth(200);
        //this -> player = player;
    }
    else if (age >= 18 && age < 30){
        Player player("菜雞", 50, 70, 30, 100);
        player.setMaxHealth(200);
        this -> player = player;
    }
    else if (age >= 30 && age < 60){
        Player player("社畜", 50, 30, 70, 500);
        player.setMaxHealth(200);
        this -> player = player;
    }
    else if (age >= 60){
        Player player("瀕死富翁", 25, 25, 25, 1000);
        player.setMaxHealth(200);
        this -> player = player;
    }
    cout << "Congrats! You are a " << player.getName() << endl;
    cout << "Let's start getting rid of seasick!" << endl;
}

/* Create a map, which include several different rooms */
void Dungeon::createMap(){
    int roomNumber = 7;
    //vector<Room> rooms;
    vector<Item*> commodity1, commodity2, commodity3;
    vector<Object*> player, littleMonster, boss, item1, item2, npc, prize;
    
    Monster* TRH = new Monster("高富帥", 50, 50, 25);
    Monster* B = new Monster("她的前男友", 100, 50, 50);
    
    Item* cigar = new Item("四包菸", 80, 40, 40, 0, 5, false);
    Item* tree = new Item("True嗎", 40, 25,75, 0, 5, false);
    Item* lifebuoy = new Item("lifebuoy", 0 , 0, 0, 0, 5, false);
    
    Item* med = new Item("暈船藥" , 100, 10, 90, 100, 0, false);
    Item* ticket = new Item("勒戒所門票", 200, 50, 100, 200, 1, false);
    Item* surgery = new Item("整形手術", 300, 100, 200, 500, 2, false);
    
    commodity1.push_back(med);
    commodity2.push_back(ticket);
    commodity3.push_back(surgery);
    NPC* sailor = new NPC("水手", "Ahoy!", commodity1, commodity2, commodity3, false, false, false);
    
    littleMonster.push_back(TRH);
    boss.push_back(B);
    item1.push_back(cigar);
    item2.push_back(tree);
    npc.push_back(sailor);
    prize.push_back(lifebuoy);
    
    for(int index = 0 ; index <= roomNumber; index++){
        Room temp;
        temp.setIndex(index);
        rooms.push_back(temp);
    }
    rooms[0] = Room(false, 0, player);
    rooms[1] = Room(false, 1, item1);
    rooms[2] = Room(false, 2, littleMonster);
    rooms[3] = Room(false, 3, npc);
    rooms[4] = Room(false, 4, item2);
    rooms[5] = Room(false, 5, boss);
    rooms[6] = Room(true, 6, prize);

    rooms[0].setUpRoom(&rooms[1]);
    rooms[1].setDownRoom(&rooms[0]);
    rooms[1].setUpRoom(&rooms[2]);
    rooms[2].setDownRoom(&rooms[1]);
    rooms[2].setRightRoom(&rooms[4]);
    rooms[2].setLeftRoom(&rooms[3]);
    rooms[4].setLeftRoom(&rooms[2]);
    rooms[3].setRightRoom(&rooms[2]);
    rooms[3].setUpRoom(&rooms[5]);
    rooms[5].setDownRoom(&rooms[3]);
    rooms[5].setLeftRoom(&rooms[6]);
    rooms[6].setRightRoom(&rooms[5]);
}

/* Deal with player's moveing action */
void Dungeon::handleMovement(){
    int selection;
    switch (player.getCurrentRoom()->getIndex()) {
        case 0:
            cout << endl;
            cout << "Which way do you wanna go?" << endl;
            cout << "1. go up 2. I'm leaving, save my progress" << endl;
            
            cin >> selection;
            
            if (selection == 1) {
                player.setPreviousRoom(&rooms[0]);
                player.setCurrentRoom(&rooms[1]);
                handleEvent(player.getCurrentRoom()->getObjects()[0]);
            }
            if (selection == 2) {
                Record record;
                record.saveToFile(&player, rooms);
                exit(0);
            }
            break;
        case 1:
            //handleEvent(player.getCurrentRoom()->getObjects()[0]);
            cout << endl;
            cout << "Which way do you wanna go?" << endl;
            //handleEvent(player.getCurrentRoom()->getObjects()[0]);
            cout << "1. go up 2. go down 3. I'm leaving, save my progress" << endl;
            cin >> selection;
            if (selection == 1) {
                player.setPreviousRoom(&rooms[1]);
                player.setCurrentRoom(&rooms[2]);
                handleEvent(player.getCurrentRoom()->getObjects()[0]);
            }
            if (selection == 2) {
                //player.setCurrentRoom(&rooms[0]);
                player.changeRoom(player.getCurrentRoom()->getDownRoom());
                //handleEvent(player.getCurrentRoom()->getObjects()[0]);
            }
            if (selection == 3) {
                Record record;
                record.saveToFile(&player, rooms);
                exit(0);
            }
            break;
        case 2:
            //handleEvent(player.getCurrentRoom()->getObjects()[0]);
            cout << endl;
            cout << "Which way do you wanna go?" << endl;
            //handleEvent(player.getCurrentRoom()->getObjects()[0]);
            cout << "1. go right 2. go left 3. go down 4. I'm leaving, save my progress" << endl;
            cin >> selection;
            if (selection == 1) {
                player.setPreviousRoom(&rooms[2]);
                player.setCurrentRoom(&rooms[4]);
                handleEvent(player.getCurrentRoom()->getObjects()[0]);
            }
            if (selection == 2) {
                player.setPreviousRoom(&rooms[2]);
                player.setCurrentRoom(&rooms[3]);
                handleEvent(player.getCurrentRoom()->getObjects()[0]);
            }
            if (selection == 3) {
                player.setPreviousRoom(&rooms[2]);
                player.setCurrentRoom(&rooms[1]);
                handleEvent(player.getCurrentRoom()->getObjects()[0]);
            }
            if (selection == 4) {
                Record record;
                record.saveToFile(&player, rooms);
                exit(0);
            }
            break;
        case 3:
            //handleEvent(player.getCurrentRoom()->getObjects()[0]);
            cout << endl;
            cout << "Which way do you wanna go?" << endl;
            //handleEvent(player.getCurrentRoom()->getObjects()[0]);
            cout << "1. go up 2. go right 3. I'm leaving, save my progress" << endl;
            cin >> selection;
            if (selection == 1) {
                player.setPreviousRoom(&rooms[3]);
                player.setCurrentRoom(&rooms[5]);
                handleEvent(player.getCurrentRoom()->getObjects()[0]);
            }
            if (selection == 2) {
                player.setPreviousRoom(&rooms[3]);
                player.setCurrentRoom(&rooms[2]);
                handleEvent(player.getCurrentRoom()->getObjects()[0]);
            }
            if (selection == 3) {
                Record record;
                record.saveToFile(&player, rooms);
                exit(0);
            }
            break;
        case 4:
            //handleEvent(player.getCurrentRoom()->getObjects()[0]);
            cout << endl;
            cout << "Which way do you wanna go?" << endl;
            cout << "1. go left 2. I'm leaving, save my progress" << endl;
            cin >> selection;
            if (selection == 1) {
                player.setPreviousRoom(&rooms[4]);
                player.setCurrentRoom(&rooms[2]);
                handleEvent(player.getCurrentRoom()->getObjects()[0]);
            }
            if (selection == 2) {
                Record record;
                record.saveToFile(&player, rooms);
                exit(0);
            }
            break;
        case 5:
            //handleEvent(player.getCurrentRoom()->getObjects()[0]);
            cout << endl;
            cout << "Which way do you wanna go?" << endl;
            cout << "1. go down 2. go left 3. I'm leaving, save my progress" << endl;
            cin >> selection;
            if (selection == 1) {
                player.setPreviousRoom(&rooms[5]);
                player.setCurrentRoom(&rooms[3]);
                handleEvent(player.getCurrentRoom()->getObjects()[0]);
            }
            if (selection == 2) {
                player.setPreviousRoom(&rooms[5]);
                player.setCurrentRoom(&rooms[6]);
                handleEvent(player.getCurrentRoom()->getObjects()[0]);
            }
            if (selection == 3) {
                Record record;
                record.saveToFile(&player, rooms);
                exit(0);
            }
            break;
        case 6:
            cout << endl;
            for (int i=0; i < player.getInventory().size(); i++) {
                if (player.getInventory()[i].getName() == "lifebuoy") {
                    cout << "The lifebuoy was a prize! You just came out of the closet!" << endl;
                    cout << "Congrats on winning! Let's go off board together!" << endl;
                    exit(0);
                }
                if (i == player.getInventory().size()-1) {
                    break;
                }
            }
            player.setPreviousRoom(&rooms[6]);
            player.setCurrentRoom(&rooms[5]);
            handleEvent(player.getCurrentRoom()->getObjects()[0]);
            
        default:
            break;
    }
}

/* Deal with player's iteraction with objects in that room */
void Dungeon::handleEvent(Object* objects){
    Item* item = dynamic_cast<Item*>(objects);
    Monster* monster = dynamic_cast<Monster*>(objects);
    NPC* npc = dynamic_cast<NPC*>(objects);
    if (item) {
        if (!item -> getTaken()) {
            item -> triggerEvent(&player);
        }
        else {
            cout << endl;
            cout << "Nothing here, you already took it!" << endl;
            return handleMovement();
        }
    }
    if (monster) {
        if (monster -> getCurrentHealth()<=0) {
            cout << endl;
            cout << "The Monster's already dead, you killed it, remember?" << endl;
            return handleMovement();
        }
        else
            monster -> triggerEvent(&player);
    }
    if (npc) {
        npc -> triggerEvent(&player);
    }
}

/* Deal with all game initial setting       */

/* Including create player, create map etc  */
void Dungeon::startGame(){
    int start;
    cout << "[THE SEASICK REHAB]" << endl;
    cout << "1. Read from previous data 2. Start a new game" << endl;
    cin >> start;
    if (start == 1) {
        cout << endl;
        cout << "Welcome back!" << endl;
        createMap();
        Record findRecord;
        findRecord.loadFromFile(&player, rooms);
    }
    else if (start == 2){
        cout << endl;
        cout << "Setting up..." << endl;
        createPlayer();
        createMap();
        player.setCurrentRoom(&rooms[0]);
    }
}

/* Deal with the player's action     */
/* including showing the action list that player can do at that room   */
/* and dealing with player's input   */
void Dungeon::chooseAction(vector<Object*> object){
        cout << endl;
        cout << "So what now?" << endl;
        cout << "A. Let's go to the next room." << endl;
        cout << "B. Check my status for me." << endl;
        cout << "C. Save to file, I'm leaving." << endl;
        char action;
        cin >> action;
        if (action == 'A' || action == 'a') {
            handleMovement();
        }
        else if (action == 'B' || action == 'b') {
            player.triggerEvent(&player);
        }
        else if (action == 'C' || action == 'c') {
            Record record;
            record.saveToFile(&player, rooms);
            exit(0);
        }
        else {
            cout << endl;
            cout << "Wrong input, dummy==" << endl;
        }
}

/* Check whether the game should end or not */
/* Including player victory, or he/she dead */
bool Dungeon::checkGameLogic(){
    if (player.getCurrentHealth() <= 0) {
        cout << endl;
        cout << "You just lost!" << endl;
        return true;
    }
    else{
        return false;
    }
}

/* Deal with the whole game process */
void Dungeon::runDungeon(){
    startGame();
    while (!checkGameLogic()) {
        chooseAction(player.getCurrentRoom()->getObjects());
    }
}
