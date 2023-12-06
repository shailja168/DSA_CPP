#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> k;

    //window: a[i....j]
    int i = 0, ans = 0, zerocnt = 0;
    for (int j = 0; j < n; j++){
        if(a[j] == 0){
            zerocnt++;
        }
        while (zerocnt > k){
            if(a[i] == 0){
                zerocnt--;
            }
            i++;
        }
        ans = max(ans, j - i + 1);
    }
    cout << ans;

    return 0;
}