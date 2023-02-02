#include <ctime>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

void merge(int* arr, int left, int mid, int right)
{
    int indexL = mid - left + 1, indexR = right - mid;
    int tmpArrL[500] = {0}, tmpArrR[500] = {0};

    for (int i=0; i<indexL; i++) {
        tmpArrL[i] = arr[left+i];
    }
    for (int j=0; j<indexR; j++) {
        tmpArrR[j] = arr[mid+1+j];
    }
    int i=0, j=0, k=0;
    for (k=left; k<=right; k++) {
        if(i < indexL && j < indexR)
        {
        if (tmpArrL[i] <= tmpArrR[j]) {
            arr[k] = tmpArrL[i++];
        }
        else arr[k] = tmpArrR[j++];
        }
        else break;
    }
    while(i < indexL)
    {
        arr[k] = tmpArrL[i++];
        k++;
    }
    while(j < indexR)
    {
        arr[k] = tmpArrR[j++];
        k++;
    }
}

void mergeSort(int* arr, int left, int right)
{
    int mid = 0;
    if (right > left) {
        mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
    else return;
}
double execute(void)
{
    clock_t start, end;
    start = clock();
    
    int N;
    while (cin >> N)
    {
        if (N == 0) {
            break;
        }
        
        int arr[1000] = {0};
        for(int i=0; i<N; i++){
            cin >> arr[i];
        }
        
        mergeSort(arr, 0, N-1);
        
        for (int i=0; i<N; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    end = clock();
    double timeUsed = (double)end - (double)start;

    return timeUsed;
}

int main() {
    
    double thisRound = execute();
    
    cout << "Time: " << thisRound/CLOCKS_PER_SEC << endl;
    
    return 0;
}


