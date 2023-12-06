#include <bits/stdc++.h>
using namespace std;  

void xorfolding(){
    long long n,m;
    cin>>n>>m;
    string arr[n];

    long long flag=0;

    for(long long i=0;i<n;i++){
        cin>>arr[i];
        for(auto j:arr[i])
            flag^=(j-'0');
    }
    if(flag==0)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--){
        xorfolding();
    }  
    return 0;
}