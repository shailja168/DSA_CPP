#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    int target;
    cin >> target;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    bool ans = false;

    for (int i = 0; i < n; i++){
        int l = i + 1, r = n - 1;
        while(l<r){
            int cur = a[i] + a[l] + a[r];
            if(cur == target){
                cout << "Triplet is "<< a[i] << " " << a[l] << " " << a[r];
                ans = true;
                break;
            }
            else if (cur < target){
                l++;
            }
            else{
                r-- ;
            }
        }
    }
    if(!ans){
        cout << "no such triplet";
    }

    return 0;
}