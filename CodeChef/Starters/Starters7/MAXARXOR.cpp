#include<bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        ll n,k;
        cin>>n>>k;
        
        ll mxshift = pow(2, (n-1));
        ll ans, temp = pow(2, n) - 1;
        if(k > mxshift){
            ans = temp * 2 * mxshift;
        }
        else{
            ans = temp * 2 * k;
        }
        cout<<ans<<endl;
    }
}