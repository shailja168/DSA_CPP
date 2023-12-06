#include<bits/stdc++.h>
using namespace std;

bool ifpowerof4( int n )
{
   int checkbit=3;  //3=11 in binary , used to check last two bits are zero or not

   while((checkbit & n) == 0)
      n>>=2; 

   if ((n & n-1) != 0 )
      return false; 

   return ((n & checkbit)== 1);   

}

int main()
{
   int n;
   cin>>n;

   if(ifpowerof4(n))  
      cout<<"Power of 4\n";
   else
      cout<<"Not a power of 4\n";   

   return 0;  
}   