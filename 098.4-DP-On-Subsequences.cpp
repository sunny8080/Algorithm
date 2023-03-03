#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll                 long long
// #define int                long long
#define ull                unsigned long long
#define ff                 first
#define ss                 second
#define pb                 push_back
#define mp                 make_pair
#define pii                pair<int,int>
#define vi                 vector<int>
#define vll                vector<ll> 
#define vvi                vector< vector<int>>
#define vvll               vector< vector<ll>>
#define vpii               vector<pair<int,int>>
#define mii                map<int,int>
#define pqb                priority_queue<int>
#define pqs                priority_queue<int, vector<int>, greater<int>>
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define mod                1000000007
#define inf                1e18
#define ps(x,y)            fixed<<setprecision(y)<<x
#define mk(arr, n, type)   type *arr=new type[n];
#define wt(x)              int x; cin>>x; while( x-- )
#define sp                 ' '
#define nl                 char(10)
#define PRT(ar)            for( auto i : ar ) cout<<i<<sp; cout<<nl;
#define mems(x,ch)         memset(x,ch,sizeof(x))
#define sortv(x)           sort(x.begin(),x.end())
#define sortvr(x)          sort(x.rbegin(),x.rend())
#define all(x)             x.begin(), x.end()
#define fr(t,a,b)          for( int t=(a); t<=(b); t++)
#define frr(t,a,b)         for( int t=(a); t>=(b); t--)
#define cn(x)              int x; cin>>x;
#define ri(x)              cin >> x
#define rii(x, y)          cin >> x >> y
#define riii(x, y, z)      cin >> x >> y >> z
#define riiii(x, y, z, w)  cin >> x >> y >> z >> w
#define rvi(nums)          for (auto& x : nums) cin >> x;
#define dri(x)             int x; cin >> x
#define drs(s)             string s; cin >> s
#define drii(x, y)         int x, y; cin >> x >> y
#define driii(x, y, z)     int x, y, z; cin >> x >> y >> z
#define driiii(x, y, z, w) int x, y, z, w; cin >> x >> y >> z >> w
#define drvi(nums, n)      vector<int> nums(n); for (auto& x : nums) cin >> x;
#define iff(x, y)  if(x) y

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



// Perfect Sum Problem : Count subset with sum k
// QUE :- https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

#define mod  1000000007

class Solution1 {
    int perfectSumHelp(int ind, int sum, vector< vector<int>>& dp, int* nums) {
        if (sum < 0) return 0; // for this all nums[i] must be non negative
        // if (ind == 0) {
        //     if (sum == 0 && nums[0] == 0) return 2; // to handle subset having 0 as elements
        //     if (sum == 0 || nums[0] == sum) return 1;
        //     return 0;
        // }
        if (ind == 0) return (sum == 0) + (nums[0] == sum);
        if (dp[ind][sum] != -1) return dp[ind][sum];
        return dp[ind][sum] = (perfectSumHelp(ind - 1, sum, dp, nums) + perfectSumHelp(ind - 1, sum - nums[ind], dp, nums)) % mod;
    }


public:
    int perfectSum1(int nums[], int n, int sum) {
        vector< vector<int>> dp(n, vector<int>(sum + 1, -1));
        return perfectSumHelp(n - 1, sum, dp, nums);
    }


    int perfectSum2(int nums[], int n, int sum) {
        vector< vector<int>> dp(n, vector<int>(sum + 1, 0));
        for (int i = 0; i < n; i++) dp[i][0] = 1;
        if (sum >= nums[0]) dp[0][nums[0]] += 1;

        for (int i = 1; i < n; i++) {
            for (int k = 0; k <= sum; k++) {
                int notTake = dp[i - 1][k];
                int take = k - nums[i] >= 0 ? dp[i - 1][k - nums[i]] : 0;
                dp[i][k] = (notTake + take) % mod;
            }
        }
        return dp[n - 1][sum];
    }


