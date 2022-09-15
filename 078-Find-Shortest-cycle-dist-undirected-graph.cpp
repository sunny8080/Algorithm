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
    void addEdge(vvi& adj, int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int bfs( int src, int n, vvi &adj){
        int len = INT_MAX;
        vi dist(n, INT_MAX);
        queue<int> q;

        q.push(src);
        dist[src] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for( auto nbr : adj[node] ){
                if( dist[nbr] == INT_MAX){
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;

                }else if( dist[nbr] >= dist[node] ){
                    // we found backedge or circle
                    len = min(len, dist[nbr] + dist[node] + 1);
                }
            }
        }
        return len;
    }


    // Find length of smallest cycle in undirected graph
    int findLengthOfSmallestCycle(int n, vvi &adj){ 
        int ans=INT_MAX;
        for( int i=0; i<n; i++){
            ans = min(ans, bfs(i, n, adj));
        }
        if( ans == INT_MAX) return -1;
        return ans;
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    int n = 5;
    vvi adj(n);

    sol.addEdge(adj, 0, 1);
    sol.addEdge(adj, 1, 2);
    sol.addEdge(adj, 2, 3);
    sol.addEdge(adj, 3, 4);
    sol.addEdge(adj, 4, 0);
    sol.addEdge(adj, 1, 3);

    int minLen = sol.findLengthOfSmallestCycle(n, adj);
    if( minLen == -1 ){
        cout<<"Cycle not found"<<nl;
    }else{
        cout<<"Minimum cycle length : "<<minLen<<nl;
    }


    return 0;
}

