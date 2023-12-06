#include <iostream>
using namespace std;  

void swap( int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n;
    cin>>n;
    int a[n];

    for (int i = 0; i < n; i++) cin>>a[i];

    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if(a[j] < a[i])
                swap(a[i], a[j]);
        }
        for (int i = 0; i < n; i++) cout<<a[i]<<" ";  //to output every step
        cout<<endl;
    }   

    return 0;
}