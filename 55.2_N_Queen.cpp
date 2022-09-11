#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
#define ull              unsigned long long
#define ff               first
#define ss               second
#define pb               push_back
#define mp               make_pair
#define pii              pair<int,int>
#define vi               vector<int>
#define vll              vector<ll> 
#define vvi              vector< vector<int>>
#define vvll             vector< vector<ll>>
#define mii              map<int,int>
#define pqb              priority_queue<int>
#define pqs              priority_queue<int, vector<int>, greater<int>>
#define setbits(x)       __builtin_popcountll(x)
#define zrobits(x)       __builtin_ctzll(x)
#define mod              1000000007
#define inf              1e18
#define ps(x,y)          fixed<<setprecision(y)<<x
#define mk(arr, n, type) type *arr=new type[n];
#define wt(x)            int x; cin>>x; while( x-- )
#define rep(i,a,b)       for( int i=a; i<=b; i++ )
#define repi(i,a,b)      for( int i=a; i>=b; i-- )
#define sp               ' '
#define nl               char(10)
#define endl             char(10)
#define PRT(ar)          for( auto i : ar ) cout<<i<<sp; cout<<nl;
#define mems(x,ch)       memset(x,ch,sizeof(x))
#define sortv(x)         sort(x.begin(),x.end())
#define sortvr(x)        sort(x.rbegin(),x.rend())
#define all(x)           x.begin(), x.end()

const ll cnst = 1e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //    #ifndef ONLINE_JUDGE
    //        freopen("input.txt", "r", stdin);
    //        freopen("output.txt", "w", stdout);
    //    #endif
}

class Solution {
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int tmpRow = row;
        int tmpCol = col;

        // Check upper diagonal safety
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--, col--;
        }

        // check left row safety
        row = tmpRow;
        col = tmpCol;
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        // check lower diagonal safety
        row = tmpRow;
        col = tmpCol;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row++, col--;
        }
        return true;
    }

    // METHOD :- 1.1
    // Print only one possible configuration 
    bool findOneNQueen(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return true;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                if (findOneNQueen(col + 1, board, ans, n)) return true;

                // Backtracking
                board[row][col] = '.';
            }
        }
        return false;
    }


    // METHOD :- 1.1
    // Print all possible configuration using isSafe() // return bool if you to print one one configuration
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);

                // Backtracking
                board[row][col] = '.';
            }
        }
    }


    // METHOD :- 2
    // print all possible configuration by using bitset // here we r using vector instead of bitset array
    // https://www.youtube.com/watch?v=i05Ju7AftcM&ab_channel=takeUforward
    void solve2(int col, vi& leftRow, vi& upperDiagonal, vi& lowerDiagonal, vector<string>& board, vector<vector<string>>& ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {

                board[row][col] = 'Q';
                leftRow[row] = lowerDiagonal[row + col] = upperDiagonal[n - 1 + col - row] = 1;

                solve2(col + 1, leftRow, upperDiagonal, lowerDiagonal, board, ans, n);

                leftRow[row] = lowerDiagonal[row + col] = upperDiagonal[n - 1 + col - row] = 0;
                board[row][col] = '.';
            }
        }
    }


    // METHOD :- 3
    // More optimised N-Queen Code :
    /*
        rowMask denotes which positions(colms) in all rows are filled.
        ld, rd, denotes unsafe positons along diagonals for the current row.
        DONE is int which is vector of 111...111 ( n times 1).
        safe denotes the cols safe in the current row, where we can put Queen.
    */

    void solve3(int row, int rowMask, int ld, int rd, int n, vector<string>& board, vector<vector<string>>& ans, int DONE, int& cnt) {
        if (rowMask == DONE) {
            cnt++;
            ans.push_back(board);
            return;
        }

        int blocked = (rowMask | ld | rd);
        int safe = DONE & (~blocked);  // safe positions // 01001001 :- here {0, 3, 6} are safe positions means we can put Queen here

        while (safe) {
            // Traverse one safe position to another // 01001001 :- 0 to 3 to 6th position
            int pos = safe & (-safe);

            board[row][n - log2(pos) - 1] = 'Q';

            // solve3(row + 1, (rowMask | pos), ((ld << 1) | (pos << 1)), ((rd >> 1) | (pos >> 1)), n, board, ans, DONE);
            solve3(row + 1, (rowMask | pos), ((ld | pos) << 1), ((rd | pos) >> 1), n, board, ans, DONE, cnt);

            board[row][n - log2(pos) - 1] = '.';
            safe = safe - pos;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        // vector<vector<string>> ans;
        // string s(n,'.');
        // vector<string> board(n, s);
        // solve(0, board, ans, n );
        // return ans;



        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n, s);
        vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve2(0, leftrow, upperDiagonal, lowerDiagonal, board, ans, n);
        return ans;


        // vector<vector<string>> ans;
        // string s(n, '.');
        // vector<string> board(n, s);
        // int DONE = ((1 << n) - 1); // Binary of DONE is  [1 .... 1 ] // here 1 is n times
        // int cnt = 0;
        // solve3(0, 0, 0, 0, n, board, ans, DONE, cnt);
        // cout << "No. of possible solution : " << cnt << nl;
        // return ans;
    }
};

int32_t main() {
    fastIO();

    Solution sol;

    // int n; cin>>n;
    int n = 4;
    auto ans = sol.solveNQueens(n);

    for (auto board : ans) {
        for (auto str : board) {
            cout << str << nl;
        }
        cout << nl << nl;
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

