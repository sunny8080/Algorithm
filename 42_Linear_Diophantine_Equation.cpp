#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll               long long
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

const ll cnst = 1e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //    #ifndef ONLINE_JUDGE
    //        freopen("input.txt", "r", stdin);
    //        freopen("output.txt", "w", stdout);
    //    #endif
}

// Linear Diphantine Equation ex
// QUE discussed here :- https://codeforces.com/problemset/problem/1244/C

class Solution {

public:
    ll gcd(ll a, ll b) {
        return (b == 0 ? a : gcd(b, a % b));
    }

    ll modInverse(ll a, ll m) {
        if (m == 1) return 0;
        ll m0 = m, y = 0, x = 1;

        while (a > 1) {
            ll q = a / m, t = m;
            m = a % m, a = t;
            t = y;
            y = x - q * y;
            x = t;
        }
        if (x < 0) x += m0;

        return x;
    }

    // x*w + y*d = p
    // x + y + z = n
    void solve(ll n, ll p, ll w, ll d) {
        ll g = gcd(w, d);
        if ((p % g != 0) || (n * w < p)) {
            cout << -1;
            return;
        }

        w /= g;
        d /= g;
        p /= g;

        ll y = ((p % w) * modInverse(d, w)) % w;
        ll x = (p - y * d) / w;
        ll z = n - (x + y);

        if ((x < 0) || (z < 0)) {
            cout << -1;
            return;
        }

        cout << x << sp << y << sp << z;
    }
};


int32_t main() {
    fastIO();

    ll n, p, w, d; cin >> n >> p >> w >> d;
    (new Solution())->solve(n, p, w, d);

    // cout<<(new Solution())->modInverse(3, 11)<<nl;

    return 0;
}


// OUTPUT :- 
// 30 60 3 1 -> 20 0 10
// 10 51 5 4 -> -1
// 20 0 15 5 -> 0 0 20
