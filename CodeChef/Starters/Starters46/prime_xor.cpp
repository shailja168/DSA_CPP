#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long int
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int x, y;
        cin >> x >> y;
        int z = x ^ y;
        vector<int> temp;
        temp.push_back(2);
        if ((2 ^ x) & 1)
            temp.push_back((2 ^ x));
        if ((2 ^ y) & 1)
            temp.push_back((2 ^ y));
        if ((2 ^ z) & 1)
            temp.push_back((2 ^ z));
        sort(temp.begin(), temp.end());
        for (int i = 0; i < 3; i++){
            cout << temp[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
