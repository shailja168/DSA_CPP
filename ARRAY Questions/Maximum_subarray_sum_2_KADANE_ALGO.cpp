#include<iostream>
using namespace std;
#define m 1000

int main()
{
    int n;
    cin>>n;
    int a[m];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    int currentsum=0,maxsum=INT_MIN;
    
    for(int i=0;i<n;i++){
        currentsum+=a[i];
        if(currentsum<0){
            currentsum=0;
        }
        maxsum=max(maxsum,currentsum);
    }
    cout<<maxsum;   
    return 0;
}