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



// Rat version (Right & Down - 1 step) // N x M grid 
// rat can take one step in rigth or down :- 

// Unique Path 1 :- Find no of ways / unique paths
// QUE :- https://leetcode.com/problems/unique-paths/description/
class Solution1 {
    int uniquePathsHelp1(int i, int j) {
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        return uniquePathsHelp1(i - 1, j) + uniquePathsHelp1(i, j - 1);
    }



    int uniquePathsHelp2(int i, int j, vector< vector<int>>& dp) {
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = uniquePathsHelp2(i - 1, j, dp) + uniquePathsHelp2(i, j - 1, dp);
    }
public:
    // only recursion : TC : O(2^(m*n))  // SC : O(m+n)
    int uniquePaths1(int m, int n) {
        return uniquePathsHelp1(m - 1, n - 1);
    }



    // top down dp : TC : O(m*n)  // SC : O(n*m + m + n)
    int uniquePaths2(int m, int n) {
        vector< vector<int>> dp(m, vector<int>(n, -1));
        return uniquePathsHelp2(m - 1, n - 1, dp);
    }


    // bottom up dp : TC : O(m*n)  // SC : O(n*m)
    int uniquePaths3(int m, int n) {
        vector< vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) dp[i][j] = 1;
                else {
                    int up = i >= 1 ? dp[i - 1][j] : 0;
                    int left = j >= 1 ? dp[i][j - 1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }


    // bottom up dp with space optimization : TC : O(m*n)  // SC : O(n)
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) cur[j] = 1;
                else {
                    int up = i >= 1 ? prev[j] : 0;
                    int left = j >= 1 ? cur[j - 1] : 0;
                    cur[j] = up + left;
                }
            }
            prev = cur;
        }
        return prev[n - 1];
    }

};







// Unique path 2
// QUE :- https://leetcode.com/problems/unique-paths-ii/description/
class Solution2 {
    int uniquePathsWithObstaclesHelp(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& g) {
        if (i < 0 || j < 0 || g[i][j]) return 0;
        if (i == 0 && j == 0) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = uniquePathsWithObstaclesHelp(i, j - 1, dp, g) + uniquePathsWithObstaclesHelp(i - 1, j, dp, g);
    }


public:

    // TO(n*m)   // SO(n*m + n+m)
    int uniquePathsWithObstacles1(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return uniquePathsWithObstaclesHelp(n - 1, m - 1, dp, g);
    }

    // TO(n*m)   // SO(n*m)
    int uniquePathsWithObstacles2(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j]) dp[i][j] = 0;
                else if (i == 0 && j == 0) dp[i][j] = 1;
                else {
                    int up = i >= 1 ? dp[i - 1][j] : 0;
                    int left = j >= 1 ? dp[i][j - 1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[n - 1][m - 1];
    }


    // TO(n*m)   // SO(n)
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<int> prev(m, 0), cur(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j]) cur[j] = 0;
                else if (i == 0 && j == 0) cur[j] = 1;
                else {
                    int up = i >= 1 ? prev[j] : 0;
                    int left = j >= 1 ? cur[j - 1] : 0;
                    cur[j] = up + left;
                }
            }
            prev = cur;
        }
        return prev[m - 1];
    }
};







// Minimum path
// QUE :- https://leetcode.com/problems/minimum-path-sum/description/
class Solution3 {
    int minPathSumHelp(int i, int j, vector< vector<int>>& dp, vector< vector<int>>& g) {
        if (i < 0 || j < 0) return INT_MAX;
        if (i == 0 && j == 0) return g[0][0];
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = g[i][j] + min(minPathSumHelp(i - 1, j, dp, g), minPathSumHelp(i, j - 1, dp, g));
    }
public:
    int minPathSum1(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // dp[i][j] = min path sum from (0, 0) to (i, j)
        vector< vector<int>> dp(n, vector<int>(m, -1));
        return minPathSumHelp(n - 1, m - 1, dp, grid);
    }


    int minPathSum2(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector< vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) dp[i][j] = grid[i][j];
                else {
                    int up = i >= 1 ? grid[i][j] + dp[i - 1][j] : INT_MAX;
                    int left = j >= 1 ? grid[i][j] + dp[i][j - 1] : INT_MAX;
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[n - 1][m - 1];
    }


    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> prev(m, 0), cur(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) cur[j] = grid[i][j];
                else {
                    int up = i >= 1 ? grid[i][j] + prev[j] : INT_MAX;
                    int left = j >= 1 ? grid[i][j] + cur[j - 1] : INT_MAX;
                    cur[j] = min(up, left);
                }
            }
            prev = cur;
        }
        return prev[m - 1];
    }
};






