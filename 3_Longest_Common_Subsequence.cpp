#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define ll long long
#define wt(x) int x; cin>>x; while( x-- )




int LCS( string X, string Y, int m, int n){
    vector<vector<int>> arr(m+1,vector<int>(n+1) ); // int arr[m][n];
    for( int i=0; i<m+1; i++ ){
        for( int j=0; j<n+1; j++ ){
            if( i==0 || j==0 )
                arr[i][j] = 0;
            else if( X[i-1] == Y[j-1] )
                arr[i][j] = arr[i-1][j-1]+1;
            else 
                arr[i][j] = max( arr[i-1][j], arr[i][j-1] );
        }
    }
    //cout<<"Size of LCS : "<<arr[m][n]<<endl;

    // for print LCS

    int index=arr[m][n];
    char lcs[index+1];
    lcs[index] = '\0';
    
    int i=m,j=n;
    while( i>0 && j>0 ){
        if( X[i-1] == Y[j-1] ){
            lcs[index-1] = X[i-1];
            i--; j--; index--;
        }
        else if( arr[i-1][j] > arr[i][j-1] )
            i--;
        else 
            j--;
    }
    cout<<"LCS of "<<X<<" and "<<Y<<" is : "<<lcs<<endl;

    // int index=arr[m][n];
    // char lcs[index+1];
    // lcs[index]='\0';
    // int i=m,j=n;
    // int left, top, diagonal, current ; // elements in arr 
    // while( i>0 && j>0 ){
    //     left = arr[i][j-1];
    //     top = arr[i-1][j];
    //     diagonal = arr[i-1][j-1];
    //     current = arr[i][j];
    //     if( diagonal = max(diagonal,max(left,top)) && diagonal != current ){
    //         lcs[index-1] = X[i-1];
    //         i--; j--; index--;
    //     }
    //     else if( left > top )
    //         j--;
    //     else 
    //         i--;
    // }
    // cout<<"LCS of "<<X<<" and "<<Y<<" is : "<<lcs<<endl;

    return arr[m][n];
}

int main(){
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";

    // string s1, s2;
    // cin>>s1>>s2;

    int m = s1.size();
    int n = s2.size();
    int len = LCS(s1, s2, m, n);
    cout<<"Length of LCS : "<<len<<endl;

    return 0;
}


// ABCDGH AEDFHR  --> “ADH” of length 3
// AGGTAB GXTXAYB --> “GTAB” of length 4