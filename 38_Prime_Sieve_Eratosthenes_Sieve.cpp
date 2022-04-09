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
#define mems(x,ch)        memset(x,ch,sizeof(x))
#define sortv(x)         sort(x.begin(),x.end())
#define sortvr(x)        sort(x.rbegin(),x.rend())
#define all(x)           x.begin(), x.end()

const int N = 1e6 + 5;

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

bool isPrime(int n) {
    // METHOD - 1
    // for( int i=2; i<n; i++ ){
    //     if( n%i == 0 ) return false;
    // }
    // return true;


    // METHOD - 2
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}


// Sieve of Eratosthenes  // METHOD -3.1
void prime_sieve(vector<int>& prime) {
    // Assume all are prime, so prime[1 .. N ] = 1

    // Special case
    prime[0] = prime[1] = 0;

    // All even no. are Non-prime Except 2
    for (int i = 4; i <= N; i += 2) {
        prime[i] = 0;
    }

    // Sieve
    for (ll i = 3; i <= N; i += 2) {
        // If the current number is not marked, It is prime
        if (prime[i] == 1) {
            // Mark all multiples of i as 0, as those are not prime

            // METHOD - 3
            // for( ll j=2*i; j<=N; j+=i ){
            //     prime[j] = 0;
            // }

            // METHOD - 4
            for (ll j = i * i; j <= N; j += i) {
                prime[j] = 0;
            }
        }
    }
}


// find all primes from [1 ... N]  // METHOD - 3.2 
vi primeSieve(ll N) {
    vi primes;
    // Assume all are prime, so sieve[0 1 .. N ] = 1
    vector<int> sieve(N + 1, 1);

    sieve[0] = sieve[1] = 0;

    for (ll i = 2; i <= N; i++) {
        if (sieve[i]) {
            // If the current number is 1, It is prime
            primes.pb(i);
            for (ll j = i * i; j <= N; j += i) {
                // Mark all multiples of i as 0, as those are not prime
                sieve[j] = 0;
            }
        }
    }

    return primes;
}

int32_t main() {
    fastIO();

    // Assume all are prime 
    vector<int> prime(N + 1, 1);

    prime_sieve(prime);

    cout << "Prime no. between 1 and 100 : " << nl;
    for (int i = 1; i <= 100; i++) {
        if (prime[i] == 1) {
            cout << i << sp; // 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
        }
    }
    cout << nl;




    vi ans = primeSieve(100);
    for (auto x : ans) {
        cout << x << sp; // 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
    }
    cout << nl;

    return 0;
}

