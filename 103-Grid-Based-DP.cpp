#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
#define int              long long
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
#define vpii             vector<pair<int,int>>
#define mii              map<int,int>
#define pqb              priority_queue<int>
#define pqs              priority_queue<int, vector<int>, greater<int>>
#define setbits(x)       __builtin_popcountll(x)
#define zrobits(x)       __builtin_ctzll(x)
#define mod              10000007
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
#define fr(t,a,b)        for( int t=(a); t<=(b); t++)


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




// QUE :- https://leetcode.com/problems/minimum-path-sum/
class Solution {
    int dp[105][105];
    int minCost(int r, int c, vector<vector<int>>& grid) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                // base case
                if (i == 0 and j == 0) dp[i][j] = grid[0][0];
                else if (i == 0) dp[i][j] = dp[0][j - 1] + grid[0][j];
                else if (j == 0) dp[i][j] = dp[i - 1][0] + grid[i][0];
                else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }
        return dp[r - 1][c - 1];
    }
public:

    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int r = grid.size(), c = grid[0].size();
        return minCost(r, c, grid);
    }

};




// Find no of ways
// QUE :- https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution2 {
    int dp[105][105];

public:
    // Rat version (Right & Down - 1 step) // N x M grid 
    // rat can take one step in rigth or down
    // By bottom up dp // O(N*M)
    int NumberOfPath(int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 and j == 0) dp[i][j] = 1;
                else if (i == 0 or j == 0) dp[i][j] = 1;
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[n - 1][m - 1];
    }

    // By maths P&C // O(N) // Risky due to factorial // best of less N
    int NumberOfPath2(int n, int m) {
        ll fact[100];
        fact[0] = fact[1] = 1;
        for (ll i = 2; i < 100; i++) fact[i] = fact[i - 1] * i;
        // for( ll i=0; i<15; i++) cout<<i<<sp<<fact[i]<<nl;

        int ans = fact[n + m - 2] / (fact[m - 1] * fact[n - 1]);
        return ans;
    }
};




// Find no of ways Elephant version
class Solution3 {
    int dp[105][105];
public:
    // Elephant can take any no of steps in rigth or down
    int numberOfPath(int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 and j == 0) dp[i][j] = 1;
                else {
                    int val = 0;
                    for (int k = 0; k <= i - 1; k++) val += dp[k][j];
                    for (int k = 0; k <= j - 1; k++) val += dp[i][k];
                    dp[i][j] = val;
                }
            }
        }

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<dp[i][j]<<sp;
        //     }
        //     cout<<nl;
        // }
        return dp[n - 1][m - 1];
    }

};













// Grid with obstacle problem
// find no of ways
// QUE :- https://www.codechef.com/problems/CD1IT4?tab=statement
// In this case top down approach will give TLE
int grid[1005][1005];

class Solution4 {
public:
    // Bottom up // O(r*c) // O(N*2)
    int noOfWays(int r, int c) {
        // check for 1st and last block, it is blocked or not
        if (grid[0][0] == -1 or grid[r - 1][c - 1] == -1) return 0;

        // compute for 1st col
        for (int i = 0; i < r; i++) {
            if (grid[i][0] == -1) break;
            grid[i][0] = 1;
        }

        // compute for 1st row
        for (int i = 0; i < c; i++) {
            if (grid[0][i] == -1) break;
            grid[0][i] = 1;
        }

        for (int i = 1;i < r; i++) {
            for (int j = 1;j < c; j++) {
                // if block is blocked leave it
                if (grid[i][j] == -1) continue;

                int val = 0;
                if (grid[i][j - 1] != -1) val = (val + grid[i][j - 1]) % mod;
                if (grid[i - 1][j] != -1) val = (val + grid[i - 1][j]) % mod;
                grid[i][j] = val;
            }
        }

        // for (int i = 0;i < r; i++) {
        //     for (int j = 0;j < c; j++) {
        //         cout<<grid[i][j]<<sp;
        //     }
        //     cout<<nl;
        // }

        return grid[r - 1][c - 1];
    }

