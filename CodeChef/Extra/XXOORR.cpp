#include <bits/stdc++.h>
using namespace std; 
#define ll long long 

int main() {

    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k; 

        int a[n];
        for (int i = 0; i < n; i++) cin>>a[i];

        ll ans[33] = {0};
        for (int i = 0; i < n; i++){
            int temp = a[i];
            int j = 32;
            while(temp > 0){
                ans[j] = ans[j] + (temp % 2);
                j--;
                temp/=2;
            }
        }

        int oprt = 0;

        for (int j = 0; j < 33; j++){
            if (ans[j] % k == 0){
                oprt = oprt + ans[j]/k;
            }
            else{
                oprt = oprt + ans[j]/k + 1;
            }
        }

        cout<<oprt<<endl;
        
    }

    return 0;
}