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



// Cherry Pickup II
// QUE :- https://leetcode.com/problems/cherry-pickup-ii/description/


class Solution {
    int cherryPickupHelp(int i, int j1, int j2, vector<vector<vector<int>>>& dp, vector<vector<int>>& g) {
        if (j1 < 0 || j1 >= g[0].size() || j2 < 0 || j2 >= g[0].size()) return -1e8;
        if (i == g.size() - 1) return j1 == j2 ? g[i][j1] : g[i][j1] + g[i][j2];
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1e8;
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                int tmp = j1 == j2 ? g[i][j1] : g[i][j1] + g[i][j2];
                maxi = max(maxi, tmp + cherryPickupHelp(i + 1, j1 + d1, j2 + d2, dp, g));
            }
        }
        return dp[i][j1][j2] = maxi;
    }


public:
    // TCO(N*M*M)  // SCO(N*M*M + N)
    int cherryPickup1(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector < vector<vector<int>> > dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return cherryPickupHelp(0, 0, m - 1, dp, g);
    }


    // TCO(N*M*M)  // SCO(N*M*M)
    int cherryPickup2(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector < vector<vector<int>> > dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                dp[n - 1][j1][j2] = j1 == j2 ? g[n - 1][j1] : g[n - 1][j1] + g[n - 1][j2];
            }
        }

        auto isValid = [&m](int j) {
            return j >= 0 && j < m;
        };

        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e8;

                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {
                            int tmp = j1 == j2 ? g[i][j1] : g[i][j1] + g[i][j2];
                            if (isValid(j1 + d1) && isValid(j2 + d2)) tmp += dp[i + 1][j1 + d1][j2 + d2];
                            else tmp += -1e8;
                            maxi = max(maxi, tmp);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m - 1];
    }




    // TCO(N*M*M)  // SCO(M*M)
    int cherryPickup(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector< vector<int>> next(m, vector<int>(m, 0)), cur(m, vector<int>(m, 0));

        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                next[j1][j2] = j1 == j2 ? g[n - 1][j1] : g[n - 1][j1] + g[n - 1][j2];
            }
        }

        auto isValid = [&m](int j) {
            return j >= 0 && j < m;
        };

        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e8;

                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {
                            int tmp = j1 == j2 ? g[i][j1] : g[i][j1] + g[i][j2];
                            if (isValid(j1 + d1) && isValid(j2 + d2)) tmp += next[j1 + d1][j2 + d2];
                            else tmp += -1e8;
                            maxi = max(maxi, tmp);
                        }
                    }
                    cur[j1][j2] = maxi;
                }
            }
            next = cur;
        }
        return next[0][m - 1];
    }
};

int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



