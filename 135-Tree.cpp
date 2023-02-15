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


// Tree have n nodes and n-1 
// it has no cycle, so from one node to another node there is a unique path



// 0- based indexing
class Solution {

	void dfs(int node, int par, vi& dist, vvi& adj) {
		for (auto& nbr : adj[node]) {
			if (nbr != par) {
				dist[nbr] = dist[node] + 1;
				dfs(nbr, node, dist, adj);
			}
		}
	}
public:
	// find diameter of a tree // O(N) 
	int findDiameter(vvi& adj) {
		// if (adj.size() == 1) return 0;
		int n = adj.size();
		vi dist(n, 0);

		// find farthest node assuming any node as source
		dfs(0, -1, dist, adj);
		int maxDist = 0, farNode = 0;
		for (int i = 0; i < n; i++) {
			if (maxDist < dist[i]) maxDist = dist[i], farNode = i;
			dist[i] = 0;
		}

		// diameter = find maximum distance from farthest node
		dfs(farNode, -1, dist, adj);
		int dia = *max_element(dist.begin(), dist.end());
		return dia;
	}
};







int32_t main() {
	fastIO();
	Solution sol;

	/*
	{
		dri(n);
		vvi adj(n);

		for (int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cout << sol.findDiameter(adj) << nl;
	}
	*/

	int n = 5;
	vvi edges = { {0, 1}, {1, 2}, {2, 3}, {1 , 4} };
	vvi adj(n);
	for (auto& e : edges) {
		adj[e[0]].push_back(e[1]);
		adj[e[1]].push_back(e[0]);
	}
	cout << sol.findDiameter(adj) << nl; // 3



	return 0;
}