    int noOfWays2(int r, int c) {
        if (grid[0][0] == -1 || grid[r - 1][c - 1] == -1) return 0;
        int dp[r][c] = { 0 }; // path from (r,c) to (i,j)
        dp[r - 1][c - 1] = 1;

        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                if (i == r - 1 && j == c - 1) continue;
                if (grid[i][j] == -1) dp[i][j] = 0;
                else {
                    int op1 = (i == r-1) ? 0 : dp[i + 1][j];
                    int op2 = (j == c-1) ? 0 : dp[i][j + 1];
                    dp[i][j] = (op1 + op2) % mod;
                }
            }
        }
        return dp[0][0];
    }


};











// Grid with obstacle // grid size : 1e5 * 1e5
// but no of obstacle is fixed
// find no of ways
// QUE :- https://atcoder.jp/contests/dp/tasks/dp_y


int h, w, n;
int fact[200005];
int invFact[200005];
vpii obs; // obstacle

bool comp(pii& p1, pii& p2) {
    return (p1.first + p1.second) < (p2.first + p2.second);
}


class Solution5 {
    int pwrMod(int a, int n) {
        int res = 1LL;
        while (n) {
            if ((n & 1)) res = (res * a) % mod;
            a = (a * a) % mod;
            n = n >> 1;
        }
        return res;
    }


    int inverse(int n) {
        return pwrMod(n, mod - 2);
    }


    void findFacts() {
        fact[0] = 1;
        invFact[0] = 1;
        for (int i = 1; i <= 200000; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
            invFact[i] = inverse(fact[i]);
        }
    }


    int nCrMod(int n, int r) {
        // return ((fact[n] * inv(fact[n - r])) % mod * inv(fact[r])) % mod;
        return ((fact[n] * invFact[n - r]) % mod * invFact[r]) % mod;
    }


    int pathsBetweenPts(pii a, pii b) {
        int right = b.first - a.first;
        int down = b.second - a.second;

        // if( a.first<=b.first && a.second<=b.second ){
        if (right >= 0 && down >= 0) {
            return nCrMod(right + down, down);
        }
        return 0;
    }


public:

    int solve() {
        findFacts();
        int ways = nCrMod(h + w - 2, h - 1); // total no of ways when there is no obstacle

        // sort the obstacle on the basis of manhatten distance
        sort(all(obs), comp);

        vi pathsToObs; // paths to obstacle
        pathsToObs.push_back(pathsBetweenPts({ 1,1 }, obs[0]));

        // calculate paths to obstacle 
        for (int i = 1; i < n; i++) {
            int paths = pathsBetweenPts({ 1, 1 }, obs[i]);
            for (int j = i - 1; j >= 0; j--) {
                paths = (paths - (pathsToObs[j] * pathsBetweenPts(obs[j], obs[i])) % mod + mod) % mod;
            }
            pathsToObs.push_back(paths);
        }

        for (int i = 0; i < n; i++) {
            ways = (ways - (pathsToObs[i] * pathsBetweenPts(obs[i], { h, w })) % mod + mod) % mod;
        }

        return ways;
    }

};





int32_t main() {
    fastIO();

    {
        Solution sol;
        vvi grid = { {1, 3, 1}, {1, 5, 1}, {4, 2, 1} };
        cout << sol.minPathSum(grid) << nl; // 11
    }
    cout << nl;




    {
        Solution2 sol2;
        cout << sol2.NumberOfPath(2, 2) << nl; // 2
        cout << sol2.NumberOfPath2(2, 2) << nl; // 2
        cout << sol2.NumberOfPath(3, 4) << nl; // 10
        cout << sol2.NumberOfPath2(3, 4) << nl; // 10

        cout << sol2.NumberOfPath(8, 15) << nl; // 116280
        // cout << sol2.NumberOfPath2(8, 15) << nl; // -9671 // Wrong
    }
    cout << nl;



    {
        Solution3 sol3;
        cout << sol3.numberOfPath(3, 5) << nl;
    }
    cout << nl;



    {
        Solution4 sol4;
        mems(grid, 0);
        int r, c, b; cin >> r >> c >> b;

        while (b--) {
            int x, y; cin >> x >> y;
            grid[x - 1][y - 1] = -1;
        }

        cout << sol4.noOfWays(r, c) << nl;
    }
    cout << nl;



    {
        Solution5 sol5;

        cin >> h >> w >> n;

        fr(i, 0, n - 1) {
            int u, v; cin >> u >> v;
            obs.pb({ u,v });
        }

        cout << sol5.solve() << nl;
    }


    cout << nl;
    return 0;
}

