#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t; 
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[n];
        int item = 0;

        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a, a + n);

        for (int i = 0; i < n; i++)
        {
            if(a[i] <= k){
                item++;
                k -= a[i];
            }
            else{
                double temp = double(a[i]) / 2;
                if ( temp <= k)
                    item++;
                    k -= a[i]/2;
                    break;
            }
        }
        cout << item << endl;
    }
    return 0;
}