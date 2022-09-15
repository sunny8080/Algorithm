#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll               long long
#define ff               first
#define ss               second
#define pb               push_back
#define mp               make_pair
#define pii              pair<int,int>
#define vi               vector<int>
#define vll              vector<long long> 
#define vvi              vector< vector<int>>
#define vvll             vector< vector<long long>>
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
#define PRT(ar)          for( auto i : ar )cout<<i<<sp;cout<<nl;
#define mem(x,ch)        memset(x,ch,sizeof(x))
#define sortv(x)         sort(x.begin(),x.end())
#define sortvr(x)        sort(x.rbegin(),x.rend())

const ll cnst = 1e6 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    #endif
}

void multiply( int *a, int &n, int no ){
    int carry=0;
    for( int i=0; i<n; i++ ){
        int product = a[i] * no + carry;
        a[i] = product%10;
        carry = product/10;
    }
    while( carry ){
        a[n] = carry%10;
        carry = carry/10;
        n++;
    }
}

void bigFactorial( int number ){
    int *a =new int[1000];
    mem(a, 0);

    a[0]=1;
    int n=1;
    for( int i=2; i<=number; i++ ){
        multiply( a, n, i );
    }

    for( int i=n-1; i>=0; i-- ){
        cout<<a[i];
    }
    cout<<nl<<nl;
    delete []a;
}


int32_t main(){
    fastIO();
    
    int number; cin>>number;

    // Find Big Factorial
    bigFactorial(7); // 5040
    bigFactorial(12); // 479001600
    bigFactorial(100); // 93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
    
    return 0;
}
    
    