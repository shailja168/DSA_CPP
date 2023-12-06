#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define fast  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tc ll t; cin>>t; while(t--)
#define f() for(ll i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define int ll
#define vi vector<int>

signed main()
{
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    tc
    {
        int n,k;
        cin>>n>>k;
        char ar[n];
        int d=0;
        f()
        cin>>ar[i];
        for(int i=0;i<n-1;i++)
        {
            if((ar[i])==(ar[i+1]))d+=2 ;
            else d++;
        }
        // cout<<d<<endl;
        while(k--)
        {
            int a;
            cin>>a;
            if(ar[a-1]=='0') ar[a-1]='1';
            else ar[a-1]='0';
            if(a!=1)
            {
                if(ar[a-1]==ar[a-2]) d++;
                else d--;
            }
            if(a!=n)
            {
                if(ar[a-1]==ar[a]) d++;
                else d--;
            }
            cout<<d<<endl;
        }
    }
}