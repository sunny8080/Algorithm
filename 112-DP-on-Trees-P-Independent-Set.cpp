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


// QUE : https://atcoder.jp/contests/dp/tasks/dp_p


int n;
vector<int> adj[100005];
int dp[100005][2];

class Solution {
public:
    int solve(int u, int cons, int par) {
        // constraint : 0/1 
        // 0 means node is not under cons, so can be painted by white or black
        // 1 means node is under cons, so can be painted by only white
        // dp[u][0] = no Ways to paint subtree rooted at node u, u is not under constraint
        // dp[u][1] = no Ways to paint subtree rooted at node u, u is under constraint
        // ans = dp[root][0]

        if (dp[u][cons] != -1) return dp[u][cons];

        int ans = 0;
        int w1 = 1;
        // paint its child as white
        for (auto child : adj[u]) {
            if (child != par) {
                w1 = (w1 * solve(child, 0, u)) % mod;
            }
        }
        ans = w1;

        // paint its child as black // if it is not under constraint 
        if (!cons) {
            int w2 = 1;
            for (auto child : adj[u]) {
                if (child != par) {
                    w2 = (w2 * solve(child, 1, u)) % mod;
                }
            }
            ans = (ans + w2) % mod;
        }

        return dp[u][cons] = ans;
    }



};



int32_t main() {
    fastIO();
    Solution sol;
    mems(dp, -1);

    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << sol.solve(1, 0, -1) << nl;




    return 0;
}

