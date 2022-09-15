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

void fastIO(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    #endif
}

// QUE :- https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/
/*  Also go to, 26_Rat_in_a_maze.cpp for
    https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*/
class Solution {
    
    public:

    // When rat can only go in right and down direction
    bool ratInMaze(char maze[10][10], int soln[10][10], int i, int j, int m, int n ){
        if( i==m-1 and j==n-1 and maze[i][j]=='1' ){
            soln[m-1][n-1] = 1;

            // print path
            for( int a=0; a<m; a++ ){
                for( int b=0; b<n; b++ ){
                    cout<<soln[a][b]<<sp;
                }
                cout<<nl;
            }
            cout<<nl;
            return true;
        }

        // Rat should not go out of boundry
        if( i==m || j==n ){
            return false;
        }

        // can't go if there is a obstacle
        if( maze[i][j] == '0' ){
            return false;
        }

        // Return false if path is already visited
        if(soln[i][j] == 1 ){
            return false;
        }

        soln[i][j] = 1;

        bool rightSuccess = ratInMaze(maze, soln, i, j+1, m, n);
        bool downSuccess = ratInMaze(maze, soln, i+1, j, m, n);

        // Backtracking
        soln[i][j] = 0;
        
        if( rightSuccess || downSuccess ){
            return true;
        }
        return false;
    }
};



int32_t main(){
    fastIO();
    
    int m=4, n=4;
    char maze[10][10] = {
        "1111",
        "1101",
        "1110",
        "1011"
    };
    // char maze[10][10] = {
    //     "1111",
    //     "1101",
    //     "1110",
    //     "1010"
    // };

    int soln[10][10] = { 0 };
    Solution sol;
    bool ans = sol.ratInMaze(maze, soln, 0, 0, m, n);

    if (ans == false) {
        cout << "Path doesn't exist" << nl;
    }


    cout<<"Maze 2 : "<<nl;
    mems(soln, 0);
    m=n=4;
    char maze2[10][10] = {  "1000",
                            "1101",
                            "0100",
                            "1111"  };

    ans = sol.ratInMaze(maze2, soln, 0, 0, m, n);

    if (ans == false) {
        cout << "Path doesn't exist" << nl;
    }   
    

    return 0;
}
    
    
// 1 1 0 0
// 0 1 0 0
// 0 1 1 0
// 0 0 1 1

// 1 1 0 0
// 1 1 0 0
// 0 1 1 0
// 0 0 1 1

// 1 1 0 0
// 1 1 0 0
// 1 1 1 0
// 0 0 1 1

// Maze 2 :
// 1 0 0 0
// 1 1 0 0
// 0 1 0 0
// 0 1 1 1