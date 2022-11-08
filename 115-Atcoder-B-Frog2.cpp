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


// QUE :- https://atcoder.jp/contests/dp/tasks/dp_b


int ht[100005];
int dp[100005];
int n, k;

class Solution {

public:
    // Top Down
    int solve1(int i = 1) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        int val = INT_MAX;
        for (int j = 1; j <= k; j++) {
            val = min(val, (j > n - i) ? INT_MAX : abs(ht[i] - ht[i + j]) + solve1(i + j));
        }

        return dp[i] = val;
    }

    // Bottom up
    int solve2() {
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            // int val = INT_MAX;
            // for (int j = 1; j <= k; j++) {
            //     val = min(val, (j >= i) ? INT_MAX : abs(ht[i] - ht[i - j]) + dp[i - j]);
            // }
            // dp[i] = val;

            dp[i] = INT_MAX;
            for (int j = i - 1; j >= 1 && (i - j) <= k; j--) {
                dp[i] = min(dp[i], abs(ht[i] - ht[j]) + dp[j]);
            }
        }
        return dp[n];
    }

};



int32_t main() {
    fastIO();
    Solution sol;
    mems(dp, -1);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> ht[i];
    cout << sol.solve1() << nl;
    // cout << sol.solve2() << nl;


    return 0;
}

