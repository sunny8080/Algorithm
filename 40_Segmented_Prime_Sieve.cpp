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

// Segmented Prime Sieve
// QUEstion Discussed here :-
// https://www.spoj.com/problems/PRIME1/

const int N=100005;
vector<int> primes;

class Solution {
    
    public:
    void primeSieve(){
        vector<int> arr(N+1, 1);
        arr[0] = arr[1] = 0;
        for( ll i=2; i<=N; i++ ){
            if( arr[i] ){
                primes.pb(i);
                for( ll j=i*i; j<=N; j+=i ){
                    arr[j]=0;
                }
            }
        }
    }

    void solve(ll m, ll n ){
        // Assume all no. are prime between [m ... n]
        // So dummy array contains all 1 => [ 1... 1]
        vector<ll> segment(n-m+1, 1);
        if( m == 1 ){
            segment[0]=0;
        }else if( m == 0 ){
            segment[0] = segment[1] = 0;
        }

        for( auto x : primes ){
            // Stop loop if remaining primes nos are not needed
            if( (ll)x*x > n ){
                break;
            }
            ll start = (m/x)*x;
            if( start < m ) start += x;

            // Prime no. lies in the segment sieve range
            if( x >= m ) start = 2*x;

            // Mark all multiple of x as Not prime in range [start ... n]
            for( ll i=start; i<=n; i+=x ){
                segment[i-m]=0;
            }
        }

        // Loop and print primes
        for( ll i=0; i<segment.size(); i++ ){
            if( segment[i] ){
                cout<<i+m<<nl;
            }
        }
    }
};

int32_t main(){
    fastIO();

    Solution sol;
    sol.primeSieve();

    // for(int i=0; i<100; i++ ) cout<<primes[i]<<sp;
    
    wt(t){
        ll m, n; cin>>m>>n;
        sol.solve(m, n);
        cout<<nl;
    }
    
    
    return 0;
}


// 2
// 1 10
// 3 5
// OUTPUT :-
// 2
// 3
// 5
// 7
//
// 3
// 5
    