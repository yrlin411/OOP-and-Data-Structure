#include "npc.hpp"

/*constructor*/
NPC::NPC(): GameCharacter(){}
NPC::NPC(string name, string script, vector<Item*> commodity1, vector<Item*> commodity2, vector<Item*> commodity3, bool taken1, bool taken2, bool taken3): GameCharacter(name, "NPC", 0, 0, 0){
    setName(name);
    this -> script = script;
    this -> commodity1 = commodity1;
    this -> commodity2 = commodity2;
    this -> commodity3 = commodity3;
    this -> taken1 = taken1;
    this -> taken2 = taken2;
    this -> taken3 = taken3;
}

/*other functions*/
void NPC::listCommodity(){
    cout << endl;
    cout << "[Sailor's Shop]" << endl;
    cout << ">1." << commodity1[0]->getName() << endl;
    cout << ">2." << commodity2[0]->getName() << endl;
    cout << ">3." << commodity3[0]->getName() << endl;
    cout << "(4. No thanks.)" << endl;
}

bool NPC::triggerEvent(Object* object){
    Player* player = dynamic_cast<Player*>(object);
    cout << endl;
    cout << ":" << this -> getScript() << endl;
    cout << ":Seems like you need some help, huh?" << endl;
    cout << ":I've got somthing, which one do you need?" << endl;
    listCommodity();
    int ans=0, yesOrno=0;
    cin >> ans;
        if (ans == 1 && taken1 == false) {
            cout << endl;
            cout << "[" << commodity1[0]->getName() << "]" << endl;
            cout << "> Health: " << commodity1[0]->getHealth() << endl;
            cout << "> Attack: " << commodity1[0]->getAttack() << endl;
            cout << "> Defense: " << commodity1[0]->getDefense() << endl;
            cout << "> Price: " << commodity1[0]->getPrice() << endl;
            cout << "You sure you want this? 1.yes 2.no" << endl;
            cin >> yesOrno;
            if (yesOrno == 1 && player -> pay(commodity1[0]->getPrice())) {
                player -> addItem(*commodity1[0]);
                player -> increaseStates(commodity1[0]->getHealth(), commodity1[0]->getAttack(), commodity1[0]->getDefense());
                taken1 = true;
                cout << endl;
                cout << "Item get, Status increased." << endl;
                return true;
            }
            if (yesOrno == 2) {
                cout << endl;
                cout << "You'll regret it." << endl;
                return false;
            }
        }
    if (ans == 1 && taken1 == true) {
        cout << endl;
        cout << "You've bought this, buy somthing else!" << endl;
        cin >> ans;
        }
    if (ans == 2 && taken2 == false) {
        cout << endl;
        cout << "[" << commodity2[0]->getName() << "]" << endl;
        cout << "> Health: " << commodity2[0]->getHealth() << endl;
        cout << "> Attack: " << commodity2[0]->getAttack() << endl;
        cout << "> Defense: " << commodity2[0]->getDefense() << endl;
        cout << "> Price: " << commodity2[0]->getPrice() << endl;
        cout << "You sure you want this? 1.yes 2.no" << endl;
        cin >> yesOrno;
        if (yesOrno == 1 && player -> pay(commodity2[0]->getPrice())) {
            player -> addItem(*commodity2[0]);
            player -> increaseStates(commodity2[0]->getHealth(), commodity2[0]->getAttack(), commodity2[0]->getDefense());
            taken2 = true;
            cout << endl;
            cout << "Item get, Status increased." << endl;
            return true;
        }
        if (yesOrno == 2) {
            cout << endl;
            cout << "You'll regret it." << endl;
            return false;
        }
    }
    if (ans == 2 && taken2 == true) {
        cout << endl;
        cout << "You've bought this, buy somthing else!" << endl;
        cin >> ans;
        }
    if (ans == 3 && taken3 == false) {
        cout << endl;
        cout << "[" << commodity3[0]->getName() << "]" << endl;
        cout << "> Health: " << commodity3[0]->getHealth() << endl;
        cout << "> Attack: " << commodity3[0]->getAttack() << endl;
        cout << "> Defense: " << commodity3[0]->getDefense() << endl;
        cout << "> Price: " << commodity3[0]->getPrice() << endl;
        cout << "You sure you want this? 1.yes 2.no" << endl;
        cin >> yesOrno;
        if (yesOrno == 1 && player -> pay(commodity3[0]->getPrice())) {
            player -> addItem(*commodity3[0]);
            player -> increaseStates(commodity3[0]->getHealth(), commodity3[0]->getAttack(), commodity3[0]->getDefense());
            taken3 = true;
            cout << endl;
            cout << "Item get, Status increased." << endl;
            return true;
        }
        if (yesOrno == 2) {
            cout << endl;
            cout << "You'll regret it." << endl;
            return false;
        }
    }
    if (ans == 3 && taken3 == true) {
        cout << endl;
        cout << "You've bought this, buy somthing else!" << endl;
        cin >> ans;
        }
    if (taken1 == true && taken2 == true && taken3 == true) {
        cout << endl;
        cout << "You took everything now move your ass off." << endl;
        return false;
    }
    else {
        return false;
    }
    
    return false;
}

/*set&get*/
void NPC::setScript(string script){
    this -> script = script;
}

void NPC::setCommodity1(vector<Item*> commodity1){
    this -> commodity1 = commodity1;
}

void NPC::setCommodity2(vector<Item*> commodity2){
    this -> commodity2 = commodity2;
}

void NPC::setCommodity3(vector<Item*> commodity3){
    this -> commodity3 = commodity3;
}

string NPC::getScript(){
    return this -> script;
}

vector<Item*> NPC::getCommodity1(){
    return this -> commodity1;
}

vector<Item*> NPC::getCommodity2(){
    return this -> commodity2;
}

vector<Item*> NPC::getCommodity3(){
    return this -> commodity3;
}

bool NPC::getTaken1(){
    return this -> taken1;
}

bool NPC::getTaken2(){
    return this -> taken2;
}

bool NPC::getTaken3(){
    return this -> taken3;
}
