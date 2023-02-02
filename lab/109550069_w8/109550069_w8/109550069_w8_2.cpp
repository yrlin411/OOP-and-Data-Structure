#include <iostream>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    queue<int> buffer;
    int num, time;
    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> time;
        buffer.push(time);
        while(!buffer.empty() && buffer.front() < time - 5000){
            buffer.pop();
        }
        cout << buffer.size() << " ";
    }
    return 0;
}
