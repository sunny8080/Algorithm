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

// Kosaraju's Algorithm
// It is used to print all strongly connected component


class Graph {

    void dfs1(int node, vvi& adj, vi& vis, vi& stk) {
        vis[node] = 1;

        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {
                dfs1(nbr, adj, vis, stk);
            }
        }

        // add vertex a/c to their finish time
        // add to stack when fun call is complete // add when all its nbr is visited
        stk.push_back(node);
    }

    void dfs2(int node, vvi& adj, vi& vis, vi& nums) {
        vis[node] = 1;
        nums.push_back(node);
        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {
                dfs2(nbr, adj, vis, nums);
            }
        }
    }

public:
    void addEdge(vvi& adj, vvi& revAdj, int u, int v) {
        adj[u].push_back(v);

        // add edge in reverse graph
        revAdj[v].push_back(u);
    }

    void printStronglyConnectedComponent(int n, vvi& adj, vvi& revAdj) {
        // step 1 : store the vertices acc to dfs finish time
        // ordering : stack 
        vi vis(n, 0);
        vi stk;

        // may be graph is not connected
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs1(i, adj, vis, stk);
            }
        }

        // PRT(stk);

        // step 2 : reverse the graph [ we have already revAdj]

        // step 3 : do dfs acc ordering given in the stack, from last to first

        char component = 'A';
        vis.assign(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            int node = stk[i];
            if (!vis[node]) {
                vi nums;
                dfs2(node, revAdj, vis, nums);

                cout << "Component " << component << " : ";
                PRT(nums);
                component++;
            }
        }

    }
};



int32_t main() {
    fastIO();

    int n = 7;
    Graph g;
    vvi adj(n);
    vvi revAdj(n);

    g.addEdge(adj, revAdj, 0, 2);
    g.addEdge(adj, revAdj, 2, 1);
    g.addEdge(adj, revAdj, 1, 0);
    g.addEdge(adj, revAdj, 0, 3);
    g.addEdge(adj, revAdj, 3, 5);
    g.addEdge(adj, revAdj, 5, 6);
    g.addEdge(adj, revAdj, 6, 3);
    g.addEdge(adj, revAdj, 3, 4);

    g.printStronglyConnectedComponent(n, adj, revAdj);



    return 0;
}

