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


// Dijkstras Algorithm is used find shortest distance of all the nodes from a single source node in weighted graph
// SSSP - Single Source Shortest Path  
// It works for only +vely weighted graph, so graph must not contain -ve weights (due to infinite loop) (for that use bellman ford)
// It works for both directed and undirected graph
// It is greedy algo
// TC :- O(E * logV) , E - no of edges, v - no of vertices 


// NOTE :- We can use minimum priority queue or set in Dijkstras algo, but set is faster





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









class Solution {
public:
    void addEdge(vector<vector<pii>>& adj, int u, int v, int w) {
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }




    // Dijkstra Algorithm using min priority queue
    // find the shortest distance to all node from src node    
    // TC :- O(E*logV) // E - no of edges, V - no of vertices      
    vector<int> dijkstra1(vector<vector<pair<int, int>>>& adj, int src) {
        int n = adj.size();
        vector<int> dist(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >>  pq; // {wt, node}

        pq.push({ 0, src });
        dist[src] = 0;

        while (pq.size()) {
            int nodeWt = pq.top().first, node = pq.top().second;
            pq.pop();

            for (auto nbrIt : adj[node]) {
                int nbr = nbrIt.first, nbrWt = nbrIt.second;
                if (nodeWt + nbrWt < dist[nbr]) {
                    dist[nbr] = nodeWt + nbrWt;
                    pq.push({ dist[nbr], nbr });
                }
            }
        }
        return dist;
    }





    // Dijkstra Algorithm using set
    // TC :- O(E*logV) // E - no of edges, V - no of vertices      
    vector<int> dijkstra2(vector<vector<pair<int, int>>>& adj, int src) {
        int n = adj.size();
        vector<int> dist(n, 1e9);
        set<pair<int, int>> st; // {wt, node}

        st.insert({ 0, src });
        dist[src] = 0;

        while (st.size()) {
            auto it = *st.begin();
            int nodeWt = it.first, node = it.second;
            st.erase(it);

            for (auto nbrIt : adj[node]) {
                int nbr = nbrIt.first, nbrWt = nbrIt.second;

                if (nbrWt + nodeWt < dist[nbr]) {
                    // erase it if previously existed
                    if (dist[nbr] != 1e9) st.erase({ dist[nbr], nbr });

                    dist[nbr] = nbrWt + nodeWt;
                    st.insert({ dist[nbr], nbr });
                }
            }
        }
        return dist;
    }


    



    // print shortest path of weighted undirected graph
    // O(ElogV + N) // 0-based indexing
    vector<int> shortestPath(int src, int dest, vector<vector<pair<int, int>>>& adj) {
        int n = adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> pq;
        vector<int> dist(n, 1e9);
        vector<int> par(n, -1);

        pq.push({ 0, src });
        dist[src] = 0;

        while (pq.size()) {
            auto nodeWt = pq.top().first, node = pq.top().second;
            pq.pop();

            for (auto nbrIt : adj[node]) {
                int nbr = nbrIt.first, nbrWt = nbrIt.second;
                if (nodeWt + nbrWt < dist[nbr]) {
                    dist[nbr] = nodeWt + nbrWt;
                    pq.push({ dist[nbr], nbr });
                    par[nbr] = node; // set nbr parent as node
                }
            }
        }
        if (dist[dest] == 1e9) return { -1 }; // dest unreachable

        vector<int> path;
        int node = dest;
        while (par[node] != -1) {
            path.push_back(node);
            node = par[node];
        }
        path.push_back(src);

        reverse(path.begin(), path.end());
        return path;
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
    cout << nl;


    {
        Solution sol;
        int n = 4;
        vector<vector<pii>> adj(n);
        sol.addEdge(adj, 0, 1, 24);
        sol.addEdge(adj, 0, 3, 20);
        sol.addEdge(adj, 2, 0, 3);
        sol.addEdge(adj, 3, 2, 12);
        auto dist = sol.dijkstra1(adj, 1);
        PRT(dist); // 24 0 27 39 

        auto path = sol.shortestPath(0, 3, adj);
        PRT(path); // 0 2 3
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
// 24 0 27 39
// 0 2 3