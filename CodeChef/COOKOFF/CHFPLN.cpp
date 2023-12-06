#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;

    while (t--)
    {
        cin>>n;

        ll a[n];

        for (ll i = 0; i < n; i++)
            cin>>a[i];
        
        map<ll,ll> m;
        ll count = 0;
        for (ll i = 0; i < n; i++){
            if(m.find(a[i]) == m.end()){
                m[a[i]]++;
                count++;
            }
            else{
                if(m[a[i]] < a[i] - 1){
                    count++;
                    m[a[i]]++;
                }
            }
        } 
        cout<<count<<endl;     
    }
    return 0;
}