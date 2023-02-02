#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    int graph[n][n];
    int visited[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            cin >> num;
            graph[i][j] = num;
        }
        visited[i] = i;
    }
    
    stack<int> stack;
    for(int i=0;i<n;i++){
        if(visited[i] == -1){
            continue;
        }
        if(stack.empty()){
            stack.push(i);
        }
        while(!stack.empty()){
            int p;
            p = stack.top();
            stack.pop();
            if(visited[p]!=-1){
                cout << p << " ";
                visited[p] = -1;
                for(int j=n-1;j>=0;j--){
                    if(graph[p][j]==1){
                        stack.push(j);
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}

