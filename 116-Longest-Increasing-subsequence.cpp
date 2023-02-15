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
#define fr(t,a,b)        for( int t=(a); t<=(b); t++)
#define frr(t,a,b)       for( int t=(a); t>=(b); t--)
#define cn(x)            int x; cin>>x;

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


// QUE :- https://leetcode.com/problems/longest-increasing-subsequence/submissions/
// Soln1 - https://www.youtube.com/watch?v=ekcwMsSIzVc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=42
// Soln1 - https://www.youtube.com/watch?v=IFfYfonAFGc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=43
// Soln2 - https://www.youtube.com/watch?v=on2hvxBXJH4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=44
// Soln4 - https://www.youtube.com/watch?v=cKVl1TFdNXg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=49






// Striver's solution
class Solution1 {
    int solve(int ind, int prev_ind, vector<int>& nums, vector< vector<int>>& dp) {
        if (ind == nums.size()) return 0;
        if (dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

        int len = 0 + solve(ind + 1, prev_ind, nums, dp); // not take it
        if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
            len = max(len, 1 + solve(ind + 1, ind, nums, dp)); // take it
        }
        return dp[ind][prev_ind + 1] = len;
    }
public:
    // METHOD - 1 // TC : O(N^2) // SC : O(N^2 + N) // recursion
    int lenLis1(vector<int>& nums) {
        int n = nums.size();
        vector< vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, nums, dp);
    }



    // METHOD - 2 // TC : O(N^2) // SC : O(N^2)
    int lenLis2(vector<int>& nums) {
        int n = nums.size();
        vector< vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
                int len = 0 + dp[ind + 1][prev_ind + 1];
                if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
                    len = max(len, 1 + dp[ind + 1][ind + 1]);
                }
                dp[ind][prev_ind + 1] = len;
            }
        }
        return dp[0][0];
    }



    // METHOD - 3 // TC - O(N^2) // SC : O(N)
    int lenLis3(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n + 1, 0), cur(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
                int len = 0 + next[prev_ind + 1];
                if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
                    len = max(len, 1 + next[ind + 1]);
                }
                cur[prev_ind + 1] = len;
            }
            next = cur;
        }
        return next[0];
    }




    // METHOD - 4 // TC - O(N^2) // SC - O(N) // Print LIS
    int lenLis4(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastInd = 0;
        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i] && 1 + dp[prev]>dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i], lastInd = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastInd]);
        while (lastInd != hash[lastInd]) {
            lastInd = hash[lastInd];
            ans.push_back(nums[lastInd]);
        }
        reverse(ans.begin(), ans.end());
        PRT(ans);

        return maxi;
    }




    // METHOD - 5 // TC - O(NlogN) // SC - O(N) // Binary search
    int lenLis5(vector<int>& nums) {
        // Remeber tmp is just a temp array, it is not LIS // it can only used to determine the length of LIS
        vector<int> tmp;
        tmp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (tmp.back() < nums[i]) {
                tmp.push_back(nums[i]);
            } else {
                int ind = lower_bound(tmp.begin(), tmp.end(), nums[i]) - tmp.begin();
                tmp[ind] = nums[i];
            }
        }
        return tmp.size();
    }


    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 1), cnt(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                } else if (nums[prev] < nums[i] && 1 + dp[prev] == dp[i]) {
                    cnt[i] += cnt[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) ans += cnt[i];
        }
        return ans;
    }

};








struct segment {
    int query(vector<int>& BIT, int ind) {
        int ans = 0;
        while (ind > 0) {
            ans = max(ans, BIT[ind]);
            ind -= (ind & (-ind));
        }
        return ans;
    }

    void update(vector<int>& BIT, int n, int ind, int inc) {
        while (ind <= n) {
            BIT[ind] = max(inc, BIT[ind]);
            ind += (ind & (-ind));
        }
    }
};





class Solution2 {
    int lengthOfLCS(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int dp[n + 1][m + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) dp[i][j] = 0;
                else if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

public:


    // METHOD - 1 // DP -2 tricky // O(N^2 + N)
    int lengthOfLIS1(vector<int>& nums) {
        int n = nums.size();
        int dp[n + 1];
        // dp[i] = element at which increasing subsequence of length i ends

        dp[0] = INT_MIN;
        for (int i = 1; i <= n; i++) dp[i] = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int length = 0; length < n; length++) {

                if ((dp[length] < nums[i]) && (nums[i] < dp[length + 1])) {
                    dp[length + 1] = nums[i];
                }
            }
        }

        int lis = 0;
        for (int i = 1; i <= n; i++)
            if (dp[i] != INT_MAX) lis = i;

        // for(int i=0; i<n+1; i++ ) cout<<dp[i]<<" ";
        // cout<<nl;

        return lis;
    }



    // METHOD - 2 // DP -2 with binary search // O(NlogN)
    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        int dp[n + 1];
        // dp[i] = element at which increasing subsequence of length i ends

        dp[0] = INT_MIN;
        for (int i = 1; i <= n; i++) dp[i] = INT_MAX;

        for (int i = 0; i < n; i++) {
            int length = upper_bound(dp, dp + n + 1, nums[i]) - dp;

            if ((dp[length - 1] < nums[i]) && (nums[i] < dp[length])) {
                dp[length] = nums[i];
            }
        }

        int lis = 0;
        for (int i = 1; i <= n; i++)
            if (dp[i] != INT_MAX) lis = i;

        // for (int i = 0; i < n + 1; i++) if (dp[i] != INT_MIN && dp[i] != INT_MAX) cout << dp[i] << " ";
        // cout << nl;

        return lis;
    }





    // METHOD - 3 // Using Segment Tree (or Fenwick Tree) // O(NlogN)
    int lengthOfLIS3(vector<int>& nums) {
        int n = nums.size();
        // Co-ordination compression
        set<int> st;
        for (auto x : nums) st.insert(x);
        map<int, int> mpp;
        int i = 1;
        for (auto x : st) mpp[x] = i++;

        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = mpp[nums[i]];
        }
        // PRT(temp);

        vector<int> BIT(n + 1, 0);
        segment tree;
        for (int i = 0; i < n; i++) {
            int mxTill = tree.query(BIT, temp[i] - 1);
            tree.update(BIT, n, temp[i], mxTill + 1);
        }

        return *max_element(BIT.begin(), BIT.end());
        // return -1;
    }


    // METHOD - 4 // Using longest common subsequence// O(N^2)
    int lengthOfLIS4(vector<int>& nums) {
        vector<int> nums2(nums);
        sort(nums2.begin(), nums2.end());
        nums2.resize(distance(nums2.begin(), unique(nums2.begin(), nums2.end())));
        return lengthOfLCS(nums, nums2);
    }

};




int32_t main() {
    fastIO();

    {
        Solution1 sol1;
        vector<int> nums = { 2, 1, 5, 0, 4, 6 };
        // vector<int> nums = { 1, 2, 3, 4, 5 };
        int len = sol1.lenLis5(nums);
        cout << "Length of LIS : " << len << endl; // 3
    }
    cout << nl;

    {
        Solution1 sol1;
        vector<int> nums = {1, 3, 5, 4, 7}; 
        cout<<sol1.findNumberOfLIS(nums)<<nl; // 2
    }


    {
        Solution2 sol2;
        vector<int> nums = { 2, 1, 5, 0, 4, 6 }; 
        cout << sol2.lengthOfLIS2(nums) << nl; // 3
    }
    cout << nl;





    return 0;
}

