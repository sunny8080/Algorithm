#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll 				 long long
#define ff 				 first
#define ss 				 second
#define pb 				 push_back
#define mp 				 make_pair
#define pii 			 pair<int,int>
#define vi 				 vector<int>
#define vll 			 vector<long long> 
#define vvi 			 vector< vector<int>>
#define vvll 			 vector< vector<long long>>
#define mii 			 map<int,int>
#define pqb 			 priority_queue<int>
#define pqs 			 priority_queue<int, vector<int>, greater<int>>
#define setbits(x)		 __builtin_popcountll(x)
#define zrobits(x) 		 __builtin_ctzll(x)
#define mod 			 1000000009
#define inf 			 1e18
#define ps(x,y) 		 fixed<<setprecision(y)<<x
#define mk(arr, n, type) type *arr=new type[n];
#define wt(x) 			 int x; cin>>x; while( x-- )
#define rep(i,a,b) 		 for( int i=a; i<=b; i++ )
#define repi(i,a,b) 	 for( int i=a; i>=b; i-- )
#define sp 				 ' '
#define nl 				 char(10)
#define endl 			 char(10)
#define PRT(ar) 		 for( auto i : ar )cout<<i<<sp;cout<<nl;
#define mem(x,ch) 		 memset(x,ch,sizeof(x))
#define sortv(x) 		 sort(x.begin(),x.end())
#define sortvr(x) 		 sort(x.rbegin(),x.rend())

const ll cnst = 1e6 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree< pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // 	freopen("input.txt", "r", stdin);
    // 	freopen("output.txt", "w", stdout) ;
    // #endif
}



int32_t main() {
    fastIO();

    ll q, k; cin >> q >> k;
    pbds dist;
    priority_queue<ll> pq;
    while (q--) {
        ll type; cin >> type;
        if (type == 1) {
            ll x, y; cin >> x >> y;
            x = pow(x, 2) + pow(y, 2);
            pq.push(x);
            if (pq.size() > k) pq.pop();
        } else {
            cout << pq.top() << nl;
        }
    }


    return 0;
}

