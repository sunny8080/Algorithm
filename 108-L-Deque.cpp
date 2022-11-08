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

// QUE :- https://atcoder.jp/contests/dp/tasks/dp_l


int n;
int dp[3005][3005][2];
int dp2[3005][3005];
int arr[3005];

class Solution {

public:
    int solve1(int i, int j, int turn) {
        // dp[i][j][1] = maximum score can be done by 1st player in a subarray[i...j]
        // turn = 1 // 1st player is player
        // turn = 0 // 2nd player is player
        
        if (i > j) return 0;
        if (dp[i][j][turn] != -1) return dp[i][j][turn];

        int ans = 0;
        if (turn == 1) ans = max(arr[i] + solve1(i + 1, j, 0), arr[j] + solve1(i, j - 1, 0));
        else ans = min(solve1(i + 1, j, 1), solve1(i, j - 1, 1));

        return dp[i][j][turn] = ans;
    }


    int solve2(int i, int j, int turn) {
        // dp[i][j] = maximum score can be done by 1st player in a subarray[i...j]
        // turn = 1 // 1st player is player
        // turn = 0 // 2nd player is player

        if (i > j) return 0;
        if (dp2[i][j] != -1) return dp2[i][j];

        int ans = 0;
        if (turn == 1) ans = max(arr[i] + solve2(i + 1, j, 0), arr[j] + solve2(i, j - 1, 0));
        else ans = min(solve2(i + 1, j, 1), solve2(i, j - 1, 1));

        return dp2[i][j] = ans;
    }




    int solve3(int i, int j) {
        // dp[i][j] = maximum score can be done by 1st player in a subarray[i...j]
        // turn = 1 // 1st player is player
        // turn = 0 // 2nd player is player

        if (i > j) return 0;
        if (dp2[i][j] != -1) return dp2[i][j];

        int itemTaken = n - (j-i+1);
        int turn = (itemTaken&1)? 0: 1;

        int ans = 0;
        if (turn == 1) ans = max(arr[i] + solve3(i + 1, j), arr[j] + solve3(i, j - 1));
        else ans = min(solve3(i + 1, j), solve3(i, j - 1));

        return dp2[i][j] = ans;
    }

};



int32_t main() {
    fastIO();
    Solution sol;
    mems(dp, -1);
    mems(dp2, -1);

    cin >> n;
    int sum = 0;
    fr(i, 0, n - 1) {
        cin >> arr[i];
        sum += arr[i];
    }
    // int xScore = sol.solve1(0, n - 1, 1);
    // int xScore = sol.solve2(0, n - 1, 1);
    int xScore = sol.solve3(0, n - 1);
    int yScore = sum - xScore;
    cout << xScore - yScore << nl;


    return 0;
}

