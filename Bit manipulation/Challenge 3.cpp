#include<bits/stdc++.h>
using namespace std;

bool getbit(int n, int pos)
{
   return (n >> pos) & 1 ;
}

int setbit(int n, int pos)
{
   return (n | (1 << pos));
}

int unique(int arr[], int n)
{
   int ans=0;
   for(int i=0;i<64;i++)
   {
      int sum=0;
      for(int j=0;j<n;j++)
      {
         if(getbit(arr[j],i))
            sum++;
      }
      if (sum%3!=0)
         ans= setbit(ans,i);
   }
   return ans;
}
int main()
{
   int n;
   cin>>n;
   int arr[n];

   for (int i = 0; i < n; i++)
      cin>>arr[i];

   cout<<unique(arr,n);

   return 0;
}   