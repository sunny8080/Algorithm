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
#define fr(t,a,b)        for( int t=(a); t<=(b); t++)

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


// QUE :- https://atcoder.jp/contests/dp/tasks/dp_k

int arr[105];
int grundy[N];
int n, k;

class Solution {
    int mex(unordered_set<int>& st) {
        int m = 0;
        while (st.find(m) != st.end()) m++;
        return m;
    }


    int calGrundy(int x) {
        if (x == 0) return 0;
        if (grundy[x] != -1) return grundy[x];
        unordered_set<int> st;

        fr(i, 0, n - 1) {
            if (x >= arr[i]) st.insert(calGrundy(x - arr[i]));
        }

        return grundy[x] = mex(st);
    }
public:

    // Using Sprague Grundy Theorem
    string solve1() {
        string ans;
        int XOR = 0;
        XOR = calGrundy(k);
        if (XOR != 0) ans = "First";
        else ans = "Second";
        return ans;
    }


    string solve2() {
        // dp[i] = 1 or 0 // 1 means winning position for first player // 0 means lossing position for 1st player 
        int dp[k + 1];
        mems(dp, 0);
        dp[0] = 0;
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= arr[j] && dp[i - arr[j]] == 0) {
                    dp[i] = 1;
                }
            }
        }
        return dp[k] == 1 ? "First" : "Second";
    }
};





int32_t main() {
    fastIO();
    Solution sol;

    mems(arr, -1);
    mems(grundy, -1);

    cin >> n >> k;
    fr(i, 0, n - 1) cin >> arr[i];
    // cout<<sol.solve1()<<nl;
    cout << sol.solve2() << nl;



    return 0;
}

