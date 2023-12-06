#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while (t--)
    {
        ll x, y;
        cin>>x>>y;

        if(__gcd(x , y) > 1)
            cout<<"0"<<endl;  
        else if((__gcd(x + 1 , y) > 1) || (__gcd(x , y + 1) > 1))
            cout<<"1"<<endl;  
        else
            cout<<"2"<<endl;  
    }
    return 0;
}