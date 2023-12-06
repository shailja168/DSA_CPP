#include<bits/stdc++.h>
using namespace std;

void unique(int arr[], int n)
{
   int xorsum=0;
   for (int i = 0; i < n; i++)
      xorsum^=arr[i];
   
   int index=0;

   while((xorsum & 1) !=1)
   {
      xorsum>>=1;
      index++;
   }

   int num1=0,num2=0;

   for (int i = 0; i < n; i++)
   {
      if( ( (arr[i]>>index) & 1) == 1)
         num1^=arr[i];
      else
         num2^=arr[i];   
   }
   cout<<num1<<"  "<<num2;
}
int main()
{
   int n;
   cin>>n;
   int arr[n];

   for (int i = 0; i < n; i++)
      cin>>arr[i];

   unique(arr,n);

   return 0;
}   