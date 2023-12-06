#include <iostream>
#include <vector>
using namespace std;

int main() {

    string s;
    cin >> s;
    vector<int> dict(256, -1); // since ascii codes are max 256
    int maxlen = 0, start = -1;

    for (int i = 0; i < s.size(); i++){
        if(dict[s[i]] > start){  //if repeating element occurs
            start = dict[s[i]];  //put start position to new occurence location
        }
        dict[s[i]] = i;  //update the new occurence position of the element
        maxlen = max(maxlen, i - start);
    }

    cout << maxlen;

    return 0;
}