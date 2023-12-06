#include <bits/stdc++.h>
using namespace std; 

/*
Sort array elements like a wave

Given an array, transform the array such that
arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= .....

Time Complexity: O(N)
Space Complexity: O(1)

*/

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void wavesort(int arr[], int n)
{
    for(int i = 1; i < n-1; i+=2){
        if( arr[i] > arr[i-1] )
            swap(arr, i, i-1);

        if( arr[i] > arr[i+1] && i<=n-2)
            swap(arr, i, i+1);
    }
}  

int main() {
    
    int n;
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++) cin>>arr[i];

    wavesort(arr, n);

    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
    
    return 0;
}