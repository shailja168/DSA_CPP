#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m, target;
    cin>>target;
    cin>>n>>m;
    int a[n][m];
   
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    }
    
    int r=0, c=m-1;
    bool flag= false;
    while (r<n and c>=0)
    {
        if(a[r][c]==target)
           flag=true;
        if (a[r][c]<target)
           c--;
        else 
           r++;   
    }
    if(flag)
       cout<<"Element found";  
    else  
       cout<<"Element does not exist";   
}    