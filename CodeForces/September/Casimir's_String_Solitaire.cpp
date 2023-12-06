#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {        
        string s;
        cin>>s;

        int a = 0, b = 0, c = 0;
        for(int i = 0; i< s.length();i++){
            if(s[i] == 'A')
                a++;
            else if(s[i] == 'B')
                b++;
            else
                c++;
        }

        if( (a + c) == b)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}