#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define wt(x) ll x; cin>>x; while( x-- )
#define MOD 1000000007 // for MOD
#define MAX 2000012

// Copied from a File
long long mod(long long x){
    return ( (x % MOD + MOD) % MOD ) ;
}
long long add(long long a, long long b){
    return mod(mod(a)+mod(b));
}
long long mul(long long a, long long b){
    return mod(mod(a)*mod(b));
}
ll modPow(ll a, ll b){
    if(b==0)
        return 1LL;
    ll res=1;
    while(b){
        if(b%2==1)
            res=mul(res,a);
        a=mul(a,a);
        b=b/2;
    }
    return res;
}
ll inv(ll x){
    return modPow(x,MOD-2);
}

ll divide(ll a, ll b){
    return mul(a,inv(b));
}

const int N=2e5+2;
int fact[N];

void precalc(){
    fact[0]=1;
    for(int i=1;i<N;i++)
        fact[i]=mul(fact[i-1],i);

}
ll nCr(ll n, ll r){
    return divide(fact[n],mul(fact[r],fact[n-r]));
}






// Solved by ME

// find power(a, n) under mod m
ll modPower( ll a, ll n, ll mod ) 
{
    ll res = 1LL;
    // a = a%mod; // works only if mod is prime 
    while( n ){
        if( n %2 ){
            res = (res*a) % mod ;
        }
        n /= 2;
        a = (a*a) % mod; 
    }
    return res;
}


// find Inverse Modular of a Under modulus 
// Using Fermet's Little Theorem //  m should prime
ll modInverse( ll a, ll m ) 
{
    if( __gcd(a, m) != 1 ){
        cout<<"Inverse doesn't exist"<<"\n";
        return INT_MAX;
    }
    return modPower( a, m-2, m );
}

// ll modInverse( ll a, ll m ){
//         if( m == 1 ) return 0;
//         ll m0 = m, y=0, x=1;

//         while(a>1){
//             ll q=a/m, t=m;
//             m = a%m, a=t;
//             t = y;
//             y = x - q*y;
//             x = t;
//         }
//         if( x<0 ) x += m0;

//         return x;
// }


// Returns n! % m , by Wilson's Theorem, m should be prime
// useful when m is close to input number n
// 28! % 29 = -1 , so
// 25! % 29 =( (-1)*(28!)*(1/26)(1/27)*(1/26) ) % 29 ;
ll modFact( ll n, ll m )
{
    if( n >= m )
        return 0;
    
    // Initialize result as (m-1)! which is -1 or (m-1) // Wilson's Theorem
    ll res = m-1; // res =-1;

    // Multiply modulo inverse of all numbers from (n+1) to p
    for( ll i=n+1; i<m; i++ )
        res = (res * modInverse(i,m) ) % m ;

    return res;
}

// Returns value of n! % m
ll modFact_simple(ll n, ll m)
{
    if (n >= m)
        return 0;
    ll result = 1LL;
    for (ll i = 1; i <= n; i++)
        result = (result * i) % m;

    return result;
}



int main(){
    
    cout<<modFact_simple(7, MOD )<<endl; // 5040
    
    cout<<modFact(25, 29 )<<endl; // 5

    cout<<modPower(5,3,MOD)<<endl; // 125

    cout<<modPower(5,3,9)<<endl; // 8

    precalc();
    cout<<nCr(5,2)<<endl; // 10

    cout<<add(5,4)<<endl; // 9
    cout<<mul(123654, 987 )<<endl; // 122046498
    cout<<divide(1234, 1000 )<<endl; // 538000005
    cout<<modPow(12,12)<<endl; // 100385844
    cout<<fact[7]<<" "<<fact[6]<<endl; // 5040 720
    cout<<inv(10)<<endl; // 700000005

    return 0;
}


// 5040
// 5
// 125
// 8
// 10
// 9
// 122046498
// 538000005
// 100385844
// 5040 720
// 700000005

