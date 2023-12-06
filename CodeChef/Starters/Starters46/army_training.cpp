#include <iostream>
#include <algorithm>
#define m 1000
#define ll long long int
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        int a[m];
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a + n);
        ll attack = 0, defense = 0;
        ll ans = 0;
        for(int i=0;i<n;i++)
		{
		    attack+=a[i];
		}
		for(int i=0;i<n;i++)
		{
		    attack-=a[i];
		    defense+=(1000-a[i]);
		    ans=max(ans,attack*defense);
		}
		cout<<ans<<"\n";
    }
    return 0;
}