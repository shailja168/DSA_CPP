#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n - 1);
        
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        for (ll i = 0; i < n - 1; i++)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        map<ll, ll> mp;
        for (ll i = 0; i < n - 1; i++)
        {
            ll m1 = b[i] - a[i];
            ll m2 = b[i] - a[i + 1];
            if (m1 != m2)
            {
                if (m1 > 0)
                    mp[m1] ++;
                if (m2 > 0)
                    mp[m2] ++;
            }
            else
            {
                if (m1 > 0)
                    mp[m1] ++;
            }
        }

        for (auto i : mp)
        {
            if (i.second == (n - 1))
            {
                cout << i.first << endl;
                break;
            }
        }
    }
}