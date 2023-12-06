#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> prices(n), ans;
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++){
        cin >> prices[i];
    }
    
    for (int i = 0; i < n; i++){
        int days = 1;
        while(!s.empty() && s.top().first <= prices[i]){
            days += s.top().second;
            s.pop();
        }
        s.push({prices[i], days});
        ans.push_back(days);
    }
    
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}