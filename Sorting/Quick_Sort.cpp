#include <bits/stdc++.h>
using namespace std;  

/*
Time Complexity:
Best Case = 0(n log n)
Worst Case = O(n^2)
*/

void swap( int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];  //taking last element as pivot
    int i = l - 1;

    for (int j = l; j < r; j++){
        if( arr[j] < pivot){
            i++;
            swap( arr, i, j);
        }
    }
    swap( arr, i + 1, r);
    return i + 1;  
}

int n;

void quicksort(int arr[], int l, int r)
{
    if ( l < r ){
        int pivot = partition( arr, l, r );

        for (int i = 0; i < n; i++)  cout<<arr[i]<<" ";   // to print after every pass
        cout<<endl;

        quicksort(arr, l, pivot - 1);
        quicksort(arr, pivot + 1, r);
        
    }
}

int main()
{
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++)  cin>>arr[i];
    
    quicksort(arr, 0, n-1);

    for (int i = 0; i < n; i++)  cout<<arr[i]<<" ";
    
    return 0;
}