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
    
    // METHOD - 1 // Trial Division
    bool isPrimeTrial( ll n ){
        // for( ll i=2; i<n; i++ ){
        //     if( n%i == 0 )
        //         return false;
        // }

        // As if x is divisible by t then x is also divisble by x/t // Also, t or x/t <= sqrt(x)
        for( ll i=2; i*i<=n; i++ ){
            if( n%i == 0 )
                return false;
        }
        return true;
    }


    ll modPower( ll a, ll n, ll m ){
        ll ans = 1LL;
        while( n ){
            if( (n&1) ) ans = (ans*a)%m;

            a = (a*a)%m;
            n = n>>1;
        }
        return ans;
    }


    // METHOD - 2 // Fermat Primality Test // O(K* logN) // k=iter
    bool isPrimeProbablyFermat( int n, int iter=5 ){
        if( n<4 ){
            return n==2 || n==3;
        }

        for( int i=0; i<iter; i++ ){
            // Pick any a in [ 2... n-2]
            int a = 2 + rand()%(n-3);

            if( __gcd(a, n) != 1 ) return false;

            // Fermat's little theorem
            if( modPower(a, n-1, n) != 1)
                return false;
        }
        return true;
    }


    bool checkComposite( int n, int a, int d, int s ){
        int x = modPower(a, d, n);
        if( x == 1 || x==n-1 ) return false;

        for( int r=1; r<s; r++ ){
            x = (x * x) % n;
            d = d>>1;

            if( x == n-1 ) return false;
        }
        return true;
    }

    // METHOD - 3 // Miller - Rabin Primality test
    bool isPrimeMillerRabin( int n, int iter=5 ){
        if( n<4 ){
            return n==2 || n==3;
        }

        int s=0, d=n-1;
        while( (d&1) == 0 ){
            d = d>>1;
            s++;
        }

        for( int i=0; i<iter; i++ ){
            int a = 2 + rand()%(n-3);

            // Miller test  or // check composite or not
            if( checkComposite(n, a, d, s) ) return false;
        }
        return true;
    }







    // find (a+b)%m // for big numbers
    ll modMul( ll a, ll b, ll m ){
        ll res=0;
        while( b ){
            if( (b&1LL) ) res = (res + a)%m;
            a = (a*2)%m;
            b /= 2;
        }
        return res;
    }


    // find (a^n)%p // for big numbers
    ll bigModPower( ll a, ll n, ll p ){
        ll ans = 1LL;
        while( n ){
            if( (n&1) ){
                ans = modMul(ans, a, p)%p;
            }

            a = modMul(a, a, p)%p;
            n = n>>1;
        }
        return ans;
    }



    // METHOD - 4 // Miller - Rabin primality test
    // Some improvement has done
    bool isPrimeForLarge( ll n ){
        if( n<4 ){
            return n==2 || n==3;
        }
        if( n%2 == 0 ) return false;    

        // So, now n is only odd and in [ 4 ...3*10^8 ]

        // n-1 = s * pow(2,d)
        ll d=n-1, s=0;
        while( (d&1) == 0 ){
            d >>=1;
            s++;
        }

        // To check prime below 3*10^18
        vi primeDiv = {2, 3, 5, 7, 11, 13, 17, 19, 23 };
        
        for( int i=0; i<primeDiv.size(); i++ ){
            // a should be in [ 2 ... n-2]
            if( primeDiv[i] > n-2 ) continue;

            ll ad = bigModPower( primeDiv[i], d, n);

            // check n can be prime or not // Miller test
            if( ad%n == 1 ) continue;

            bool prime=false;
            for( ll r=0; r<s; r++ ){
                // (2^r)%n
                ll rr = modPower(2, r, n);
                
                // ( a^(d*2^r))%n  = (ad^rr)%n
                ll ard = modPower(ad, rr, n);

                if( ard %n == n-1 ){
                    prime = true;
                    break;
                }
            }

            if( prime == false ) return false;
        }

        return true;
    }



};

int32_t main(){
    fastIO();
    
    Solution sol;

    cout<<sol.isPrimeTrial(13)<<nl; // 1
    cout<<sol.isPrimeTrial(23)<<nl; // 1
    cout<<sol.isPrimeTrial(561)<<nl; // 0
    cout<<nl;

    cout<<sol.isPrimeProbablyFermat(13)<<nl; // 1
    cout<<sol.isPrimeProbablyFermat(23, 5)<<nl; // 1
    cout<<sol.isPrimeProbablyFermat(561, 20)<<nl; // 0 // it can be 1 , as 561 is a Carmichael no.
    cout<<nl;

    cout<<sol.isPrimeMillerRabin(13)<<nl; // 1
    cout<<sol.isPrimeMillerRabin(23, 5)<<nl; // 1
    cout<<sol.isPrimeMillerRabin(561, 20)<<nl; // 0 
    cout<<nl;

    cout<<sol.isPrimeForLarge(13)<<nl; // 1
    cout<<sol.isPrimeForLarge(23)<<nl; // 1
    cout<<sol.isPrimeForLarge(561)<<nl; // 0 
    cout<<sol.isPrimeForLarge(3825123056546413051)<<nl; // 1  // -> but this no. is not prime (=149491*747451*3423321) // becoz by this method, we can check no. which is less than 3*10^18
    cout<<nl;

    
    return 0;
}
    
    