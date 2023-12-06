#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largest_rectangle_area(vector<int> hist){
    stack<int> s;
    int area = 0;
    hist.push_back(0); //make the last bar zero to avoid handling leftover elements in stack
    for (int i = 0; i < hist.size(); i++){
        while(!s.empty() && hist[s.top()] >= hist[i]){
            int h = hist[s.top()];
            s.pop();
            if(s.empty()){
                area = max(area, h * i);
            }
            else{
                int len = i - s.top() - 1;
                area = max(area, h * len);
            }
        }
        s.push(i); //we are pushing index value of bars and not their height
    } 
    return area;
}

int main() {

    int n;
    cin >> n;
    vector<int> hist(n+1);
    for (int i = 0; i < n ; i++){
        cin >> hist[i];
    }
    cout << largest_rectangle_area(hist);

    return 0;
}