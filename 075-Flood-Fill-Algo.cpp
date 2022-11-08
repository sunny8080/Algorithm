#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
// #define int              long long
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

const ll N = 1e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}



class Solution {

public:
    void printMat(vector<string> &mat) {
        for( int i=0; i<mat.size(); i++ ){
            for( int j=0; j<mat[i].size(); j++){
                cout<<mat[i][j];
            }
            cout<<nl;
        }
    }

    // Flood fill by Recursion // O(R*C) time
    void floodFill(vector<string> &mat, int r, int c, int i, int j, char ch, char color) {
        // matrix boundry check 
        if( i<0 || j<0 || i>=r || j>=c){
            return;
        }

        // Figure boundry check
        if( mat[i][j] != ch){
            return;
        }
        
        vector<pair<int,int>> ways= {{0, 1}, {0, -1}, {1, 0},{-1,0}};
        mat[i][j] = color;

        for( auto x : ways){
            floodFill(mat, r, c, i+x.first, j+x.second, ch, color);
        }
    }





    // Check coordinate is valid or not // check matrix boundry
    bool isValidCord(int i, int j, int r, int c){
        if( i<0 || j<0 || i>=r || j>=c) return 0;
        return 1;
    }

    // Flood fill by BFS // O(R*C) time
    void floodFillByBFS(vector<string> &mat, int r, int c, int x, int y, char prevColor, char color){
        vvi vis(r, vector<int>(c,0));
        queue<pair<int,int>> q;

        vector<pair<int, int>> ways = { {0, 1}, {0, -1}, {1, 0},{-1,0} };

        q.push({x, y});
        vis[x][y] = 1;

        while( ! q.empty()){
            auto tmp = q.front();
            q.pop();

            int x,y;
            tie(x, y) = make_pair(tmp.first, tmp.second);    
            mat[x][y] = color;

            for( auto w : ways ){
                int i, j;
                tie(i,j)=make_pair(x+w.first, y+w.second);
                if( isValidCord(i, j, r, c) && vis[i][j] == 0 && mat[i][j] == prevColor){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
    }

};



int32_t main() {
    fastIO();
    Solution sol;
    
    // int r, c; 
    // cin>>r>>c;
    // vector<string> mat(r);

    // for( int i=0; i<r; i++){
    //     cin>>mat[i];
    // }

    vector<string> mat = {  "..................................", 
                            "..............######..............", 
                            "..............#....#..............",
                            "..............#....#..............",
                            "..........#####....######.........",
                            "....######....######.....####.....",
                            "...##........................##...",
                            "..##..........................##..",
                            ".##............................##.",
                            "..##..........................##..",
                            "...##........................##...",
                            "....##......................##....",
                            "......##...................##.....",
                            ".......##.................##......",
                            "........##...............##.......",
                            ".........###...........###........",
                            "...........###.......###..........",
                            ".............#########............",
                            "..................................",
                            "..............APPLE..............."
                        };

    int r = mat.size(), c = mat[0].size();
    // sol.printMat(mat);
    cout<<nl<<nl;

    // sol.floodFill(mat, r, c, 8, 10, '.', 'R');
    // sol.floodFill(mat, r, c, 0, 0, '.', '!');
    // sol.floodFill(mat, r, c, 2, 15, '.', ' ');


    sol.floodFillByBFS(mat, r, c, 8, 10, '.', 'R');
    sol.floodFillByBFS(mat, r, c, 0, 0, '.', '!');
    // sol.floodFillByBFS(mat, r, c, 2, 15, '.', ' ');



    sol.printMat(mat);

    return 0;
}
    
    
// OUTPUT :-
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!######!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!#....#!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!#....#!!!!!!!!!!!!!!
// !!!!!!!!!!#####....######!!!!!!!!!
// !!!!######RRRR######RRRRR####!!!!!
// !!!##RRRRRRRRRRRRRRRRRRRRRRRR##!!!
// !!##RRRRRRRRRRRRRRRRRRRRRRRRRR##!!
// !##RRRRRRRRRRRRRRRRRRRRRRRRRRRR##!
// !!##RRRRRRRRRRRRRRRRRRRRRRRRRR##!!
// !!!##RRRRRRRRRRRRRRRRRRRRRRRR##!!!
// !!!!##RRRRRRRRRRRRRRRRRRRRRR##!!!!
// !!!!!!##RRRRRRRRRRRRRRRRRRR##!!!!!
// !!!!!!!##RRRRRRRRRRRRRRRRR##!!!!!!
// !!!!!!!!##RRRRRRRRRRRRRRR##!!!!!!!
// !!!!!!!!!###RRRRRRRRRRR###!!!!!!!!
// !!!!!!!!!!!###RRRRRRR###!!!!!!!!!!
// !!!!!!!!!!!!!#########!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!APPLE!!!!!!!!!!!!!!!