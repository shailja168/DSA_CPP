#include<iostream>
using namespace std;

void fact(int num){
  int ft=1;
  for(int i=1;i<=num;i++){
    ft*=i;
  }
  cout<<ft;
}

int main()
{
    int n;
    cin>>n;

    fact(n);

    return 0; 
}

          

