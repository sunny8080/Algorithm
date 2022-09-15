#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<algorithm>
using namespace std;
#define int long long
#define ll long long
#define wt(x) int x; cin>>x; while( x-- )
#define REP(i,n) for( int i=0; i<n; i++ )
#define REPc(i,a,b) for( int i=a; i<b; i++ )
#define MOD 1000000007
#define MAX 190090000
#define nl "\n"


#define N 20
int F[N][N], I[N][N] = {0} ;
int Sum = 0;

void mulMatrix( int A[][N], int B[][N], int n){
    int res[N+1][N+1];
    REP(i,n)
        REP(j,n){
            res[i][j]=0;
            REP(k,n)
                res[i][j] = ( res[i][j] + ( A[i][k]*B[k][j] )%MOD )%MOD;
        }
    REP(i,n) REP(j,n) A[i][j] = res[i][j] ;
}

int powMatrix( int pwr ){  // Matrix Exponentiation
    I[0][0] = 0, I[0][1] = I[1][0] = I[1][1] = 1;
    F[0][0] = 0, F[0][1] = F[1][0] = F[1][1] = 1;

    while(pwr){ // Binary Exponentiation
        if( pwr%2)
            mulMatrix(I, F, 2), pwr-- ;
        else 
            mulMatrix(F, F, 2), pwr/=2 ;

    }
    int Fn = I[1][0];
    return Fn;
}

/*
int powMatrix( int n ){
    F[0][0] = 0, F[0][1] = F[1][0] = F[1][1] = 1LL;
    I[0][0] = 0, I[0][1] = I[1][0] = I[1][1] = 1LL;
    while( n ){
        if( n%2 )
            mulMatrix(I, F, 2);
        mulMatrix(F, F, 2 );
        n /= 2;
    }
    ll fib = I[1][0];
    return fib;
}*/

int fib( int n ){
    if( n == 0 ) return 0;
    return powMatrix(n-1) ;
}

// To find sum of first N Fibonacci numbers
class Solution{
    vector<vector<int>> multiply( vector<vector<int>> &a, vector<vector<int>> &b ){
        int sz = a.size();
        vector<vector<int>> ans( sz, vector<int>(sz,0));
        for( int i=0; i<sz; i++ ){
            for( int j=0; j<sz; j++ ){
                for( int k=0; k<sz; k++ ){
                    ans[i][j] =( ans[i][j] + (a[i][k] *1LL* b[k][j] )%MOD ) %MOD ;
                }
            }
        }
        return ans;
    }

    vector<vector<int>> matrixExponentiate( vector<vector<int>> &a, int n ){
        if( n == 0 ){
            int sz =  a.size();
            vector<vector<int>> ans( sz, vector<int>(sz,0) );
            for( int i=0; i<sz; i++ ){
                ans[i][i]=1;
            }
            return ans;
        }
        if( n == 1 ){
            return a;
        }

        vector<vector<int>> temp = matrixExponentiate(a, n/2 );
        vector<vector<int>> ans = multiply( temp, temp );
        if( n&1 ){
            ans = multiply(ans,a);
        }
        return ans;
    }
    public:

    int fibSum(int n){
        vector<vector<int>> a(3, vector<int>(3, 0));
        a[0][0] = a[0][1] = a[0][2] = 1;
        a[1][1] = a[1][2] = 1;
        a[2][1] = 1;

        vector<vector<int>> ans = matrixExponentiate(a, n);
        cout<<nl;
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << nl;
        }
        int sum = ans[0][2];
        return sum;
    }

};


map<ll, ll> Fib;

// Codeforces hack
ll f( ll n ){
    if( Fib.count(n) ) return Fib[n];
    ll k = n/2;
    if( n%2 == 0 ){ // n = 2*k
        return Fib[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % MOD; 
    }else{ // n = 2*k + 1
        return Fib[n] = (f(k)*f(k+1) + f(k)*f(k-1)) % MOD;
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);  cin.tie(0); cout.tie(0);

    // // Find Fibonacci by Matrix Exponentiation
    int t; 
    t = 6;
    // cout<<fib(t)<<nl; // 8
    // cout<<fib(15)<<nl; // 610
    // cout<<fib(123565)<<nl; // 572375539
    // cout<<fib(123456789)<<nl; // 62791945
    // cout<<fib(2147483647)<<nl; // 822963728

    // int n;cin>>n;
    // cout<<fib(n)<<nl;


    // Find Sum of First N Fibonacci
    int n=7;  
    //cin>>n;
    Solution sol;
    int sum = sol.fibSum(n);
    cout<<"Sum of First "<<n<<" Fibonacci no. : "<<sum<<nl;
    cout<<nl<<nl;




    // Find Fibonacci by a Codeforces hack  // It is Bottom Up Approach
    // https://codeforces.com/blog/entry/14516
    Fib[0] = Fib[1] = 1;
    // cout<<(n==0 ? 0 : f(n-1))<<nl;
    n=0;
    cout<<(n==0 ? 0 : f(n-1))<<nl; // 0
    cout<<f(6-1)<<nl; // 8
    cout<<f(15-1)<<nl; // 610
    cout<<f(123565-1)<<nl; // 572375539
    cout<<f(123456789-1)<<nl; // 62791945
    cout<<f(2147483647-1)<<nl; // 822963728


    return 0;
}

// For Sum of first 7 Fibo no.
// 1 53 33 
// 0 21 13 
// 0 13 8 
// Sum of First 7 Fibonacci no. : 33

// 0
// 8
// 610
// 572375539
// 62791945
// 822963728



// Identity Matrix for Sum of Fibonacci no.
// | 1 1 1 |
// | 0 1 1 |
// | 0 1 0 | 

// Identity Matrix for F[n]
// | 0 1 |
// | 1 1 |
