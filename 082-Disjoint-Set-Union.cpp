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


// Disjoint Set Union (DSU) is used to detect the cycle
// METHOD -1 // O(N)
class Graph {
    int n;
    vector<pair<int, int>> ls;
public:
    Graph(int n) {
        this->n = n;
    }

    // store graph as edge list 
    void addEdge(int u, int v) {
        ls.push_back({ u, v });
    }

    // Find set in which i belongs // returns root/leader of the set in which i present // O(N)
    int findSet(int i, vi& parent) {
        if (parent[i] == -1) {
            return i;
        }
        return findSet(parent[i], parent);
    }


    // Union // merge sets which contains u and v, only if they are from diff sets
    void unionSet(int u, int v, vi& parent) {
        int s1 = findSet(u, parent);
        int s2 = findSet(v, parent);

        // merge if both sets are not same
        if (s1 != s2) {
            parent[s1] = s2;
        }
    }

    bool containsCycle() {
        // DSU logic to check if graph contains cycle or not
        vi parent(n, -1);
        for (auto edge : ls) {
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if (s1 != s2) {
                unionSet(s1, s2, parent);
            } else {
                // same parent means, creating cycle
                cout << "Same parents : " << s1 << sp << s2 << nl;
                return true;
            }
        }
        PRT(parent);
        return false;
    }

};




// Optimised DSU // METHOD - 2 // O(1) 
class Graph2 {
    int n;
    vector<pair<int, int>> ls;
public:
    Graph2(int n) {
        this->n = n;
    }

    // store graph as edge list 
    void addEdge(int u, int v) {
        ls.push_back({ u, v });
    }

    // path compression optimisation 
    int findSet2(int i, vi& parent) {
        if (parent[i] == -1) {
            return i;
        }
        // path compression optimization
        return parent[i] = findSet2(parent[i], parent);
    }


    // Union by Rank optimation  
    void unionSet2(int u, int v, vi& parent, vi& rank) {
        int s1 = findSet2(u, parent);
        int s2 = findSet2(v, parent);

        // merge if both sets are not same
        if (s1 != s2) {
            // union by rank optimization
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            } else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }


    bool containsCycle() {
        // DSU logic to check if graph contains cycle or not
        vi parent(n, -1);
        vi rank(n, 1);
        for (auto edge : ls) {
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet2(i, parent);
            int s2 = findSet2(j, parent);

            if (s1 != s2) {
                unionSet2(s1, s2, parent, rank);
            } else {
                // same parent means, creating cycle
                cout << "Same parents : " << s1 << sp << s2 << nl;
                return true;
            }
        }
        // PRT(parent);
        // PRT(rank);
        return false;
    }

};


int32_t main() {
    fastIO();

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    if (g.containsCycle()) {
        cout << "Contains cycle" << nl;
    } else {
        cout << "Does not Contains cycle" << nl;
    }
    cout << nl;


    Graph2 g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 0);

    if (g2.containsCycle()) {
        cout << "Contains cycle" << nl;
    } else {
        cout << "Does not Contains cycle" << nl;
    }
    cout << nl << nl;



    // {
    //     // 0 <-- 1 -> 2 -> 0  // there is not a cycle, but DSU says there is cycle // 
    //     // That's why Kruskal's algo fails for MST in case of directed graph 
    //     Graph2 g3(3);
    //     g3.addEdge(1, 0);
    //     g3.addEdge(1, 2);
    //     g3.addEdge(0, 2);

    //     if (g3.containsCycle()) {
    //         cout << "Contains cycle" << nl;
    //     } else {
    //         cout << "Does not Contains cycle" << nl;
    //     }
    // }
    
    return 0;
}

