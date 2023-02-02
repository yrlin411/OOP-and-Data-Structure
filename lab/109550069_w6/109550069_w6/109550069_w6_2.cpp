#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    int numOfQuery = 0;
    char step;
    int newElement, find;
    cin >> numOfQuery;
    for (int i=0; i<numOfQuery; i++) {
        cin >> step;
        if (step == 'a') {
            cin >> newElement;
            v.push_back(newElement);
        }
        if (step == 'e') {
            cin >> find;
            for (int i=0; i<v.size(); i++) {
                if (find == v[i]) {
                    v.erase(v.begin()+i);
                }
            }
        }
        if (step == 'r') {
            reverse(v.begin(), v.end());
        }
        if (step == 'd') {
            v.pop_back();
        }
        if (step == 's') {
            cout << v.size() << ' ';
        }
        if (step == 'p') {
            for (int i=0; i<v.size(); i++) {
                cout << v[i] << ' ';
            }
        }
    }
    
    return 0;
}
