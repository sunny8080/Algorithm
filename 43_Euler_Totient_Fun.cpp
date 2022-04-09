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

// Euler's Totient Function ( phi ) -> for N, it return count of numbers in [ 1 ... N ] which are coprime with N. i.e., gcd(N, i)=1.

class Solution {
    
    public:

    // METHOD - 1  // By Definition  // O(N * logN)
    int phi( int n ){
        int cnt=0;
        for( int i=1; i<=n; i++ ){
            if( __gcd(n, i) == 1 ) 
                cnt++;
        }
        return cnt;
    }

    // METHOD - 2 // By formula // O(sqrt(N))
    int phiByFormula( int n ){
        float ans=n;
        
        for( int p=2; p*p<=n; p++ ){
            // Check if p is prime
            if( n%p == 0 ){
                ans *= (1.0 - (1.0/p));

                while( n%p == 0 ) n/=p;
            }
        }

        // if n is a prime no
        if( n>1 ){
            ans *= (1.0 - (1.0/n));
        }
        return (int)ans;
    }


    // METHOD - 3 // Avoid float calculation // O(sqrt(N))
    int phiByFormula2( int n ){
        int ans=n;
        
        for( int p=2; p*p<=n; p++ ){
            // check if p is prime or not
            if( n%p == 0 ){
                // substract all multiple of prime p from n
                ans = (ans - ans/p);

                while( n%p == 0 ) n/=p;
            }
        }

        // if n is a prime no
        if( n>1 ){
            ans = (ans - ans/n);
        }
        return ans;
    }


    // find Smallest Prime Factor for [ 1 ... N ]
    vi findSmallestPrimeFactor( ll N ){
        vi spf(N+1, 1);
        spf[1] = 1;
        for( ll i=2; i<=N; i++ ){
            // if 1 then i is prime
            if( spf[i] == 1 ){
                spf[i] = i;

                for( ll j=i*i; j<=N; j+=i ){
                    if( spf[j] == 1 ) spf[j] = i;
                }
            }
        }
        return spf;
    }


    // Find Prime factor of n
    vi findAllPrimeFactorsBySieveErato( ll n ){
        vi spf = findSmallestPrimeFactor(1e5);
        vi primeFactors;

        while( n>1 ){
            int p = spf[n];
            if( ! binary_search(all(primeFactors), p ) )
                primeFactors.pb(p);
            n /= p;
        }
        return primeFactors;
    }


    // METHOD - 4 // Find prime factors by Prime Sieve // O(logN)
    int phiByFormula3( int n ){
        vi primeFactors = findAllPrimeFactorsBySieveErato(n);
        int ans = n;

        for( int i=0; i<primeFactors.size(); i++ ){
            ans = (ans - ans/primeFactors[i]);
        }
        return ans;
    }


    // METHOD - 5 // Find phi for all numbers between [ 1 ... N ]  
    // Sieve of Eratosthenes is used // So O(N * loglogN ) // Best complexicity
    vi computeTotient( int n ){
        vi phi(n+1);

        // Indicate not initiated // max value of phi(n) = n-1 
        for( int i=1; i<=n; i++ ){
            phi[i] = i;
        }

        for( int p=2; p<=n; p++ ){

            // Check p is prime or not by Sieve Erato 
            if( phi[p] == p ){

                // Update phi values of all multiple of prime p 
                for( int j=p; j<=n; j+=p ){
                    phi[j] -= phi[j]/ p;
                }
            }
        }

        return phi;
    }


    // METHOD - 6 // Find phi for all numbers between [ 1 ... N ]  
    // Addition property of phi is used //  O(N*logN)
    vi computeTotientByAddProperty( int n ){
        vi phi(n+1);
        phi[0]=0, phi[1]=1;

        for( int i=2; i<=n; i++ ){
            phi[i] = i-1;
        }

        for( int i=2; i<=n; i++ ){
            for( int j=2*i; j<=n; j+=i ){
                phi[j] -= phi[i];
            }
        }
        return phi;
    }

};


int32_t main(){
    fastIO();
    
    Solution sol;

    cout<<sol.phi(7)<<nl; // 6  // -> 1, 2, 3, 4, 5, 6
    cout<<sol.phi(8)<<nl; // 4 // -> 1, 3, 5, 7
    cout<<sol.phi(10)<<nl; // 4
    cout<<sol.phi(15)<<nl; // 8
    cout<<nl;
    
    cout<<sol.phiByFormula(7)<<nl; // 6 
    cout<<sol.phiByFormula(8)<<nl; // 4 
    cout<<sol.phiByFormula(10)<<nl; // 4
    cout<<sol.phiByFormula(15)<<nl; // 8
    cout<<nl;

    cout<<sol.phiByFormula2(7)<<nl; // 6 
    cout<<sol.phiByFormula2(8)<<nl; // 4 
    cout<<sol.phiByFormula2(10)<<nl; // 4
    cout<<sol.phiByFormula2(15)<<nl; // 8
    cout<<nl;

    cout<<sol.phiByFormula3(7)<<nl; // 6 
    cout<<sol.phiByFormula3(8)<<nl; // 4 
    cout<<sol.phiByFormula3(10)<<nl; // 4
    cout<<sol.phiByFormula3(15)<<nl; // 8
    cout<<nl<<nl;


    // Compute phi for all no. between [ 1 ... 25 ]
    vi phi = sol.computeTotient(25);
    cout<<phi[7]<<nl; // 6 
    cout<<phi[8]<<nl; // 4 
    cout<<phi[10]<<nl; // 4 
    cout<<phi[15]<<nl; // 8
    cout<<phi[22]<<nl; // 10
    cout<<nl;


    phi = sol.computeTotientByAddProperty(25);
    cout<<phi[7]<<nl; // 6 
    cout<<phi[8]<<nl; // 4 
    cout<<phi[10]<<nl; // 4 
    cout<<phi[15]<<nl; // 8
    cout<<phi[22]<<nl; // 10
    cout<<nl;


    return 0;
}
    
    