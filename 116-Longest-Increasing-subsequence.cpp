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




// 300. Longest Increasing Subsequence (go to 67 for segment tree)
// QUE :- https://leetcode.com/problems/longest-increasing-subsequence/submissions/
// Soln1 - https://www.youtube.com/watch?v=ekcwMsSIzVc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=42
// Soln1 - https://www.youtube.com/watch?v=IFfYfonAFGc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=43
// Soln2 - https://www.youtube.com/watch?v=on2hvxBXJH4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=44
// Soln4 - https://www.youtube.com/watch?v=cKVl1TFdNXg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=49


// 673. Number of Longest Increasing Subsequence
// QUE :- https://leetcode.com/problems/number-of-longest-increasing-subsequence/





// Striver's solution
class Solution1 {
    int lengthOfLISHelp(int ind, int prev_ind, vector< vector<int>>& dp, vector<int>& nums) {
        if (ind == nums.size()) return 0;
        if (dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

        int len = lengthOfLISHelp(ind + 1, prev_ind, dp, nums); // not take it
        if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
            len = max(len, 1 + lengthOfLISHelp(ind + 1, ind, dp, nums)); // take it
        }
        return dp[ind][prev_ind + 1] = len;
    }

public:
    // METHOD - 1 : Top Down DP // TCO(N^2) // SCO(N^2 + N) 
    int lengthOfLIS1(vector<int>& nums) {
        int n = nums.size();
        vector< vector<int>> dp(n, vector<int>(n + 1, -1));
        return lengthOfLISHelp(0, -1, dp, nums);
    }



    // METHOD - 2 : Bottom Up DP // TCO(N^2) // SCO(N^2) 
    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        vector< vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
                int len = dp[ind + 1][prev_ind + 1]; // not take
                if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
                    len = max(len, 1 + dp[ind + 1][ind + 1]); // take
                }
                dp[ind][prev_ind + 1] = len;
            }
        }
        return dp[0][-1 + 1];
    }



    // METHOD - 3 : Bottom Up DP // TCO(N^2) // SCO(N) 
    int lengthOfLIS3(vector<int>& nums) {
        int n = nums.size();
        vector<int> nxt(n + 1, 0), cur(n + 1, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
                int len = nxt[prev_ind + 1]; // not take
                if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
                    len = max(len, 1 + nxt[ind + 1]); // take
                }
                cur[prev_ind + 1] = len;
            }
            nxt = cur;
        }
        return nxt[0];
    }



    // METHOD - 4 : Bottom Up DP // TCO(N^2) // SCO(N) 
    int lengthOfLIS4(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), par(n, 0);
        int maxLen = 1, lastInd = 0;

        for (int i = 0; i < n; i++) {
            par[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    par[i] = prev;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i], lastInd = i;
            }
        }

        // // To print LCS
        // vector<int> lcs;
        // lcs.push_back(nums[lastInd]);
        // while (par[lastInd] != lastInd) {
        //     lastInd = par[lastInd];
        //     lcs.push_back(nums[lastInd]);
        // }
        // reverse(lcs.begin(), lcs.end());
        // cout << "LCS len : " << maxLen << " -> " << "\n";
        // for (auto x : lcs) cout << x << " ";

        return maxLen;
    }




    // METHOD - 4 : Binary Search // TCO(N*logN) // SCO(N) 
    int lengthOfLIS(vector<int>& nums) {
        // Remeber tmp is just a temp array, it is not LIS // it can only used to determine the length of LIS
        vector<int> tmp;
        tmp.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > tmp.back()) tmp.push_back(nums[i]);
            else {
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








class Solution2 {
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


public:
    // METHOD - 3 // Using Segment Tree (or Fenwick Tree) // O(NlogN)
    int lengthOfLIS6(vector<int>& nums) {
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
    }

};




int32_t main() {
    fastIO();

    {
        Solution1 sol1;
        vector<int> nums = { 2, 1, 5, 0, 4, 6 };
        // vector<int> nums = { 1, 2, 3, 4, 5 };
        int len = sol1.lengthOfLIS(nums);
        cout << "Length of LIS : " << len << endl; // 3
    }
    cout << nl;

    {
        Solution1 sol1;
        vector<int> nums = { 1, 3, 5, 4, 7 };
        cout << sol1.findNumberOfLIS(nums) << nl; // 2
    }


    {
        Solution2 sol2;
        vector<int> nums = { 2, 1, 5, 0, 4, 6 };
        cout << sol2.lengthOfLIS6(nums) << nl; // 3
    }
    cout << nl;





    return 0;
}