    int perfectSum(int nums[], int n, int sum) {
        vector<int> prev(sum + 1, 0), cur(sum + 1, 0);
        prev[0] = cur[0] = 1;
        if (sum >= nums[0]) prev[nums[0]] += 1;

        for (int i = 1; i < n; i++) {
            for (int k = 0; k <= sum; k++) {
                int notTake = prev[k];
                int take = k - nums[i] >= 0 ? prev[k - nums[i]] : 0;
                cur[k] = (notTake + take) % mod;
            }
            prev = cur;
        }
        return prev[sum];
    }
};








// coins Change
// QUE :- https://leetcode.com/problems/coin-change/
class Solution2 {
    int coinChangeHelp(int ind, int amt, vector< vector<int>>& dp, vector<int>& coins) {
        if (amt == 0) return 0;
        if (ind == 0) return amt % coins[0] == 0 ? (amt / coins[0]) : 1e9;
        if (dp[ind][amt] != -1) return dp[ind][amt];

        int notTake = 0 + coinChangeHelp(ind - 1, amt, dp, coins);
        int take = amt - coins[ind] >= 0 ? 1 + coinChangeHelp(ind, amt - coins[ind], dp, coins) : 1e9;

        // int take = 1e9;
        // for (int i = coins[ind]; i <= amt; i += coins[ind]) {
        //     take = min(take, i / coins[ind] + coinChangeHelp(ind - 1, amt - i, dp, coins));
        // }
        return dp[ind][amt] = min(take, notTake);
    }



    int coinChangeHelp2(int amt, vector<int>& dp, vector<int>& coins) {
        if (amt == 0) return 0;
        if (dp[amt] != -1) return dp[amt];

        int ans = 1e9;

        // pick a coins if it can be
        for (auto x : coins) {
            if (x <= amt) {
                ans = min(ans, 1 + coinChangeHelp2(amt - x, dp, coins));
            }
        }
        return dp[amt] = ans;
    }
public:
    int coinChange1(vector<int>& coins, int amt) {
        int n = coins.size();
        vector< vector<int>> dp(n, vector<int>(amt + 1, -1));
        int ans = coinChangeHelp(n - 1, amt, dp, coins);
        return ans == 1e9 ? -1 : ans;
    }



    int coinChange2(vector<int>& coins, int amt) {
        int n = coins.size();
        vector< vector<int>> dp(n, vector<int>(amt + 1, 0));
        for (int a = 0; a <= amt; a++)
            dp[0][a] = a % coins[0] == 0 ? a / coins[0] : 1e9;

        for (int i = 1; i < n; i++) {
            for (int a = 0; a <= amt; a++) {
                int notTake = 0 + dp[i - 1][a];
                int take = a - coins[i] >= 0 ? 1 + dp[i][a - coins[i]] : 1e9;
                dp[i][a] = min(take, notTake);
            }
        }
        return dp[n - 1][amt] == 1e9 ? -1 : dp[n - 1][amt];
    }


    int coinChange3(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<int> prev(amt + 1, 0), cur(amt + 1, 0);
        for (int a = 0; a <= amt; a++)
            prev[a] = a % coins[0] == 0 ? a / coins[0] : 1e9;

        for (int i = 1; i < n; i++) {
            for (int a = 0; a <= amt; a++) {
                int notTake = 0 + prev[a];
                int take = a - coins[i] >= 0 ? 1 + cur[a - coins[i]] : 1e9;
                cur[a] = min(take, notTake);
            }
            prev = cur;
        }
        return prev[amt] == 1e9 ? -1 : prev[amt];
    }


    // Diff approarch : TCO(N*A)  // SCO(2*A) // A-amt
    int coinChange4(vector<int>& coins, int amt) {
        vector<int> dp(amt + 1, -1);
        int ans = coinChangeHelp2(amt, dp, coins);
        return ans == 1e9 ? -1 : ans;
    }


    // Diff approarch : TCO(N*A)  // SCO(A) // A-amt
    int coinChange(vector<int>& coins, int amt) {
        vector<int> dp(amt + 1, 0);
        int n = coins.size();
        dp[0] = 0;
        for (int a = 1; a <= amt; a++) {
            dp[a] = 1e9;

            // try every coin
            for (auto x : coins) {
                if (a >= x) dp[a] = min(dp[a], 1 + dp[a - x]);
            }
        }
        return dp[amt] == 1e9 ? -1 : dp[amt];
    }
};










int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



