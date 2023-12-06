#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++){
      for(int j=n-i;j>=1;j--){
        cout<<"  ";
    }
      int star=(2*i)-1;    
      for(int k=1;k<=star;k++){
        cout<<"* ";
      }
    cout<<endl;  
  } 
  for(int i=n;i>=1;i--){
      for(int j=n-i;j>=1;j--){
        cout<<"  ";
    }
      int star=(2*i)-1;    
      for(int k=1;k<=star;k++){
        cout<<"* ";
      }
    cout<<endl;  
  }  
}

          

