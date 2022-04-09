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

void fastIO(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    #endif
}


// Wilson's Theorem
// QUE:- https://www.spoj.com/problems/DCEPC11B/
class Solution {
    
    public:

    ll modPower( ll a, ll b, ll m){
        ll ans=1;
        while(b){
            if( (b&1) ) ans = (ans*a)%m;
            a = (a*a)%m;
            b >>=1;
        }
        return ans;
    }

    // Mod inverse by Fermat's little theorem
    ll modInv( ll a, ll p ){
        if( p == 1 ) return 0;
        return modPower(a, p-2, p);
    }

    ll findModFact( ll n, ll p){
        if( n>=p ) return 0;

        // Wilson's theorem
        ll ans=p-1;
        for( ll i=n+1; i<p; i++ ){
            ans = (ans*modInv(i, p))%p;
        }

        return ans;
    }
};


int32_t main(){
    fastIO();
    
    wt(t){
        ll n, p; cin>>n>>p;
        cout << (new Solution())->findModFact(n, p) << nl;
    }

    return 0;
}
    

// Example :-
// 3
// 2 5
// 5 11
// 21 71
// OUT:-
// 2
// 10
// 6

