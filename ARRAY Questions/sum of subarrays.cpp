#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main()
{
int n,a[10];
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++){
    int sum=0;
    for(int j=i;j<n;j++){
        sum+=a[j];
        cout<<sum<<" ";
    }
}
}