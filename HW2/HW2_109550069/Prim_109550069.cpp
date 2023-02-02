#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define kav pair<int, int> // key and vertex
using namespace std;

class graph
{
private:
    int m;
    vector<kav> *matrix;
public:
    graph(int vertexNum)
    {
        this->m = vertexNum;
        matrix = new vector<kav>[vertexNum];
    }
    void edge(int start, int end, int length)
    {
        matrix[start].push_back(make_pair(end, length));
        matrix[end].push_back(make_pair(start, length));
    }
    void prim()
    {
        int inEdge[m];
        bool visited[m];
        for (int i=0; i<m; i++) {
            visited[i] = false;
            inEdge[i] = 200001;
        }
        int start=0;
        priority_queue<kav,vector<kav>,greater<kav>> queue;
        queue.push(make_pair(0, start));
        inEdge[start] = 0;
        
        while (queue.empty()!=true) {
            int current = queue.top().second;
            queue.pop();
            
            if (visited[current]==true) {
                continue;
            }
            visited[current] = true;
            vector<kav>::iterator next;
            
            for (next = matrix[current].begin(); next != matrix[current].end(); ++next) {
                int vertex = (*next).first;
                int weight = (*next).second;
                
                if (visited[vertex]==false && weight < inEdge[vertex]) {
                    inEdge[vertex] = weight;
                    queue.push(make_pair(inEdge[vertex], vertex));
                }
            }
        }
        int totalCost = 0;
        for (int i=0; i<m; i++) {
            totalCost += inEdge[i];
        }
        cout << totalCost << endl;
    }
};



int main() {
    
    int n=0, m=0;
    cin >> m; // nodes
    cin >> n; // edges
    
    graph newGraph(m);
    for (int i=0; i<n; i++) {
        int a=0, b=0;
        cin >> a; // start
        cin >> b; // end
        int c=0;
        cin >> c;
        newGraph.edge(a, b, c);
    }
    newGraph.prim();
    
    return 0;
}

