#include "item.hpp"

/*constructor*/
Item::Item(): Object(){}
Item::Item(string name, int health, int attack, int defense, int price, int index, bool taken): Object(name, "Item"){
    this -> health = health;
    this -> attack = attack;
    this -> defense = defense;
    this -> price = price;
    this -> index = index;
    this -> taken = taken;
}

/*other functions*/
bool Item::triggerEvent(Object* item){
    Player* player = dynamic_cast<Player*>(item);
    cout << endl;
    cout << "Look! We found something!" << endl;
    cout << "Do you want " << this -> getName() << "?" << endl;
    cout << "[" << this -> getName() << "]" << endl;
    cout << "> Health: " << this -> getHealth() << endl;
    cout << "> Attack: " << this -> getAttack() << endl;
    cout << "> Defense: " << this -> getDefense() << endl;
    cout << "1. Sure, since it's for free." << endl;
    cout << "2. No they look terrible." << endl;
    int ans=0 ;
    cin >> ans;
    if (ans == 1) {
        player -> addItem(*this);
        player -> increaseStates(this -> getHealth(), this -> getAttack(), this -> getDefense());
        taken = true;
        cout << endl;
        cout << "God this is heavy." << endl;
        return true;
    }
    else {
        cout << endl;
        cout << "Fine." << endl;
        taken = false;
        return false;
    }
}

/*set&get*/
int Item::getHealth(){
    return this -> health;
}

int Item::getAttack(){
    return this -> attack;
}

int Item::getDefense(){
    return this -> defense;
}

int Item::getPrice(){
    return this -> price;
}

int Item::getIndex(){
    return this -> index;
}

bool Item::getTaken(){
    return this -> taken;
}

void Item::setHealth(int health){
    this -> health = health;
}

void Item::setAttack(int attack){
    this -> attack = attack;
}

void Item::setDefense(int defense){
    this -> defense = defense;
}

void Item::setPrice(int price){
    this -> price = price;
}

void Item::setIndex(int index){
    this -> index = index;
}
