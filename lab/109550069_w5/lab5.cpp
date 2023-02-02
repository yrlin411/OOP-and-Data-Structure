#include <vector>
#include <iostream>
using namespace std;

class Object{
public:
    virtual void response() = 0;
    
    virtual ~Object() = default;
};

class IceMonster : public Object{
    //add constructor or functions if you need
public: 
    int been;
    IceMonster(){
        been=0;
    }
    void response(){
        if(been==0) cout<<"fire attack\n";
        else cout<<endl;
        been=1;
    }
};

class FireMonster : public Object{
    //add constructor or functions if you need
public:
    int been;
    FireMonster(){
        been=0;
    }
    void response(){
        if(been==0) cout<<"ice attack\n";
        else cout<<endl;
        been=1;
    }
};

class Treasure : public Object{
    //add constructor or functions if you need
public:
    int been;
    Treasure(){
        been=0;
    }
    void response(){
        if(been==0) cout<<"ya\n";
        else cout << endl;
        been=1;
    }
};


class Room{
public:
    Room *up_room;
    Room *down_room;
    Room *left_room;
    Room *right_room;
    int index;
    Object *o;

    Room(){
        up_room=NULL;
        down_room=NULL;
        left_room=NULL;
        right_room=NULL;
        index=0;
    }
    //add constructor or functions if you need
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int room,step;
    cin>>room>>step;
    
    char rkind;
    int u,d,l,r;
    char mvmt;

    Room rooms[10];
    for(int i=0;i<room;i++){
        cin>>rkind;
        cin>>u>>d>>l>>r;

        rooms[i].index=i;
        if(u!=-1){
            rooms[i].up_room = &rooms[u];
        }
        if(d!=-1){
            rooms[i].down_room = &rooms[d];
        }
        if(l!=-1){
            rooms[i].left_room = &rooms[l];
        }
        if(r!=-1){
            rooms[i].right_room = &rooms[r];
        }

        if(rkind=='e')rooms[i].o = NULL;
        else if(rkind=='i')rooms[i].o = new IceMonster();
        else if(rkind=='f')rooms[i].o = new FireMonster();
        else if(rkind=='t')rooms[i].o = new Treasure();
    

    }
    Room *cur = &rooms[0];
    
    cout<<0<<endl;

    for(int i=0;i<step;i++){
        
        cin>>mvmt;
        Room *next;
        if(mvmt=='u') next=cur->up_room;
        if(mvmt=='d') next=cur->down_room;
        if(mvmt=='l') next=cur->left_room;
        if(mvmt=='r') next=cur->right_room;

        if(next==NULL) cout<<"-1\n";
        else{
            cur=next;
            cout<<cur->index<<" ";
            if(cur->o == NULL) cout<<endl;
            else{
                cur->o->response();
            }
            
        }


    }

    return 0;
}