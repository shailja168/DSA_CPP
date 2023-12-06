#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int binarytodecimal(int n){
    int ans=0,i=0;
    while(n>0){
        int x=n%10;
        ans+=x*pow(2,i);
        i++;
        n/=10;
    }
    return ans;    
}

int octaltodecimal(int n){
    int ans=0,i=0;
    while(n>0){
        int x=n%10;
        ans+=x*pow(8,i);
        i++;
        n/=10;
    }
    return ans;   
}

int hexadecimaltodecimal(string n){
    int ans=0,x=1;
    int s= n.size();

    for (int i=s-1;i>=0;i--){
        if(n[i]>='0'&& n[i]<='9'){
            ans+=x*(n[i]-'0');
        }
        else if(n[i] >='A' && n[i] <='F'){
            ans+=x*(n[i]-'A'+10);
        }
        x*=16;
    }
    return ans;
}

int decimaltobinary(int n){
    int ans=0,x=1;

    while(x<=n)
        x*=2;
    x/=2;

    while(x>0){
        int lastdigit=n/x;
        n-=lastdigit*x;
        x/=2;
        ans=ans*10+lastdigit;
    }  
    return ans;               
}

int decimaltooctal(int n){
    int ans=0,x=1;

    while(x<=n)
        x*=8;
    x/=8;

    while(x>0){
        int lastdigit=n/x;
        n-=lastdigit*x;
        x/=8;
        ans=ans*10+lastdigit;
    }  
    return ans;  
}

string decimaltohexadecimal(int n){
    int x=1;
    string ans="";
    while(x<=n)
        x*=16;
    x/=16;

    while(x>0){
        int lastdigit=n/x;
        n-=lastdigit*x;
        x/=16;

        if(lastdigit<=9){
            ans=ans + to_string(lastdigit);
        }
        else{
            char c='A'+ lastdigit -10;
            ans.push_back(c);
        }
    }
    return ans;  
}

int main()
{
    int n;
    cin>>n;

    cout<<decimaltobinary(n);

    return 0;
}

          

