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



class Solution {

public:
    void addEdge(int u, int v, vi adj[]) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    bool dfsHelper(int node, vi adj[], vi& vis, int parent, int currColor) {
        vis[node] = currColor; // 1 or 2, both mean visited

        for (auto nbr : adj[node]) {
            if (vis[nbr] == 0) {
                bool isBartite = dfsHelper(nbr, adj, vis, node, 3-currColor);
                if( isBartite == false ) return false;
                
            } else if (nbr != parent and currColor == vis[nbr]) {
                return false;
            }
        }
        return true;
    }

    bool checkBipartite(int n, vi adj[]) {
        vi vis(n, 0); // 0 - not visited, 1 - visited color is 1, 2 - visited color is 2 
        bool isBartite = dfsHelper(0, adj, vis, -1, 1);
        for(int i=0; i<n; i++){
            cout<<i<<" - node color - "<<vis[i]<<nl;
        }
        return isBartite;
    }
};




int32_t main() {
    fastIO();
    Solution sol;

    int n = 5;
    vector<int> adj[n];
    sol.addEdge(0, 1, adj);
    sol.addEdge(1, 2, adj);
    sol.addEdge(2, 3, adj);
    sol.addEdge(3, 4, adj);
    sol.addEdge(4, 0, adj);

    bool isBartite = sol.checkBipartite(n, adj);
    if (isBartite) {
        cout << "Graph is bartite" << nl;
    } else {
        cout << "Graph is not bartite" << nl;
    }
    cout<<nl<<nl;



    int n1 = 5;
    vector<int> adj1[n1];
    sol.addEdge(0, 1, adj1);
    sol.addEdge(1, 2, adj1);
    sol.addEdge(2, 3, adj1);
    sol.addEdge(3, 4, adj1);

    bool isBartite1 = sol.checkBipartite(n1, adj1);
    if (isBartite1) {
        cout << "Graph is bartite" << nl;
    } else {
        cout << "Graph is not bartite" << nl;
    }

    return 0;
}



// OUTPUT :-
//
// 0 - node color - 1
// 1 - node color - 2
// 2 - node color - 1
// 3 - node color - 2
// 4 - node color - 1
// Graph is not bartite
//
//
// 0 - node color - 1
// 1 - node color - 2
// 2 - node color - 1
// 3 - node color - 2
// 4 - node color - 1
// Graph is bartite