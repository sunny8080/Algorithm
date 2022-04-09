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

class Solution {
    
    public:

    ll powerMod( ll a, ll n, int m ){
        ll ans = 1LL;
        while( n ){
            if( (n&1) ) ans = (ans*a)%m;
            a = (a*a)%m;
            n = n>>1;
        }
        return ans;
    }
    

    // Using Fermat's little theorem // p is prime 
    ll modInverse( int a, int p ){
        // To inverse to be exist under modulo p, a and p should be co-prime
        if( __gcd(a,p) != 1 ){
            return INT_MAX;
        }

        return powerMod(a, p-2, p);
    }


    // Using Fermat's little theorem // p should be prime // also n<p otherwise ans is 0 which can be wrong 
    ll nCrModPFermet( ll n, ll r, ll p ){ 
        if( n<r ) return 0;
        if( r == 0 ) return  1;

        // nCr % p = ( (fact[n] * modInverse(fact[r], p))%p * modInverse(fact[n-r], p) )%p

        vll fact(n+1);
        fact[0] = 1;
        
        for( int i=1; i<=n; i++ ){
            fact[i] = (fact[i-1] * i)%p;
        }

        ll ans = ( (fact[n] * modInverse(fact[r], p))%p * modInverse(fact[n-r], p) )%p ;
        return ans;
    }
};

int32_t main(){
    fastIO();
    
    Solution sol;

    ll x = sol.modInverse(8, 6);
    if( x == INT_MAX ){
        cout<<"Inverse doesn't exist"<<nl; // Inverse ...
    }else{
        cout<<x<<nl;
    }
    
    cout<<sol.modInverse(3, 11)<<nl; // 4
    cout<<nl;

    // mod should be prime
    cout<<sol.nCrModPFermet(10, 2, 13)<<nl; // 6
    cout<<sol.nCrModPFermet(10, 2, mod)<<nl; // 45
    // cout<<sol.nCrModPFermet(6, 1, 5)<<nl; // 0 -> which is not right // ans should be 6%5=1
    cout<<nl;
    
    return 0;
}
    
    