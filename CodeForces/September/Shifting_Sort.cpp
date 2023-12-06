#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    while(t--){
        int n;
        cin>>n;
        
        vector <int> v(n);

        for (int i = 0; i < n; i++) cin>>v[i];
        
        vector <vector<int>> ans;

        for (int i = n-1; i > 0; i--){
            int mx = INT_MIN;
            int indx = -1;
            for (int j = 0; j <=i; j++){
                if(mx < v[j]){
                    mx = v[j];
                    indx = j;
                }
            }
            if(indx == i)
                continue;
            else{
                vector <int> temp1;
                vector <int> temp2(n);
                for(int j=0;j<=i;j++)
                    temp2[j]=v[(j+indx+1)%(i+1)];
                
                v=temp2;
                ans.push_back({1,i+1,indx+1});
            } 
        }
        cout<<ans.size()<<endl;
        for(auto i:ans){
            for(auto j:i)
                cout<<j<<" ";
            cout<<endl;
        }
    }
    return 0;
}