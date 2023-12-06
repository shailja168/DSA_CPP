#include <iostream>
#include <algorithm>
#include <math.h>
#define ll long long int
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        int p, ans = 0;
        for (int i = 1; i <= n ; i++){
            cin >> p;
            int x = abs(p - i);
            ans = __gcd(ans, x);
        }
        cout << ans << endl;
    }
    return 0;
}