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



class Graph {
    map<int, vector<int>> ls;
public:
    void addEdge(int u, int v) {
        ls[u].push_back(v);
        ls[v].push_back(u);
    }

    int shortestPathDist(int src, int dest) {
        // to store node and distance from src
        map<int, int> dist;
        queue<int> q;

        // Assume dist from src to each node as INT_MAX
        for (auto x : ls) {
            dist[x.first] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for( auto nbr : ls[node]){
                if( dist[node] + 1 < dist[nbr]){
                    dist[nbr] = dist[node]+1;
                    q.push(nbr);
                }
            }
        }

        // for (auto x : dist) {
        //     cout << src << " -> " << x.first << " = " << x.second << nl;
        // }
        // cout << nl;

        return dist[dest];
    }
};



int32_t main() {
    fastIO();


    {
        Graph g1;
        g1.addEdge(0, 1);
        g1.addEdge(0, 3);
        g1.addEdge(1, 2);
        g1.addEdge(2, 3);
        g1.addEdge(3, 4);
        g1.addEdge(4, 5);

        int dist = g1.shortestPathDist(0, 5);
        cout << "Shortest Dist [0 -> 5] = " << dist << nl; // Shortest Dist [0 -> 5] = 3
    }
    cout << nl;


    {
        Graph g1;
        g1.addEdge(0, 1);
        g1.addEdge(0, 3);
        g1.addEdge(1, 3);
        g1.addEdge(1, 2);
        g1.addEdge(2, 6);
        g1.addEdge(3, 4);
        g1.addEdge(4, 5);
        g1.addEdge(5, 6);
        g1.addEdge(6, 7);
        g1.addEdge(7, 8);
        g1.addEdge(8, 6);

        int dist = g1.shortestPathDist(0, 2);
        cout << "Shortest Dist [0 -> 2] = " << dist << nl; // Shortest Dist [0 -> 2] = 2
    }

    return 0;
}

