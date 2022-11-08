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




// QUE :- https://leetcode.com/problems/maximum-subarray/
// find maximum subarray sum
class Solution {
public:

    // Bottom up
    int maxSubArraySum1(vi& nums) {
        int n = nums.size();
        vi dp(n, 0);

        dp[0] = nums[0] > 0 ? nums[0] : 0;
        int mxSum = nums[0];

        for (int i = 1;i < n; i++) {
            dp[i] = dp[i - 1] + nums[i];
            mxSum = max(mxSum, dp[i]);

            if (dp[i] < 0) dp[i] = 0;
        }
        return mxSum;
    }



    // Bottom up with space optimisation
    // Kadane's Algorithm
    int maxSubArraySum2(vi& nums) {
        int n = nums.size();
        int currSum = 0;
        int mxSum = nums[0];
        int ans_l = 0, ans_r = 0, minus_pos = -1; // for find subarray

        for (int i = 0;i < n; i++) {
            currSum += nums[i];
            // mxSum = max(mxSum, currSum);
            if (mxSum < currSum) {
                mxSum = currSum;
                ans_l = minus_pos + 1;
                ans_r = i;
            }
            if (currSum < 0) {
                currSum = 0;
                minus_pos = i;
            }
        }

        // cout << "Subarray which gives max sum : ";
        // for (int i = ans_l; i <= ans_r; i++)
        //     cout << nums[i] << sp;
        // cout << nl;
        // cout << "Maximum subarray sum : " << mxSum << endl;
        return mxSum;
    }


};



int32_t main() {
    fastIO();

    {
        Solution sol;
        vi nums = { -3, 2, 5, -1, 6, 3, -2, 7, -5, 2 };
        cout << sol.maxSubArraySum1(nums) << nl; // 20
        cout << sol.maxSubArraySum2(nums) << nl; // 20

        vi nums2 = { -3, -1, -2, -5 };
        cout << sol.maxSubArraySum1(nums2) << nl; // -1
        cout << sol.maxSubArraySum2(nums2) << nl; // -1
    }
    cout << nl;



    return 0;
}

