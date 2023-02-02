#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define LN(i) (i<<1)
#define RN(i) ((i<<1)|1)
#define UN(i) (i>>1)

int a[100005]; //the min will be on the top
int cnt;

void swap(int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void bubbleUp(int i)
{
    if ((i!=1)&&(a[UN(i)]>=a[i]))//not the root && bigger than its father
    {
        swap(UN(i), i);
        bubbleUp(UN(i));
    }
    return;
}

void bubbleDown(int i)
{
    if (LN(i) < cnt) {
        if (RN(i) < cnt) {
            if ((a[LN(i)]<=a[RN(i)])&&(a[LN(i)]<=a[i]))
            {
                swap(LN(i), i);
                bubbleDown(LN(i));
            }
            else if ((a[RN(i)]<=a[LN(i)])&&(a[RN(i)]<=a[i]))
            {
                swap(RN(i), i);
                bubbleDown(RN(i));
            }
        }
        else
        {
            if (a[LN(i)]<a[i]) {
                swap(LN(i), i);
            }
        }
    }
    return;
}

int main() {
    int hm;
    while(cin >> hm)
    {
        if (hm==0) {
            break;
        }
        
        for (int i=1; i<=hm; i++) {
            int n;
            cin>>n;
            a[i]=n;
            bubbleUp(i);
        }
        
        int tmp = 0;
        int sum = 0;
        for (cnt = hm; cnt>=1; cnt--) {
            if (cnt == 1) {
                cout << sum << endl;
                break;
            }
            tmp = a[1];
            a[1] = a[cnt];
            bubbleDown(1);
            
            tmp += a[1];
            a[1] = a[cnt-1];
            bubbleDown(1);
            
            a[cnt-1] = tmp;
            bubbleUp(cnt-1);
            
            sum += tmp;
        }
    }
    
    return 0;
}

