#include<iostream>
using namespace std;

void fib(int num){
  int t1=0, t2=1, t3;
  for(int i=1;i<=num;i++){
    t3=t1+t2;
    cout<<t3<<"\t";
    t1=t2;
    t2=t3;
  }

}
int main()
{
    int n;
    cin>>n;

    fib(n);

    return 0; 
}

          

