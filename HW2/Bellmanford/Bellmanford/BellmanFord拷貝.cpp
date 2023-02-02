#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define INF 100000000
 
using namespace std;

class vertex
{
public:
    int d = INF; // set the distances to infintiy
};

class edge
{
public:
    vertex* start;
    vertex* end;
    int weight;
};

class graph
{
public:
    int numVertex, numEdge;
    vertex* v;
    edge* e;
    graph(int m, int n)
    {
        this->numVertex = m;
        this->numEdge = n;
        this->v = new vertex[this->numVertex];
        this->e = new edge[this->numEdge];
    }
    void bellmanFord(graph* newGraph, int s, int t)
    {
        (newGraph->v + s)->d = 0;
        
        for (int i=0; i<(numVertex-1); i++) {
            for (int j=0; j<(newGraph->numEdge); j++) {
                edge* current = (newGraph->e + j); // current edge
                if (current->start->d + current->weight < current->end->d && current->start->d!=INF) {
                    current->end->d = current->start->d + current->weight;
                }
            }
        }
        
        bool negativeLoop = false;
        for (int i=0; i<numEdge; i++) {
            edge* check = (newGraph->e + i); // check current edge
            if (check->start->d + check->weight < check->end->d && check->start->d!=INF) {
                negativeLoop = true;
                break;
            }
        }
        
        if (negativeLoop == true) {
            cout << "Negative loop detected!" << endl;
        }
        else cout << (newGraph->v + t)->d <<endl;
    }
};

int main()
{
    int m = 0 ,n = 0, s = 0, t = 0;
    cin >> m;
    cin >> n;
    cin >> s;
    cin >> t;
    
    graph* newGraph = new graph(m, n);
    int a=0, b=0, c=0;
    for (int i=0; i<n; i++) {
        cin >> a;
        cin >> b;
        cin >> c;
        (newGraph->e + i)->start = (newGraph->v + a);
        (newGraph->e + i)->end = (newGraph->v + b);
        (newGraph->e + i)->weight = c;
    }
    newGraph->bellmanFord(newGraph, s, t);
    
    return 0;
}
