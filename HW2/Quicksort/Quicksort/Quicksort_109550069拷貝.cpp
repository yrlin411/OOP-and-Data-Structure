#include <ctime>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

void quickSort(int* arr, int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex) {
        int leftSearch = leftIndex;
        int rightSearch = rightIndex + 1;
        int pivot = arr[leftIndex];
        do {
            do leftSearch++; while(arr[leftSearch] < pivot);
            do rightSearch--; while(arr[rightSearch] > pivot);
            if (leftSearch < rightSearch) {
                swap(arr[leftSearch], arr[rightSearch]);
            }
        } while (leftSearch < rightSearch);
        swap(arr[leftIndex], arr[rightSearch]);
        
        quickSort(arr, leftIndex, rightSearch-1);
        quickSort(arr, rightSearch+1, rightIndex);
    }
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
        
        quickSort(arr, 0, N-1);
        
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


