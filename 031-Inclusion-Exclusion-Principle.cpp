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


class Solution1 {
    public:
    ll findNoOfNumDivBy3or4(ll N ){
        ll count1 = N/3;
        ll count2 = N/4;
        ll count3 = N/(3*4);
        return (count1 + count2 - count3 );
    }
    
};


class Solution2 {
    public:
    // Find number of Numbers which are divisible by any prime no. given in array prime and also less than N
    // 1<=N<=10^18
    ll findNoOfNum( ll N, vll & prime ){
        ll noOfSubSets = (1<<prime.size()) - 1; 

        ll ans=0;
        for( ll i=1; i<=noOfSubSets; i++ ){
            ll denom = 1ll;
            ll setBits = setbits(i);

            for( ll j=0; j<prime.size(); j++ ){
                if( (i&(1<<j)) ){
                    denom *= prime[j];
                }
            }   
            if( (setBits & 1) ){
                ans += N/denom;
            }else{
                ans -= N/denom;
            }
        }
        return ans;
    }
};



int32_t main(){
    fastIO();

    // Find number of Numbers which are divisible by 3 or 4 and less than and equal to N
    cout<<(new Solution1())->findNoOfNumDivBy3or4(1000)<<nl; // 500
    cout<<(new Solution1())->findNoOfNumDivBy3or4(1500)<<nl; // 750
    cout<<nl<<nl;


    // Find number of Numbers which are divisible by any prime no. given in array prime and also less than N
    // 1<=N<=10^18
    vll prime({2, 3, 5, 7, 11, 13, 17, 19} );
    // PRT(prime); // 2 3 5 7 11 13 17 19
    cout<<(new Solution2())->findNoOfNum(100, prime)<<nl; // 82
    cout<<(new Solution2())->findNoOfNum(1000, prime)<<nl; // 830
    cout<<(new Solution2())->findNoOfNum(123456, prime)<<nl; // 102344
    
    return 0;
}