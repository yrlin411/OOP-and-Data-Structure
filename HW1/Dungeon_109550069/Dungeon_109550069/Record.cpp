#include "Record.hpp"

/*constructor*/
Record::Record(){}

/*other functions*/
void Record::saveToFile(Player* player, vector<Room>& rooms){
    ofstream playerFile("playerRecord2.txt");
    ofstream roomsFile("roomsRecord2.txt");
    Record::savePlayer(player, playerFile);
    Record::saveRooms(rooms, roomsFile);
}

void Record::loadFromFile(Player* player, vector<Room>& rooms){
    ifstream playerFile("playerRecord2.txt");
    ifstream roomsFile("roomsRecord2.txt");
    //int roomIndex;
    //playerFile >> roomIndex;
    //player -> setCurrentRoom(&rooms[roomIndex]);
    Record::loadPlayer(player, playerFile);
    Record::loadRooms(rooms, roomsFile);
    player -> setCurrentRoom(&rooms[roomindex]);
}

void Record::savePlayer(Player* player, ofstream& playerFile){
    playerFile << player->getName() << endl;
    playerFile << player->getCurrentHealth() << endl;
    playerFile << player->getAttack() << endl;
    playerFile << player->getDefense() << endl;
    playerFile << player->getSavings() << endl;
    playerFile << player->getCurrentRoom()->getIndex() <<endl;
    if (!player->getInventory().empty()) {
        for (int i=0; i<player->getInventory().size(); i++) {
            playerFile << player->getInventory()[i].getName() << endl;
        }
    }
}

void Record::saveRooms(vector<Room>& rooms, ofstream& roomsFile){
    Monster* littleMonster = dynamic_cast<Monster*>(rooms[2].getObjects()[0]);
    Monster* boss = dynamic_cast<Monster*>(rooms[5].getObjects()[0]);
    roomsFile << littleMonster->getCurrentHealth() << endl;
    roomsFile << boss->getCurrentHealth() << endl;
}

void Record::loadPlayer(Player* player, ifstream& playerFile){
    string name;
    Room room;
    int currentHealth, attack, defense, savings;
    playerFile >> name;
    playerFile >> currentHealth;
    playerFile >> attack;
    playerFile >> defense;
    playerFile >> savings;
    playerFile >> roomindex;
    player -> setName(name);
    player -> setCurrentHealth(currentHealth);
    player -> setAttack(attack);
    player -> setDefense(defense);
    player -> setSavings(savings);
}

void Record::loadRooms(vector<Room>& rooms, ifstream& roomsFile){
    int littleMonsterCurrentHealth, bossCurrentHealth;
    roomsFile >> littleMonsterCurrentHealth;
    roomsFile >> bossCurrentHealth;
    Monster* littleMonster = dynamic_cast<Monster*>(rooms[2].getObjects()[0]);
    Monster* boss = dynamic_cast<Monster*>(rooms[5].getObjects()[0]);
    littleMonster -> setCurrentHealth(littleMonsterCurrentHealth);
    boss -> setCurrentHealth(bossCurrentHealth);
}

