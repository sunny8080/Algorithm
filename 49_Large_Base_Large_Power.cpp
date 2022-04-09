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

// QUE:- https://www.youtube.com/watch?v=K_UOxtlAIms
// Fermet's Little theorem is used // Also some modulo concept require
// ANS :- (A^B)%p = ( (A%p)^(B%(p-1)) )%p
class Solution {
    
    public:
    ll findMod( string s, ll m ){
        ll ans=0;
        for( int i=0; i<s.size(); i++ ){
            ans = ( (ans*10)%m + (s[i]-'0') )%m;
        }
        return ans;
    }

    ll modPower( ll a, ll b, ll m ){
        ll ans=1;
        while( b ){
            if( (b&1) ) ans = (ans*a)%m;
            a = (a*a)%m;
            b >>=1;
        }
        return ans;
    }


    // Find A^B, when   1<=A,B<= 10^(10^5)
    // ANS :- (A^B)%p = ( (A%p)^(B%(p-1)) )%p
    // O(s1 + s2 + log(b)) // s1=length of a, s2=length of b
    ll findLargeBasePower( string a, string b, ll p){
        ll num1 = findMod(a, p);
        ll num2 = findMod(b, p-1);

        ll ans = modPower(num1, num2, p);
        return ans;
    }
};

int32_t main(){
    fastIO();
    
    // string a, b; cin>>a>>b;

    Solution sol;

    cout<<sol.findLargeBasePower("3", "2", mod)<<nl; // 9
    cout<<sol.findLargeBasePower("4", "5", mod)<<nl; // 1024
    cout<<sol.findLargeBasePower("7", "4", mod)<<nl; // 2401
    cout << sol.findLargeBasePower("123456789123456789123", "12345678912345678912378", mod) << nl; // 250591750

    
    
    return 0;
}
    
    