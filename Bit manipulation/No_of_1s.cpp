#include<bits/stdc++.h>
using namespace std;

int noofones(int n)
{
   int c=0;
   while (n)
   {
      n = n & n-1 ;
      c++;
   }
   return c;
}

int main()
{
   int n;
   cin>>n;

   cout<<noofones(n)<<endl;
   return 0;  
}   