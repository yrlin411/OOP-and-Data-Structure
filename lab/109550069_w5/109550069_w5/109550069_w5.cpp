#include <vector>
#include <iostream>
using namespace std;

class Object{
public:
    virtual void response() = 0;
    
    virtual ~Object() = default;
};

class IceMonster : public Object{
public:
    int been;
    IceMonster(){
        been = 0;
    }
    void response(){
        if (been == 0) {
            cout << "fire attack" << endl;
        }
        else cout << endl;
        been = 1;
    }
};

class FireMonster : public Object{
public:
    int been;
    FireMonster(){
        been = 0;
    }
    void response(){
        if (been == 0) {
            cout << "ice attack" << endl;
        }
        else cout << endl;
        been = 1;
    }
};

class Treasure : public Object{
public:
    int been;
    Treasure(){
        been = 0;
    }
    void response(){
        if (been == 0) {
            cout << "ya" << endl;
        }
        else cout << endl;
        been = 1;
    }
};


class Room{
public:
    Room *up_room ;
    Room *down_room ;
    Room *left_room ;
    Room *right_room ;
    int index;
    Object *o;
    Room(){
        up_room = NULL;
        down_room=NULL;
        left_room=NULL;
        right_room=NULL;
        index = 0;
    }
};

int main() {
    int roomNum;
    int stepNum;
    cin >> roomNum;
    cin >> stepNum;
    char type = '\0';
    int upNeighbor, downNeighbor, leftNeighbor, rightNeighbor;
    
    Room theRoom[10];
    for (int i=0; i<roomNum; i++) {
        cin >> type;
        if (type =='t') {
            theRoom[i].o = new Treasure();
        }
        else if (type =='f'){
            theRoom[i].o = new FireMonster();
        }
        else if (type =='i'){
            theRoom[i].o = new IceMonster();
        }
        else if (type == 'e'){
            theRoom[i].o = NULL;
        }
        
        theRoom[i].index = i;
        cin >> upNeighbor;
        if (upNeighbor == -1) {
            theRoom[i].up_room = NULL;
        }
        else theRoom[i].up_room = &theRoom[upNeighbor];
            
        cin >> downNeighbor;
        if (downNeighbor == -1) {
            theRoom[i].down_room = NULL;
        }
        else theRoom[i].down_room = &theRoom[downNeighbor];
        
        cin >> leftNeighbor;
        if (leftNeighbor == -1) {
            theRoom[i].left_room = NULL;
        }
        else theRoom[i].left_room = &theRoom[leftNeighbor];
        
        cin >> rightNeighbor;
        if (rightNeighbor == -1) {
            theRoom[i].right_room = NULL;
        }
        else theRoom[i].right_room = &theRoom[rightNeighbor];
    }
    
    Room *currentRoom = &theRoom[0];
    cout << 0 << endl;
    
    char mvmt;
    for (int i=0; i<stepNum; i++) {
        
        cin>>mvmt;
        Room *nextRoom = nullptr;
        if (mvmt=='r') {
            nextRoom = currentRoom->right_room;
        }
        if (mvmt=='l') {
            nextRoom = currentRoom->left_room;
        }
        if (mvmt=='u') {
            nextRoom = currentRoom->up_room;
        }
        if (mvmt=='d') {
            nextRoom = currentRoom->down_room;
        }
        if (nextRoom == NULL) {
            cout << "-1\n";
        }
        else{
            currentRoom = nextRoom;
            cout << currentRoom->index << " ";
            if (currentRoom->o == NULL) {
                cout<<endl;
            }
            else{
                currentRoom->o->response();
            }
        }
    }
    
    return 0;
}
