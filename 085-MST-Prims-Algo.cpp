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

// QUE :- https://www.spoj.com/problems/MST/


// MST (Minimum spanning tree) : Spanning tree with min wt
// Find MST of Connected Undirected Weighted Graph by Prim's Algo
// It is a greedy algo



// 0-based indexing
class Graph {

public:

    void addEdge(vector<vector<pair<int, int>>>& adj, int u, int v, int w) {
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    int primsAlgo(int n, vector<vector<pair<int, int>>>& adj) {

        // Init min heap
        // in priority q -> {wt, u, v} -> denotes that this edge is pointing from u to v having weight wt
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;

        // vis[i] array denotes whether ith node is included in MST or not
        vi vis(n, 0);

        // to store all mst edges with their wt
        vector<tuple<int, int, int>> mst;

        q.push({ 0, 0, 0 }); // {wt, node, par} // node - par

        int mstWt = 0;

        while (!q.empty()) {
            // pick out the edge with min weight
            auto best = q.top();
            q.pop();

            int wt = get<0>(best);
            int from = get<1>(best);
            int to = get<2>(best); // this edge pointing to to // x->y => this edge pointing to y  // having weight, wt

            // if this node is visited, so it is in MST, so discard it // as it is not a active edge
            if (vis[to]) continue;

            // take the current edge
            mstWt += wt;
            vis[to] = 1;
            mst.push_back(make_tuple(from, to, wt));

            // add the new edge in queue // these are neighbours of current edge
            for (auto edge : adj[to]) { // {to, wt}
                int u, v, w;

                tie(u, v, w) = make_tuple(to, edge.first, edge.second);
                if (vis[v] == 0) {
                    q.push({ w, u, v });
                }
            }
        }

        cout << "MST :- " << nl;
        for (auto x : mst) {
            cout << get<0>(x) << sp << get<1>(x) << sp << get<2>(x) << nl;
        }

        return mstWt;
    }

};







// Prims algo // find mst wt
class Solution {

public:
    void addEdge(vector<vector<pii>>& adj, int u, int v, int w) {
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }


    // TC :- O(ElogE)  // SC : O(E)
    int mstByPrims(vector<vector<pii>>& adj, int n) {
        vector<int> vis(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int mstWt = 0;

        pq.push({ 0, 0 }); // {wt, node}

        while (!pq.empty()) {
            int wt = pq.top().first, node = pq.top().second;
            pq.pop();

            if (vis[node]) continue;
            vis[node] = 1;
            mstWt += wt;

            for (auto& e : adj[node]) {
                int nbr = e.first, nbrWt = e.second;
                if (!vis[nbr]) {
                    pq.push({ nbrWt, nbr });
                }
            }
        }
        return mstWt;
    }
};






int32_t main() {
    fastIO();

    {
        int n = 4;
        vector<vector<pair<int, int>>> adj(n);
        Graph g;
        g.addEdge(adj, 0, 1, 1);
        g.addEdge(adj, 1, 3, 2);
        g.addEdge(adj, 3, 2, 3);
        g.addEdge(adj, 2, 0, 2);
        g.addEdge(adj, 1, 2, 2);
        g.addEdge(adj, 0, 3, 2);
        cout << g.primsAlgo(n, adj) << nl;
    }
    cout << nl;



    // {
    //     int n, m; cin >> n >> m;
    //     vector<vector<pair<int, int>>> adj(n);
    //     Graph gr;
    //     int u, v, w;
    //     for (int i = 0; i < m; i++) {
    //         cin >> u >> v >> w;
    //         u--, v--;
    //         gr.addEdge(adj, u, v, w);
    //     }
    //     cout << gr.primsAlgo(n, adj);
    // }


    {
        Solution sol;
        int n = 4;
        vector<vector<pair<int, int>>> adj(n);
        sol.addEdge(adj, 0, 1, 1);
        sol.addEdge(adj, 1, 3, 2);
        sol.addEdge(adj, 3, 2, 3);
        sol.addEdge(adj, 2, 0, 2);
        sol.addEdge(adj, 1, 2, 2);
        sol.addEdge(adj, 0, 3, 2);
        cout << sol.mstByPrims(adj, n) << nl; //5
    }

    return 0;
}


// OUT:-
//
// MST:-
// 0 0 0
// 0 1 1
// 0 2 2
// 0 3 2
// 5
//
// 5
