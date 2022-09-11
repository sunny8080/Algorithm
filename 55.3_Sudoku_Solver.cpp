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


// YT - https://www.youtube.com/watch?v=FWAIf_EVUKE&ab_channel=takeUforward
class Solution {
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(i, j, c, board)) {
                            board[i][j] = c;
                            if (solve(board) == true)
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
    bool isValid(int row, int col, char c, vector<vector<char>>& board) {

        // int rn = sqrt(n);
        // int blockRow = (row/rn)*rn;
        // int blockCol = (col/rn)*rn; 

        int blockRow = 3 * (row / 3);
        int blockCol = 3 * (col / 3);
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) return false;

            if (board[i][col] == c) return false;

            if (board[blockRow + i / 3][blockCol + i % 3] == c) return false;
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
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


        vector<vector<int>> usedRow(9, vector<int>(9, 0));
        vector<vector<int>> usedCol(9, vector<int>(9, 0));
        vector<vector<int>> usedBox(9, vector<int>(9, 0));

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] != '.') {

                    int num = board[i][j] - '0' - 1;
                    int k = (i / 3) * 3 + j / 3;
                    if (usedRow[i][num] || usedCol[j][num] || usedBox[k][num])
                        return false;

                    usedRow[i][num] = usedCol[j][num] = usedBox[k][num] = 1;

                }

        return true;

    }
    int isSafe(vector<vector<char>>& board, int row, int col) {
        int item = board[row][col];
        int blockRow = 3 * (row / 3);
        int blockCol = 3 * (col / 3);
        for (int i = 0; i < 9; i++) {
            if (i != col && board[row][i] == item) return false;

            if (i != row && board[i][col] == item) return false;

            int x = blockRow + i / 3, y = blockCol + i % 3;
            if (x != row && y != col && board[x][y] == item) return false;
        }
        return true;
    }
};


// Solve Sudoku by Recursion and Backtracking
class Solution3 {

    bool isSafe(int mat[][9], int i, int j, int n, int number) {
        int rn = sqrt(n);
        int blockRow = (i / rn) * rn;
        int blockCol = (j / rn) * rn; // (blockRw, blockCol) - starting index of subgrid 

        for (int k = 0; k < n; k++) {
            // check col
            if (mat[k][j] == number) return false;

            // check row
            if (mat[i][k] == number) return false;

            // Check diagonal in sub grid
            if (mat[blockRow + k / 3][blockCol + k % 3] == number) return false;
        }

        // // Check diagonal in sub grid // by traversing that sub grid
        // for( int x=blockRow; x<blockRow+rn; x++ ){
        //     for( int y=blockCol; y<blockCol+rn; y++ ){
        //         if( mat[x][y] == number ) return false;
        //     }
        // }

        return true;
    }

public:
    bool solveSudoku(int mat[][9], int i, int j, int n) {
        // base case
        if (i == n) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << mat[i][j] << sp;
                }
                cout << nl;
            }
            return true;
        }

        // Case row end
        if (j == n) {
            return solveSudoku(mat, i + 1, 0, n);
        }

        // Skip pre-filled cells
        if (mat[i][j] != 0) {
            return solveSudoku(mat, i, j + 1, n);
        }

        // Rec case
        // Fill the current cell with possible oprions
        for (int number = 1; number <= 9; number++) {
            if (isSafe(mat, i, j, n, number)) {
                mat[i][j] = number;

                // Recursion
                if (solveSudoku(mat, i, j + 1, n)) return true;
            }
        }
        // Backtracking
        mat[i][j] = 0;
        return false;
    }

};

int32_t main() {
    Solution sol;
    vector<vector<char>> board;

    board = {   
                { '5'  ,  '3'  ,  '.'  ,  '.'  ,  '7'  ,  '.'  ,  '.'  ,  '.'  ,  '.'   },
                { '6'  ,  '.'  ,  '.'  ,  '1'  ,  '9'  ,  '5'  ,  '.'  ,  '.'  ,  '.'   },
                { '.'  ,  '9'  ,  '8'  ,  '.'  ,  '.'  ,  '.'  ,  '.'  ,  '6'  ,  '.'   },
                { '8'  ,  '.'  ,  '.'  ,  '.'  ,  '6'  ,  '.'  ,  '.'  ,  '.'  ,  '3'   },
                { '4'  ,  '.'  ,  '.'  ,  '8'  ,  '.'  ,  '3'  ,  '.'  ,  '.'  ,  '1'   },
                { '7'  ,  '.'  ,  '.'  ,  '.'  ,  '2'  ,  '.'  ,  '.'  ,  '.'  ,  '6'   },
                { '.'  ,  '6'  ,  '.'  ,  '.'  ,  '.'  ,  '.'  ,  '2'  ,  '8'  ,  '.'   },
                { '.'  ,  '.'  ,  '.'  ,  '4'  ,  '1'  ,  '9'  ,  '.'  ,  '.'  ,  '5'   },
                { '.'  ,  '.'  ,  '.'  ,  '.'  ,  '8'  ,  '.'  ,  '.'  ,  '7'  ,  '9'   }
            };

    for (int i = 0; i < board.size(); i++) {
        PRT(board[i]);
    }
    cout << nl << nl;

    sol.solveSudoku(board);

    for (int i = 0; i < board.size(); i++) {
        PRT(board[i]);
    }
    cout << "\n\n";



    // Solve sudoku by Recursion and Backtracking
    int mat[9][9] = {
                        { 5, 3, 0, 0, 7, 0, 0, 0, 0},
                        { 6, 0, 0, 1, 9, 5, 0, 0, 0},
                        { 0, 9, 8, 0, 0, 0, 0, 6, 0},
                        { 8, 0, 0, 0, 6, 0, 0, 0, 3},
                        { 4, 0, 0, 8, 0, 3, 0, 0, 1},
                        { 7, 0, 0, 0, 2, 0, 0, 0, 6},
                        { 0, 6, 0, 0, 0, 0, 2, 8, 0},
                        { 0, 0, 0, 4, 1, 9, 0, 0, 5},
                        { 0, 0, 0, 0, 8, 0, 0, 7, 9}
                    };
    Solution3 sol3;
    sol3.solveSudoku(mat, 0, 0, 9);


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


