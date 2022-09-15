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

const int N = 1e7;

void bitsetSieve( bitset<N+5> &bset, vi &primes ){
    bset.set(); // Set all bits // 1 1 1 1 1 ..... 1

    bset[0] = bset[1] = 0;

    for( ll i=2; i<=N; i++ ){
        if( bset[i] ){
            primes.push_back(i);
            for( ll j=i*i; j<=N; j+=i ){
                bset[j]=0;
            }
        }
    }
}

bool isPrime( ll n, bitset<N+5> &bset, vi &primes ){
    // if n < 1e7
    if( n <= N ){
        return bset[n] == 1 ? true : false;
    }

    // n > 10^7
    for( ll i=0; primes[i]*(ll)primes[i] <= n; i++ ){
        if( n % primes[i] == 0 ) return false;
    }
    return true;
}

int32_t main(){
    fastIO();
    
    bitset<N+5> bset;
    vi primes;

    bitsetSieve(bset, primes);

    cout<<"1000 Prime no.s :- "<<nl;
    for( int i=0; i<=1000; i++ ){
        cout<<primes[i]<<sp;
    }
    cout<<"\n\n";


    if( isPrime(25, bset, primes ) ){
        cout<<"25 is a prime no. "<<nl;
    }else{
        cout<<"25 is not a prime no. "<<nl;
    }
    
    if( isPrime(12345678913, bset, primes ) ){
        cout<<"12345678913 is a prime no. "<<nl;
    }else{
        cout<<"12345678913 is not a prime no. "<<nl;
    }
    
    if( isPrime(21474836471, bset, primes ) ){
        cout<<"21474836471 is a prime no. "<<nl;
    }else{
        cout<<"21474836471 is not a prime no. "<<nl;
    }
    
    return 0;
}
    
    