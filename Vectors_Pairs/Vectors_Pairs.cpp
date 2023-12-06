#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
using namespace std; 

int main() {
    
    //initialize vector
	vector<int> v;
    vector<int> v2 (3, 50);   //50 50 50

    // 2d vector
    vector<vector<int>> v3;

    //append values in vector
    v.push_back(1);         
    v.push_back(2);
    v.push_back(3);
    
    //traversal in vector

    for (int i = 0; i < v.size(); i++){
        cout<<v[i]<<endl;
    }  //1 2 3

    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++){
        cout<<*it<<endl;    //it is a pointer
    }  //1 2 3

    for(auto element:v){
        cout<<element<<endl;
    }  //1 2 3

    //delete last element
    v.pop_back();   // 1 2
    
    //swap two vectors
    swap(v,v2);
    for(auto element:v){
        cout<<element<<endl;
    } 
    for(auto element:v2){
        cout<<element<<endl;
    } 

    //sort a vector
    sort(v.begin(), v.end());

    //sum of vector
    int sum = accumulate(v.begin(), v.end(), 0);
    cout<<sum<<endl;

    //max_element() returns iterator to the max element
    int mx = *max_element(v.begin(), v.end());

    //min_element() returns iterator to the min element
    int mn = *min_element(v.begin(), v.end());

    //converts the vector into a prefix sum vector or cummulative sum vector
    partial_sum(v.begin(), v.end(), v,(begin));

    //initialize pair

    pair <int,char> p;
    p.first = 4;
    p.second = 'g';
    cout<<p.first<<" "<<p.second<<endl;

    pair <double, int> yo;
    yo = make_pair (3.536, 6);
    cout<<yo.first<<" "<<yo.second<<endl;  

    //custom comparator
    bool mycompare(pair<int,int> p1, pair<int, int> p2){
        return p1.first < p2.first;
    } 

    return 0;
}