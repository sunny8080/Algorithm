#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

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
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    #endif
}

class Solution {
    
    public:

    // Find square root of n, with precison of p decimal points
    float squareRoot( int n, int p){    
        // make a Monotonic Search-space as [l ... r]
        int l=0;
        int r = n;
        float ans = -1;

        while( l<=r ){
            int mid = (l+r)>>1;

            if( mid * mid == n ) return mid;
            else if( mid * mid < n ){
                ans = mid;
                l = mid +1;
            }else{
                r = mid -1;
            }
        }

        // for Floating point precision use brute force
        float inc = 0.1;
        for( int times=1; times<=p; times++){
            while( ans * ans <= n){
                ans = ans + inc;
            }
            // overshot the value
            ans = ans - inc;
            inc = inc / 10;
        }
        return ans;
    }
};

int32_t main(){
    fastIO();
    Solution sol;

    cout<<sol.squareRoot(10, 3)<<nl; // 3.162
    cout<<sol.squareRoot(16, 3)<<nl; // 4
    cout<<sol.squareRoot(15, 4)<<nl; // 3.8729
    
    
    return 0;
}
    
    