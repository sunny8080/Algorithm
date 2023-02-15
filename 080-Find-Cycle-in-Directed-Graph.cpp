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
class Solution {
    bool dfsCycleFound(int node, vector<int>& vis, vector<int>& path, vector< vector<int>>& adj) {
        // marked node as visited and add it to current path
        vis[node] = path[node] = 1;
        for (auto nbr : adj[node]) {
            if (!vis[nbr] && dfsCycleFound(nbr, vis, path, adj)) return 1;
            else {
                // if the node has been previously visited and it is in current path, then cycle found
                if (path[nbr]) return 1;
            }
        }

        // remove from current path
        path[node] = 0;
        return 0;
    }
public:
    void addEdge(vvi& adj, int u, int v, bool directed = true) {
        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }


    bool cycleFound(int n, vector<vector<int>>& adj) {
        vector<int> vis(n, 0), path(n, 0);

        // graph may be not connected
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfsCycleFound(i, vis, path, adj)) return 1;
            }
        }
        return 0;
    }
};





// Cycle detection by BFS
// Using reverse of Kahn's Algo (Used in topological sorting)
class Solution2 {

public:
    void addEdge(vvi& adj, int u, int v, bool directed = true) {
        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    bool isCyclic(int n, vector< vector<int>>& adj) {
        vector<int> indegree(n, 0);
        for (auto x : adj) {
            for (auto y : x) {
                indegree[y]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            cnt++;
            for (auto nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        // if we can generate topological sorting then there is no cycle
        // in topological sorting, there is always n nodes
        if (cnt == n) return false;
        return true;
    }
};






int32_t main() {
    fastIO();


    {
        Solution g;

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
            cout << "Cycle found"; // Cycle found
        } else {
            cout << "Cycle not found";
        }
    }
    cout << nl;



    {
        Solution2 sol2;

        int n = 7;
        vvi adj(n);
        sol2.addEdge(adj, 0, 1);
        sol2.addEdge(adj, 1, 2);
        sol2.addEdge(adj, 2, 3);
        sol2.addEdge(adj, 3, 4);
        sol2.addEdge(adj, 4, 5);
        sol2.addEdge(adj, 5, 6);
        sol2.addEdge(adj, 1, 5);
        sol2.addEdge(adj, 4, 2);
        auto isCycle = sol2.isCyclic(n, adj);
        if (isCycle) {
            cout << "Cycle found";  // Cycle found
        } else {
            cout << "Cycle not found";
        }
    }
    cout << nl;



    return 0;
}

