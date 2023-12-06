#include <bits/stdc++.h>
using namespace std;  

int main()
{
    int n,q;
    cin>>n>>q;

    int a[n];
    for (int i = 0; i < n; i++) cin>>a[i];
    
    for (int i = 0; i < q; i++){
        int x ;
        cin>>x;
        int pos = lower_bound(a, a + n, x) - a ;   

        if (pos < n && a[pos] == x)
            cout<<"0\n";
        else if (pos % 2 == 0)
            cout<<"POSITIVE\n";
        else
            cout<<"NEGATIVE\n";
    }
        
    return 0;
}