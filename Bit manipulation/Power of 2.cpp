#include<bits/stdc++.h>
using namespace std;

int ifpowerof2( int n )
{
   if ( n==0 )
   {  cout<<"Not a power of 2\n";
      return 0; }
   if ((n & n-1)  == 0 )
      cout<<"Power of 2\n";
   else
      cout<<"Not a power of 2\n";

   return 0;   
}

int main()
{
   int n;
   cin>>n;

   ifpowerof2(n);

   return 0;  
}   