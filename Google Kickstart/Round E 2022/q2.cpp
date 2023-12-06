#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    int test = t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> r, d, m;
        
        for (int i = 0; i < n; i++){
            ll j;
            cin >> j;
            r.push_back(j);
            d.push_back(j * 2);
        }

        //sort(d.begin(), d.end());

        ll ans;
        for (int i = 0; i < n; i++){
            ans = -1;
            for (int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                if(d[i]>=r[j]){
                    ans = max(ans, r[j]);
                }
            }
            m.push_back(ans);
        }
        
        cout << "Case #" << test-t << ": ";
        for (int i = 0; i < n; i++){
            cout << m[i] << " ";
        }
        cout << endl;
    }
    return 0;
}




