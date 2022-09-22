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

// MST - Minimum Spanning Tree
// find MST of Directed Graph by Kruskal Algo
// DSU data str is used
// Path compression + Union by rank


class DSU {
    int n;
    vi parent;
    vi rank;
public:
    DSU(int n) {
        this->n = n;
        // for (int i = 0; i < n; i++) {
        //     parent.pb(-1);
        //     rank.pb(i);
        // }

        parent.resize(n, -1);
        rank.resize(n);
        iota(all(rank), 0);
    }


    // find Parent fun
    int findPar(int i) {
        return (parent[i] == -1) ? i : (parent[i] = findPar(parent[i]));
    }

    // union (or unite fun)
    void unite(int x, int y) {
        x = findPar(x);
        y = findPar(y);

        if (x != y) {
            // union by rank
            if (rank[x] < rank[y]) {
                parent[x] = y;
                rank[y] += rank[x];
            } else {
                parent[y] = x;
                rank[x] += rank[y];
            }
        }
    }
};



class Graph {
    int n;
    vector<vector<int>> edgeList;
public:
    Graph(int n) {
        this->n = n;
    }


    // Store the graph as edge list // so that we can sort the edges
    void addEdge(int x, int y, int w) {
        edgeList.push_back({ w, x, y });
    }


    // O(NlogN) // n - no of edges
    int kruskalAlgo() {
        // 1. Sort all edges
        sort(all(edgeList));
        int wt = 0;
        vpii nums;

        // Initiate a DSU
        DSU dsu(n);

        for (auto edge : edgeList) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // Step 2 :- take that edge in MST if it doesn't form a cycle 
            if (dsu.findPar(x) != dsu.findPar(y)) {
                dsu.unite(x, y);
                wt += w;
                nums.push_back({ x, y });
            }
        }

        cout<<"MST :- "<<nl;
        for( auto edge : nums ){
            cout<<edge.first<<" -> "<<edge.second<<nl;
        }
        return wt;
    }


};





int32_t main() {
    fastIO();


    {
        Graph g(4);
        // g.addEdge(x, y, w);
        g.addEdge(0, 1, 1);
        g.addEdge(1, 3, 3);
        g.addEdge(3, 2, 4);
        g.addEdge(2, 0, 2);
        g.addEdge(0, 3, 2);
        g.addEdge(1, 2, 2);
        int mstWt = g.kruskalAlgo();
        cout << mstWt << nl;
    }

    // int n, e; cin >> n >> e;
    // Graph gr(n);
    // int x, y, w;
    // for (int i = 0; i < n; i++) {
    //     cin >> x >> y >> w;
    //     x--;
    //     y--;
    //     gr.addEdge(x, y, w);
    // }
    // cout << gr.kruskalAlgo();


    return 0;
}

// OUT :-
// //
// MST:-
// 0 -> 1
// 0 -> 3
// 1 -> 2
// 5
