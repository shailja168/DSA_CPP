#include <bits/stdc++.h>
using namespace std;  

void permutations(string s , string ans)
{
    if(s.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        permutations(s.substr(0,i) + s.substr(i+1), ans + ch);
    }
    
}

int countPath( int start, int end)
{
    if( start == end) return 1;

    if( start > end) return 0; 

    int count = 0;
    for (int i = 1; i < 6; i++)
        count+=countPath(start + i, end);
    
    return count;
}

int countPathmaze( int i, int j, int n)
{
    if( i == n-1 & j == n-1) return 1;

    if( i >= n || j >= n) return 0;

    return countPathmaze( i+1, j, n) + countPathmaze( i, j+1, n);
}

int main()
{
    //string s;
    //cin>>s;

    //permutations( s , "");

    //int start, end;
    //cin>>start>>end;

    //cout<<countPath(start, end);

    int n;
    cin>>n;

    cout<<countPathmaze(0,0,n);

    return 0;
}