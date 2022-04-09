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
    // #METHOD - 1
    int gcd( int a, int b ){
        int i;
        for( i=min(a,b); i>=1; i-- ){
            if( a%i == 0 && b%i == 0 ) break;
        }
        return i;
    }

    // METHOD - 2
    int euclidGcd( int a, int b ){
        return b==0 ? a : gcd(b, a%b);
    }

    int lcm( int a, int b ){
        int g = gcd(a,b);
        int lcm = (a*b)/g;
        return lcm;
    }

    void extendedEuclidMethod( int a, int b, int &x, int &y, int &GCD ){
        // Base case
        if( b == 0 ){   
            x = 1, y=0, GCD=a;
            return;
        }

        // Recursive case
        extendedEuclidMethod(b, a%b, x, y, GCD);
        int cX = y; // cX = current_X
        int cY = x - (a/b)*y;

        // cout<<cX<<sp<<cY<<nl;

        x = cX, y=cY; 
    }

    int inverseModulo( int a, int m ){
        // Check Inverse exists or not 
        if( euclidGcd(a, m) != 1 ){
            cout<<"Modulo Inverse not exist"<<nl;
            return INT_MAX;
        }

        int x, y, gcd;
        extendedEuclidMethod(a, m, x, y, gcd);
        return (x%m + m )%m;
    }


    // inverse Mod using Euclid's extended theorem by iterative
    int invModByIterarive( int a, int m ){
        int x=1, y=0, m0 = m;

        if( m == 1 ) return 0;
        
        while( a != 1 ){
            int q = a/m;

            // // RHS = gcd(a, m)  =  gcd(m, a%m)
            // int aNex = m;
            // m = a%m,  a=aNex;
            tie(a, m) = make_pair(m, a%m);

            // // Update x and y
            // int t = x;
            // x = y;
            // y = t - q*y;
            tie(x, y) = make_pair(y, x-q*y );
        }

        // always take +ve values
        x = (x%m0 + m0)%m0;

        return x;
    }

    int findMod( string num, int m ){
        int res=0;
        for( int i=0; i<num.size(); i++ ){
            res = ( (res*10)%m + (num[i]-'0')%m ) %m; // res = (res*10 + (num[i] - '0') )%m;
        }
        return res;
    }

};



int32_t main(){
    fastIO();
    
    Solution sol;

    // Find GCD
    cout<<sol.gcd(20, 12)<<nl; // 4
    cout<<sol.euclidGcd(20, 12)<<nl; // 4
    cout<<sol.lcm(20, 12)<<nl; // 60

    cout<<sol.euclidGcd(18, 30)<<nl; // 6
    cout<<sol.euclidGcd(30, 18)<<nl; // 6
    cout<<nl;


    // Solve equation by Extended Euclid Theorem
    int a=18, b=30, x, y, GCD;
    sol.extendedEuclidMethod( a, b, x, y, GCD);
    cout<<x<<sp<<y<<sp<<GCD<<nl; // 2 -1 6
    
    a = 28, b = 14;
    sol.extendedEuclidMethod( a, b, x, y, GCD);
    cout<<x<<sp<<y<<sp<<GCD<<nl; // 0 1 14


    cout<<nl;

    


    // Find Inverse Modulo
    int t = sol.inverseModulo(20, 12); // Modulo Inverse not exist
    if( t != INT_MAX ){
        cout<<x<<nl;
    }
    cout<<sol.inverseModulo(6, 7)<<nl; // 6
    cout<<sol.inverseModulo(8, 7)<<nl; // 1
    cout<<sol.inverseModulo(3, 11)<<nl; // 4
    cout<<nl;

    cout<<sol.invModByIterarive(6, 7)<<nl; // 6
    cout<<sol.invModByIterarive(8, 7)<<nl; // 1
    cout<<sol.invModByIterarive(3, 11)<<nl; // 4
    cout<<nl;

    cout<<sol.findMod("625", 5)<<nl; // 0
    cout<<sol.findMod("157", 10)<<nl; // 7
    cout<<sol.findMod("12316767678678", 10)<<nl; // 8



    return 0;
}
    
    