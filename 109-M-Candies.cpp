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


// QUE :- https://atcoder.jp/contests/dp/tasks/dp_m


int n, k;
int arr[105];
int dp[105][100005];



class Solution {

public:
    // TC :- O(n*K^2) // so TLE
    int solve1(int i, int j) {
        if (i == n && j == 0) return 1;
        if (i == n) return 0;
        if (j == 0) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        int ways = 0;
        fr(i, 0, arr[i]) {
            if (j >= i) {
                ways = (ways + solve1(i + 1, j - i)) % mod;
            } else break;
        }
        return dp[i][j] = ways;
    }


    // Optimised // Bottom up // TC - O(N*K)
    int solve2() {
        for (int j = 0; j <= k;j++) {
            dp[0][j] = (j > arr[0]) ? 0 : 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                // Optimisation
                if (j == 0) dp[i][j] = dp[i - 1][j];
                else {
                    dp[i][j] = (dp[i][j - 1]
                        + dp[i - 1][j]
                        - ((j - 1 - arr[i] >= 0) ? dp[i - 1][j - 1 - arr[i]] : 0)
                        + mod) % mod;
                }
            }
        }

        return dp[n - 1][k];
    }


    // (i+1) th child, no of candies available = j // O(N*K)
    int solve3(int i, int j) {
        if (i == 0) {
            return (j <= arr[0] ? 1 : 0);
        }
        if (j == 0) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        ans = (solve3(i, j - 1) + solve3(i - 1, j) - ((j - 1 - arr[i] >= 0) ? solve3(i - 1, j - 1 - arr[i]) : 0) + mod) % mod;

        return dp[i][j] = ans;
    }


};



int32_t main() {
    fastIO();
    Solution sol;
    mems(dp, -1);

    cin >> n >> k;
    fr(i, 0, n - 1) cin >> arr[i];
    // cout << sol.solve1(0, k) << nl;
    cout << sol.solve2() << nl;
    // cout << sol.solve3(n-1, k) << nl;



    return 0;
}

