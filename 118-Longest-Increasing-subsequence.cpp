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



class Solution {
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

    // METHOD -1 // DP -1  // O(N^2 + N)
    int lengthOfLIS1(vector<int>& nums) {
        int n = nums.size();

        // dp[i]= length of lis  ending at index i
        int dp[n];
        for (int i = 0; i < n; i++) {
            dp[i] = 0;
            for (int j = 0; j <= i - 1; j++) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j]);
            }
            dp[i] += 1;
        }

        int lis = 0;
        for (int i = 0; i < n; i++) lis = max(lis, dp[i]);
        // for( int i=0; i<n; i++ ) cout<<dp[i]<<sp;

        return lis;
    }



    // METHOD - 2 // DP -2 tricky // O(N^2 + N)
    int lengthOfLIS2(vector<int>& nums) {
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



    // METHOD - 3 // DP -2 with binary search // O(NlogN)
    int lengthOfLIS3(vector<int>& nums) {
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

        // for(int i=0; i<n+1; i++ ) cout<<dp[i]<<" ";
        // cout<<nl;

        return lis;
    }





    // METHOD - 4 // Using Segment Tree (or Fenwick Tree) // O(NlogN)
    int lengthOfLIS4(vector<int>& nums) {
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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> nums2(nums);
        sort(nums2.begin(), nums2.end());
        nums2.resize(distance(nums2.begin(), unique(nums2.begin(), nums2.end())));
        return lengthOfLCS(nums, nums2);
    }

};









class Solution2 {

public:
    // METHOD 1 // O(N*N)
    int LICS(vector<int> arr, int n) { // O(N*N)
        vector<int> lis(n);
        lis[0] = 1;
        for (int i = 1; i < n; i++) {
            lis[i] = 1;
            for (int j = 0; j < i; j++)
                if (lis[j] + 1 > lis[i] && arr[j] < arr[i])
                    lis[i] = lis[j] + 1;
        }

        // For print the longest Increasing sequence
        int ind = 0;
        int maxi = lis[0];
        for (int i = n - 1; i > 0; i--)
            if (maxi < lis[i]) {
                ind = i;
                maxi = lis[i];
            }

        vector<int> sq; // to store sequence
        sq.push_back(arr[ind]);
        for (int i = ind - 1; i >= 0; i--) {
            if (lis[i] + 1 == lis[ind] && arr[i] < arr[ind]) {
                ind = i;
                sq.push_back(arr[i]);
            }
        }
        reverse(sq.begin(), sq.end());
        //cout<<"Length of Longest increasing Subsequence : "<<maxi<<"\n";
        cout << "LICS : ";
        for (auto x : sq)
            cout << x << " ";
        cout << endl;

        return (*max_element(lis.begin(), lis.end()));
    }

    // METHOD 2 // O(N*logN)
    int LICS2(vector<int> arr, int n) {
        vector<int> seq;
        seq.push_back(arr[0]);
        for (int i = 1; i < n; i++) {
            if (seq.back() < arr[i])
                seq.push_back(arr[i]);
            else {
                int indx = lower_bound(seq.begin(), seq.end(), arr[i]) - seq.begin();
                seq[indx] = arr[i];
            }
        }
        cout << "LICS : ";
        for (auto x : seq)
            cout << x << " ";
        cout << endl;
        return (seq.size());
    }

};


int32_t main() {
    fastIO();
    Solution sol;

    {
        int n; cin >> n;
        vi nums(n);
        for (auto& x : nums) cin >> x;
        cout << sol.lengthOfLIS(nums) << nl;
    }
    cout << nl;


    {
        Solution2 sol2;
        int n; cin >> n;
        vector<int> arr(n);
        for (auto& i : arr)
            cin >> i;
        int len = sol2.LICS(arr, n);
        cout << "Length of Longest increasing Subsequence : " << len << endl;
    }

    return 0;
}

