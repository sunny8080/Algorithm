#include<bits/stdc++.h>
#define ll long long
#define wt(x) int x; cin>>x; while( x-- )
#define REP(i,n) for( int i=0; i<n; i++ )
#define REPc(i,a,b) for( int i=a; i<b; i++ )
#define REPi(i,n) for( int i=n-1; i>=0; i-- )
#define REPci(i,a,b) for( int i=a; i>=b; i-- )
#define sp ' '
#define nl char(10)
#define endl char(10)
#define MOD 1000000007
#define vi vector<int>
#define vvi vector< vector<int> >
#define vll vector<long long> 
#define vvll vector< vector<long long> >
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define PRT(ar) for( auto i : ar )cout<<i<<sp;cout<<nl;
using namespace std;

class Solution {
    bool isSafe( int row, int col, vector<string> &board, int n ){
        int tmpRow = row;
        int tmpCol = col;

        // Check upper diagonal safety
        while( row >=0 && col >= 0 ){
            if( board[row][col] == 'Q' ) return false;
            row--, col--;
        }

        // check left row safety
        row = tmpRow;
        col = tmpCol;
        while( col >= 0 ){
            if( board[row][col] == 'Q' ) return false;
            col--;
        }

        // check lower diagonal safety
        row = tmpRow;
        col = tmpCol;
        while( row < n && col>=0 ){
            if( board[row][col] == 'Q' ) return false;
            row++, col-- ;
        }
        return true;
    }
    void solve( int col, vector<string> &board, vector<vector<string>> &ans, int n ){
        if( col == n ){
            ans.push_back(board);
            return;
        }
        for( int row=0; row<n; row++ ){
            if( isSafe( row, col, board, n ) ){
                board[row][col] = 'Q';
                solve( col+1, board, ans, n );
                board[row][col] = '.';
            }
        }
    }

    void solve2( int col, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, vector<string> &board, vector<vector<string>> &ans, int n ){
        if( col == n ){
            ans.push_back(board);
            return;
        }
        for( int row=0; row<n; row++ ){
            if( leftRow[row] ==0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1 + col - row ] == 0 ){

                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1+col-row] = 1;

                solve2( col+1, leftRow, upperDiagonal, lowerDiagonal, board, ans, n );

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1+col-row] = 0;

            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {

        // vector<vector<string>> ans;
        // vector<string> board(n);
        // string s(n,'.');
        // for( int i=0; i<n; i++ ) board[i] = s;
        // solve(0, board, ans, n );
        // return ans;



        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for( int i=0; i<n; i++ ) board[i] = s;
        vector<int> leftrow(n,0), upperDiagonal( 2*n-1, 0 ), lowerDiagonal( 2*n-1, 0 );
        solve2( 0, leftrow, upperDiagonal, lowerDiagonal, board, ans, n );
        return ans;
    }
};

int32_t main(){
    Solution sol;
    vector<vector<string>> ans;

    int n=4;
    ans = sol.solveNQueens(n);
    
    for( int i=0; i<ans.size(); i++ ){
        for( int j=0; j<ans[0].size(); j++ )
            cout<<ans[i][j]<<nl;
        cout<<nl<<nl;
    }

    return 0;
}


// ..Q.
// Q...
// ...Q
// .Q..
//
//
// .Q..
// ...Q
// Q...
// ..Q.