#include<bits/stdc++.h>
using namespace std;

int main()
{
   char arr[100];
   cin>>arr;
    
   int l= strlen(arr);
   bool flag=true;
   for(int i=0;i<l;i++){
      if (arr[i]!=arr[l-1-i]){
         flag=false;
         break;
      }   
   }
   if (flag)
      cout<<"PALINDROME";
   else
      cout<<"NOT A PALINDROME";   
}    