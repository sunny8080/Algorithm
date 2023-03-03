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

// Articulation point : A node in a graph whose removal of its node and all its related edges 
//                          can cause an increase in no of connected component in the graph
// find articulation point in a graph

// YT :- https://www.youtube.com/watch?v=j1QDfU21iZk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=56
// GFG :- https://practice.geeksforgeeks.org/problems/articulation-point-1/1




class Solution {
    int timer = 0;
    void dfs(int node, int par, vector<int>& vis, vector<int>& tin, vector<int>& low, vector< vector<int>>& adj, vector<int>& isArti) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;

        for (auto nbr : adj[node]) {
            if (nbr == par) continue;
            if (!vis[nbr]) {
                // for every node (node - nbr) check it can be articulation point or not 
                dfs(nbr, node, vis, tin, low, adj, isArti);
                low[node] = min(low[node], low[nbr]);

                if (low[nbr] >= tin[node] && par != -1) { // slight change from bridge prog
                    isArti[node] = 1;
                }
                child++;
            } else {
                // slight change from bridge prog 
                // it is already visited, take min(low[node], tin[nbr]) as low[node]
                low[node] = min(low[node], tin[nbr]);
            }
        }
        // slight change from bridge prog 
        if (par == -1 && child > 1) isArti[node] = 1;
    }



public:
    void addEdge(vvi& adj, int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }



    vector<int> articulationPoints(vector< vector<int>>& adj) {
        // vis[i] : ith node is visited or not 
        // tin[i] : time enter -> discovered time of node i// time when a node is discovered first time 
        // low[i] : time low -> min lowest time of insertion of all adjacent nodes except its parent || it point to lowest node that can be reached by i

        int n = adj.size();
        vector<int> vis(n, 0), tin(n), low(n), isArti(n, 0), arti;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs(i, -1, vis, tin, low, adj, isArti);
        }
        for (int i = 0; i < n; i++) {
            if (isArti[i]) arti.push_back(i);
        }
        return arti.size() == 0 ? vector<int>({ -1 }) : arti;
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

        auto arti = sol.articulationPoints(adj);
        cout << "Articulation point : " << sp;
        PRT(arti);
        cout << nl;
    }



    return 0;
}



// Articulation point : 3 4 5 7 9

