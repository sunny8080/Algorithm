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


// Find shortest path in DAG (Directed Acyclic Graph)
// i.e, graph must not contain cycle

class Solution {

    void findTopoSort(int src, vector<pair<int, int>> adj[], stack<int>& stk, vi& vis) {
        vis[src] = 1;
        for (auto nbr : adj[src]) {
            if (!vis[nbr.first]) {
                findTopoSort(nbr.first, adj, stk, vis);
            }
        }
        stk.push(src);
    }

public:
    void addEdge(vector<pair<int, int>> adj[], int u, int v, int w) {
        adj[u].push_back({ v, w });
    }


    int shortestPathDAG(int src, int dest, int n, vector<pair<int, int>> adj[]) {
        vi vis(n, 0);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                findTopoSort(i, adj, stk, vis);
            }
        }

        vi dist(n, INT_MAX);
        vi parent(n, -1);

        dist[src] = 0;
        parent[src] = -1;

        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();

            // if the node has been reached previously
            if (dist[node] != INT_MAX) {
                for (auto nbr : adj[node]) {
                    if (dist[node] + nbr.second < dist[nbr.first]) {
                        dist[nbr.first] = dist[node] + nbr.second;
                        parent[nbr.first] = node;
                    }
                }
            }
        }

        cout << "Dist from src " << nl;
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) {
                cout << src << " -> " << i << " : " << "INF" << nl;;
            } else {
                cout << src << " -> " << i << " : " << dist[i] << nl;
            }
        }
        cout<<nl;

        if (dist[dest] != INT_MAX) {
            cout << "Path from " << src << " to " << dest << " : ";
            cout << dest << " <- ";
            int node = dest;
            while (parent[node] != src) {
                cout << parent[node] << " <- ";
                node = parent[node];
            }
            cout << src << nl;
        }

        return dist[dest];
    }
};



int32_t main() {
    fastIO();

    {
        Solution sol;
        int n = 6;
        vector<pair<int, int>> adj[n];
        sol.addEdge(adj, 0, 1, 2);
        sol.addEdge(adj, 1, 2, 3);
        sol.addEdge(adj, 2, 3, 6);
        sol.addEdge(adj, 0, 4, 1);
        sol.addEdge(adj, 4, 2, 2);
        sol.addEdge(adj, 4, 5, 4);
        sol.addEdge(adj, 5, 3, 1);

        int shortestDist = sol.shortestPathDAG(0, 2, n, adj);
        if (shortestDist == INT_MAX) {
            cout << "Path not found" << nl;
        } else {
            cout << "Shortest path dest : " << shortestDist << nl;
        }
    }
    cout << nl;



    return 0;
}


// OUT:-
//
// Dist from src 
// 0 -> 0 : 0
// 0 -> 1 : 2
// 0 -> 2 : 3
// 0 -> 3 : 6
// 0 -> 4 : 1
// 0 -> 5 : 5
//
// Path from 0 to 2 : 2 <- 4 <- 0
// Shortest path dest : 3


