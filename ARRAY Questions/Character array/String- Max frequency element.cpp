#include<bits/stdc++.h>
using namespace std;

int main()
{
   string st="ddkbwefkdndsfdszzzzz";

   int freq[26];

   for (int i = 0; i < 26; i++)
      freq[i]=0;

   for (int i = 0; i < st.size(); i++)
   {
      freq[st[i]- 'a']++;
   }

   int ansf=0;
   char ansch=st[0];

   for (int i = 0; i < 26; i++)
   {
      if( freq[i]>=ansf)
      { 
         ansf=freq[i];
         ansch= 'a'+ i;
      }
   }

   cout<<ansch<<"\t"<<ansf<<endl;
     
   

   
      
}   