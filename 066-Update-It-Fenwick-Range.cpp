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


// Update Range in Fenwick Tree
// And Query on points

// QUE :- https://www.spoj.com/problems/UPDATEIT/
// Add value val in range [l ... r]

class Solution {

public:
    void buildTree(vi& nums, vi& BIT) {
        for (int i = 0; i < nums.size(); i++) {
            updateNode(BIT, i + 1, nums[i]);
        }
    }

    void updateNode(vi& BIT, int ind, int inc) {
        while (ind < BIT.size()) {
            BIT[ind] += inc;
            ind += (ind & (-ind));
        }
    }

    int query(vi& BIT, int ind) {
        int ans = 0;
        while (ind > 0) {
            ans += BIT[ind];
            ind -= (ind & (-ind));
        }
        return ans;
    }

    void updateRange(vi& BIT, int l, int r, int inc) {
        updateNode(BIT, l, inc);
        updateNode(BIT, r + 1, -inc);
    }

    void printPreSum(vi& BIT) {
        for (int i = 1; i < BIT.size(); i++) {
            cout << query(BIT, i) << sp;
        }
        cout << nl;
    }
};

int32_t main() {
    fastIO();
    Solution sol;

    wt(t) {
        int n, u, l, r, val ; 
        cin >> n >> u;
        vi BIT(n + 1, 0);
        
        while (u--) {
            cin >> l >> r >> val;
            sol.updateRange(BIT, l + 1, r + 1, val);
        }

        // sol.printPreSum(BIT);

        wt(q) {
            int ind; cin >> ind;
            cout << sol.query(BIT, ind + 1) << nl;
        }
    }



    return 0;
}

