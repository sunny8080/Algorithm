#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
#define wt(x) int x; cin>>x; while( x-- )
#define REP(i,n) for( int i=0; i<n; i++ )
#define nl "\n"
#define N 51
#define MOD 1000000007
int A[N][N], I[N][N];

void mulMatrix( int A[][N], int B[][N], int dim ){
    int res[N+1][N+1];
    REP( i, dim )
        REP(j, dim ){
            res[i][j]=0;
            REP(k,dim)
                res[i][j] =( res[i][j] + ( A[i][k]*1LL*B[k][j])%MOD ) % MOD ;
        }
    
    REP(i,dim)  REP(j,dim) A[i][j] = res[i][j];
}

void powMatrix( int A[][N], int dim, int n ){
    REP( i, dim ) 
        REP(j, dim ) 
            if(i==j) I[i][j]=1LL; 
            else    I[i][j]=0;
    
    // O(M^3 * N )
    // REP(i,n)
    //     mulMatrix(I,A,dim);


    // O(M^3 * logN )
    while(n){ // Binary Exponentiation
        if( n%2)
            mulMatrix(I, A, dim), n-- ;
        else 
            mulMatrix(A, A, dim), n/=2 ;
    }

    // while(n){
    //     if( n%2)
    //         mulMatrix(I, A, dim) ;
    //
    //     mulMatrix(A, A, dim);
    //     n/=2 ;
    // }


    REP(i,dim) REP(j,dim) A[i][j] = I[i][j];
}

void printMatrix( int a[][N], int dim ){
    REP(i,dim)  {
        REP(j,dim)
            cout<<a[i][j]<<" ";
        cout<<nl;
    }
}
int32_t main(){
    wt(t){
        int dim, pwr; cin>>dim>>pwr;
        REP(i,dim) REP(j,dim) cin>>A[i][j];
        powMatrix(A, dim, pwr );
        printMatrix(A, dim);
        cout<<nl;
    }
    
    return 0;
}


// 2
//
// 2 3
// 1 0 
// 1 1 
//
// 3 3
// 1 0 4 
// 1 2 2 
// 0 4 4 
//
//
//
// 1 0 
// 3 1 
//
// 17 112 116 
// 15 88 100 
// 28 144 160
