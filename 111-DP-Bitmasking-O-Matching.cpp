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

int n;
int arr[22][22];
int dp[22][(1 << 22)];


// QUE :- https://atcoder.jp/contests/dp/tasks/dp_o
// Also visit another QUE : https://atcoder.jp/contests/dp/tasks/dp_u



class Solution {

public:
    // Brute force // TLE
    int solve1(int i, int pairs, int* col) {
        if (i == n + 1 && pairs == n) return 1;
        if (i == n + 1) return 0;

        int ways = 0;
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 1 && col[j] != 1) {
                col[j] = 1;
                ways = (ways + solve1(i + 1, pairs + 1, col)) % mod;
                col[j] = 0;
            }
        }

        return ways;
    }



    // DP Bitmasking
    // Top down DP with Bitmasking // O(N^2 * 2^N)
    // here womenSubset is used as Bitmasking for available womens to pair
    int solve2(int i, int womenSubset) {
        if (i == n + 1 && womenSubset == 0) return 1;
        if (i == n + 1 || womenSubset == 0) return 0;

        if (dp[i][womenSubset] != -1) return dp[i][womenSubset];

        int ans = 0;
        for (int women = 0; women < n; women++) {
            int avaliable = (womenSubset & (1 << women)) ? 1 : 0;
            if (avaliable && arr[i][women + 1]) {
                ans = (ans + solve2(i + 1, (womenSubset ^ (1 << women)))) % mod;
            }
        }

        return dp[i][womenSubset] = ans;
    }

};



int32_t main() {
    fastIO();
    Solution sol;
    mems(arr, -1);
    mems(dp, -1);


    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    // cout << sol.solve1(1, 0, col) << nl;
    int womenSubset = (1 << n) - 1;
    cout << sol.solve2(1, womenSubset) << nl;


    return 0;
}

