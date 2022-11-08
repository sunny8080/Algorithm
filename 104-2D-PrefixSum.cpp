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




/*
{
    Gold Grid(Hackerblocks)

    Sayan's friend has left a game field organized as an N*N grid. Each square in the grid either has or does not have a gold coin He has to divide the gamefield with his three other friends as follows : he will draw one horizontal line and one vertical line to divide the field into four rectangles. His friends will choose three of the four smaller fields and he gets the last one. He wants to divide the field so that he gets the maximum number of gold coins, assuming that his friends will pick the best three rectangles.
    1 <= N <= 1000


    6 13
    1 2
    1 3
    2 1
    2 4
    2 5
    3 2
    4 2
    4 3
    4 6
    5 1
    5 4
    5 5
    6 2


    // OUT :- 3 2
}
*/



int dp[1005][1005];

class Solution {

public:
    void solve(int n) {
        // calculate prefix sum
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 and j == 0) dp[i][j] += 0;
                else if (i == 0) dp[i][j] += dp[i][j - 1];
                else if (j == 0) dp[i][j] += dp[i - 1][j];
                else {
                    dp[i][j] += dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
                }
            }
        }

        int mxGold = 0, x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // prefix sum
                int gold1 = dp[i][j];
                int gold2 = dp[i][n - 1] - dp[i][j];
                int gold3 = dp[n - 1][j] - dp[i][j];
                int gold4 = dp[n - 1][n - 1] - gold1 - gold2 - gold3;

                int mn = min({ gold1, gold2, gold3, gold4 });
                if (mn > mxGold) {
                    mxGold = mn, x = i, y = j;
                }
            }
        }

        // cout << "Maximum gold he will get : " << mxGold << nl;
        cout << x + 1 << sp << y + 1 << nl;
    }

};



int32_t main() {
    fastIO();
    Solution sol;

    mems(dp, 0);
    int n, m; cin >> n >> m;

    while (m--) {
        int x, y; cin >> x >> y;
        dp[x - 1][y - 1] = 1;
    }
    sol.solve(n);


    return 0;
}

