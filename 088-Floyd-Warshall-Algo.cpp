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


// Floyd Warshall Algorithm
// It is used to find All pair shortest path distance (APSP)
// Multiple Source shortest path 

// O(N^3) time // N -no. of vertices
// O(N^2) space
class Solution {

public:
    void addEdge(vvi& dist, int u, int v, int w) {
        dist[u][v] = w;
    }

    void floydWarshall(vvi& dist, int n) {
        // Phases, in kth phase we included vertices [1, 2... k ] as intermediate vertices
        for (int k = 1; k <= n; k++) {
            // Iterate over entire 2D Matrix
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {

                    // if vertex k is included, can we minimise the dist
                    if ((dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) and (dist[i][j] > dist[i][k] + dist[k][j])) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Check for negative wt cycle
        for (int i = 1; i <= n; i++) {
            // dist of a node to itself is always 0 
            // if it is -ve then -ve wt cycle found
            if (dist[i][i] < 0) {
                cout << "Negative Cycle Weight found" << nl;
                return;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << dist[i][j] << sp;
            }
            cout << nl;
        }
    }

};



int32_t main() {
    fastIO();
    Solution sol;

    {
        int n = 4;

        // init for every x and y, dist[x->y] = infinity
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));

        // dist of a node to itself is always 0
        for (int i = 1; i <= n; i++) dist[i][i] = 0;

        sol.addEdge(dist, 2, 1, 4);
        sol.addEdge(dist, 1, 3, -2);
        sol.addEdge(dist, 3, 4, 2);
        sol.addEdge(dist, 4, 2, -1);
        sol.addEdge(dist, 2, 3, 3);
        sol.floydWarshall(dist, n);
    }
    cout << nl << nl;



    {
        int n = 3;
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 1; i <= n; i++) dist[i][i] = 0;

        sol.addEdge(dist, 1, 2, 2);
        sol.addEdge(dist, 2, 3, -4);
        sol.addEdge(dist, 3, 1, 1);
        sol.floydWarshall(dist, n);
    }


    return 0;
}


// OUT:-
//
// 0 - 1 - 2 0
// 4 0 2 4
// 5 1 0 2
// 3 - 1 1 0
//
//
// Negative Cycle Weight found