// fixed starting point, variable ending point
// always start recursion from fixed point in recursion (Top Down)
// Triangle ( minimum path sum )
// QUE :- https://leetcode.com/problems/triangle/

class Solution4 {
    int minimumTotalHelp(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& tri) {
        if (i == tri.size() - 1) return tri[i][j];
        if (dp[i][j] != -1) return dp[i][j];
        int down = minimumTotalHelp(i + 1, j, dp, tri);
        int dia = minimumTotalHelp(i + 1, j + 1, dp, tri);
        return dp[i][j] = tri[i][j] + min(down, dia);
    }
public:
    // TCO(n*n) // SCO(n*n + n)
    int minimumTotal1(vector<vector<int>>& tri) {
        int n = tri.size();
        vector< vector<int>> dp(n, vector<int>(n, -1));
        return minimumTotalHelp(0, 0, dp, tri);
    }


    // TCO(n*n) // SCO(n*n)
    int minimumTotal2(vector<vector<int>>& tri) {
        int n = tri.size();
        vector< vector<int>> dp(n, vector<int>(n, 0));
        // base case
        for (int j = 0; j < n; j++) dp[n - 1][j] = tri[n - 1][j];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                dp[i][j] = tri[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }


    // TCO(n*n) // SCO(2*n)
    int minimumTotal3(vector<vector<int>>& tri) {
        int n = tri.size();
        vector<int> next(n), cur(n, 0);
        for (int j = 0; j < n; j++) next[j] = tri[n - 1][j];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                cur[j] = tri[i][j] + min(next[j], next[j + 1]);
            }
            next = cur;
        }
        return next[0];
    }


    // TCO(n*n) // SCO(n)
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        vector<int> next(n);
        for (int j = 0; j < n; j++) next[j] = tri[n - 1][j];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                next[j] = tri[i][j] + min(next[j], next[j + 1]);
            }
        }
        return next[0];
    }
};





// variable starting point, variable ending point
// Minimum Falling Path Sum
// QUE :- https://leetcode.com/problems/minimum-falling-path-sum/description/

class Solution5 {
    int minFallingPathSumHelp(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& mat) {
        if (j < 0 || j >= mat[0].size()) return INT_MAX;
        if (i == 0) return mat[i][j];
        if (dp[i][j] != -1) return dp[i][j];
        int up = minFallingPathSumHelp(i - 1, j, dp, mat); ;
        int leftDia = minFallingPathSumHelp(i - 1, j - 1, dp, mat);
        int rightDia = minFallingPathSumHelp(i - 1, j + 1, dp, mat);
        return dp[i][j] = mat[i][j] + min({ up, leftDia, rightDia });
    }
public:
    // TCO(N*M) // SCO(N*M + N)
    int minFallingPathSum1(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = INT_MAX;
        for (int j = 0; j < m; j++) ans = min(ans, minFallingPathSumHelp(n - 1, j, dp, mat));
        return ans;
    }

    // TCO(N*M) // SCO(N*M)
    int minFallingPathSum2(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0) dp[i][j] = mat[i][j];
                else {
                    int up = dp[i - 1][j];
                    int leftDia = j - 1 >= 0 ? dp[i - 1][j - 1] : INT_MAX;
                    int rightDia = j + 1 < m ? dp[i - 1][j + 1] : INT_MAX;
                    dp[i][j] = mat[i][j] + min({ up, leftDia, rightDia });
                }
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }



    // TCO(N*M) // SCO(M)
    int minFallingPathSum4(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> prev(m, 0), cur(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0) cur[j] = mat[i][j];
                else {
                    int up = prev[j];
                    int leftDia = j - 1 >= 0 ? prev[j - 1] : INT_MAX;
                    int rightDia = j + 1 < m ? prev[j + 1] : INT_MAX;
                    cur[j] = mat[i][j] + min({ up, leftDia, rightDia });
                }
            }
            prev = cur;
        }
        return *min_element(prev.begin(), prev.end());
    }


    // TCO(N*M) // SCO(1)
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] += min({ mat[i - 1][j],
                                    j - 1 >= 0 ? mat[i - 1][j - 1] : INT_MAX,
                                    j + 1 < m ? mat[i - 1][j + 1] : INT_MAX,
                    });
            }
        }
        return *min_element(mat[n - 1].begin(), mat[n - 1].end());
    }

};










// Find no of ways Elephant version
class Solution6 {
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


class Solution7 {
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
    // Solution sol;



    return 0;
}




