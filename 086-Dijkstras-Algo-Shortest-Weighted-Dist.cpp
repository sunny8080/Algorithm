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


// Dijkstras Algorithm is used find distance b/w any two nodes in weighted graph
// SSSP - Single Source Shortest Path  


// NOTE :- We use set in Dijkstras,
// We can also use priority queue but implementation may be tough



template<typename T = int>
class Graph {
    unordered_map<T, list<pair<T, int>>> adj;
public:
    void addEdge(T u, T v, int dist, bool bidir = true) {
        adj[u].push_back(make_pair(v, dist));
        if (bidir) {
            adj[v].push_back(make_pair(u, dist));
        }
    }

    void printAdj() {
        for (auto x : adj) {
            cout << x.first << " -> ";
            for (auto y : x.second) {
                cout << "(" << y.first << sp << y.second << ")  ";
            }
            cout << nl;
        }
    }

    int dijkstrasSSSP(T src, T dest) {
        unordered_map<T, int> dist; // {node, dist from source} 

        // set all distance to infinity
        for (auto x : adj) {
            dist[x.first] = INT_MAX;
        }

        // Make a set to find out node with min distance // {dist from src, node}
        // we can also use priority queue instead of set
        set<pair<int, T>> st;

        unordered_map<T, T> parent;

        dist[src] = 0;
        st.insert({ dist[src], src });

        while (!st.empty()) {
            // find the pair with min dist // front pair
            auto p = *(st.begin());
            st.erase(st.begin());

            int nodeDist = p.first;
            T node = p.second;

            // Iterate over all nbrs of current node
            for (auto nbr_pair : adj[node]) {
                T nbr = nbr_pair.first;
                int nbrWt = nbr_pair.second;

                if (nodeDist + nbrWt < dist[nbr]) {
                    // remove the old pair of nbr from set if present
                    auto f = st.find({ dist[nbr], nbr });
                    if (f != st.end()) {
                        st.erase(f);
                    }

                    // Insert the new pair of nbr
                    dist[nbr] = nodeDist + nbrWt;
                    st.insert({ dist[nbr], nbr });
                    parent[nbr] = node;
                }
            }
        }

        // // print distance to all other nodes from src
        // cout<<"Dist from src "<<src<<" : "<<nl;
        // for( auto x : dist ){
        //     cout<<x.first<<" -> "<<x.second<<nl;
        // }

        // cout<<"Parent : "<<nl;
        // for( auto x : parent ){
        //     cout<<x.first<<sp<<x.second<<nl;
        // }


        cout << "Path : ";
        T node = dest;
        cout << node << " <- ";
        while (parent[node] != src) {
            cout << parent[node] << " <- ";
            node = parent[node];
        }
        cout << src << nl;

        return dist[dest];
    }
};








// Kruskal algo
// 1-based indexing
class Solution {

public:
    void addEdge(vector<vector<pii>>& adj, int u, int v, int w) {
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    int findShortestPathByDijkstras(vector<vector<pii>>& adj, int n, int src, int dest = 1) {
        vi dist(n + 1, INT_MAX);
        set<pii> st; // {w, u}

        dist[src] = 0;
        st.insert({ dist[src], src });

        while (!st.empty()) {
            auto p = *(st.begin());
            st.erase(st.begin());

            int node, nodeWt;
            tie(nodeWt, node) = p;

            for (auto nbr_p : adj[node]) {
                int u, nbr, nbrWt;
                tie(u, nbr, nbrWt) = make_tuple(node, nbr_p.first, nbr_p.second);

                if (nodeWt + nbrWt < dist[nbr]) {
                    auto f = st.find({ dist[nbr], nbr });
                    if (f != st.end()) {
                        st.erase(f);
                    }

                    dist[nbr] = nodeWt + nbrWt;
                    st.insert({ dist[nbr], nbr });
                }
            }
        }

        // for (int i = 1; i <= n; i++) {
        //     if (i != src) {
        //         if (dist[i] == INT_MAX) cout << -1 << sp;
        //         else cout << dist[i] << sp;
        //     }
        // }
        // cout<<nl;

        return dist[dest];
    }
};






int32_t main() {
    fastIO();

    {
        Graph<> g1;
        g1.addEdge(1, 2, 1);
        g1.addEdge(1, 3, 4);
        g1.addEdge(2, 3, 1);
        g1.addEdge(3, 4, 2);
        g1.addEdge(1, 4, 7);
        // g1.printAdj();
        int dist1 = g1.dijkstrasSSSP(1, 3);
        cout << "Wt : " << dist1 << nl;
    }
    cout << nl << nl;


    {
        Graph<string> g2;
        g2.addEdge("Amritsar", "Delhi", 1);
        g2.addEdge("Amritsar", "Jaipur", 4);
        g2.addEdge("Jaipur", "Delhi", 2);
        g2.addEdge("Jaipur", "Mumbai", 8);
        g2.addEdge("Bhopal", "Agra", 2);
        g2.addEdge("Mumbai", "Bhopal", 3);
        g2.addEdge("Agra", "Delhi", 1);
        // g2.printAdj();
        int dist2 = g2.dijkstrasSSSP("Amritsar", "Bhopal");
        cout << "Wt : " << dist2 << nl;
    }
    cout<<nl;


    {
        Solution sol;
        int n = 4;
        vector<vector<pii>> adj(n+1);
        sol.addEdge(adj, 1, 2, 24);
        sol.addEdge(adj, 1, 4, 20);
        sol.addEdge(adj, 3, 1, 3);
        sol.addEdge(adj, 4, 3, 12);
        auto len = sol.findShortestPathByDijkstras(adj, n, 1, 2);
        cout<<"Min dist from 1 to 2 : "<<len<<nl;
    }

    return 0;
}


// OUT:-
//
// Path : 3 <- 2 <- 1
// Wt : 2
//
//
// Path : Bhopal <- Agra <- Delhi <- Amritsar
// Wt : 4
//
// Min dist from 1 to 2 : 24

