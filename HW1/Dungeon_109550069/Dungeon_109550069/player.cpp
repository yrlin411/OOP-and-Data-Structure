#include "player.hpp"

/*constructor*/
Player::Player(): GameCharacter(){}
Player::Player(string name, int currentHealth, int attack, int defense, int savings): GameCharacter(name, "Player", currentHealth, attack, defense){
    setName(name);
    setCurrentHealth(currentHealth);
    setAttack(attack);
    setDefense(defense);
    setSavings(savings);
}

/*other functions*/
void Player::addItem(Item newItem){
    inventory.push_back(newItem);
}

void Player::increaseStates(int addHealth, int addAttack, int addDefense){
    int totalHealth = getCurrentHealth() + addHealth;
    int totalAttack = getAttack() + addAttack;
    int totalDefense = getDefense() + addDefense;
    setCurrentHealth(totalHealth);
    setAttack(totalAttack);
    setDefense(totalDefense);
}

bool Player::pay(int price){
    int totalSavings = getSavings() - price;
    if (totalSavings >= 0) {
        setSavings(totalSavings);
        return true;
    }
    else {
        cout << "You are broke. Stop buying." << endl;
        return false;
    }
}

void Player::changeRoom(Room* nextRoom){
    this -> previousRoom = currentRoom;
    this -> currentRoom = nextRoom;
}

bool Player::triggerEvent(Object* object){
    cout << endl;
    cout << "Showing your status:" << endl;
    cout << "[" << this -> getName() << "]" << endl;
    cout << "> Health: " << this -> getCurrentHealth() << endl;
    cout << "> Attack: " << this -> getAttack() << endl;
    cout << "> Defense: " << this -> getDefense() << endl;
    cout << "> Room: " << this -> getCurrentRoom()->getIndex() << endl;
    cout << "> Savings: " << this -> getSavings() << endl;
    return true;
}

/*set&get*/
void Player::setCurrentRoom(Room* currentRoom){
    this -> currentRoom = currentRoom;
}

void Player::setPreviousRoom(Room* previousRoom){
    this -> previousRoom = previousRoom;
}

void Player::setInventory(vector<Item> inventory){
    this -> inventory = inventory;
}

void Player::setSavings(int savings){
    this -> savings = savings;
}

Room* Player::getCurrentRoom(){
    return this -> currentRoom;
}

Room* Player::getPreviousRoom(){
    return this -> previousRoom;
}

vector<Item> Player::getInventory(){
    return this -> inventory;
}

int Player::getSavings(){
    return this -> savings;
}
