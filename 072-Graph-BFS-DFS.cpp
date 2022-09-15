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


template<typename T>
class Graph1 {
    map<T, list<T>> ls;
public:

    void addEdge(T u, T v) {
        ls[u].push_back(v);
        ls[v].push_back(u);
    }

    void bfs(T src) {
        map<T, int> visited;
        queue<T> q;

        q.push(src);
        visited[src] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << sp;

            for (auto nbr : ls[node]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = 1;
                }
            }
        }
    }


    // Recursive fn that will traverse the graph
    void dfsHelper(T src, map<T, bool> &vis){
        cout<<src<<sp;
        vis[src] = true;
        for( T nbr : ls[src]){
            if( ! vis[nbr] ){
                dfsHelper(nbr, vis);
            }
        }
    }

    void dfs(T src){
        map<T, bool> vis;
        // Mark all the nodes as not visited int the beginning
        for( auto x : ls){
            int node = x.first;
            vis[node] = false;
        }
        dfsHelper(src, vis);
    }

};





// 0-based indexing // O(V + 2E) // v-no of vertices E-no of edges 
class Solution {

    void dfsHelper(int node, vector<int>& vis, vector<int>* adj, vector<int>& nums) {
        vis[node] = 1;
        nums.push_back(node);

        // traverse all the neighbours
        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {
                dfsHelper(nbr, vis, adj, nums);
            }
        }
    }

public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[], int src) {
        // Code here
        vector<int> vis(v);
        vector<int> bfs;
        queue<int> q;

        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto x : adj[node]) {
                if (!vis[x]) {
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }
        return bfs;
    }



    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> adj[], int src) {
        vector<int> vis(v);
        vector<int> nums;
        dfsHelper(src, vis, adj, nums); 
        return nums;
    }

};

int32_t main() {
    fastIO();

    Graph1<int> g1;
    g1.addEdge(0, 1);
    g1.addEdge(0, 3);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    g1.addEdge(4, 5);
    g1.bfs(0); // 0 1 3 2 4 5 
    cout<<nl;
    g1.dfs(1); // 1 0 3 2 4 5 
    cout<<nl<<nl;




    Solution sol;
    vector<pair<int, int>> nums = { {0, 1}, {0, 3}, {1, 2}, {2, 3}, {3, 4}, {4, 5} };
    int v = 6; // no.of vertices / nodes

    vector<int> adj[v];
    for (auto x : nums) {
        adj[x.first].push_back(x.second);
        adj[x.second].push_back(x.first);
    }
    vi bfs = sol.bfsOfGraph(v, adj, 0); // 0 1 3 2 4 5 
    PRT(bfs);
    vi dfs = sol.dfsOfGraph(v, adj, 1); // 1 0 3 2 4 5 
    PRT(dfs);
    cout<<nl<<nl;



    return 0;
}

