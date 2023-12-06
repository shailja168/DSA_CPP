#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll merge(int arr[], int l, int mid, int r)
{
    ll inv = 0;

    int sizea = mid - l + 1;
    int sizeb = r - mid;

    int a[sizea], b[sizeb];

    for (int i = 0; i < sizea; i++)
        a[i] = arr[l + i];
    
    for (int i = 0; i < sizeb; i++)
        b[i] = arr[mid + 1 + i];
    
    int ptra = 0, ptrb = 0, ptrc = l;

    while( ptra < sizea && ptrb < sizeb){
        if(a[ptra] <= b[ptrb]){
            arr[ptrc] = a[ptra];
            ptra++; ptrc++;
        }
        else{
            arr[ptrc] = b[ptrb];
            inv += (sizea - ptra);   // a[ptra], a[ptra + 1]... all are > b[ptrb] and ptra < ptrb... So we count inversions for all numbers
            ptrb++; ptrc++;
        }
    }
    while( ptra < sizea ){
        arr[ptrc] = a[ptra];
        ptra++; ptrc++;
    }
    while( ptrb < sizeb ){
        arr[ptrc] =b[ptrb];
        ptrb++; ptrc++;
    }
    return inv;
}

ll mergesort(int arr[], int l, int r)
{
    ll inv = 0;
    if(l < r){
        int mid = (l + r)/2;
        inv += mergesort(arr, l, mid);
        inv += mergesort(arr, mid + 1, r);
        inv += merge(arr, l, mid, r);
    }
    return inv;
}

int main() {
    
	int n;
    cin>>n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin>>arr[i];
    
    cout<<mergesort(arr, 0, n-1);

    return 0;
}