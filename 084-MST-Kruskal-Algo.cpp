#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll                 long long
// #define int                long long
#define ull                unsigned long long
#define ff                 first
#define ss                 second
#define pb                 push_back
#define mp                 make_pair
#define pii                pair<int,int>
#define vi                 vector<int>
#define vll                vector<ll> 
#define vvi                vector< vector<int>>
#define vvll               vector< vector<ll>>
#define vpii               vector<pair<int,int>>
#define mii                map<int,int>
#define pqb                priority_queue<int>
#define pqs                priority_queue<int, vector<int>, greater<int>>
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define mod                1000000007
#define inf                1e18
#define ps(x,y)            fixed<<setprecision(y)<<x
#define mk(arr, n, type)   type *arr=new type[n];
#define wt(x)              int x; cin>>x; while( x-- )
#define sp                 ' '
#define nl                 char(10)
#define PRT(ar)            for( auto i : ar ) cout<<i<<sp; cout<<nl;
#define mems(x,ch)         memset(x,ch,sizeof(x))
#define sortv(x)           sort(x.begin(),x.end())
#define sortvr(x)          sort(x.rbegin(),x.rend())
#define all(x)             x.begin(), x.end()
#define fr(t,a,b)          for( int t=(a); t<=(b); t++)
#define frr(t,a,b)         for( int t=(a); t>=(b); t--)
#define cn(x)              int x; cin>>x;
#define ri(x)              cin >> x
#define rii(x, y)          cin >> x >> y
#define riii(x, y, z)      cin >> x >> y >> z
#define riiii(x, y, z, w)  cin >> x >> y >> z >> w
#define rvi(nums)          for (auto& x : nums) cin >> x;
#define dri(x)             int x; cin >> x
#define drs(s)             string s; cin >> s
#define drii(x, y)         int x, y; cin >> x >> y
#define driii(x, y, z)     int x, y, z; cin >> x >> y >> z
#define driiii(x, y, z, w) int x, y, z, w; cin >> x >> y >> z >> w
#define drvi(nums, n)      vector<int> nums(n); for (auto& x : nums) cin >> x;
#define iff(x, y)  if(x) y

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
// QUE :- https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree


// MST - Minimum Spanning Tree
// Find MST of Connected Undirected Weighted Graph by Kruskal's Algo
// DSU data str is used
// Path compression + Union (or size ) by rank





// Disjoint set
class DSU {
    int n;
    vector<int> par, size;
public:
    DSU(int n) {
        this->n = n;
        par.resize(n + 1, -1);
        size.resize(n + 1, 1);
    }
    int findPar(int node) {
        return par[node] == -1 ? node : par[node] = findPar(par[node]);
    }

    bool unionBySize(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if (u == v)return 0;
        if (size[u] < size[v]) {
            par[u] = v;
            size[v] += size[u];
        } else {
            par[v] = u;
            size[u] += size[v];
        }
        return 1;
    }
};






class Solution {
public:
    void addEdge(int u, int v, int wt, vector< vector<pair<int, int>>>& adj) {
        adj[u].push_back({ v,wt });
        adj[v].push_back({ u,wt });
    }


    // kruskal algo // O(N*logN)
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    // adj[i][j] = {v,wt} => {i, u, wt} 
    int spanningTree(vector<vector<pair<int, int>>>& adj) {
        vector<vector<int>> edges;
        int n = adj.size();
        for (int i = 0; i < n; i++) {
            for (auto nbr : adj[i]) {
                edges.push_back({ nbr.second, i, nbr.first }); // {wt, u, v}
            }
        }

        // sort edges by their wt
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        DSU dsu(n); // Initiate a dsu
        // vector< vector<int>>  mst;

        for (auto& e : edges) {
            int u, v, wt;
            tie(wt, u, v) = make_tuple(e[0], e[1], e[2]);

            // take that edge in MST if it doesn't form a cycle 
            if (dsu.findPar(u) != dsu.findPar(v)) {
                dsu.unionBySize(u, v);
                mstWt += wt;
                // mst.push_back({ u, v, wt });
            }
        }
        // cout << "MST :- " << nl;
        // for (auto e : mst) {
        //     cout << e[0] << " -> " << e[1] << " " << e[2] << "\n";
        // }
        return mstWt;
    }
};





int32_t main() {
    fastIO();

    {
        Solution sol;
        int n = 5;
        vector<vector<pair<int, int>>> adj(n);
        sol.addEdge(0, 1, 1, adj);
        sol.addEdge(1, 3, 3, adj);
        sol.addEdge(3, 2, 4, adj);
        sol.addEdge(2, 0, 2, adj);
        sol.addEdge(0, 3, 2, adj);
        sol.addEdge(1, 2, 2, adj);
        int mstWt = sol.spanningTree(adj); // 5
        cout << mstWt << nl;
    }




    return 0;
}




