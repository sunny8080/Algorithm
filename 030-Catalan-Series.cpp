#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ull              unsigned long long
#define ll               long long
#define ff               first
#define ss               second
#define pb               push_back
#define mp               make_pair
#define pii              pair<int,int>
#define vi               vector<int>
#define vll              vector<long long> 
#define vvi              vector< vector<int>>
#define vvll             vector< vector<long long>>
#define mii              map<int,int>
#define pqb              priority_queue<int>
#define pqs              priority_queue<int, vector<int>, greater<int>>
#define setbits(x)       __builtin_popcountll(x)
#define zrobits(x)       __builtin_ctzll(x)
#define mod              1000000009
#define inf              1e18
#define ps(x,y)          fixed<<setprecision(y)<<x
#define mk(arr, n, type) type *arr=new type[n];
#define wt(x)            int x; cin>>x; while( x-- )
#define rep(i,a,b)       for( int i=a; i<=b; i++ )
#define repi(i,a,b)      for( int i=a; i>=b; i-- )
#define sp               ' '
#define nl               char(10)
#define endl             char(10)
#define PRT(ar)          for( auto i : ar )cout<<i<<sp;cout<<nl;
#define mem(x,ch)        memset(x,ch,sizeof(x))
#define sortv(x)         sort(x.begin(),x.end())
#define sortvr(x)        sort(x.rbegin(),x.rend())

const ll cnst = 1e6 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//    #ifndef ONLINE_JUDGE
	//        freopen("input.txt", "r", stdin);
	//        freopen("output.txt", "w", stdout);
	//    #endif
}

// Catalan number
// Soln - https://youtu.be/0s20L4-chDA



// No of binary search tree that can be formed using N nodes [1....N] -> Nth catalann no.
// No of binary tree that can be formed using N nodes [1....N] -> (Nth catalann no) * (N!)
// no of unlabelled binary trees = same as BST = nth catalan no
// Catalan(N) = (2nCn)/(n+1) == 2n! / (n! * (n+1)!) 



class Solution {

	ull nCr(int n, int r) {
		ull ans = 1;
		for (int i = 1; i <= r; i++) {
			ans *= (n - r + i);
			ans /= i;
		}
		return ans;
	}

public:
	ull nthCatalanNumber(ll n) {
		// Catalan(N) = (2nCn)/(n+1) == 2n! / (n! * (n+1)!) 
		ull ans = nCr(2 * n, n) / (n + 1);
		return ans;
	}

	// top down dp
	ull nthCatalanNumber2(ll n, vi& dp) {
		if (n == 0) return 1;
		if (n == 1) return 1;

		if (dp[n] != -1) return dp[n];

		ll val = 0;
		for (int i = 1; i <= n; i++) {
			val += nthCatalanNumber2(i - 1, dp) * 1LL * nthCatalanNumber2(n - i, dp);
		}
		return dp[n] = val;
	}

};

int32_t main() {
	fastIO();
	Solution sol;

	cout << "Catalan Series :- " << nl;
	int n = 8;
	for (int i = 0; i < n; i++) {
		cout << sol.nthCatalanNumber(i) << sp; // 1 1 2 5 14 42 132 429
	}
	cout << nl;

	vector<int> dp(n + 1, -1);
	for (int i = 0; i < n; i++) {
		cout << sol.nthCatalanNumber2(i, dp) << sp; // 1 1 2 5 14 42 132 429
	}

	return 0;
}

