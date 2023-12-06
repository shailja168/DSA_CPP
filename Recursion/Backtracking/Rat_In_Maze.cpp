#include <bits/stdc++.h>
using namespace std;  

bool isSafe (int** arr, int x, int y, int m, int n )
{
    if ( x < m && y < n && arr[x][y]==1 )
        return true;
    
    return false;
}

bool RatInMaze (int** arr, int x, int y, int m, int n, int** solArr)
{
    if( x == (m-1) && y == (n-1)){
        solArr[x][y] = 1;
        return true;
    }

    if( isSafe(arr, x, y, m, n) ){
        solArr[x][y] = 1;

        if ( RatInMaze(arr, x + 1, y, m, n, solArr))
            return true;
        if ( RatInMaze(arr, x, y + 1, m, n, solArr))
            return true;

        solArr[x][y]=0;     //backtracking
        return false;
    }
    return false;
}

int main()
{
    int m, n;
    cin>>m>>n;

    int** arr = new int*[m];
    for (int i = 0; i < m; i++)  
        arr[i]= new int[n];

    for (int i = 0; i < m; i++){ 
        for (int j = 0; j < n; j++) 
            cin>>arr[i][j];
    }
    cout<<endl;

    int** solArr = new int*[m];
    for (int i = 0; i < m; i++){
        solArr[i]= new int[n];
        for (int j = 0; j < n; j++) 
            solArr[i][j]=0;
    }        

    if (RatInMaze(arr, 0, 0, m, n, solArr) ){
        for (int i = 0; i < m; i++){ 
            for (int j = 0; j < n; j++) 
                cout<<solArr[i][j]<<" ";
            cout<<endl;    
        }
    }
    else
        cout<<"No Path";

    return 0;
}