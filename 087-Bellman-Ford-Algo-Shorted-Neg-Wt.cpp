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


// Bellman Ford Algo // used to find shortest dist from source in directed graph
// it can handle -ve wt and -ve wt cycle
// O((N-1) * E)

// 1- based indexing
class Solution {
public:

    void addEdge(vvi& edgeList, int u, int v, int w) {
        edgeList.push_back({ u, v, w });
    }

    void printedgeList(vvi& edgeList) {
        for (auto x : edgeList) {
            cout << x[0] << sp << x[1] << sp << x[2] << nl;
        }
    }

    int bellmanFordAlgo(int n, vvi& edgeList, int src, int dest) {
        vi dist(n + 1, INT_MAX);
        unordered_map<int, int> parent;

        dist[src] = 0;
        parent[src] = -1;

        // Relax all the edge n-1 times // n-> no of nodes
        for (int i = 0; i < n - 1; i++) {
            for (auto edge : edgeList) {
                int u, v, w;
                tie(u, v, w) = make_tuple(edge[0], edge[1], edge[2]);

                if ((dist[u] != INT_MAX) && (dist[u] + w < dist[v])) {
                    parent[v] = u;
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative wt cycle
        for (auto edge : edgeList) {
            int u, v, w;
            tie(u, v, w) = make_tuple(edge[0], edge[1], edge[2]);

            // detect negative cycle wt
            if ((dist[u] != INT_MAX) && (dist[u] + w < dist[v])) {
                // cout << "Negative Cycle Weight found" << nl;
                return INT_MIN;
            }
        }

        // // Print Distance vector
        // cout << "Distance from source " << src << " : " << nl;
        // for (int i = 1; i <= n; i++) {
        //     cout << i << " -> " << dist[i] << nl;
        // }


        // print path if path exist
        if (dist[dest] != INT_MAX) {
            cout << "Path : ";
            int node = dest;
            cout << node << " <- ";
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
    Solution sol;

    {
        int n = 3, m = 3; // no. of nodes, edge
        vector<vector<int>> edgeList;
        sol.addEdge(edgeList, 1, 2, 3);
        sol.addEdge(edgeList, 2, 3, 4);
        sol.addEdge(edgeList, 3, 1, -10);
        // sol.printedgeList(edgeList);
        int shortDist = sol.bellmanFordAlgo(n, edgeList, 1, 2);
        if (shortDist == INT_MIN) {
            cout << "Negative Cycle Weight found" << nl;
        } else {
            cout << "Wt : " << shortDist << nl;
        }
    }
    cout << nl << nl;


    {
        int n = 3, m = 3; // no. of nodes, edge
        vector<vector<int>> edgeList;
        sol.addEdge(edgeList, 1, 2, 3);
        sol.addEdge(edgeList, 2, 3, 4);
        sol.addEdge(edgeList, 1, 3, -10);
        // sol.printedgeList(edgeList);
        int shortDist = sol.bellmanFordAlgo(n, edgeList, 3, 2);
        if (shortDist == INT_MIN) {
            cout << "Negative Cycle Weight found" << nl;
        } else if (shortDist == INT_MAX) {
            cout << "Path not possible" << nl;
        } else {
            cout << "Wt : " << shortDist << nl;
        }
        cout << nl;


        shortDist = sol.bellmanFordAlgo(n, edgeList, 1, 2);
        if (shortDist == INT_MIN) {
            cout << "Negative Cycle Weight found" << nl;
        } else if (shortDist == INT_MAX) {
            cout << "Path not possible" << nl;
        } else {
            cout << "Wt : " << shortDist << nl;
        }

    }



    return 0;
}

// OUT :-
//
// Negative Cycle Weight found
//
// Path not possible
//
// Path : 2 <- 1
// Wt: 3

