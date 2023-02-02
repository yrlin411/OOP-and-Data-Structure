#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
};

class LinkedList {
public:
    Node *root;
    int len;
    LinkedList() : root(nullptr), len(0) {}
    void push(int);
    void insert(int, int);
    int find(int);
    void remove(int);
    void print();
};

void LinkedList::push(int x){
    Node *n = new Node;
    n->val = x;
    if(len == 0){
        root = n;
    }
    else{
        Node *head = root;
        for(int i = 0; i < len - 1; i++){
            head = head->next;
        }
        head->next = n;
    }
    len++;
}

void LinkedList::insert(int pos, int x){
    Node *n = new Node;
    n->val = x;
    
    if( pos > len ){
        cout << "insert fail" << endl;
    }
    else{
        if(pos == 0){
            n->next = root;
            root = n;
        }
    
        else{
            Node *head = root;
            for(int i = 0; i < pos - 1; i++){
                head = head->next;
            }
            n->next = head->next;
            head->next = n;
            
        }
        len++;
    }
    
}

int LinkedList::find(int x){
    
    Node *head = root;
    
    for(int i = 0; i < len ; i++){
        
        if( (head->val) == x){
            return i;
        }
        if(head->next != NULL){
        head = head->next;
        }
    }
    
    return -1;
}

void LinkedList::remove(int pos){
    
    
    if( pos > len - 1){
        cout << "remove fail" << endl;
    }
    else{
        if(pos == 0){
            root = root->next;
            
        }

        else{
            Node *head = root;
            for(int i = 0; i < pos - 1; i++){
                head = head->next;
            }
            head->next = head->next->next;
            
        }
        len--;
    }
}

void LinkedList::print(){
    if(root == nullptr)
        return;

    Node *cur = root;
    while(cur->next != nullptr){
        cout << cur->val << ", ";
        cur = cur->next;
    }
    cout << cur->val << endl;
}

int main(){
    LinkedList mylist;
    
    int n, a, b;
    cin >> n;
    char c;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == 'p'){
            cin >> a;
            mylist.push(a);
        }else if(c == 'i'){
            cin >> a >> b;
            mylist.insert(a, b);
        }else if(c == 'r'){
            cin >> a;
            mylist.remove(a);
        }else if(c == 'f'){
            cin >> a;
            cout << mylist.find(a) << endl;
        }else if(c == '?'){
            mylist.print();
        }
    }
    return 0;
}
