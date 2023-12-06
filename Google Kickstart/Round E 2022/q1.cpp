#include <iostream>
#define ll long long int
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    ll test = t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;

        for (int i = 1, j = n; i <= j; i+=2, j-=3){
            ans++;
        }

        cout << "Case #" << test-t << ": " << ans << endl;
    }
    return 0;
}




