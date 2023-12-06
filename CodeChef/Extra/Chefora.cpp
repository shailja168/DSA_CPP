#include <bits/stdc++.h>
#include <math.h>
using namespace std; 
#define ll long long 

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll chefora[100001] = {0};

    for (int i = 1; i < 100001; i++){
        ll temp = i, n = i;
        n /= 10;
        while (n != 0){
            ll var = n % 10;
            temp = (temp * 10) + var;
            n /= 10;
        }
        chefora[i] = temp;          
    }
        
    ll prefixsum[100001] = {0};
    ll sum = 0;
    for (int i = 1; i < 100001; i++){
        sum += chefora[i];
        prefixsum[i] = sum;
    }

    ll q;
    cin>>q;

    while(q--){
        ll l, r;
        cin>>l>>r;

        ll power = prefixsum[r] - prefixsum[l];
        ll ans = 1;
        ll base = chefora[l];

        ll mod9 = pow(10, 9)+7;
        //cout<<mod9<<" "<<power<<" "<<ans<<" "<<base<<endl;
        
        while( power > 0){
            if(power%2 == 1){
                ans *= base;
                ans %= mod9;  
            }
            base *= base; 
            base %= mod9;
            power = int(power/2);
        }
        //cout<<mod9<<" "<< ans <<endl;  

        cout<<ans % mod9<<endl;
    }

    return 0;
}