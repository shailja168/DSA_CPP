#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        ll a[100000];
        int odds = 0;
        int sum = 0;
        int non_1 = 0;
        int piles_of_1 = 0;
        int piles_of_2 = 0;
        
        for (int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == 1){
                piles_of_1++;
            }    
            else{
                if(a[i] == 2){
                    piles_of_2++;
                }
                sum += a[i];
                non_1++;
                if(a[i]%2){
                    odds++;
                }
            }
        }

        //sort(a, a + n);
        
        if(piles_of_1 == 1){
            if( !(odds%2) ){
                cout << "Chef\n";
                continue;
            }
            if(piles_of_2 == 0){
                cout << "Chefina\n"; 
                continue; 
            }
            sum -= 2;
            non_1--;
            if((sum - non_1) % 2){
                cout << "Chefina\n"; 
                continue;
            }
            else{
                cout << "Chef\n"; 
                continue;
            }
        }
        else if(piles_of_1 > 1){
            if((sum - non_1) % 2){
                cout << "Chef\n";
                continue;
            }
            else{
                cout << "Chefina\n";  
                continue;
            }
        }
        if(odds%2 == 1){
            cout << "Chef\n";
            continue;
        }
        else{
            cout << "Chefina\n";
            continue;
        }
    }
    return 0;
}
