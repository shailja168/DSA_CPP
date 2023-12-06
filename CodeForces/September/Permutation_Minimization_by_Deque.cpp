#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void display_deque(deque <int> x){
    deque <int> :: iterator i;
    for(i = x.begin(); i != x.end(); i++)
        cout<<*i<<" ";
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int a[n];
        for (int i = 0; i < n; i++){ cin>>a[i];}

        deque <int> x;
        x.push_back(a[0]);

        for (int i = 1; i < n; i++){
            if(a[i] > x.front())
                x.push_back(a[i]);
            else
                x.push_front(a[i]); 
        }
        display_deque(x);
    }
    return 0;
}