#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll                 long long
// #define int                long long
#define ull                unsigned long long
#define ff                 first
#define ss                 second
#define pb                 push_back
#define mp                 make_pair
#define pii                pair<int,int>
#define vi                 vector<int>
#define vll                vector<ll> 
#define vvi                vector< vector<int>>
#define vvll               vector< vector<ll>>
#define vpii               vector<pair<int,int>>
#define mii                map<int,int>
#define pqb                priority_queue<int>
#define pqs                priority_queue<int, vector<int>, greater<int>>
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define mod                1000000007
#define inf                1e18
#define ps(x,y)            fixed<<setprecision(y)<<x
#define mk(arr, n, type)   type *arr=new type[n];
#define wt(x)              int x; cin>>x; while( x-- )
#define sp                 ' '
#define nl                 char(10)
#define PRT(ar)            for( auto i : ar ) cout<<i<<sp; cout<<nl;
#define mems(x,ch)         memset(x,ch,sizeof(x))
#define sortv(x)           sort(x.begin(),x.end())
#define sortvr(x)          sort(x.rbegin(),x.rend())
#define all(x)             x.begin(), x.end()
#define fr(t,a,b)          for( int t=(a); t<=(b); t++)
#define frr(t,a,b)         for( int t=(a); t>=(b); t--)
#define cn(x)              int x; cin>>x;
#define ri(x)              cin >> x
#define rii(x, y)          cin >> x >> y
#define riii(x, y, z)      cin >> x >> y >> z
#define riiii(x, y, z, w)  cin >> x >> y >> z >> w
#define rvi(nums)          for (auto& x : nums) cin >> x;
#define dri(x)             int x; cin >> x
#define drs(s)             string s; cin >> s
#define drii(x, y)         int x, y; cin >> x >> y
#define driii(x, y, z)     int x, y, z; cin >> x >> y >> z
#define driiii(x, y, z, w) int x, y, z, w; cin >> x >> y >> z >> w
#define drvi(nums, n)      vector<int> nums(n); for (auto& x : nums) cin >> x;
#define iff(x, y)  if(x) y

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




// DSU ( Disjoint Set Union ) used to join two disjoint set
// it is also used to detect the cycle in graph
// YT :- https://youtu.be/aBxjDBC4M1U?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn
// It can be used to find no of connected component in a graph by checking its parent








// Use union by rank or union by size to unite two nodes // O(1) 
class DisjointSet {
    vector<int> par, rank, size;
    int n;
public:
    DisjointSet(int n) {
        this->n = n;
        par.resize(n + 1, -1); // n+1 so that it can be used for 0 or 1 based indexing
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
    }


    // find parent of node // returns root/leader of the set in which node present
    // path compression optimised // O(4 * alpha) == O(1)
    int findPar(int node) {
        if (par[node] == -1) return node;
        return par[node] = findPar(par[node]);
    }


    // union two nodes by rank // O(4 * alpha) == O(1) 
    // return true on successful union, o/w false
    bool unionByRank(int u, int v) {
        int parU = findPar(u);
        int parV = findPar(v);
        if (parU == parV) return 0;
        if (rank[parU] < rank[parV]) par[parU] = parV;
        else if (rank[parU] > rank[parV]) par[parV] = parU;
        else {
            par[parV] = parU;
            rank[parU]++;
        }
        return 1;
    }


    // union two nodes by size // O(4 * alpha) == O(1)
    // return true on successful union, o/w false
    bool unionBySize(int u, int v) {
        int parU = findPar(u);
        int parV = findPar(v);
        if (parU == parV) return 0;
        if (size[parU] < size[parV]) {
            par[parU] = parV;
            size[parV] += size[parU];
        } else {
            par[parV] = parU;
            size[parU] += size[parV];
        }
        return 1;
    }
};








// Use it as a data str in a problem
class DSU {
    vector<int> par, size;
public:
    DSU(int n) {
        par.resize(n + 1, -1);
        size.resize(n + 1, 1);
    }

    int findPar(int n) {
        return par[n] == -1 ? n : par[n] = findPar(par[n]);
    }

    int findSize(int n) {
        return size[n];
    }

    bool unite(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if (u == v) return 0;
        if (size[u] > size[v]) swap(u, v);
        par[u] = v;
        size[v] += size[u];
        return 1;
    }
};





