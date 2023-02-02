#include "monster.hpp"

/*constructor*/
Monster::Monster(): GameCharacter(){}
Monster::Monster(string name, int currentHealth, int attack, int defense): GameCharacter(name, "Monster", currentHealth, attack, defense){
    setName(name);
    setCurrentHealth(currentHealth);
    setAttack(attack);
    setDefense(defense);
}

/*other functions*/
bool Monster::triggerEvent(Object* object){
    Player* player = dynamic_cast<Player*>(object);
    cout << endl;
    cout << "Oops, seems like we've found a monster!" << endl;
    cout << "Do you want to fight with " << this->getName() << "?" << endl;
    cout << "1. Check our status first." << endl;
    cout << "2. Sure, who pop who." << endl;
    cout << "3. uhhhhhahhhhhhhh nooooooooo." << endl;
    int ans=0, ansAgain=0;
    cin >> ans;
    if (ans == 1) {
        cout << endl;
        cout << "[" << this->getName() << "]" << endl;
        cout << "> Health: " << this->getCurrentHealth() << endl;
        cout << "> Attack: " << this->getAttack() << endl;
        cout << "> Defense: " << this->getDefense() << endl;
        cout << "[" << player->getName() << "]" << endl;
        cout << "> Health: " << player->getCurrentHealth() << endl;
        cout << "> Attack: " << player->getAttack() << endl;
        cout << "> Defense: " << player->getDefense() << endl;
        cout << "So do you want to fight with it or not ==" << endl;
        cout << "1. Fine but you owe me one." << endl;
        cout << "2. No I hate you, leave me alone." << endl;
        cin >> ansAgain;
    }
    if(ans == 2 || ansAgain == 1){
        while (this->getCurrentHealth()>0 && player->getCurrentHealth()>0) {
            this -> setCurrentHealth(takeDamage(player -> getAttack()));
            if (this -> getCurrentHealth() <= 0) {
                break;
            }
            player -> setCurrentHealth(takeDamage(this -> getAttack()));
            if (player -> getCurrentHealth() <= 0) {
                break;
            }
        }
        if (this->getCurrentHealth()>0) {
            cout << endl;
            cout << "(A few moments later...)" << endl;
            cout << "Ha, loser." << endl;
            exit(0);
        }
        else if (player->getCurrentHealth()>0){
            cout << endl;
            cout << "(A few moments later...)" << endl;
            cout << "Woah, can't believe you just won." << endl;
            return true;
        }
    }
    if(ans == 3 || ansAgain == 2){
        player->setCurrentRoom(player->getPreviousRoom());
    }
    return false;
}
