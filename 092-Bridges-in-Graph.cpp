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


// find bridges in an undirected graph

class Solution {

public:
    void addEdge(vvi& adj, int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int node, int parent, vi& vis, vi& tin, vi& low, int& timer, vvi& adj, vpii& bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for (auto nbr : adj[node]) {
            if (nbr == parent) continue;

            if (!vis[nbr]) {
                dfs(nbr, node, vis, tin, low, timer, adj, bridges);
                low[node] = min(low[node], low[nbr]);

                // condition for bridges for edge 
                if (low[nbr] > tin[node]) {
                    bridges.push_back({ node, nbr });
                }
            } else {
                low[node] = min(low[node], tin[nbr]);
            }
        }
    }

    void findBridges(vvi& adj, int n) {
        vi tin(n, -1); // time enter // discovered time // time when a node is discovered first time 
        vi low(n, -1); // time low // it point to lowest node that can be reached by i
        vi vis(n, 0);
        vector<pair<int, int>> bridges;
        int timer = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, timer, adj, bridges);
            }
        }

        cout << "Bridges : " << nl;
        for (auto edge : bridges) {
            cout << edge.first << " - " << edge.second << nl;
        }
    }


};



int32_t main() {
    fastIO();

    {
        Solution sol;
        int n = 12;
        vvi adj(n);
        sol.addEdge(adj, 0, 1);
        sol.addEdge(adj, 1, 2);
        sol.addEdge(adj, 2, 3);
        sol.addEdge(adj, 3, 0);
        sol.addEdge(adj, 3, 4);
        sol.addEdge(adj, 4, 5);
        sol.addEdge(adj, 5, 8);
        sol.addEdge(adj, 5, 6);
        sol.addEdge(adj, 6, 7);
        sol.addEdge(adj, 8, 7);
        sol.addEdge(adj, 7, 9);
        sol.addEdge(adj, 9, 10);
        sol.addEdge(adj, 10, 11);
        sol.addEdge(adj, 11, 9);

        sol.findBridges(adj, n);
    }
    cout << nl;



    return 0;
}

// OUT:-
//
// Bridges :
// 7 - 9
// 4 - 5
// 3 - 4


