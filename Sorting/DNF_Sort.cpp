#include <bits/stdc++.h>
using namespace std; 

/*
DNF (Dutch National Flag) Sort

Time Complexity: O(n)

*/

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void DNFsort(int arr[], int n){
    int low = 0, mid = 0, high = n-1;

    while (mid <= high){
        if(arr[mid] == 0){
            swap(arr, low, mid);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr, mid, high);
            high--;
        }
    }
}  

int main() {
    
    int n;
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++) cin>>arr[i];

    DNFsort(arr, n);

    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
    
    return 0;
}