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
            // indegree[x] += 1
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

        for( auto x : ordering ){
            cout<<x<<nl;
        }

    }

};



int32_t main() {
    fastIO();

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
    cout<<nl<<nl;


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
    cout<<nl<<nl;


    Graph2<> g3;
    g3.addEdge(0, 2);
    g3.addEdge(1,2);
    g3.addEdge(2,3);
    g3.addEdge(3,5);
    g3.addEdge(2,5);
    g3.addEdge(1,4);
    g3.addEdge(4,5);
    g3.topologicalSortingByBFS();


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