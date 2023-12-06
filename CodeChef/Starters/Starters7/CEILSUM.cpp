#include<bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--){
        ll a,b;
        cin>>a>>b;

        ll x;

        if(a == b){
            cout<<0<<endl;
            continue;
        }
        else if(a<b) {
            x = a - 1;
        }
        else{
            x = b - 1;
        }

        ll maxsum = ceil(double(b-x)/2) + ceil(double(x-a)/2);

        cout<<maxsum<<endl; 
    }
}