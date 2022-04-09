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
    bool solve( vector<vector<char>> &board ){
        for( int i=0; i<board.size(); i++ ){
            for( int j=0; j<board[0].size(); j++ ){

                if( board[i][j] == '.' ){
                    for( char c='1'; c<='9'; c++ ){
                        if( isValid( i, j, c, board ) ){
                            board[i][j] = c;
                            if( solve(board) == true )
                                return true;
                            else 
                                board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }
    bool isValid( int row, int col, char c, vector<vector<char>> &board ){
        int blockRow = 3*(row/3) ;
        int blockCol = 3*(col/3) ;
        for( int i=0; i<9; i++ ){
            if( board[row][i] == c ) return false;

            if( board[i][col] == c ) return false;

            if(  board[ blockRow + i/3][blockCol + i%3 ] == c ) return false;
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>> &board) {
        solve(board);
    }
};


// To check A partially filled pseudo board is valid or not...
class Solution2 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // for( int i=0; i<board.size(); i++ ){
        //     for( int j=0; j<board[i].size(); j++){
        //         if( board[i][j] != '.' && !isSafe(board, i, j ) )
        //             return false;
        //     }
        // }
        // return true;


        vector<vector<int>> usedRow(9,vector<int>(9,0));
        vector<vector<int>> usedCol(9,vector<int>(9,0));
        vector<vector<int>> usedBox(9,vector<int>(9,0));

        for( int i=0; i<board.size(); i++ )
            for( int j=0; j<board[i].size(); j++ )
                if( board[i][j] != '.' ){

                    int num = board[i][j]-'0' - 1 ;
                    int k = (i/3)*3 + j/3;
                    if( usedRow[i][num] || usedCol[j][num] || usedBox[k][num] )
                        return false;
                    
                    usedRow[i][num] = usedCol[j][num] = usedBox[k][num] = 1;

                }

        return true;

    }
    int isSafe( vector<vector<char>> &board, int row, int col ){
        int item = board[row][col];
        int blockRow = 3*(row/3);
        int blockCol = 3*(col/3);
        for( int i=0; i<9; i++ ){
            if( i != col && board[row][i] == item ) return false;

            if( i != row && board[i][col] == item ) return false;

            int x=blockRow + i/3, y=blockCol + i%3 ;
            if( x!=row && y!=col && board[x][y] == item ) return false;
        }
        return true;
    }
};

int32_t main(){
    Solution sol;
    vector<vector<char>> board;

    board ={ { '5'  ,  '3'  ,  '.'  ,  '.'  ,  '7'  ,  '.'  ,  '.'  ,  '.'  ,  '.'   },
             { '6'  ,  '.'  ,  '.'  ,  '1'  ,  '9'  ,  '5'  ,  '.'  ,  '.'  ,  '.'   },
             { '.'  ,  '9'  ,  '8'  ,  '.'  ,  '.'  ,  '.'  ,  '.'  ,  '6'  ,  '.'   },
             { '8'  ,  '.'  ,  '.'  ,  '.'  ,  '6'  ,  '.'  ,  '.'  ,  '.'  ,  '3'   },
             { '4'  ,  '.'  ,  '.'  ,  '8'  ,  '.'  ,  '3'  ,  '.'  ,  '.'  ,  '1'   },
             { '7'  ,  '.'  ,  '.'  ,  '.'  ,  '2'  ,  '.'  ,  '.'  ,  '.'  ,  '6'   },
             { '.'  ,  '6'  ,  '.'  ,  '.'  ,  '.'  ,  '.'  ,  '2'  ,  '8'  ,  '.'   },
             { '.'  ,  '.'  ,  '.'  ,  '4'  ,  '1'  ,  '9'  ,  '.'  ,  '.'  ,  '5'   },
             { '.'  ,  '.'  ,  '.'  ,  '.'  ,  '8'  ,  '.'  ,  '.'  ,  '7'  ,  '9'   } 
           };

    for( int i=0; i<board.size(); i++ ){
        PRT( board[i] );
    }
    cout<<nl<<nl;

    sol.solveSudoku(board);

    for( int i=0; i<board.size(); i++ ){
        PRT( board[i] );
    }

    
    return 0;
}


// 5 3 . . 7 . . . . 
// 6 . . 1 9 5 . . . 
// . 9 8 . . . . 6 . 
// 8 . . . 6 . . . 3 
// 4 . . 8 . 3 . . 1 
// 7 . . . 2 . . . 6 
// . 6 . . . . 2 8 . 
// . . . 4 1 9 . . 5 
// . . . . 8 . . 7 9 
//
//
// 5 3 4 6 7 8 9 1 2 
// 6 7 2 1 9 5 3 4 8 
// 1 9 8 3 4 2 5 6 7 
// 8 5 9 7 6 1 4 2 3 
// 4 2 6 8 5 3 7 9 1 
// 7 1 3 9 2 4 8 5 6 
// 9 6 1 5 3 7 2 8 4 
// 2 8 7 4 1 9 6 3 5 
// 3 4 5 2 8 6 1 7 9