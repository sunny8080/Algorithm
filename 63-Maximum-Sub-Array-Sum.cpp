#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
#define int              long long
#define ull              unsigned long long
#define ff               first
// #define ss               second
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
#define INT_MINN -78947
#define MAX 100000
const ll cnst = 1e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //    #ifndef ONLINE_JUDGE
    //        freopen("input.txt", "r", stdin);
    //        freopen("output.txt", "w", stdout);
    //    #endif
}


// Find Maximum Subarray Sum
// QUE :- https://www.spoj.com/problems/GSS1/


struct treeNode {
    int ps, ss, ts, ms;  // prefix sum,  suffix sum, total sum, max subarray sum
};

treeNode tree[4 * MAX + 1];


class Solution {

public:
    void buildSegmentTree(vi& nums, int s, int e, treeNode* tree, int ind) {
        if (s == e) {
            tree[ind].ps = tree[ind].ss = tree[ind].ts = tree[ind].ms = nums[s];
            return;
        }

        int mid = (s + e) / 2;
        buildSegmentTree(nums, s, mid, tree, 2 * ind);
        buildSegmentTree(nums, mid + 1, e, tree, 2 * ind + 1);

        treeNode left = tree[2 * ind];
        treeNode right = tree[2 * ind + 1];

        tree[ind].ps = max(left.ps, left.ts + right.ps);
        tree[ind].ss = max(right.ss, right.ts + left.ss);
        tree[ind].ts = left.ts + right.ts;
        tree[ind].ms = max({ left.ms, right.ms, left.ss + right.ps });
    }

    treeNode maxSumQuery(treeNode* tree, int ss, int se, int qs, int qe, int ind) {
        // complete overlap
        if (qs <= ss && se <= qe) {
            return tree[ind];
        }

        // no overlap
        if (qe < ss or se < qs) {
            treeNode temp;
            temp.ps = temp.ss = temp.ts = temp.ms = INT_MIN;
            return temp; // DEBUG
        }

        // partial overlap
        int mid = (ss + se) / 2;
        treeNode left = maxSumQuery(tree, ss, mid, qs, qe, 2 * ind);
        treeNode right = maxSumQuery(tree, mid + 1, se, qs, qe, 2 * ind + 1);
        treeNode tmp;

        tmp.ps = max(left.ps, left.ts + right.ps);
        tmp.ss = max(right.ss, right.ts + left.ss);
        tmp.ts = left.ts + right.ts;
        tmp.ms = max({ left.ms, right.ms, left.ss + right.ps });
        return tmp;
    }
};




int32_t main() {
    fastIO();
    Solution sol;

    int n; cin >> n;
    vi nums(n);  for (auto& x : nums) cin >> x;

    sol.buildSegmentTree(nums, 0, n - 1, tree, 1);
    int l, r;
    treeNode tmp;

    wt(q) {
        cin >> l >> r;
        tmp = sol.maxSumQuery(tree, 0, n - 1, l - 1, r - 1, 1);
        cout << tmp.ms << nl;
    }



    return 0;
}


