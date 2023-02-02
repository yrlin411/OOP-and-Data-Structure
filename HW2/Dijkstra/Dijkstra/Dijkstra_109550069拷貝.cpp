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
    vector<pair<vertex*, int>> matrix; // <vertex, weight>
};

bool compare(vertex* left, vertex* right)
{
    return left->d > right->d;
}

class graph
{
public:
    int numVertex;
    vertex* v;
    graph(int m)
    {
        this->numVertex = m;
        this->v = new vertex[this->numVertex];
    }
    void dijkstra(graph* newGraph, int s, int t)
    {
        (newGraph->v + s)->d = 0;
        
        vector<vertex*> minheap;
        for (int i=0; i<numVertex; i++)
        {
            minheap.push_back(v+i);
        }
        while (minheap.empty() == false) {
            make_heap(minheap.begin(), minheap.end(), compare);
            pop_heap(minheap.begin(), minheap.end(), compare);
            vertex* minVertex = minheap.back();
            
            if (minVertex->matrix.empty() == true) {
                continue;
            }
            
            for (int i=0; i<minVertex->matrix.size(); i++) {
                pair<vertex*, int> next = minVertex->matrix[i];
                if(minVertex->d + next.second < next.first->d && minVertex->d!=INF)
                {
                    next.first->d = minVertex->d + next.second;
                }
            }
            minheap.pop_back();
        }
        cout << (newGraph->v + t)->d << endl;
    }
};

int main()
{
    int m=0, n=0, s=0, t=0;
    cin >> m;
    cin >> n;
    cin >> s;
    cin >> t;
    graph* newGraph = new graph(m);
    
    int a=0, b=0, c=0;
    for (int i=0; i<n; i++) {
        cin >> a;
        cin >> b;
        cin >> c;
        (newGraph->v + a)->matrix.push_back(make_pair(newGraph->v + b, c));
    }
    newGraph->dijkstra(newGraph, s, t);
    
    return 0;
}
