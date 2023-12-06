#include <bits/stdc++.h>
using namespace std;  

//Time Complexity = O(n log n)
//Space Complexity = O(n)

void merge( int arr[], int l, int mid, int r)
{
    int sizeA = (mid - l + 1);
    int sizeB = (r - mid);

    int A[sizeA], B[sizeB];  //temp arrays

    for (int i = 0; i < sizeA; i++){
        A[i] = arr[l + i];
    }
    for (int i = 0; i < sizeB; i++){
        B[i] = arr[mid + 1 + i];
    }
    int ptrA = 0;
    int ptrB = 0;
    int ptrC = l;

    while ( ptrA < sizeA && ptrB < sizeB ){
        if( A[ptrA] < B[ptrB] ){
            arr[ptrC] = A[ptrA];
            ptrC++;   ptrA++;  
        }
        else{
            arr[ptrC] = B[ptrB];
            ptrC++;   ptrB++; 
        }
    }

    while ( ptrA < sizeA ){
        arr[ptrC] = A[ptrA];
        ptrC++;   ptrA++;  
    }

    while ( ptrB < sizeB ){
        arr[ptrC] = B[ptrB];
        ptrC++;   ptrB++;  
    }
}

int n;

void mergeSort( int arr[], int l, int r)
{
    if (l < r) {
        int mid = (l+r)/2 ;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        for (int i = 0; i < n; i++)  cout<<arr[i]<<" ";   // to print after every pass
        cout<<endl;

        merge(arr, l, mid, r);
    }
}

int main()
{
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++) cin>>arr[i];  

    mergeSort(arr, 0, n-1);

    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";

    return 0;
}