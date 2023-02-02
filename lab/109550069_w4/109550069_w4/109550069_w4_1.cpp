#include <iostream>
using namespace std;

class Room{
public:
    Room *left_room=NULL;
    Room *right_room=NULL;
    int index;
    Room(int n){
        index = n;
    }
};

int main() {
    int roomnum;
    cin>>roomnum;
    int ind,mvmt;
    char step;

    
    Room *first,*cur;
    for(int i=0;i<roomnum;i++){
        cin>>ind;
        if(first==NULL){
            cur=new Room(ind);
            first=cur;
        }else{
            cur->right_room=new Room(ind);
            cur->right_room->left_room=cur;
            cur=cur->right_room;
        }
    }
    
    cur=first;
    cin>>mvmt;
    cout<<cur->index;
    getchar();
    for(int i=0;i<mvmt;i++){
        cin>>step;
        if(step=='r'){
            if(cur->right_room==NULL){
                cout<<" -1";
            }else{
                cur=cur->right_room;
                cout<<" "<<cur->index;
            }
        }else{
            if(cur->left_room==NULL){
                cout<<" -1";
            }else{
                cur=cur->left_room;
                cout<<" "<<cur->index;
            }
        }
    }
    return 0;
}
