#include <bits/stdc++.h>
using namespace std;  

void revString(string s)
{
    if (s.length()== 0) return;

    string remstring = s.substr(1);

    revString(remstring);
    cout<<s[0];   
}

void replacepi( string s)
{
    if( s.length() == 0) return;

    if ((s[0] =='p') && (s[1] == 'i')){
        cout<<"3.14";
        replacepi( s.substr(2) );    
    }
    else{
        cout<<s[0];
        replacepi(s.substr(1));    
    }
}

void towerofhanoi( int n, char source, char dest, char helper)
{
    if(n == 0) return;

    towerofhanoi( n-1, source, helper, dest);
    cout<<"Move disk "<< n <<" from "<<source<<" to "<<dest<<endl;
    towerofhanoi( n-1, helper, dest, source);
}

string removeDuplicate( string s)
{
    if ( s.length() == 0) return "";

    char ch= s[0];
    string ans= removeDuplicate( s.substr(1));

    if(ch == ans[0]) return ans;
    
    return ch+ans;
}

string moveallx( string s)
{
    if (s.length() == 0) return "";

    char ch = s[0];
    string ans = moveallx(s.substr(1));

    if (ch == 'x') return ( ans + ch);

    return (ch + ans);
}

void substrings( string s, string ans)
{
    if (s.length() == 0) {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string remstring = s.substr(1);

    substrings( remstring , ans);
    substrings( remstring , ans+ ch);
}

string keypadArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad( string s, string ans)
{
    if(s.length() == 0){
        cout<<ans<<endl;
        return;
    }

    char ch = s[0];
    string code = keypadArr[ch-'0'];

    for (int i = 0; i < code.length(); i++)
        keypad( s.substr(1), ans + code[i]);
}

int main()
{
    string s;
    cin>>s;

    //revString(s);   

    //replacepi(s); 

    //towerofhanoi(n, 'A', 'C', 'B');

    //cout<<removeDuplicate(s);

    //cout<<moveallx(s);

    //substrings(s, "");

    keypad(s,"");

   return 0;
}