#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int rain_water(vector<int> w){
    stack<int> s;
    int ans = 0;
    for (int i = 0; i < w.size(); i++){
        while(!s.empty() && w[s.top()] < w[i]){
            int cur = s.top();
            s.pop();
            if(s.empty()){
                break;
            }
            else{
                int width = i - s.top() - 1; //the width of the container inbetween 
                //w[s.top()], w[i] give the left and right walls, there min minus cur bar gives height of container
                int h = (min(w[s.top()], w[i]) - w[cur]);
                ans += (h * width); 
            }
        }
        s.push(i); //we are pushing the index of the bar not its value
    }
    return ans;
}

int main() {

    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n ; i++){
        cin >> w[i];
    }

    cout << rain_water(w);

    return 0;
}