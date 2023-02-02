#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node
{
public:
    node *left, *right;
    int val;
    node(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    node* root;
    int size;
    BST()
    {
        size = 0;
        root = NULL;
    }
    
    void insert(int);
    void traverse(node*);
};

void BST::insert(int n){
    if (size == 0)//set the first node as the root
    {
        root = new node(n);
        size++; //not the first node anymore
        return;
    }
    node* now = root;//start from the root
    while (1) {
        if (n > (now->val))//goes to the right
        {
            if (now->right == NULL)
            {
                now->right = new node(n);//set the right node
                break;
            }
            else now = now->right;//keep searching the right
        }
        else // left
        {
            if (now->left == NULL)
            {
                now->left = new node(n);//set the left node
                break;
            }
            else now = now->left;//keep searching the left
        }
        size++;
        return;
    }
}

void BST::traverse(node* n)
{
    if (n == NULL) {
        return;
    }
    traverse(n->left);
    traverse(n->right);
    cout << n->val << endl;
}

int main() {
    BST tree;
    int data;
    while (cin >> data) {
        tree.insert(data);
    }
    tree.traverse(tree.root);//start from the root
    return 0;
}
