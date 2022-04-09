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

void fastIO(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    #endif
}

const int MAX=1000;
ull triangle[MAX+1][MAX+1];

class Solution {
    bool trFormed = false;

    void makeTriangle(){
        triangle[0][0] = 1;
        for( int i=1; i<MAX; i++ ){
            triangle[i][0] = 1;

            for( int j=1; j<=i; j++ ){
                triangle[i][j] = triangle[i-1][j-1]  + triangle[i-1][j];
            }
        }
    }

    ull fact( int n ){
        if( n == 0 ) return 1;
        return (n*fact(n-1));

        // if( n == 0 ) return 1;
        // ull ans=1;
        // for( int i=1; i<=n; i++ ){
        //     ans *= i;
        // }
        // return ans;
    }

    public:
    ull nCr(int n, int r){

        // #METHOD 1 
        if( r > n-r ) r = n-r; // nCr = nC(n-r)
        ull ans = 1;
        for( int i=1; i<=r; i++ ){
            ans *= (n-r+i);
            ans /= i;
        }
        return ans;


        // #METHOD 2 // Best For n < 1000  
        // if( ! trFormed ) { 
        //     makeTriangle(); trFormed = true; 
        // }
        // return triangle[n][r];



        // #METHOD 3
        // ull row[MAX+1];
        // mem(row, 0);
        // row[0] = 1; // C(0, 0)
        // for( int i=1; i<=n; i++ ){
        //     for( int j=i; j>0; j-- ){
                // // C(n, r) = C(n-1, r-1) + C(n-1, r) 
        //         row[j] += row[j-1];
        //     }
        // }
        // return row[r];




        // #METHOD 4 // Recursive Approach
        // if( n == r ) return 1;
        // if( r == 1 ) return n;
        // return ( nCr(n-1, r ) + nCr(n-1, r-1 )) ;




        // #METHOD  // nCr = n!/(r!*(n-r)!)  // Best for n<20
        // ull ans = fact(n) / ( fact(r) * fact(n-r) );
        // return ans;

    }

};

// TODO

int32_t main(){
    fastIO();
    
    cout<<(new Solution())->nCr(5, 0)<<nl;
    cout<<(new Solution())->nCr(5, 1)<<nl;
    cout<<(new Solution())->nCr(10, 3)<<nl;
    cout<<(new Solution())->nCr(1234567, 2)<<nl;


    return 0;
}
    
    
    