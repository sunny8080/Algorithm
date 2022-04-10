#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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
#define mod              1000000000
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

void fastIO(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    #endif
}

// Linear Reccurance Matrix Exponentiation
// Q -> https://www.spoj.com/problems/SEQ/ 

vll b,c;
ll k;

class Solution {
    
    vector<vector<ll>> multiply( vector<vector<ll>> A, vector<vector<ll>> B ){
        
        vector<vector<ll>> C(k+1, vector<ll>(k+1) );
        // Multiply two vectors
        for( int i=1; i<=k; i++ ){
            for( int j=1; j<=k; j++ ){
                for( int t=1; t<=k; t++ ){
                    C[i][j] = ( C[i][j] + (A[i][t]*B[t][j])%mod)%mod;
                }
            }
        }
        return C;
    }

    vector<vector<ll>> pwr( vector<vector<ll>> M, int n ){
        if( n == 1 ) return M;
        if( n&1 ){
            return multiply(M,pwr(M, n-1));
        }
        vector<vector<ll>> tmp = pwr(M,n/2);
        return multiply(tmp, tmp);
    }

    public:
    ll solve(ll n ){
        if( n == 0 ) return 0;
        if( n <= k ) return b[n-1];

        // array to store f(n) :- F1(n) 
        // 1 based indexing
        vll F1(k+1);
        for( int i=1; i<=k; i++ ) F1[i] = b[i-1];

        // create Transformation Matrix
        vector<vector<ll> > T(k+1, vector<ll>(k+1) );

        for( int i=1; i<=k; i++ ){
            for( int j=1; j<=k; j++ ){
                if( i<k ){
                    if( j == i+1 ){
                        T[i][j] = 1;
                    }else{
                        T[i][j] = 0;
                    }
                }else{
                    T[i][j] = c[k-j];
                }
            }
        }

        // Step - 3 // T -> T^n
        T = pwr(T, n-1 );

        // step - 4 // Matrix[1][i] * vector[i]
        ll ans = 0;
        for( int i=1; i<=k; i++ ){
            ans = (ans + (T[1][i]*F1[i]) %mod )%mod;
        }
        return ans;
    }
};

int32_t main(){
    fastIO();
    
    wt(t){
        cin>>k;
        ll x; 
        for( int i=0; i<k; i++ ) { cin>>x; b.push_back(x); }; 
        for( int i=0; i<k; i++ ) { cin>>x; c.push_back(x); };
        ll n; cin>>n;

        cout<<(new Solution())->solve(n)<<nl;

        b.clear();
        c.clear();
    }
    
    
    return 0;
}
    


// 3 
// 3 
// 5 8 2 
// 32 54 6 
// 2 
// 3 
// 1 2 3 
// 4 5 6 
// 6 
// 3 
// 24 354 6 
// 56 57 465 4
// 98765432
//
// OUTPUT:-
// 8
// 714
// 257599514