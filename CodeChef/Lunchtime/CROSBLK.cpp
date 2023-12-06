#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while (t--){
        ll n;
        cin>>n;

        ll a[n];
        int nosol = 0;

        for (ll i = 0; i < n; i++){
            cin>>a[i];
            if( i > 0 && a[i] > a[0])
                nosol = 1;
        }

        if(nosol){
            cout<<-1<<endl;
        }
        else{
            stack<int> s;
            for(int i=1;i<n;i++){
                while(s.size() && s.top() <= a[i]){
                    s.pop();
                }
                s.push(a[i]);
            }
            int ans=0;
            while(!s.empty()){
                ans++;
                s.pop();
            }
            cout<<ans<<endl;
        }  
    }
    return 0;
}