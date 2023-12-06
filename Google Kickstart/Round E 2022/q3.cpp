#include <iostream>
#define ll long long int
using namespace std;

bool isPalindrome(string p){
    for (int i = 0, j = p.length() - 1; i < j; i++, j--){
        if(p[i] == p[j]){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    int test = t;
    while(t--){
        int n;
        cin >> n;
        string p, q;
        cin >> p;

        cout << isPalindrome(p);

        cout << "Case #" << test-t << ": "<< q << endl;
        
    }
    return 0;
}




