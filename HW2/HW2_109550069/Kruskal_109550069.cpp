#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int length;
    int start;
    int end;
};

int parent[1000];
int child[1000];

bool compare(const Edge left, const Edge right)
{
    return left.length < right.length;
}

int findParent(int a)
{
    if (a==parent[a]) {
        return a;
    }
    else return findParent(parent[a]);
}

bool checkCycle(int a, int b)
{
    int root1=0, root2=0;
    root1 = findParent(a);
    root2 = findParent(b);
    
    if (root1 == root2) {
        return false;
    }
    else {
        if (child[root1] >= child[root2])
        {
        parent[root2] = root1;
        child[root1] += root2;
        }
        else
        {
        parent[root1] = root2;
        child[root2] += root1;
        }
    }
    return true;
}

void kruskal(vector<vector<int>> matrix, int n, int m)
{
    int totalCost = 0;
    Edge Edges[n];
    bool visited[m];
    for (int i=0; i<m; i++) {
        visited[i] = false;
    }
    int k=0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            while (matrix[i][j] != 0 && k<n) {
                Edges[k].length = matrix[i][j];
                Edges[k].start = i;
                Edges[k].end = j;
                k++;
                break;
                }
        }
    }
    sort(Edges, Edges+n, compare);
    
    for (int i=0; i<m; i++) {
        parent[i] = i;
        child[i] = 0;
    }
    for (int i=0; i<n; i++) {
        if (checkCycle(Edges[i].start, Edges[i].end)) {
            totalCost += Edges[i].length;
        }
    }
    
    cout << totalCost << endl;
    
}

int main() {
    
    int n=0, m=0;
    cin >> m; // vertices
    cin >> n; // edges
    
    vector<vector<int>> matrix;
    matrix.resize(m);
    for (int i=0; i<m; i++) {
        matrix[i].resize(m);
    }
    
    for (int i=0; i<n; i++) {
        int a=0, b=0;
        cin >> a; // start
        cin >> b; // end
        int c=0;
        cin >> c;
        matrix[a][b] = c; // edge
    }
    
    kruskal(matrix, n, m);
    
    return 0;
}

