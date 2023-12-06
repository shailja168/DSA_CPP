#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin >> T;
    while (T--)
    {   
        int n;
        cin>>n;

        string s;
        cin>>s;

        map<int,int> a;
        map<int,int> b;

        for (int i = 0; i < n; i++){
            a[i - int(s[i])]++;
            b[i + int(s[i])]++;
        }

        int nice_pair = 0;

        for(auto i = a.begin(); i != a.end(); i++)
            nice_pair += i->second * (i->second - 1) / 2 ;        

        for(auto i = b.begin(); i != b.end(); i++)
            nice_pair += i->second * (i->second - 1) / 2 ;

        cout<<nice_pair<<endl;
    }

    return 0;
}