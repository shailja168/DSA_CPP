#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long int
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int length = n;
        bool flag = true;
        while (length != 0){   
            if (length % 2 == 0){
                length /= 2;
                if (s.substr(0, length) != s.substr(length,length)){
                    flag = false;
                    break;
                }
            }
            else{
                length--;
            }
        }
        if(flag==true)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    } 
    return 0;
}
