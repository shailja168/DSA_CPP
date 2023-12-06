#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n, mx, sum;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;

    while (t--)
    {
        cin>>n;

        ll a[n];
        mx = -100000;

        for (ll i = 0; i < n; i++){ 
            cin>>a[i];
            if(a[i] > mx)
                mx = a[i];
        }
        
        sum = 0;

        for (ll i = 0; i < n; i++){
            sum |= (a[i] ^ mx);
        }

        cout<<mx<<" "<<sum<<endl;          
    }
    return 0;
}