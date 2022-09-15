#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
// #define int              long long
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


// Find no of connected components in Graph using DFS
// 0-based indexing
class Solution {
    void dfs(int src, vvi& adj, vi& vis, vi& nums) {
        nums.pb(src);
        vis[src] = 1;

        for (auto nbr : adj[src]) {
            if (!vis[nbr]) dfs(nbr, adj, vis, nums);
        }
    }
public:
    int noOfConnectedComponents(vector<pair<int, int>>& edges, int n) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            int u, v;
            tie(u, v) = make_pair(e.first, e.second);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vi vis(n, 0);
        int cnt = 0;

        // Traverse all the nodes, and find which is not visited
        for (int i = 0;i < n; i++) {
            vi nums;
            if (!vis[i]) {
                dfs(i, adj, vis, nums);
                cnt++;
                PRT(nums); // print the nodes of connected graph
            }
        }
        return cnt;
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    int n = 9; // no of nodes

    vector<pair<int, int>> edges;
    edges.push_back({ 0, 1 });
    edges.push_back({ 1, 2 });
    edges.push_back({ 2,3 });
    edges.push_back({ 0,3 });
    edges.push_back({ 0,4 });
    edges.push_back({ 5,6 });
    edges.push_back({ 6,7 });
    edges.push_back({ 8,8 });

    int cnt = sol.noOfConnectedComponents(edges, n);
    cout << "No. of connected components : " << cnt << nl; // 3

    return 0;
}

