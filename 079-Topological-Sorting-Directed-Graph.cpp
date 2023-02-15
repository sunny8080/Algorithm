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

// To check topological sorting is possible or not
class Solution {
    bool cycleFound(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {
                if (cycleFound(nbr, vis, pathVis, adj)) return true;
            } else if (pathVis[nbr]) {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }

public:
    bool isTopoPossible(int n, vector<vector<int>>& adj) {

        vector<int> vis(n, 0); // contains nodes which are visited
        vector<int> pathVis(n, 0); // path visited - contains nodes which are in current path

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (cycleFound(i, vis, pathVis, adj)) return false;
            }
        }

        return true;
    }
};






// topological sorting by DFS
template<typename T>
class Graph1 {
    map<T, list<T>> ls;


    void dfsHelper(T node, map<T, bool>& vis, list<T>& ordering) {
        vis[node] = 1;

        for (T nbr : ls[node]) {
            if (!vis[nbr]) {
                dfsHelper(nbr, vis, ordering);
            }
        }

        // add node before its neighbour, as we have to traverse first node then its neighbours
        ordering.push_front(node);
    }

public:

    void addEdge(T u, T v) {
        ls[u].push_back(v);
    }


    void topologicalSortingByDFS() {
        map<T, bool> vis;
        list<T> ordering;

        for (auto x : ls) {
            vis[x.first] = 0;
        }


        // in case when graph is disconnected
        for (auto x : ls) {
            if (!vis[x.first]) {
                dfsHelper(x.first, vis, ordering);
            }
        }

        for (auto x : ordering) {
            cout << x << nl;
        }
        cout << nl;
    }

};










// topological sorting by BFS
template<typename T = int>
class Graph2 {
    map<T, list<T>> ls;
public:

    void addEdge(T u, T v) {
        // directed graph
        ls[u].push_back(v);
    }

