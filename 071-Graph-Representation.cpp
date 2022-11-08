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



// Adjacency list
// Bidirectional / Undirected Graph  Where vertex is a integer
class Graph1 {
    int v;
    list<int>* ls;
public:
    Graph1(int v) {
        this->v = v;
        ls = new list<int>[v];
    }

    void addEdge(int x, int y) {
        ls[x].push_back(y);
        ls[y].push_back(x);
    }

    void printAdjList() {
        for (int i = 0; i < v; i++) {
            cout << i << " -> ";
            for (auto nbr : ls[i]) {
                cout << nbr << sp;
            }
            cout << nl;
        }
    }

};






// Graph with directed and undirected edge and weight, Where vertex is a string
// Also graph is weighted
class Graph2 {
    unordered_map<string, list<pair<string, int>>> ls;
public:
    void addEdge(string x, string y, bool bidir, int wt) {
        ls[x].push_back(make_pair(y, wt));
        if (bidir) {
            ls[y].push_back(make_pair(x, wt));
        }
    }

    void printAdjList() {
        for (auto v : ls) {
            cout << v.first << " -> ";
            for (auto nbr : v.second) {
                cout << "( " << nbr.first << ", " << nbr.second << " ) ";
            }
            cout << nl;
        }
    }
};








// Undirected graph
// Nodes are 1-based indexing 
// METHOD -1 // Adjacency matrix // O(N^2) memory
class Graph3 {
    int v, e;
    vvi adj;

public:
    Graph3(int v, int e) {
        this->v = v;
        this->e = e;
        adj = vector<vector<int>>(v + 1);
        for (int i = 0; i <= v; i++) {
            adj[i] = vector<int>(v + 1);
        }
        // cout<<adj.size()<<sp<<adj[0].size()<<nl;
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void printAdj() {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= e; j++) {
                cout << adj[i][j] << sp;
            }
            cout << nl;
        }
    }

};








// Undirected graph
// Nodes are 1-based indexing 
// METHOD -2 // Adjacency list // O(2E) memory   // BEST
class Graph4 {
    int v, e;
    vvi adj;

public:
    Graph4(int v, int e) {
        this->v = v;
        this->e = e;
        adj = vector<vector<int>>(v + 1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printAdj() {
        for (int i = 1; i <= v; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j] << sp;
            }
            cout << nl;
        }
    }

};

int32_t main() {
    fastIO();


    Graph1 g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.printAdjList();
    cout << nl << nl;



    Graph2 g2;
    g2.addEdge("A", "B", true, 20);
    g2.addEdge("B", "D", true, 40);
    g2.addEdge("A", "C", true, 10);
    g2.addEdge("C", "D", true, 40);
    g2.addEdge("A", "D", false, 50);
    g2.printAdjList();
    cout << nl << nl;



    Graph3 g3(5, 6);
    g3.addEdge(1, 2);
    g3.addEdge(1, 3);
    g3.addEdge(3, 4);
    g3.addEdge(2, 4);
    g3.addEdge(2, 5);
    g3.addEdge(4, 5);
    g3.printAdj();
    cout << nl << nl;



    Graph4 g4(5, 6);
    g4.addEdge(1, 2);
    g4.addEdge(1, 3);
    g4.addEdge(3, 4);
    g4.addEdge(2, 4);
    g4.addEdge(2, 5);
    g4.addEdge(4, 5);
    g4.printAdj();
    cout << nl << nl;




    // // METHOD - 1 // O(N^2) memory
    // int n, m;
    // cin >> n >> m;
    // int adj[n + 1][m + 1];
    // memset(adj, 0, sizeof(adj));
    // for (int i = 0; i < m; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u][v] = 1;
    //     adj[v][u] = 1;
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j= 1; j <= m; j++) {
    //         cout<<adj[i][j]<<sp;
    //     }
    //     cout<<nl;
    // }
    // cout << nl << nl;




    // // METHOD - 2 // O(2E) memory  // BEST
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << sp;
        }
        cout << nl;
    }
    cout << nl << nl;







    // Weighted Graph


    // // METHOD - 1 // O(N^2) memory
    // int n, m;
    // cin >> n >> m;
    // int adj[n + 1][m + 1];
    // memset(adj, 0, sizeof(adj));
    // for (int i = 0; i < m; i++) {
    //     int u, v, wt;
    //     cin >> u >> v >> wt;
    //     adj[u][v] = wt;
    //     adj[v][u] = wt;
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << adj[i][j] << sp;
    //     }
    //     cout << nl;
    // }
    // cout << nl << nl;





    // // METHOD - 2 // O(2E) memory  // BEST
    // int n, m;
    // cin >> n >> m;
    // vector<pair<int, int>> adj[n + 1];
    // for (int i = 0; i < m; i++) {
    //     int u, v, wt;
    //     cin >> u >> v >> wt;
    //     adj[u].push_back(make_pair(v, wt));
    //     adj[v].push_back(make_pair(u, wt));
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j < adj[i].size(); j++) {
    //         cout << "( " << adj[i][j].first << ", " << adj[i][j].second << ") ";
    //     }
    //     cout << nl;
    // }
    // cout << nl << nl;





    return 0;
}

