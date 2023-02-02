#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node{
public:
    int data;
    class node *left, *right, *parent;
    node* Insert(node*, int);
    void Insert(int);
    void print(node*);
    void print();
private:
    node* root;
};

node* node::Insert(node* newNode, int data){
    if (newNode == NULL) {
        newNode = new node;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;
    }
    else if (newNode->data < data){
        newNode->right = Insert(newNode->right, data);
        newNode->right->parent = newNode;
    }
    else if (newNode->data < data){
        newNode->left = Insert(newNode->left, data);
        newNode->left->parent = newNode;
    }
    return newNode;
}

void node::Insert(int data)
{
    root = Insert(root, data);
}

void node::print(node* node)
{
    if (node == NULL) {
        return;
    }
    print(node->left);
    print(node->right);
    cout << node->data << endl;
}

void node::print()
{
    print(root);
    cout << endl;
}

int main() {
    node* node1 = new node;
    int data;
    while(cin >> data) {
        node1->Insert(data);
    }
    node1->print();
    
    return 0;
}

