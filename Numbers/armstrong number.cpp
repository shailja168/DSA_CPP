#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int original=n;

    int sum=0;

    while(n>0){
      int lastdigit=n%10;
      sum+=lastdigit*lastdigit*lastdigit;
      n/=10;
    }
    if(sum==original){
      cout<<"armstrong number";
    }
    else{
      cout<<"Not an armstrong number";
    }
}

          

