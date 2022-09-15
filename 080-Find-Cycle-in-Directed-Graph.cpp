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



// Check cycle is present or not in directed graph
// DFS used
class Graph {
    bool cycleHelper(int node, vvi& adj, vi& vis, vi& stk) {
        // marked node as visited and add it to stack
        vis[node] = 1;
        stk[node] = 1;

        for (auto nbr : adj[node]) {
            // if node is already present is current path (check stack), then cycle found
            if (stk[nbr]) {
                return true;
            }
            if (vis[nbr] == false) {
                bool isCycle = cycleHelper(nbr, adj, vis, stk);
                if (isCycle) return true;
            }
        }

        // remove from stack
        stk[node] = 0;
        return false;
    }

public:
    void addEdge(vvi& adj, int u, int v, bool directed = true) {
        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }



    bool cycleFound(int n, vvi& adj) {
        vi vis(n, 0);
        vi stk(n, 0);
        return cycleHelper(0, adj, vis, stk);
    }
};



int32_t main() {
    fastIO();
    Graph g;

    int n = 7;
    vvi adj(n);
    g.addEdge(adj, 0, 1);
    g.addEdge(adj, 1, 2);
    g.addEdge(adj, 2, 3);
    g.addEdge(adj, 3, 4);
    g.addEdge(adj, 4, 5);
    g.addEdge(adj, 5, 6);
    g.addEdge(adj, 1, 5);
    g.addEdge(adj, 4, 2);
    auto isCycle = g.cycleFound(n, adj);
    if (isCycle) {
        cout << "Cycle found";
    } else {
        cout << "Cycle not found";
    }


    return 0;
}

