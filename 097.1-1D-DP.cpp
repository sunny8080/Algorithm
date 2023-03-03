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
// Atcoder dp task : https://atcoder.jp/contests/dp/tasks



// Find fibonacci numbers, with various approach
class Solution {
public:
    // Normal fib function
    // Time - O(2^N)   // Space - O(N)
    int fib(int n) {
        if (n <= 1) return n; // base case
        return fib(n - 1) + fib(n - 2); // recursion
    }


    // find fib with Top Down approach
    // Time - O(N)   // Space - O(N)
    int fibTD(int n, int* dp) {
        if (n <= 1) return n;
        if (dp[n] != 0) return dp[n]; // look up

        return dp[n] = fibTD(n - 1, dp) + fibTD(n - 2, dp);
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
        if (n <= 1) return n;
        int a = 0;
        int b = 1;

        for (int i = 2; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};







// Min Steps
// QUE :- https://practice.geeksforgeeks.org/problems/minimum-steps-to-minimize-n-as-per-given-condition0618/1
class Solution2 {
public:
    int dp[10005] = {};

    // Top Down approach
    int minSteps1(int n){
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









// climing stairs
// QUE :- https://leetcode.com/problems/climbing-stairs/
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
        vector<int> dp(n + 1, 0);
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
// QUE  :- https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
// Soln :- https://youtu.be/mO8XpGoJwuo?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY
// Soln : https://youtu.be/zYZasir27Tg
class Solution6 {
    int cutRodHelp1(int ind, int len, vector< vector<int>>& dp, int* price) {
        if (ind == 0) return len * price[0];
        if (dp[ind][len] != -1) return dp[ind][len];
        int notTake = cutRodHelp1(ind - 1, len, dp, price);
        int rodLenth = ind + 1;
        int take = len - rodLenth >= 0 ? price[ind] + cutRodHelp1(ind, len - rodLenth, dp, price) : INT_MIN;
        return dp[ind][len] = max(notTake, take);
    }


    int cutRodHelp2(int len, vector<int>& dp, int* price, int n) {
        if (len <= 0) return 0;
        if (len < 0) return -1e9;
        if (dp[len] != -1) return dp[len];
        int ans = -1e9;
        for (int cut = 1; cut <= len; cut++) ans = max(ans, price[cut - 1] + cutRodHelp2(len - cut, dp, price, n));
        return dp[len] = ans;
    }
public:
    // Top Down
    int cutRod1(int price[], int n) {
        vector< vector<int>> dp(n, vector<int>(n + 1, -1));
        return cutRodHelp1(n - 1, n, dp, price);
    }

    // Bottom Up
    int cutRod2(int price[], int n) {
        vector< vector<int>> dp(n, vector<int>(n + 1, 0));
        for (int l = 0; l <= n; l++) dp[0][l] = price[0] * l;

        for (int ind = 1; ind < n; ind++) {
            for (int len = 0; len <= n; len++) {
                int notTake = dp[ind - 1][len];
                int rodLenth = ind + 1;
                int take = len - rodLenth >= 0 ? price[ind] + dp[ind][len - rodLenth] : INT_MIN;
                dp[ind][len] = max(notTake, take);
            }
        }
        return dp[n - 1][n];
    }


    int cutRod3(int price[], int n) {
        vector<int> prev(n + 1, 0);
        for (int l = 0; l <= n; l++) prev[l] = price[0] * l;

        for (int ind = 1; ind < n; ind++) {
            for (int len = 0; len <= n; len++) {
                int notTake = prev[len];
                int rodLenth = ind + 1;
                int take = len - rodLenth >= 0 ? price[ind] + prev[len - rodLenth] : INT_MIN;
                prev[len] = max(notTake, take);
            }
        }
        return prev[n];
    }


    // Different approach
    // Top Down
    int cutRod4(int price[], int n) {
        vector<int> dp(n + 1, -1);
        return cutRodHelp2(n, dp, price, n);
    }


    // Different approach
    // Bottom Up
    int cutRod5(int price[], int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;

        for (int len = 1; len <= n; len++) {
            dp[len] = INT_MIN;
            for (int cut = 1; cut <= len; cut++) {
                dp[len] = max(dp[len], price[cut - 1] + dp[len - cut]);
            }
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

