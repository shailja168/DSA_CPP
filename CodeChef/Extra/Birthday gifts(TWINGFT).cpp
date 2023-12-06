#include <bits/stdc++.h>
using namespace std;

int main()
{
   cout.sync_with_stdio(false);
   cout.tie(NULL);
    
   int t;
   cin>>t;

   while(t--)
   {
      int n,k;
      cin>>n>>k;

      int A[n];
      for (int i = 0; i < n; i++) cin>>A[i];

      int asize= sizeof(A)/sizeof(A[0]);

      sort(A, A+asize, greater<int>());

      int twin1=0, twin2=0;
      
      if(n==1)
      {
         cout<<A[0]<<endl;
         continue;
      }    

      int j;
      for ( j = 0; j < 2*k; j++)
      {
         if(j%2==0) 
            twin1+=A[j];
         else  
            twin2+=A[j];
      }
      twin2+=A[j];

      cout<<max(twin1,twin2)<<endl;
   }

   return 0;
}