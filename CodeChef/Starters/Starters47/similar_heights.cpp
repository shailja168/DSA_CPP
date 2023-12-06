#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define ll long long int
using namespace std;

int main() {

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin >> n;
        ll h[100000];
        ll max_height = -1;
        for (ll i = 0; i < n; i++){
            cin >> h[i];
            max_height = max(max_height, h[i]);
        }
        sort(h, h + n);
        ll count = 0;
        vector<pair<ll, ll>> temp;
        for (ll i = 0; i < n; i++){
            count++;
            if(h[i] != h[i+1]){
                temp.push_back({h[i], count});
                count = 0;
            }
        }
        ll ans = 0;
        vector<ll> a, b;
        for(auto &i: temp){
            if(i.second == 1){
                ans++;
                a.push_back(i.first);
            }
            else{
                b.push_back(i.second);
            }
        }

        if(ans == 1){
            ans++;
            if(max_height == a[0]){
                if(*max_element(b.begin(), b.end()) <= 2){
                    cout << *max_element(b.begin(), b.end()) << endl;
                    continue;
                }
            }
        }
        cout << ((ans+1)/2) << endl;
    } 
    return 0;
}
