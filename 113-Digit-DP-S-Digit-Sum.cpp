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



// QUE : https://atcoder.jp/contests/dp/tasks/dp_s



string k;
int D;
int dp[10005][105][2];


class Solution {

public:
    int solve(int pos, int d, int tight) {
        // dp[pos][d][tight] : Count of numbers such that we are yet to fix digits in places [pos ... (N-1)]
        // and S%D = d 
        // tight says that for current position, is there tight bound or not 

        if (dp[pos][d][tight] != -1) return dp[pos][d][tight];

        int ub = tight ? (k[pos] - '0') : 9;
        if (pos == k.length() - 1) {
            int ans = 0;
            for (int x = 0; x <= ub; x++) {
                if (x % D == d)
                    ans++;
            }
            return dp[pos][d][tight] = ans;
        }

        int ans = 0;
        for (int x = 0; x <= ub; x++) {
            ans = (ans + solve(pos + 1, (D + d - x % D) % D, tight && (x == ub))) % mod;
        }
        return dp[pos][d][tight] = ans;
    }

};



int32_t main() {
    fastIO();
    Solution sol;
    mems(dp, -1);

    cin >> k;
    cin >> D;
    cout << (sol.solve(0, 0, 1) - 1 + mod) % mod << nl;


    return 0;
}

