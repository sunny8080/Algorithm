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
#define nl             char(10)
#define PRT(ar)          for( auto i : ar ) cout<<i<<sp; cout<<nl;
#define mems(x,ch)       memset(x,ch,sizeof(x))
#define sortv(x)         sort(x.begin(),x.end())
#define sortvr(x)        sort(x.rbegin(),x.rend())
#define all(x)           x.begin(), x.end()
#define MOD 1000000007
#define MAX 1000012

ll Fact[MAX];
ll invFact[MAX];


// find (a^b)%md 
ll modPower(ll a, ll b, ll md) {
    ll ans = 1LL;
    while (b) {
        if ((b & 1)) ans = (ans * a) % md;
        a = (a * a) % md;
        b >>= 1;
    }
    return ans;
}


ll nCr(int n, int r) {
    return((Fact[n] * invFact[n - r]) % MOD * invFact[r]) % MOD;
}


// YT - https://youtu.be/jIb1W3ObIho
// nCr % p by DP // p is prime
int nCrModPDp(int n, int r, int p) {
    if(n<r) return 0;
    if( (n-r) < r ) r = n-r;
    vi c(r + 1);
    c[0] = 1;

    // nCr = (n-1)Cr + (n-1)C(r-1)
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--) {
            c[j] = (c[j] + c[j - 1]) % p;
        }
    }
    return c[r];
}

// nCr % p // p is prime // Lucas theorem
int nCrModPLucas(int n, int r, int p) {
    if (r == 0) return 1;
    int ni = n % p;
    int ri = r % p;
    return (nCrModPLucas(n / p, r / p, p) * nCrModPDp(ni, ri, p));
}



// Fermat's little theorem
// WARNING :-
// in nCr % p  ->  n < p // to use modulo, n<p // also p should prime 
// if n>=p then nCr % p is 0 which can be wrong 
ll C(int n, int r) {
    return((Fact[n] * modPower(Fact[n - r], MOD - 2, MOD)) % MOD * modPower(Fact[r], MOD - 2, MOD)) % MOD;
}


ll inverse(ll n) {
    //ll inv =( (MOD-MOD/n)*inverse(MOD%n) )%MOD;
    if (n == 1) return 1;
    return ((MOD - MOD / n) * inverse(MOD % n)) % MOD;
}


// find mod inverse of n wrt md // md is prime
ll inverseEuler(ll n, ll md) {
    return modPower(n, md - 2, md);
}

// find mod inverse of n wrt md // md is not-prime
ll inverseBrute(ll a, ll md) {
    ll x = 1;
    while (1) {
        if ((a * x) % md == 1) return x;
        x++;
    }
    return x;
}

// find (nCr % md) // md should be prime
ll nCrPrimeMod(ll n, ll r, ll md) {
    if (n < r) return 0;
    if (r == 0) return 1;

    ll fact[n + 1];
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % md;
    }

    // nCr % md = (n! * modInv(r!, md) * modInv((n-r)!, md) ) %md
    ll ans = ((fact[n] * inverseEuler(fact[r], md)) % md * inverseEuler(fact[n - r], md)) % md;
    return ans;
}


// find (nCr % 1681) // md should be 1681 = 41*41 // md is not prime
ll nCrMod1681(ll n, ll r) {
    int fact[n + 1][2];
    fact[0][0] = 1;
    fact[0][1] = 0;

    for (int i = 1; i <= n; i++) {
        int t = i;

        // Remove all multiple of 41 and store it in fact[i][1]
        fact[i][1] = fact[i - 1][1];
        while (t % 41 == 0) {
            t /= 41;
            fact[i][1]++;
        }

        fact[i][0] = (fact[i - 1][0] * t) % 1681;
    }

    // nCr % md = (n! * modInv(r!, md) * modInv((n-r)!, md) ) %md
    int ans = fact[n][0];
    ans = (ans * inverseBrute(fact[r][0], 1681)) % 1681;
    ans = (ans * inverseBrute(fact[n - r][0], 1681)) % 1681;

    // Add requirred powers of 41 // p41(n) - p41(r) - p41(n-r) // p41(x) = power of 41 in x
    int p41Require = fact[n][1] - fact[r][1] - fact[n - r][1];
    ans = (ans * modPower(41, p41Require, 1681)) % 1681;
    return ans;
}




int main() {

    // Pre calculation
    Fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        Fact[i] = (Fact[i - 1] * i) % MOD;

    invFact[0] = invFact[1] = 1;
    for (int i = 2; i < MAX; i++)
        invFact[i] = ((MOD - MOD / i) * invFact[MOD % i]) % MOD;
    for (int i = 1; i < MAX; i++)
        invFact[i] = (invFact[i - 1] * invFact[i]) % MOD;



    // Driver

    cout << nCr(5, 2) << nl; // 10
    cout << nCrModPDp(5, 2, mod) << nl; // 10
    cout << nCrModPLucas(5, 2, mod) << nl; // 10
    cout << C(5, 2) << nl; // 10
    cout << nCrPrimeMod(5, 2, mod) << nl; // 10
    cout << nl;


    cout << nCr(100, 15) << nl; // 576619357
    cout << nCrModPDp(100, 15, mod) << nl; // 576619357
    cout << nCrModPLucas(100, 15, mod) << nl; // 576619357
    cout << C(100, 15) << nl; // 576619357
    cout << nCrPrimeMod(100, 15, mod) << nl; // 576619357
    cout << nl;


    cout << nCr(98747, 12345) << nl; // 856569438
    // // cout << nCrModPDp(98747, 12345, mod) << nl; // TLE
    // // cout << nCrModPLucas(98747, 12345, mod) << nl; // TLE
    cout << C(98747, 12345) << nl; // 856569438
    cout << nCrPrimeMod(98747, 12345, mod) << nl; // 856569438
    cout << nl;


    cout << modPower(6543, 912, MOD) << nl; // 350514071
    cout << Fact[6] << nl; // 720
    cout << invFact[6] << nl; // 301388891
    cout << nl;



    // if MOD = 5;
    // cout<<nCr(6,1)<<nl; // 0 -> wrong
    // cout<<C(6,1)<<nl; // 0 -> wrong
    // cout<<nl;


    // nCr %1681 // 1681 = 41*41 // not prime
    cout << nCrMod1681(98747, 12345) << nl; // 1589


    return 0;
}




// 10
// 10
// 576619357
// 576619357
// 491077626
// 491077626
//
// 350514071
// 720
// 301388891