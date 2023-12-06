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

    int l = 0, r = n - 1;
    while(l<r){
        if(a[l] + a[r] == target){
            cout << "Pair is " << " " << a[l] << " " << a[r];
            ans = true;
            break;
        }
        else if (a[l] + a[r] < target){
            l++;
        }
        else{
            r-- ;
        }
    }
    if(!ans){
        cout << "no such pair";
    }

    return 0;
}