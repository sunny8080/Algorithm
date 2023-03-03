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


// QUE :- https://leetcode.com/problems/longest-increasing-subsequence/
// Go to 116

// Solution using Fenwick Tree or BIT // O(NlogN)
class Solution {

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

    int solve(vector<int>& nums, int n) {
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
        for (int i = 0; i < n; i++) {
            int mxTill = query(BIT, temp[i] - 1);
            update(BIT, n, temp[i], mxTill + 1);
        }
        // PRT(BIT);
        return *max_element(BIT.begin(), BIT.end());
        // return -1;
    }

public:

    int lengthOfLIS(vector<int>& nums) {
        return solve(nums, nums.size());
    }

};


int32_t main() {
    fastIO();
    Solution sol;

    int n; cin >> n;
    vector<int> nums(n);
    for (auto& x : nums) cin >> x;

    cout << sol.lengthOfLIS(nums) << nl;

    return 0;
}



// 8
// 10 9 2 5 3 7 101 18
// OUT: 4

// 7
// 7 7 7 7 7 7 7
// OUT: 1

// 9
// 1 3 6 7 9 4 10 5 6
// OUT: 6
