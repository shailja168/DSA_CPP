#include <bits/stdc++.h>
using namespace std;  

int knapsack( int value[], int wt[], int n, int W)
{
    if ( W == 0 | n == 0 ) return 0;

    if ( wt[n-1] > W) return knapsack( value, wt, n-1, W);

    return max( knapsack( value, wt, n-1, W- wt[n-1]) + value[n-1] , knapsack( value, wt, n-1, W) );
}

int main()
{
    int n, W;
    cin>>n>>W;

    int value[n], wt[n];

    for (int i = 0; i < n; i++) cin>>value[i];
    
    for (int i = 0; i < n; i++) cin>>wt[i];
    
    cout<<knapsack( value, wt, n, W);

    return 0;
}