    void topologicalSortingByBFS() {
        // store indegree of all nodes
        map<T, int> indegree;

        for (auto x : ls) {
            // update indegree by traversing edges x->y
            // indegree[y] += 1
            for (auto y : ls[x.first]) {
                indegree[y]++;
            }
        }

        queue<T> q;
        for (auto x : ls) {
            if (indegree[x.first] == 0) {
                q.push(x.first);
            }
        }

        list<T> ordering;
        while (!q.empty()) {
            T node = q.front();
            q.pop();
            ordering.push_back(node);

            for (auto nbr : ls[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        for (auto x : ordering) {
            cout << x << nl;
        }
    }

};













// topological sorting using BFS  // Kahn's Algorithm
// it also check topo sorting is possible or not, by checking graph contain cycle or not
class Solution2 {

public:
    void addEdge(vvi& adj, int u, int v) {
        adj[u].push_back(v);
    }

    vector<int> findOrder(int n, vector<vector<int>>& adj) {
        vector<int> cntInDeg(n, 0);
        vector<int> ordering;

        for (auto x : adj) {
            for (auto y : x) {
                cntInDeg[y]++;
            }
        }

        set<pair<int, int>> indeg;

        for (int i = 0; i < n; i++) {
            indeg.insert({ cntInDeg[i], i });
        }

        while (!indeg.empty()) {
            auto p = *(indeg.begin());
            indeg.erase(p);

            // graph contain cycle // so no topological sorting possible
            if (p.first > 0) {
                ordering.clear();
                break;
            }

            ordering.push_back(p.second);

            // go to neighbours and cut the indegree of nbr by 1
            for (auto nbr : adj[p.second]) {
                if (cntInDeg[nbr] > 0) {
                    indeg.erase({ cntInDeg[nbr], nbr });
                    cntInDeg[nbr]--;
                    indeg.insert({ cntInDeg[nbr], nbr });
                }
            }
        }
        return ordering;
    }




    vector<int> findOrder1(int n, vector<vector<int>>& adj) {
        vector<int> indegree(n, 0), ans;
        for (auto x : adj) {
            for (auto y : x) {
                indegree[y]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        // if we can generate topological sorting then there is no cycle
        // in topological sorting, there is always n nodes
        return ans.size() == n ? ans : vector<int>();
    }
};











// it is assumed that graph is DAG (Directed Acyclic Garph) // so no checking is done
class Solution3 {
    void dfs(int node, vector<int>& vis, stack<int>& stk, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (auto nbr : adj[node]) {
            if (!vis[nbr]) dfs(nbr, vis, stk, adj);
        }
        stk.push(node);
    }
public:
    // topological sorting using dfs
    vector<int> topoSortDFS(int n, vector<vector<int>>& adj) {
        vector<int> vis(n, 0), ans;
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i, vis, stk, adj);
        }

        while (stk.size()) ans.push_back(stk.top()), stk.pop();
        return ans;
    }


    // topological sorting using bfs // O(V+E)
    vector<int> topoSortBFS(int n, vector<vector<int>>& adj) {
        vector<int> indeg(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto nbr : adj[i])
                indeg[nbr]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
        vector<int> ans;

        while (q.size()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto nbr : adj[node]) {
                indeg[nbr]--;
                if (indeg[nbr] == 0) q.push(nbr);
            }
        }
        return ans;
    }

};








int32_t main() {
    fastIO();

    {
        Graph1<string> g1;
        g1.addEdge("Python", "DataPreprocessing");
        g1.addEdge("Python", "PyTorch");
        g1.addEdge("Python", "ML");
        g1.addEdge("DataPreprocessing", "ML");
        g1.addEdge("PyTorch", "DL");
        g1.addEdge("ML", "DL");
        g1.addEdge("DL", "FaceRecogn");
        g1.addEdge("Dataset", "FaceRecogn");
        g1.topologicalSortingByDFS();
        cout << nl << nl;
    }


    {
        Graph2<string> g2;
        g2.addEdge("Python", "DataPreprocessing");
        g2.addEdge("Python", "PyTorch");
        g2.addEdge("Python", "ML");
        g2.addEdge("DataPreprocessing", "ML");
        g2.addEdge("PyTorch", "DL");
        g2.addEdge("ML", "DL");
        g2.addEdge("DL", "FaceRecogn");
        g2.addEdge("Dataset", "FaceRecogn");
        g2.topologicalSortingByBFS();
    }
    cout << nl << nl;


    {
        Graph1<int> g3;
        g3.addEdge(0, 2);
        g3.addEdge(1, 2);
        g3.addEdge(2, 3);
        g3.addEdge(3, 5);
        g3.addEdge(2, 5);
        g3.addEdge(1, 4);
        g3.addEdge(4, 5);
        g3.topologicalSortingByDFS();
    }
    cout << nl;


    {
        Graph2<> g3;
        g3.addEdge(0, 2);
        g3.addEdge(1, 2);
        g3.addEdge(2, 3);
        g3.addEdge(3, 5);
        g3.addEdge(2, 5);
        g3.addEdge(1, 4);
        g3.addEdge(4, 5);
        g3.topologicalSortingByBFS();
    }
    cout << nl;


    // topological sorting not possible
    {
        Graph1<int> g;
        g.addEdge(0, 1);
        g.addEdge(1, 0);

        int n = 2;
        vvi adj(n);
        adj[0].push_back(1);
        adj[1].push_back(0);
        Solution sol;
        if (sol.isTopoPossible(n, adj) == false) {
            cout << "Topological sorting is not possible" << nl; // not poss
        } else {
            g.topologicalSortingByDFS();
        }
    }
    cout << nl;



    {
        Solution2 sol2;
        int n = 4;
        vvi adj(n);
        sol2.addEdge(adj, 0, 1);
        sol2.addEdge(adj, 0, 2);
        sol2.addEdge(adj, 1, 3);
        sol2.addEdge(adj, 2, 3);

        auto order = sol2.findOrder(n, adj);
        if (order.size() == 0) {
            cout << "Topo sorting not possible" << nl;
        } else {
            cout << "Topo sort : ";
            PRT(order); // Topo sort : 0 1 2 3 
        }
    }
    cout << nl;


    {
        Solution2 sol2;
        int n = 2;
        vvi adj(n);
        sol2.addEdge(adj, 0, 1);
        sol2.addEdge(adj, 1, 0);

        auto order = sol2.findOrder(n, adj);
        if (order.size() == 0) {
            cout << "Topo sorting not possible" << nl; // Topo sort not ...
        } else {
            cout << "Topo sort : ";
            PRT(order);
        }
    }
    cout << nl;





    return 0;
}

// OUT:-
//
// Python
// PyTorch
// Dataset
// DataPreprocessing
// ML
// DL
// FaceRecogn
//
//
// Dataset
// Python
// DataPreprocessing
// PyTorch
// ML
// DL
// FaceRecogn
//
//
// 0
// 1
// 2
// 4
// 3
// 5
//
// Topological sorting is not possible
//
// Topo sort : 0 1 2 3
//
// Topo sorting not possible