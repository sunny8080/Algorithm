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
#define mod              1000000009
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

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //    #ifndef ONLINE_JUDGE
    //        freopen("input.txt", "r", stdin);
    //        freopen("output.txt", "w", stdout);
    //    #endif
}

class Solution {

public:
    // METHOD -1  // O(N) for prime N 
    vi findAllPrimeFactors(ll n) {
        vi primeFactors;

        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                primeFactors.pb(i);
                n /= i;
            }
        }
        return primeFactors;
    }



    // METHOD -2 // O(sqrt(N))
    vi findAllPrimeOfN(ll n) {
        vi primeFactors;

        for (ll i = 2; i * i <= n; i++) {
            while (n % i == 0) {     // i is a prime factor of n
                primeFactors.pb(i);
                n /= i;
            }
        }

        // if n is not 1 then n itself is a prime no
        if (n != 1) {
            primeFactors.pb(n);
        }

        return primeFactors;
    }

    // METHOD-2.1 
    vector<pair<ll, ll>> findAllPrimeOfN2(ll n) {
        vector<pair<ll, ll>> factors;
        ll cnt;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                cnt = 0;
                while (n % i == 0) {
                    cnt++;
                    n /= i;
                }
                factors.pb(make_pair(i, cnt));
            }
        }
        if (n != 1) {
            factors.pb(make_pair(n, 1));
        }
        return factors;
    }


    // TC : O(N)
    int isPrime(int n) {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) return 0;
        }
        return 1;
    }

    // TC : O(sqrt(N))
    int isPrime2(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return 0;
        }
        return 1;
    }

    // O(N*loglogN)
    vi primeSieve(ll N) {
        vi primes;
        vi sieve(N + 1, 1);

        sieve[0] = sieve[1] = 0;

        for (ll i = 2; i <= N; i++) {
            // i is prime if sieve[i] = 1
            if (sieve[i] == 1) {
                primes.pb(i);
                for (ll j = i * i; j <= N; j += i) {
                    sieve[j] = 0;
                }
            }
        }
        return primes;
    }


    // METHOD - 3  // Using prime sieve // O(logN)
    vi factorize(ll n) {
        vi primes = primeSieve(n);
        vi primeFactors;

        int i = 0;
        int pr = primes[i++];

        while (pr * pr <= n) {
            if (n % pr == 0) {
                while (n % pr == 0) {
                    primeFactors.pb(pr);
                    n /= pr;
                }
            }
            pr = primes[i++];
        }

        if (n != 1) {
            primeFactors.pb(n);
        }
        return primeFactors;
    }


    // Find smallest prime factor from [ 1... N]   // Using Prime Sieve // O(N*loglogN)
    vi findSmallestPrimeFactor(int N) {
        vi spf(N + 1, 1); // smallest Prime Factor
        spf[1] = 1;

        for (ll i = 2; i <= N; i++) {
            // i is prime if spf[i]=1
            if (spf[i] == 1) {
                spf[i] = i;
                for (ll j = i * i; j <= N; j += i) {
                    // if not marked, mark its smallest prime factor
                    if (spf[j] == 1) spf[j] = i;
                }
            }
        }

        // for( int i=0; i<=100; i++ ) cout<<spf[i]<<sp;    cout<<nl<<nl;
        return spf;
    }


    // METHOD - 4  // O(log(N)) // Using prime sieve and Smallest Prime Factor
    vi findAllPrimeFactorsBySieveOfErato(ll n) {

        // PreComputation
        ll N = 1e5;
        vi spf = findSmallestPrimeFactor(N);

        vi primeFactors;
        while (n != 1) {
            primeFactors.pb(spf[n]);
            n /= spf[n];
        }
        return primeFactors;
    }



    // find no of divisors using prime sieve
    int noOfDivisors(int n) {
        vi primes = primeSieve(n);

        int i = 0;
        int pr = primes[i++];
        int ans = 1;

        while (pr * pr <= n) {
            int cnt = 0;
            while (n % pr == 0) {
                cnt++;
                n /= pr;
            }

            // As if (2^x * 3^y * 5^z) then no. of divisors can be formed is (x+1)*(y+1)*(z+1)
            ans = ans * (cnt + 1);
            pr = primes[i++];
        }

        if (n != 1) {
            ans = ans * 2;
        }

        return ans;
    }
};


int32_t main() {
    fastIO();

    Solution sol;

    PRT(sol.findAllPrimeFactors(1000)); // 2 2 2 5 5 5
    PRT(sol.findAllPrimeFactors(16170)); // 2 3 5 7 7 11
    PRT(sol.findAllPrimeFactors(7)); // 7
    cout << nl;

    PRT(sol.findAllPrimeOfN(1000)); // 2 2 2 5 5 5
    PRT(sol.findAllPrimeOfN(16170)); // 2 3 5 7 7 11
    cout << nl;

    PRT(sol.factorize(1000)); // 2 2 2 5 5 5
    PRT(sol.factorize(16170)); // 2 3 5 7 7 11
    cout << nl;

    PRT(sol.findAllPrimeFactorsBySieveOfErato(1000)); // 2 2 2 5 5 5
    PRT(sol.findAllPrimeFactorsBySieveOfErato(16170)); // 2 3 5 7 7 11
    cout << nl;
    cout << nl;

    cout << sol.noOfDivisors(10) << nl; // 4 // as 10 -> 1, 2, 5, 10
    cout << sol.noOfDivisors(40) << nl; // 8 
    cout << sol.noOfDivisors(60) << nl; // 12

    return 0;
}



// 2 2 2 5 5 5
// 2 3 5 7 7 11
// 7

// 2 2 2 5 5 5
// 2 3 5 7 7 11

// 2 2 2 5 5 5
// 2 3 5 7 7 11

// 2 2 2 5 5 5
// 2 3 5 7 7 11


// 4
// 8
// 12