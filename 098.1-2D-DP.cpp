#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
// #define int              long long
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



class Solution {
public:
    void solve(int n) {
        vvi dp(n, vector<int>(n, 0));

        // Traverse the top-left to down-right diagonal 
        // for lower half diagonal
        int x = n - 1;
        int k = 1;
        while (x >= 0) {
            int i = x--;
            int j = 0;

            while (i < n && j < n) {
                dp[i++][j++] = k++;
            }
        }

        // for uppper half diagonal 
        int y = 1;
        while (y < n) {
            int i = 0;
            int j = y++;
            while (i < n && j < n) {
                dp[i++][j++] = k++;
            }
        }

        // print the array how array is traversed
        for (auto x : dp) {
            PRT(x);
        }
    }
};








// 2D - DP
// QUE :- https://www.codechef.com/MALI2017/problems-old/MAXCOST

class Solution2 {
public:
    // Top Down approach
    int maxProfit1(int i, int j, vi& wines, int age, vvi& dp) {
        if (i > j) return 0;
        if (dp[i][j] != 0) return dp[i][j];
        int pro1 = wines[i] * age + maxProfit1(i + 1, j, wines, age + 1, dp);
        int pro2 = wines[j] * age + maxProfit1(i, j - 1, wines, age + 1, dp);
        return dp[i][j] = max(pro1, pro2);
    }


    // Bottom Up approach
    int maxProfit2(vi& wines) {
        int n = wines.size();
        vvi dp(n, vector<int>(n, 0));

        // see the solution1 dp to see how the array is traverse
        // traverse the lower half (i>j) // so dp[i][j] = 0;
        int x = n - 1;
        while (x > 0) {
            int i = x--;
            int j = 0;

            while (i < n && j < n) {
                dp[i++][j++] = 0;
            }
        }

        // traverse the diagonal // sell each wine at the end
        int age = n;
        for (int i = 0; i < n; i++) dp[i][i] = wines[i] * age;
        age--;

        // Traverse the upper half (i<j) 
        int y = 1;
        while (y < n) {
            int i = 0;
            int j = y++;
            while (i < n && j < n) {
                int op1 = wines[i] * age + dp[i + 1][j];
                int op2 = wines[j] * age + dp[i][j - 1];
                dp[i][j] = max(op1, op2);
                i++, j++;
            }
            age--;
        }

        // for (auto x : dp) {
        //     PRT(x);
        // }

        return dp[0][n - 1];
    }

};







int32_t main() {
    fastIO();

    {
        Solution sol;
        int n = 4;
        sol.solve(n);
    }
    cout<<nl<<nl;


    {
        Solution2 sol2;

        int n; cin >> n;
        vi wines(n);
        for (auto& x : wines) cin >> x;

        vvi dp(n, vector<int>(n, 0));
        int age = 1;
        cout << sol2.maxProfit1(0, n - 1, wines, age, dp)<<nl;
        cout << sol2.maxProfit2(wines)<<nl;
    }


    return 0;
}


// OUT :-
// 5
// 1 3 1 5 2


// 7 11 14 16
// 4 8 12 15
// 2 5 9 13
// 1 3 6 10
//
//
// 43
// 43