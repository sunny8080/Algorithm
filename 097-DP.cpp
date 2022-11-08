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

const ll N = 1e3 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}



// Dynamic Programming




// Find fibonacci numbers, with various approach
class Solution {
public:
    // Normal fib function
    // Time - O(2^N)   // Space - O(N)
    int fib(int n) {
        if (n == 0 || n == 1) return n; // base case
        int ans = fib(n - 1) + fib(n - 2); // recursion
        return ans;
    }


    // find fib with Top Down approach
    // Time - O(N)   // Space - O(N)
    int fibTD(int n, int* dp) {
        if (n == 0 || n == 1) return n;

        // look up
        if (dp[n] != 0) return dp[n];

        int ans = fibTD(n - 1, dp) + fibTD(n - 2, dp);
        return (dp[n] = ans);
    }



    // find fib with Bottom Up approach
    // Time - O(N)   // Space - O(N)
    int fibBU(int n) {
        int dp[N] = { 0 };
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i < N;i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }



    // find fib with Bottom Up approach with space optimized
    // Time - O(N)   // Space - O(1)
    int fibBUspaceOpti(int n) {
        if (n == 0 || n == 1) return n;
        int a = 0;
        int b = 1;
        int c = 0;

        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};







// Min Steps
// QUE :- https://practice.geeksforgeeks.org/problems/minimum-steps-to-minimize-n-as-per-given-condition0618/1
class Solution2 {
public:
    int dp[10005] = {};

    // Top Down approach
    int minSteps1(int n)
    {
        // Your code goes here
        if (n == 0) return 0;
        if (n == 1) return 0;
        if (dp[n] != 0) return dp[n];

        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;

        if (n % 2 == 0) op1 = minSteps1(n / 2);
        if (n % 3 == 0) op2 = minSteps1(n / 3);
        op3 = minSteps1(n - 1);

        return dp[n] = min({ op1, op2, op3 }) + 1;
    }


    // Bottom Up approach
    int minSteps2(int n)
    {
        // Your code goes here
        int dp[n + 1] = { 0 };
        dp[0] = dp[1] = 0;

        int op1, op2, op3;
        for (int i = 2; i <= n; i++) {
            op1 = op2 = op3 = INT_MAX;
            if (i % 2 == 0) op1 = dp[i / 2];
            if (i % 3 == 0) op2 = dp[i / 3];
            op3 = dp[i - 1];
            dp[i] = min({ op1, op2, op3 }) + 1;
        }
        return dp[n];
    }
};









// coins Change
// QUE :- https://leetcode.com/problems/coin-change/
class Solution3 {
    int dp[10005] = { 0 };
    int solveTD(vector<int>& coins, int amt) {
        if (amt == 0) return 0;
        if (dp[amt] != 0) return dp[amt];

        int n = coins.size();
        int ans = INT_MAX;

        for (int i = 0;i < n; i++) {
            if (amt - coins[i] >= 0) {
                int subProb = solveTD(coins, amt - coins[i]);
                if (subProb != INT_MAX) ans = min(ans, subProb + 1);
            }
        }
        return dp[amt] = ans;
    }
public:
    int coinChange(vector<int>& coins, int amt) {
        // top down approach // O(N*A) // A-amt
        // memset(dp, 0, sizeof(dp));
        // int ans = solveTD(coins, amt);
        // return ans == INT_MAX ? -1 : ans;


        // Bottom Up approach
        int dp[100005] = { 0 };
        for (int n = 1; n <= amt; n++) {
            dp[n] = INT_MAX;

            for (int i = 0; i < coins.size(); i++) {
                if (amt - coins[i] >= 0) {
                    int subProb = dp[n - coins[i]];
                    if (subProb != INT_MAX) dp[n] = min(dp[n], subProb + 1);
                }
            }
        }
        return (dp[amt] == INT_MAX) ? -1 : dp[amt];
    }

};









// climing stairs
// QUE :- https://leetcode.com/problems/climbing-stairs/
#define vi vector<int>
class Solution4 {
    int dp[1005] = { 0 };
public:
    // Top Down // O(N*K)
    int minSteps1(int n, int k = 2) {
        if (n == 0) return 1;
        if (dp[n] != 0) return dp[n];
        int ways = 0;

        for (int i = 1; i <= k; i++) {
            if (n - i >= 0) {
                ways += minSteps1(n - i, k);
            }
        }
        return dp[n] = ways;
    }


    // Bottom up // O(N*K)
    int minSteps2(int n, int k = 2) {
        vi dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n;i++) {
            dp[i] = 0;
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    dp[i] += dp[i - j];
                }
            }
        }
        return dp[n];
    }



    // Bottom up + Sliding window// O(N+K) // BEST
    int minSteps3(int n, int k = 2) {
        vi dp(n + 2, 0);

        dp[0] = dp[1] = 1;
        for (int i = 2;i <= k; i++) {
            dp[i] = 2 * 1LL * dp[i - 1];
        }

        for (int i = k + 1; i <= n; i++) {
            dp[i] = 2 * 1LL * dp[i - 1] - dp[i - k - 1];
        }
        return dp[n];
    }
};









// Rod cutting
// QUE :- https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
// Soln : https://youtu.be/zYZasir27Tg
class Solution6 {
    int dp[1005] = { 0 };
public:
    // Top down
    int cutRod1(int price[], int n) {
        //code here
        if (n <= 0) return 0;
        if (dp[n] != 0) return dp[n];

        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            int cut = i + 1;
            int currProfit = price[i] + cutRod(price, n - cut);
            ans = max(ans, currProfit);
        }
        return dp[n] = ans;
    }

    // Bottom up
    int cutRod(int price[], int n) {
        //code here
        int dp[n + 1] = { 0 };
        dp[0] = 0;

        for (int len = 1; len <= n; len++) {
            int ans = INT_MIN;
            for (int i = 0; i < len; i++) {
                int cut = i + 1;
                int currProfit = price[i] + dp[len - cut];
                ans = max(ans, currProfit);
            }
            dp[len] = ans;
        }

        return dp[n];
    }
};










int32_t main() {
    fastIO();
    Solution sol;

    {
        cout << sol.fib(2) << nl; // 1
        cout << sol.fib(5) << nl; // 5
        cout << sol.fib(7) << nl; // 13
        cout << sol.fib(10) << nl; // 55
        // cout<<sol.fib(100)<<nl; // TLE
    }
    cout << nl;



    {
        int dp[N] = { 0 };
        cout << sol.fibTD(2, dp) << nl; // 1
        cout << sol.fibTD(5, dp) << nl; // 5
        cout << sol.fibTD(7, dp) << nl; // 13
        cout << sol.fibTD(10, dp) << nl; // 55
        cout << sol.fibTD(100, dp) << nl; // 3736710778780434371
    }
    cout << nl;



    {
        cout << sol.fibBU(2) << nl; // 1
        cout << sol.fibBU(5) << nl; // 5
        cout << sol.fibBU(7) << nl; // 13
        cout << sol.fibBU(10) << nl; // 55
        cout << sol.fibBU(100) << nl; // 3736710778780434371
    }
    cout << nl;



    {
        cout << sol.fibBUspaceOpti(2) << nl; // 1
        cout << sol.fibBUspaceOpti(5) << nl; // 5
        cout << sol.fibBUspaceOpti(7) << nl; // 13
        cout << sol.fibBUspaceOpti(10) << nl; // 55
        cout << sol.fibBUspaceOpti(100) << nl; // 3736710778780434371
    }
    cout << nl;


    



    return 0;
}

