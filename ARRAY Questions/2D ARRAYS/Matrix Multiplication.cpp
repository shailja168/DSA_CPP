#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int m1[n1][n2], m2[n2][n3];
   
    for (int i=0;i<n1;i++){
        for (int j=0;j<n2;j++)
            cin>>m1[i][j];
    }
    for (int i=0;i<n2;i++){
        for (int j=0;j<n3;j++)
            cin>>m2[i][j];
    }
    int ans[n1][n3];
    for (int i=0;i<n1;i++){
        for (int k=0;k<n3;k++){
            int sum=0;
            for (int j=0;j<n2;j++){
                sum+=m1[i][j]*m2[j][k];
            }  
            ans[i][k]=sum;
        }
    }
    for (int i=0;i<n1;i++){
        for (int j=0;j<n3;j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    } 
}    