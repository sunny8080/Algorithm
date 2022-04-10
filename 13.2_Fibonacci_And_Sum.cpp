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
#define mem(x,ch)        memset(x,ch,sizeof(x))
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


// Find Fibosum 
// Question Discussed here
// https://www.spoj.com/problems/FIBOSUM/
class Solution {
    
    vector<vector<ll>> multiplyMatrix( vector<vector<ll>> A, vector<vector<ll>> B, ll size ){
        vector<vector<ll>> C(size+1, vector<ll>(size+1));

        for( int i=1; i<=size; i++){
            for( int j=1; j<=size; j++ ){
                for( int k=1; k<=size; k++ ){
                    C[i][j] = ( C[i][j] + (A[i][k]*B[k][j])%mod )%mod;
                }
            }
        }
        return C;
    }

    vector<vector<ll>> pwrMatrix( vector<vector<ll>> A, ll n, ll size ){
        if( n == 1 ) return A;
        if( (n&1) ) return multiplyMatrix( A, pwrMatrix(A, n-1, size), size);
        vector<vector<ll>> tmp = pwrMatrix( A, n/2, size);
        return multiplyMatrix( tmp, tmp, size );


        return A;
    }

    public:

    // #METHOD 1
    ll fib( ll n ){
		// for n, F(n) => cout<< fib2(n+1);
        vll F1 = {-1, 0, 1};
        vll coeff = {1, 1};
        ll k=2;

		if( n <= 1 ) return F1[n];

        // Create Transformation matrix
        vector<vector<ll>> T(k+1, vector<ll>(k+1));
        for( int i=1; i<=k; i++ ){
            for( int j=1; j<=k; j++ ){
                if( i<k ){
                    if( j==i+1) T[i][j] = 1;
                    else T[i][j] = 0;
                }else{
                    T[i][j] = coeff[k-j];
                }
            }
        }

        T = pwrMatrix(T, n-1, k);

        ll ans=0;
        for( int i=1; i<=k; i++ ){
            ans =(ans + (T[1][i]*F1[i])%mod )%mod;
        }

        return ans;
    }

    // #METHOD 2
    ll fib2( ll n, map<ll, ll> &Fib ){
        // for n, fib(n) => cout<< (n==0 ? 0 : fib2(n-1));
        if( Fib.count(n) ) return Fib[n];

        ll k = n/2;
        if( (n&1) ) {  // n is odd
            return Fib[n] = ( fib2(k, Fib)*fib2(k+1, Fib) + fib2(k-1, Fib)*fib2(k, Fib) )%mod;
        }else{  // n is even
            return Fib[n] = ( fib2(k, Fib)*fib2(k, Fib) + fib2(k-1, Fib)*fib2(k-1, Fib) )%mod;
        }
    }




    // #METHOD - 1 for Fib Sum from 0 to nth term
    ll fibSum( ll n ){
        // S(n) = F(n+2)-1
		// F(n) = fib(n+1)
        ll ans = (fib(n+2+1) - 1 + mod)%mod;
        return ans;
    }

};


int32_t main(){
    fastIO();

    wt(t){
        ll m, n; cin>>m>>n;

        ll sum1 = (new Solution())->fibSum(m-1);
        ll sum2 = (new Solution())->fibSum(n);

        // cout<<"fibSum(m-1) : "<<sum1<<nl;
        // cout<<"fibSum(n) : "<<sum2<<nl;

        ll ans = ((sum2 - sum1)%mod + mod)%mod;
        cout<<ans<<nl;

    }
    
    return 0;
}
    
    


// 3
// 0 3
// 3 5
// 10 19
// OUTPUT :-
// 4
// 10
// 10857