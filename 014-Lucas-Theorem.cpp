#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#define wt(x) int x; cin>>x; while( x-- )
#define REP(i,n) for( int i=0; i<n; i++ )
#define REPc(i,a,b) for( int i=a; i<b; i++ )
#define REPi(i,n) for( int i=n-1; i>=0; i-- )
#define REPci(i,a,b) for( int i=a; i>=b; i-- )
#define sp ' '
#define nl char(10)
#define endl char(10)
#define MOD 1000000007
#define vi vector<int>
#define vvi vector< vector<int> >
#define vll vector<long long> 
#define vvll vector< vector<long long> >
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

// Returns nCr % p.  In this Lucas Theorem based program,
// this function is only called for n < p and r < p.
int nCrModpDP( int n, int r, int p ){
    int C[r+1];
    memset( C, 0, sizeof(C) );
    C[0]=1; // 0C0 = 1
    for( int i=1; i<=n; i++ ){
        for( int j=min(i,r); j>0; j-- ){
            C[j] =( C[j]+C[j-1] ) % p ; // nCr = (n-1)C(r) + (n-1)C(r-1)
        }
    }
    // for( auto x : C )
    //     cout<<x<<" ";
    // cout<<nl;
    return C[r];
}

// Lucas Theorem based function that returns nCr % p
int nCrModpLucas( int n, int r, int p ){
    if( r == 0 ) return 1;
    int ni = n%p;
    int ri = r%p;

    // Compute result for last digits computed above, and
    // for remaining digits.  Multiply the two results and
    // compute the result of multiplication in modulo p
    return ( nCrModpLucas(n/p, r/p, p) * nCrModpDP(ni, ri, p) )% p ; //( Last digits of n and r) * ( Remaining digits )
}

int32_t main(){
    
    int n=1000, r=900, p=13;
    cout<<"nCr % p = "<<nCrModpLucas(n, r, p )<<nl; // 8
    
    n=5, r=2, p=2;
    cout<<"nCr % p = "<<nCrModpLucas(n, r, p )<<nl; // 0

    n=5, r=1, p=2;
    cout<<"nCr % p = "<<nCrModpLucas(n, r, p )<<nl; // 1

    return 0; 
}