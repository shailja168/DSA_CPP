#include<iostream>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--){
        ll e,k;
        cin>>e>>k;

        ll chain = 0;
        while( e > 0){
            e/=k;
            chain++;
        }
        cout<<chain<<endl;
    }
}