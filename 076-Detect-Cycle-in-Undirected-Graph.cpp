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




// Detect cycle in undirected graph by BFS
// 0-based
class Solution1 {

public:
    void addEdge(vvi& adj, int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    bool checkForCycle(int node, vvi& adj, vi& vis) {
        queue<pair<int, int>> q;
        int par = -1;

        vis[node] = 1;
        q.push({ node, par });

        while (!q.empty()) {
            tie(node, par) = q.front();
            q.pop();

            for( auto nbr : adj[node]){
                if( !vis[nbr] ){
                    vis[nbr] = 1;
                    q.push({nbr, par});
                }else if( nbr != par ){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int n, vector<vector<int>>& adj) {
        vector<int> vis(n, 0);

        // Graph may be disconnected
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (checkForCycle(i, adj, vis)) return true;
            }
        }
        return false;
    }
};





// Detect cycle in undirected graph by DFS
// 0-based
class Solution2 {

public:
    void addEdge(vvi& adj, int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // check cycle is present in graph or not // By DFS
    // 0 - based indexing
    bool cycleHelper(int node, vvi& adj, vi& vis, int parent) {
        vis[node] = 1;

        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {
                bool cycleFound = cycleHelper(nbr, adj, vis, node);
                if (cycleFound) return true;
            } else if (nbr != parent) {
                return true;
            }
        }
        return false;
    }

    bool cycleDetector(int n, vvi& adj) {
        vi vis(n, 0);
        int parent = -1;
        int src = 0;

        return cycleHelper(src, adj, vis, parent);
    }
};





int32_t main() {
    fastIO();

    {
        Solution1 sol1;
        int n =11;
        vector<vector<int>> adj(n);
        sol1.addEdge(adj, 0, 1);
        sol1.addEdge(adj, 1, 3);

        sol1.addEdge(adj, 2, 4);
        sol1.addEdge(adj, 4, 5);
        sol1.addEdge(adj, 5, 6);
        sol1.addEdge(adj, 6, 7);
        sol1.addEdge(adj, 4, 9);
        sol1.addEdge(adj, 9, 8);
        sol1.addEdge(adj, 8, 7);
        sol1.addEdge(adj, 7, 10);

        bool cycleFound = sol1.isCycle(n, adj);
        if (cycleFound) cout << "Cycle found" << nl; // Cycle found
        else cout << "Cycle not found" << nl;
    }
    cout<<nl;


    {
        Solution2 g;
        int n = 5;
        vector<vector<int>> adj(5);
        g.addEdge(adj, 0, 1);
        g.addEdge(adj, 1, 2);
        g.addEdge(adj, 2, 3);
        g.addEdge(adj, 3, 4);
        g.addEdge(adj, 1, 3);

        bool cycleFound = g.cycleDetector(n, adj);
        if (cycleFound) cout << "Cycle found" << nl; // Cycle found
        else cout << "Cycle not found" << nl;
    }
    cout << nl;




    {
        Solution2 g;
        int n = 5;
        vector<vector<int>> adj(5);
        g.addEdge(adj, 0, 1);
        g.addEdge(adj, 1, 2);
        g.addEdge(adj, 2, 3);
        g.addEdge(adj, 3, 4);

        bool cycleFound1 = g.cycleDetector(n, adj);
        if (cycleFound1) cout << "Cycle found" << nl;
        else cout << "Cycle not found" << nl;  // Cycle not found
    }



    return 0;
}

