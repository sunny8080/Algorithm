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




// Kosaraju's Algorithm
// It is used to print all strongly connected component (scc)
// scc :- component of a graph in which all nodes are reachable from any nodes
//    1 -> 2 -> 3 -> 1  
//  (1, 2, 3)  is a scc




class Solution {
    void dfs1(int node, vector<int>& vis, stack<int>& stk, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (auto nbr : adj[node]) {
            if (!vis[nbr])
                dfs1(nbr, vis, stk, adj);
        }

        // add vertex a/c to their finish time
        // add to stack when fun call is complete // add when all its nbr is visited
        stk.push(node);
    }

    void dfs2(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (auto nbr : adj[node]) {
            if (!vis[nbr])
                dfs2(nbr, vis, adj);
        }
    }


    // same as dfs2 but it also stores nodes
    void dfs3(int node, vector<int>& vis, vector<int>& nums, vector<vector<int>>& adj) {
        vis[node] = 1;
        nums.push_back(node);
        for (auto nbr : adj[node]) {
            if (!vis[nbr])
                dfs3(nbr, vis, nums, adj);
        }
    }

public:
    void addEdge(vvi& adj, int u, int v) {
        adj[u].push_back(v);
    }


    //Function to find number of strongly connected components in the graph.
    // n -> no of nodes
    // TC :- O(V+E)
    int kosaraju(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        stack<int> stk;

        // sort all nodes a/c to their finishing time // means topo sorting
        for (int i = 0; i < n; i++)
            if (!vis[i]) dfs1(i, vis, stk, adj);

        // reverse or transpose the graph
        vector<vector<int>> adjRev(n);
        for (int i = 0; i < n; i++) {
            vis[i] = 0;
            for (auto nbr : adj[i])
                adjRev[nbr].push_back(i); // reversed edge = nbr -> i
        }

        // do dfs a/c to ordering given in the stack, in reversed graph, from last to first

        // int scc = 0;
        // while (stk.size()) {
        //     int node = stk.top();
        //     stk.pop();
        //     if (!vis[node]) dfs2(node, vis, adjRev), scc++;
        // }


        // to print all the scc component
        int scc = 0;
        vector< vector<int>> comp;
        while (stk.size()) {
            int node = stk.top();
            stk.pop();
            if (!vis[node]) {
                vector<int> nums;
                dfs3(node, vis, nums, adjRev), scc++;
                comp.push_back(nums);
            }
        }

        for (auto x : comp) {
            PRT(x);
        }
        return scc;
    }
};




int32_t main() {
    fastIO();


    {
        int n = 7;
        Solution sol;
        vvi adj(n);

        sol.addEdge(adj, 0, 2);
        sol.addEdge(adj, 2, 1);
        sol.addEdge(adj, 1, 0);
        sol.addEdge(adj, 0, 3);
        sol.addEdge(adj, 3, 5);
        sol.addEdge(adj, 5, 6);
        sol.addEdge(adj, 6, 3);
        sol.addEdge(adj, 3, 4);

        int scc = sol.kosaraju(adj);
        cout << "No of scc : " << scc << nl; // 3
    }



    return 0;
}



// 0 1 2
// 3 6 5
// 4
// No of scc : 3
