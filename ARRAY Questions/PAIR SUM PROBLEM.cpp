#include<bits/stdc++.h>
using namespace std;

bool pairsum(int a[],int n, int k){
    int low=0, high=n-1;
    while(low<high){
        int temp=a[low]+a[high];
        if(temp==k){
            cout<<low<<" "<<high<<endl;
            return true;
        }
        else if (temp<k){
            low++;
        }
        else{
            high--;
        }
    }
    return false;
}

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<pairsum(a,n,k);

    return 0;
}