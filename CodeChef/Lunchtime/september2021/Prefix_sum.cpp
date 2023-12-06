#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(ll n){
    if(n % 4 != 0){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        vector<int> a;
        vector<int> b;

        ll l=1, r=n;

        ll flag = 0;
        ll c = n/2;

        while(c){
            if(flag ==0){
                a.push_back(l);
                l++;
                flag=1;
            }
            else{
                a.push_back(r);
                r--;
                flag=0;
            }
            c--;
        }

        for(ll i =l; i<=r; i++){
            b.push_back(i);
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        for(auto i:a)
            cout<<i<<" ";
        cout<<endl;

        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;

        solve(n);
    }
}