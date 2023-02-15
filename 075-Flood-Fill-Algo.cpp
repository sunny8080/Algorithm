#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll                 long long
// #define int                long long
#define ull                unsigned long long
#define ff                 first
#define ss                 second
#define pb                 push_back
#define mp                 make_pair
#define pii                pair<int,int>
#define vi                 vector<int>
#define vll                vector<ll> 
#define vvi                vector< vector<int>>
#define vvll               vector< vector<ll>>
#define vpii               vector<pair<int,int>>
#define mii                map<int,int>
#define pqb                priority_queue<int>
#define pqs                priority_queue<int, vector<int>, greater<int>>
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define mod                1000000007
#define inf                1e18
#define ps(x,y)            fixed<<setprecision(y)<<x
#define mk(arr, n, type)   type *arr=new type[n];
#define wt(x)              int x; cin>>x; while( x-- )
#define sp                 ' '
#define nl                 char(10)
#define PRT(ar)            for( auto i : ar ) cout<<i<<sp; cout<<nl;
#define mems(x,ch)         memset(x,ch,sizeof(x))
#define sortv(x)           sort(x.begin(),x.end())
#define sortvr(x)          sort(x.rbegin(),x.rend())
#define all(x)             x.begin(), x.end()
#define fr(t,a,b)          for( int t=(a); t<=(b); t++)
#define frr(t,a,b)         for( int t=(a); t>=(b); t--)
#define cn(x)              int x; cin>>x;
#define ri(x)              cin >> x
#define rii(x, y)          cin >> x >> y
#define riii(x, y, z)      cin >> x >> y >> z
#define riiii(x, y, z, w)  cin >> x >> y >> z >> w
#define rvi(nums)          for (auto& x : nums) cin >> x;
#define dri(x)             int x; cin >> x
#define drs(s)             string s; cin >> s
#define drii(x, y)         int x, y; cin >> x >> y
#define driii(x, y, z)     int x, y, z; cin >> x >> y >> z
#define driiii(x, y, z, w) int x, y, z, w; cin >> x >> y >> z >> w
#define drvi(nums, n)      vector<int> nums(n); for (auto& x : nums) cin >> x;
#define iff(x, y)  if(x) y

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

    void dfs(int i, int j, char pre, char clr, vector<string>& img) {
        int n = img.size(), m = img[0].size();
        int way[][2] = { { 1,  0}, {-1, 0}, {0, -1}, {0, 1} };

        img[i][j] = clr;
        for (auto w : way) {
            int x = i + w[0], y = j + w[1];
            if (x < n && y < m && x >= 0 && y >= 0 && img[x][y] == pre) dfs(x, y, pre, clr, img);
        }
    }

public:

    void printMat(vector<string>& mat) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                cout << mat[i][j];
            }
            cout << nl;
        }
    }
    vector<string> floodFill(vector<string>& image, int sr, int sc, char clr) {
        vector<string> img = image;
        if (img[sr][sc] == clr) return img;
        dfs(sr, sc, img[sr][sc], clr, img);
        return img;
    }
};










class Solution2 {
    // O(N*M)
    void dfs(int i, int j, int pre, int clr, vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        int way[][2] = { { 1,  0}, {-1, 0}, {0, -1}, {0, 1} };

        img[i][j] = clr;
        for (auto w : way) {
            int x = i + w[0], y = j + w[1];
            if (x < n && y < m && x >= 0 && y >= 0 && img[x][y] == pre) dfs(x, y, pre, clr, img);
        }
    }


    void bfs(int i, int j, int pre, int clr, vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        int way[][2] = { { 1,  0}, {-1, 0}, {0, -1}, {0, 1} };
        queue<pair<int, int>> q;
        img[i][j] = clr;
        q.push({ i, j });

        while (q.size()) {
            int i = q.front().first, j = q.front().second;
            q.pop();

            for (auto w : way) {
                int x = i + w[0], y = j + w[1];
                if (x < n && y < m && x >= 0 && y >= 0 && img[x][y] == pre) q.push({ x,y }), img[x][y] = clr;
            }
        }
    }



public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int clr) {
        vector<vector<int>> img = image;
        if (img[sr][sc] == clr) return img;
        dfs(sr, sc, img[sr][sc], clr, img);
        // dfs(sr, sc, img[sr][sc], clr, img);
        return img;
    }
};






int32_t main() {
    fastIO();
    Solution sol;


    vector<string> mat = { "..................................",
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




    // sol.printMat(mat);

    // auto mat2 = sol.floodFill(mat, 0, 0, '!');
    // auto mat2 = sol.floodFill(mat, 2, 15, ' ');
    auto mat2 = sol.floodFill(mat, 8, 10, 'R');

    sol.printMat(mat2);


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


