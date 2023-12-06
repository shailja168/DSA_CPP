#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main()
{
int n;
cin>>n;
int a[n+1];
a[n]=-1;

if (n==1){
    cout<<"1\n";
    return 0;
}
for(int i=0;i<n;i++){
    cin>>a[i];
}
int mx=a[0],ans=0;
for(int i=1;i<n;i++){
    mx=max(mx,a[i-1]);
    if(a[i]>mx && a[i]>a[i+1]){
        ans++;    
    }
}
cout<<"\n"<<ans;  

return 0;
}