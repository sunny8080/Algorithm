#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
#define wt(x) int x; cin>>x; while( x-- )


// To find the pascal's Triagle
vector<vector<int>> generate_Pascals( int rows ){
    vector<vector<int>> ans( rows);
    for( int i=0; i<rows; i++ ){
        ans[i].resize( i+1 );
        ans[i][0] = ans[i][i] = 1;
        for( int j=1; j<i; j++ )
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
    }
    return ans;
}

// To find nth row of Pascal's Triangle
vector<int> getRow( int rowIndex ){
    vector<int> pRow(rowIndex+1);
    int res=1;
    pRow[0] = res;
    for( int i=0; i<rowIndex; i++ ){
        res *= (rowIndex-i);
        res /= i+1;
        pRow[i+1] = res;
    }
    return pRow;
}

// find pascal[row][col] // nCr ( for 0 indexing ) // (n-1)C(r-1) ( for 1 indexing )
int getElement( int row, int col ){
    int res = 1;
    if( row == 0 )
        return 1;
    for( int i=0; i<row; i++ ){
        res *= (row-i);
        res /= (i+1);
        if( col == i+1 )
            return res;
    }
    return res;
}


int main(){
    int rows;    cin>>rows;
    
    // Find pascal's Triangle of n rows
    vector<vector<int>> pascal = generate_Pascals( rows );
    for( auto i : pascal ){
        for( auto j : i )
            cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;

    // Find nth Row of Pascal's triangle
    int row_no; cin>>row_no;
    vector<int> pascal_row = getRow( row_no );
    for( auto i : pascal_row )
        cout<<i<<" ";
    cout<<endl;

    // find value of pascal[row][col] // nCr ( for 0 indexing )
    int row, col ; cin>>row>>col;
    int val = getElement( row, col );
    cout<<"\n"<<val<<"\n";

    return 0;
}


// 5
// 6
// 6 3
// -------
// 1 
// 1 1 
// 1 2 1 
// 1 3 3 1 
// 1 4 6 4 1 
//
// 1 6 15 20 15 6 1
//
// 20