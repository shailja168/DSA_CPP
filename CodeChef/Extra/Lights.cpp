#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int x[n];

    for (int i = 0; i < n; i++)
        cin>>x[i];

    int ans=0;

    for (int i = 0; i < n; i++)
    {
        if( x[i]==0 )
        {
            ans++;
            for (int j = i; j < n; j++)
                 x[j]= !x[j];
        }
    } 

    cout<<ans<<endl;  

    return 0;
}