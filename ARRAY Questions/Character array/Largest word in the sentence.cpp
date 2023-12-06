#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Largest word in the sentence

   int n;
   cin>>n;
   cin.ignore(); //to clear out the buffer as we are using getline function

   char arr[n+1];
   cin.getline(arr , n);
   cin.ignore();

   int sum=0, maxlen=0;
   int st=0, maxst=0;
   int i=0;

   while(1){

      if (arr[i]==' ' || arr[i]=='\0'){
         if (sum>maxlen){
            maxlen=sum;
            maxst=st;
         }   
         sum=0;
         st=i+1;
      }
      else
         sum++;

      if (arr[i]=='\0') 
         break;

      i++;   
   }
   for (int i = 0; i < maxlen; i++)
   {
      cout<<arr[i+maxst];
   }
    
   cout<<"\t"<<maxlen<<endl;
}    