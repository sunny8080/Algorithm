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

// QUE :- https://www.spoj.com/problems/CLFLARR/
// DSU used

class Solution {
    vi par;
public:
    void init(int n) {
        par.resize(n);

        // initiate par[x] = x
        iota(all(par), 0);
    }

    int getParent(int i) {
        return (i == par[i]) ? i : (par[i] = getParent(par[i]));
    }

    void unite(int x, int y) {
        x = getParent(x);
        y = getParent(y);

        if (x != y) {
            par[x] = max(par[x], par[y]);
            // par[y] = max(par[x], par[y]);
        }
    }


    void solve(int n, int q, vi& l, vi& r, vi& c) {
        init(n + 2);
        vi res(n + 2, 0);

        for (int i = l.size() - 1; i >= 0; i--) {
            // ind -> rightmost non coloured index
            int ind = getParent(l[i]);

            while (ind <= r[i]) {
                res[ind] = c[i];
                unite(ind, ind + 1);
                ind = getParent(ind);
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << res[i] << nl;
        }
    }

};



int32_t main() {
    fastIO();
    Solution sol;

    int n, q; cin >> n >> q;
    vi l(q), r(q), c(q);
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i] >> c[i];
    }

    sol.solve(n, q, l, r, c);





    return 0;
}

