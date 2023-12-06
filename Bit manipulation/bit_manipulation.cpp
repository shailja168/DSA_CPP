#include<bits/stdc++.h>
using namespace std;

int getbit(int n, int pos)
{
   return (n >> pos) & 1 ;
}

int setbit(int n, int pos)
{
   return (n | (1 << pos));
}

int clearbit(int n , int pos)
{
   int mask=  ~(1 << pos) ;
   return (n & mask);
}

int updateBit( int n, int pos, int value)
{
    int mask=  ~(1 << pos) ;  // clearbit
    n = n & mask ; 
    return (n | ( value << pos));  //setbit
}

int toggleBit( int n, int pos)
{
    return ( n ^ (1<<pos));
}

int main()
{
   int n, pos;
   cin>>n>>pos;
   //cout<<getbit(n,pos)<<endl;
   //cout<<setbit(n,pos)<<endl;  
   //cout<<clearbit(n,pos)<<endl;  
   //cout<< updateBit( n, pos , 1);
   cout<< toggleBit(n, pos);
   
   return 0;  
}   