// Use case :- detect a cycle
class Solution {
public:
    bool checkCycle(int n, vvi& edges) {
        DisjointSet dsu(n);
        for (auto e : edges) {
            // include a edge
            if (dsu.unionByRank(e[0], e[1]) == 0)  return 1;
        }
        return 0;
    }


    int noOfConnectedComponent(int n, vvi& edges) {
        DSU dsu(n);
        int cntComp = 0;
        for (auto& e : edges) dsu.unite(e[0], e[1]);
        for (int i = 0; i < n; i++) cntComp += (dsu.findPar(i) == i);
        return cntComp;
    }
};







// 2D DSU :- 
// Number of Islands - online queries
// GFG - https://practice.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands
class Solution2 {
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>>& ops) {
        vector<int> ans;
        vector<vector<int>> g(n, vector<int>(m, 0));
        DSU dsu(n * m);
        vector<vector<int>> ways = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        int cnt = 0;
        auto isValid = [&n, &m](int r, int c) {
            return r >= 0 && c >= 0 && r < n && c < m;
        };

        for (auto q : ops) {
            int i = q[0], j = q[1], u = m * i + j;
            if (g[i][j]) { ans.push_back(cnt); continue; }

            g[i][j] = 1;
            cnt++;
            for (auto w : ways) {
                int x = i + w[0], y = j + w[1], v = m * x + y;
                if (isValid(x, y) && g[x][y] && dsu.unite(u, v) && --cnt);
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};





// 2D DSU
// Making A Large Island
// LeetCode : https://leetcode.com/problems/making-a-large-island/description/
class Solution3 {
public:
    int largestIsland(vector<vector<int>>& g) {
        int n = g.size();
        vector< vector<int>> ways = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
        DSU dsu(n * n);
        auto isValid = [n](int i, int j) {
            return i >= 0 && j >= 0 && i < n && j < n;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j]) {
                    int u = n * i + j;
                    for (auto& w : ways) {
                        int x = i + w[0], y = j + w[1], v = x * n + y;
                        if (isValid(x, y) && g[x][y]) dsu.unite(u, v);
                    }
                }
            }
        }

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int u = n * i + j;
                if (!g[i][j]) {
                    set<int> st;
                    for (auto& w : ways) {
                        int x = i + w[0], y = j + w[1], v = x * n + y;
                        if (isValid(x, y) && g[x][y]) st.insert(dsu.findPar(v));
                    }
                    int cnt = 1;
                    for (auto x : st) {
                        cnt += dsu.findSize(x);
                    }
                    maxi = max(cnt, maxi);
                } else {
                    maxi = max(maxi, dsu.findSize(dsu.findPar(u)));
                }
            }
        }
        return maxi;
    }
};





int32_t main() {
    // fastIO();
    // Solution sol;

    {
        DisjointSet ds(7);
        ds.unionBySize(1, 2);
        ds.unionBySize(2, 3);
        ds.unionBySize(4, 5);
        ds.unionBySize(6, 7);
        ds.unionBySize(5, 6);

        // if 3 and 7 same are on same tree node or not 
        puts(ds.findPar(3) == ds.findPar(7) ? "In same tree" : "Not in same tree"); // Not in same tree

        ds.unionBySize(3, 7);
        puts(ds.findPar(3) == ds.findPar(7) ? "In same tree" : "Not in same tree"); // In same tree
    }
    cout << nl;


    {
        int n = 4; // no of nodes
        vvi edges = { {0, 1}, {1, 2}, {2, 3}, {3, 0} };
        Solution sol;
        puts(sol.checkCycle(n, edges) ? "Cycle found" : "Cycle not found"); // Cycle found
    }

    {
        int n = 4;
        vvi edges = { {0, 1}, {1, 2}, {2, 3} };
        Solution sol;
        puts(sol.checkCycle(n, edges) ? "Cycle found" : "Cycle not found"); // Cycle not found
    }


    {
        // 0 <-- 1 -> 2 -> 0  // there is not a cycle, but DisjointSet says there is cycle 
        // That's why Kruskal's algo fails for MST in case of directed graph 
        int n = 4;
        vvi edges = { {1, 0}, {1, 2}, {2,0} };
        Solution sol;
        puts(sol.checkCycle(n, edges) ? "Cycle found" : "Cycle not found"); // Cycle found
    }
    cout << nl;

    {
        int n = 6; // no of nodes
        vvi edges = { {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3} };
        Solution sol;
        cout << sol.noOfConnectedComponent(n, edges); // 3
    }

    return 0;
}

