#include <bits/stdc++.h>
using namespace std; 

/*
Time Complexity: O(max( Ai, N))   , Ai = max element of arr
*/
void countsort(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++){
        if(arr[i] > mx)
            mx = arr[i];
    }

    int countarr[mx + 1] = {0};

    for (int i = 0; i < n; i++){
        countarr[arr[i]]++;
    }

    for (int i = 1; i <= mx; i++){
        countarr[i]+=countarr[i-1];
    }

    int result[n];

    for (int i = n-1; i >= 0; i--){
        int index = --countarr[arr[i]];
        result[index] = arr[i];
    }

    for (int i = 0; i < n; i++) 
        arr[i] = result[i];    
}

int main() {
    
    int n;
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++) cin>>arr[i];

    countsort(arr, n);

    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
    
    return 0;
}