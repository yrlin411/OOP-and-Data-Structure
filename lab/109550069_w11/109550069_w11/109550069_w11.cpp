#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,num,probe1,probe2,r;
    int lin[19]={0},qua[19]={0};
    cin >> n;
    
    for(int i=0;i<n;i++){
        
        cin >> num;
        r = num % 19;
        
        probe1 = 0;
        while(1){
            if(r+probe1>18){
                r = (r+probe1)%19;
                probe1 = 0;
            }
            
            if(lin[r+probe1]!=0){
                probe1++;
            }
            else{
                lin[r+probe1] = num;
                break;
            }
        }
        
        r = num % 19;
        probe2 = 0;
        while(1){
            if(r+probe2*probe2>18){
                r = (r+probe2*probe2)%19;
                probe2 = 0;
            }
            
            if(qua[r+probe2*probe2]!=0){
                probe2++;
            }
            else{
                qua[r+probe2*probe2] = num;
                break;
            }
        }
    }
    
    for(int i=0;i<19;i++){
        cout << lin[i] << " ";
    }
        
    cout << endl;
        
    for(int i=0;i<19;i++){
        cout << qua[i] << " ";
    }
    
    return 0;
}

