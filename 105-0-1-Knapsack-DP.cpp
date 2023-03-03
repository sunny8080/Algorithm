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

// QUE :- https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// QUE :- https://atcoder.jp/contests/dp/tasks/dp_d
// Soln :- https://www.youtube.com/watch?v=GqOmJHQZivw
// 1<=N<=1000   1<=W<=10^5    1<=v[i]<=10^9

class Solution1 {
    int knapSackHelp(int ind, int w, vector< vector<int>>& dp, int* wt, int* val) {
        if (ind == 0) return  w >= wt[0] ? val[0] : 0;
        if (dp[ind][w] != -1) return dp[ind][w];

        // for every item we have two choices to take it or to not take it
        int notTake = 0 + knapSackHelp(ind - 1, w, dp, wt, val);
        int take = w - wt[ind] >= 0 ? val[ind] + knapSackHelp(ind - 1, w - wt[ind], dp, wt, val) : INT_MIN;
        return dp[ind][w] = max(notTake, take);
    }
public:
    //Function to return max value that can be put in knapsack of capacity W.
    // bagWt - max weight or capacity of knapSack 


    // METHOD -1 : // Top Down - TCO(N*W) // SCO(N*W + N)
    int knapSack1(int bagWt, int wt[], int val[], int n) {
        vector< vector<int>> dp(n, vector<int>(bagWt + 1, -1));
        return knapSackHelp(n - 1, bagWt, dp, wt, val);
    }




    // METHOD -2 : // Bottom Up - TCO(N*W) // SCO(N*W)
    int knapSack2(int bagWt, int wt[], int val[], int n) {
        vector< vector<int>> dp(n, vector<int>(bagWt + 1, 0));
        for (int w = wt[0]; w <= bagWt; w++) dp[0][w] = val[0];

        for (int i = 1; i < n; i++) {
            for (int w = 0; w <= bagWt; w++) {
                int notTake = 0 + dp[i - 1][w];
                int take = w - wt[i] >= 0 ? val[i] + dp[i - 1][w - wt[i]] : INT_MIN;
                dp[i][w] = max(notTake, take);
            }
        }
        return dp[n - 1][bagWt];
    }




    // METHOD -3 : // Bottom Up - TCO(N*W) // SCO(2*N)
    int knapSack3(int bagWt, int wt[], int val[], int n) {
        vector<int> prev(bagWt + 1, 0), cur(bagWt + 1, 0);
        for (int w = wt[0]; w <= bagWt; w++) prev[w] = val[0];

        for (int i = 1; i < n; i++) {
            for (int w = 0; w <= bagWt; w++) {
                int notTake = 0 + prev[w];
                int take = w - wt[i] >= 0 ? val[i] + prev[w - wt[i]] : INT_MIN;
                cur[w] = max(notTake, take);
            }
            prev = cur;
        }
        return prev[bagWt];
    }



    // METHOD -4 : // Bottom Up - TCO(N*W) // SCO(N)  // BEST
    int knapSack(int bagWt, int wt[], int val[], int n) {
        vector<int> prev(bagWt + 1, 0);
        for (int w = wt[0]; w <= bagWt; w++) prev[w] = val[0];

        for (int i = 1; i < n; i++) {
            for (int w = bagWt; w >= 0; w--) {
                int notTake = 0 + prev[w];
                int take = w - wt[i] >= 0 ? val[i] + prev[w - wt[i]] : INT_MIN;
                prev[w] = max(notTake, take);
            }
        }
        return prev[bagWt];
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
                int take = val[i] <= v ? wt[i] + dp[i - 1][v - val[i]] : INT_MAX;
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




    return 0;
}

