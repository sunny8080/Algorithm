#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
#define int              long long
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
#define vpii             vector<pair<int,int>>
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

const ll N = 1e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}


// QUE :- https://codeforces.com/problemset/problem/682/D
// Soln :- https://youtu.be/Uz0WD9yRzFE

string s, t;
int n, m, k;
int dp[1005][1005][12][2];

class Solution {

public:
    int solve(int is, int it, int rem, int cont) { // indxS, indxT, remaining string, continuity 

        // p1 p2 p3 p4 p5
        // if p3 has a length of 5
        // p3 = abcde
        // then if we are on b in p3 the rem stays out to be 3
        // jump from e in p3 makes rem to 2
        

        if (is == n or it == m) return ((rem == 0) ? 0 : INT_MIN);
        if (rem == 0) return 0;
        if (dp[is][it][rem][cont] != -1) return dp[is][it][rem][cont];

        int ans = INT_MIN;
        int op1, op2, op3, op4;
        op1 = op2 = op3 = op4 = INT_MIN;

        // if (cont == 1) {
        //     op1 = solve(is + 1, it, rem - 1, 0);
        //     op2 = solve(is, it + 1, rem - 1, 0);
        //     if (s[is] == t[it]) {
        //         op3 = 1 + solve(is + 1, it + 1, rem, 1);
        //         op4 = 1 + solve(is + 1, it + 1, rem - 1, 0);
        //     }
        // } else { // cont==0
        //     op1 = solve(is + 1, it, rem, 0);
        //     op2 = solve(is, it + 1, rem, 0);
        //     if (s[is] == t[it]) {
        //         op3 = 1 + solve(is + 1, it + 1, rem, 1);
        //         op4 = 1 + solve(is + 1, it + 1, rem - 1, 0);
        //     }
        // }

        op1 = solve(is + 1, it, rem - cont, 0);
        op2 = solve(is, it + 1, rem - cont, 0);
        if (s[is] == t[it]) {
            op3 = 1 + solve(is + 1, it + 1, rem, 1);
            op4 = 1 + solve(is + 1, it + 1, rem - 1, 0);
        }

        ans = max({ans, op1, op2, op3, op4});
        return dp[is][it][rem][cont] = ans;
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    mems(dp, -1);
    cin >> n >> m >> k;
    cin >> s >> t;
    cout<<sol.solve(0, 0, k,0)<<nl;


    return 0;
}

