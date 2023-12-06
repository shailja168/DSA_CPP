#include <iostream>
#include <deque>
#include <vector>
#include <set>
using namespace std;

//Method 1 explanation
/*Let us take a example array 1, 2, 3, 4, 5. 6. Let assume k be 3.
You are first pushing 3 elements in multiset i.e. 1,2,3. 
Since, it is a multiset, so elements are stored in descending order, like this 3,2,1. 
Now we push first element(3) of multiset in ans vector , because it's largest among  first 3 elements . 
Now what we have to do is we have to remove 1 from multiset because it's work is over, 
we don't need it for upcoming subarrays. Then we have to insert 4 in multiset, 
because it is a part of next subarray(2,3,4). So in multiset they are stored like 4,3,2.  
4 is then stored in ans vector. Now remove 2 and add 5 and go on till you reach end of array.*/

//Time Complexity= O(nlogn)

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &i : a){
        cin >> i;
    }

    multiset<int, greater<int>> s;
    vector<int> ans;
    for (int i = 0; i < k; i++){
        s.insert(a[i]);
    }

    ans.push_back(*s.begin());  //top value of multiset is added to the ans vector
    for (int i = k; i < n; i++){
        s.erase(s.lower_bound(a[i - k]));
        s.insert(a[i]);
        ans.push_back(*s.begin());
    }
    for(auto i : ans){
        cout << i << " ";
    }
    

    return 0;
}