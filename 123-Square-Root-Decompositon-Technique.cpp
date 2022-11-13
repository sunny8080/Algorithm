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

// Square root decompositon
// used in range query problem 

// Soln 1 : https://www.youtube.com/watch?v=yjHDwnONdI8
// Soln 1 : https://www.youtube.com/watch?v=AcvVlneAYZE




class Solution {

public:
    vi build(vi& nums) {
        int n = nums.size();
        int rn = sqrt(n);
        int block_id = -1;

        vi blocks(n / rn + 1);
        for (int i = 0; i < n; i++) {
            if (i % rn == 0) block_id++;
            blocks[block_id] += nums[i];
        }

        // PRT(blocks);
        return blocks;
    }


    // return sum from [l...r]
    int findRangeSum(vi& nums, vi& blocks, int l, int r) {
        int n = nums.size();
        int rn = sqrt(n);
        int sum = 0;

        // left part
        while (l != 0 && l <= r && l % rn != 0) {
            sum += nums[l++];
        }

        // middle part
        while (l + rn <= r) {
            sum += blocks[l / rn];
            l += rn;
        }

        // right part
        while (l <= r) sum += nums[l++];
        return sum;
    }


    // update ith value
    void update(vi& nums, vi& blocks, int ind, int newVal) {
        int rn = sqrt(nums.size());
        blocks[ind / rn] += (newVal - nums[ind]);
        nums[ind] = newVal;
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    vi nums = { 1, 3, 5, 2, 7, 6, 3, 1 , 4, 8 };
    int n = nums.size();

    vi blocks = sol.build(nums);

    cout << sol.findRangeSum(nums, blocks, 2, 8) << nl; // 28

    sol.update(nums, blocks, 2, 15);
    cout << sol.findRangeSum(nums, blocks, 2, 8) << nl; // 38


    return 0;
}

