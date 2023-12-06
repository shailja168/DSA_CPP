#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

int pow_of_2(int n){
    int ans = 0;
    for (int i = n; i >= 1; i--){
        if((i&(i-1)) == 0){ 
            ans = i;
            break;
        }
    }
    return ans;
}

int main() {

    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        ll f[100001];
        for (int i = 0; i <= n; i++){
            cin >> f[i];
        }
        int size = pow_of_2(n);
        ll a[3] = {0, 0, 0};
        for (int i = size; i > 0; i/=2){
            ll d = f[i] - f[0];
            if(d<0){
                d *= -1;
                int x = d / i;
                if(x==1){
                    x = 2;
                    if(((a[0]^i) <= n)){
                        a[0] ^= i;
                        x--;
                    }
                    if(x && (a[1]^i)<=n){
                        a[1] ^= i;
                        x--;
                    }
                    if(x>0 && (a[2]^i)<=n){
                        a[2] ^= i;
                        x--;
                    }
                }
                else if(x==3){
                    a[0] ^= i;
                    a[1] ^= i;
                    a[2] ^= i;
                }
            }
            else{
                int x = d / i;
                if(x==1){
                    if((a[0]^i)<=n){
                        a[0] ^= i;
                    }
                    else if((a[1]^i)<=n){
                        a[1] ^= i;
                    }
                    else{   
                        a[2] ^= i;
                    }
                }
            }
            sort(a, a + 3);
        }
        cout << a[0] << " " << a[1] << " " << a[2] << endl;
    }
    return 0;
}
