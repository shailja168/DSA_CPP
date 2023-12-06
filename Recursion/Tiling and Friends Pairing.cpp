#include <bits/stdc++.h>
using namespace std;  

int tilingways(int n)
{
    if(n == 1) return 1;

    if(n == 0) return 0;

    return (tilingways(n - 1) + tilingways(n - 2));
}

int friendsPairing(int n)
{
    if (n == 0 || n == 1 || n == 2) return n;

    return friendsPairing(n-1) + ((n-1) * friendsPairing (n-2)) ;
}

int main()
{
    int n;
    cin>>n;

    //cout<<tilingways(n);

    cout<<friendsPairing(n);

    return 0;
}