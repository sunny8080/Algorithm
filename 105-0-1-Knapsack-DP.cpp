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

// QUE:-https ://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// QUE :- https://atcoder.jp/contests/dp/tasks/dp_d
// Soln :- https://www.youtube.com/watch?v=GqOmJHQZivw
// 1<=N<=1000   1<=W<=10^5    1<=vi<=10^9
class Solution1 {

    // Top Down recur fun
    int solve(int ind, int W, int* wt, int* val, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (wt[0] <= W) return val[0];
            return 0;
        }

        if (dp[ind][W] != -1) return dp[ind][W];

        // for every item we have two choices to take it or to not take it
        int notTake = solve(ind - 1, W, wt, val, dp);
        int take = INT_MIN;
        if (wt[ind] <= W) {
            take = val[ind] + solve(ind - 1, W - wt[ind], wt, val, dp);
        }
        return dp[ind][W] = max(take, notTake);

    }
public:
    // METHOD -1 // TC - O(N*W)
    // Top Down // W-max weight or capacity of knapSack // SC - O(N*W + N)
    int knapSack1(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));

        for (int w = 0; w < wt[0]; w++) dp[0][w] = 0;
        for (int w = wt[0]; w <= W; w++) dp[0][w] = val[0];

        return solve(n - 1, W, wt, val, dp);
    }


    // METHOD -2 // TC - O(N*W)
    // Bottom up // SC - O(N*W)
    int knapSack2(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        for (int w = wt[0]; w <= W; w++) dp[0][w] = val[0];

        for (int i = 1; i < n; i++) {
            for (int w = 0; w <= W; w++) {
                // for every item we have two choices to take it or to not take it
                int notTake = 0 + dp[i - 1][w];
                int take = INT_MIN;
                if (wt[i] <= w) {
                    take = val[i] + dp[i - 1][w - wt[i]];
                }
                dp[i][w] = max(take, notTake);
            }
        }
        return dp[n - 1][W];
    }




    // METHOD - 3.1 // TC - O(N*W)
    // Bottom up // SC - O(N)
    int knapSack3(int W, int wt[], int val[], int n) {
        // // METHOD - 3.1 // TC - O(N*W)  
        // vector<int> prev(W+1, 0);
        // vector<int> cur(W+1, 0);
        // for (int w = wt[0]; w <= W; w++) prev[w] = val[0];
        // for (int i = 1; i < n; i++) {
        //     for (int w = 0; w <= W; w++) {
        //         int notTake = 0 + prev[w];
        //         int take = INT_MIN;
        //         if (wt[i] <= w) {
        //             take = val[i] + prev[w - wt[i]];
        //         }
        //         cur[w] = max(take, notTake);
        //     }
        //     prev=cur;
        // }
        // return cur[W];



        // METHOD - 3.2 // TC - O(N*W)  // Best
        vector<int> prev(W + 1, 0);
        for (int w = wt[0]; w <= W; w++) prev[w] = val[0];
        for (int i = 1; i < n; i++) {
            for (int w = W; w >= 0; w--) {
                int notTake = prev[w];
                int take = INT_MIN;
                if (wt[i] <= w) {
                    take = val[i] + prev[w - wt[i]];
                }
                prev[w] = max(notTake, take);
            }
        }
        return prev[W];
    }


};


// QUE :- https://atcoder.jp/contests/dp/tasks/dp_e
// 1<=N<=100   1<=W<=10^9    1<=vi<=10^3
class Solution2 {

public:
    int knapSack(int W, int wt[], int val[], int n) {
        int maxVal = n * 1000;
        int dp[n][maxVal + 1];

        // dp[i][v] -> we have to selecte items from [0...i] index 
        // dp[i][v] = w, here w represent the min wt of selected items such that
        // sum of values of all the selected items is exactly v

        for (int v = 0; v <= maxVal; v++) dp[0][v] = INT_MAX;
        dp[0][0] = 0;
        dp[0][val[0]] = wt[0];

        for (int i = 1; i < n; i++) {
            for (int v = 0; v <= maxVal; v++) {
                int notTake = dp[i - 1][v];
                int take = INT_MAX;
                if (val[i] <= v) {
                    take = wt[i] + dp[i - 1][v - val[i]];
                }
                dp[i][v] = min(take, notTake);
            }
        }

        int ans = 0;
        for (int x = 0; x <= maxVal; x++) {
            if (dp[n - 1][x] <= W) {
                ans = x;
            }
        }
        return ans;
    }

};









int32_t main() {
    fastIO();
    Solution1 sol1;

    int n, W;
    cin >> n >> W;
    int wt[n], val[n];
    for (int i = 0; i < n; i++) cin >> wt[i] >> val[i];

    // cout << sol.knapSack1(W, wt, val, n) << nl;
    // cout << sol.knapSack2(W, wt, val, n) << nl;
    // cout << sol1.knapSack3(W, wt, val, n) << nl;

    Solution2 sol2;
    cout << sol2.knapSack(W, wt, val, n) << nl;


    return 0;
}

