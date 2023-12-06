#include <bits/stdc++.h>
using namespace std; 
#define ll long long 

const ll x = 1e6;
ll a[x], fgcd[x], bgcd[x];

void gcdofarray(ll n)
{
    fgcd[1] = a[1];
    bgcd[n] = a[n];

    for (ll i = 2; i < n+1 ; i++){
        fgcd[i] = __gcd(fgcd[i-1], a[i]);
    }

    for (ll i = n-1 ; i > 0; i--){
        bgcd[i] = __gcd(bgcd[i+1], a[i]);
    }   
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n; 

        for(ll i = 1; i < n+1; i++) cin>>a[i];

        sort(a, a+n+1);

        gcdofarray(n);

        ll sum = 0;
        for(ll i = 1; i < n+1; i++)
	        sum += a[i];
	    
        ll ans = 0;
        ll mn = LLONG_MAX;
    
        for(ll i = 1; i < n+1; i++){
            ans = (sum - a[i] + __gcd(fgcd[i-1], bgcd[i+1])) /  __gcd(fgcd[i-1], bgcd[i+1]);
            if (ans < mn)
                mn = ans;
        }

        cout<<mn<<endl; 
                
    }

    return 0;
}