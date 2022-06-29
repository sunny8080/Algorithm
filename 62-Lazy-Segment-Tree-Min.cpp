#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
// #define int              long long
#define ull              unsigned long long
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

const ll cnst = 1e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    #endif
}



// Lazy Propagation Segment Tree
// Root is at index 1

class Solution {

public:
    // Build Segment tree from nums array // O(N)
    void buildSegmentTree(int* nums, int start, int end, int* tree, int ind) {
        if (start == end) {  // Leaf node
            tree[ind] = nums[start];
            return;
        }

        // Recursive case
        // int leftInd = 2 * ind, rightInd = 2 * ind + 1;  // 1 based indexing
        // build left and then right subtree // [start ... mid]  [mid+1 ... end]
        int mid = (start + end) / 2;
        buildSegmentTree(nums, start, mid, tree, 2 * ind);
        buildSegmentTree(nums, mid + 1, end, tree, 2 * ind + 1);
        tree[ind] = min(tree[2 * ind], tree[2 * ind + 1]);
        return;
    }


    int lazy[10000] = { 0 };

    // Lazy Propagation // updation range in lazy mod // O(logN)
    // Update range // update values in [l ... r] // increment by inc // O(N)
    void updateRangeLazy(int* tree, int ss, int se, int l, int r, int inc, int ind) {
        // Before going down resolve the lazy value if exists
        if (lazy[ind] != 0) {
            tree[ind] = tree[ind] + lazy[ind];

            // Non leaf node
            if (ss != se) {
                lazy[2 * ind] += lazy[ind];
                lazy[2 * ind + 1] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // No overlap case
        if (r < ss || se < l) {
            return;
        }

        // Complete overlap case
        if (l <= ss and se <= r) {
            tree[ind] = tree[ind] + inc;

            // create new lazy value for non leaf children node
            if (ss != se) {
                lazy[2 * ind] += inc;
                lazy[2 * ind + 1] += inc;
            }
            return;
        }

        // Recursive case // partially overlap case
        int mid = (ss + se) / 2;
        updateRangeLazy(tree, ss, mid, l, r, inc, 2 * ind);
        updateRangeLazy(tree, mid + 1, se, l, r, inc, 2 * ind + 1);
        tree[ind] = min(tree[2 * ind], tree[2 * ind + 1]);
    }


    // find min in a range [l ... r] // lazy propagation // O(logN)
    // ss : Segment Start,  se : Segmant End, qs : Query Start,  qe : Query End
    int queryLazy(int* tree, int ss, int se, int qs, int qe, int ind) {
        // Before going down resolve the lazy value if exists
        if (lazy[ind] != 0) {
            tree[ind] = tree[ind] + lazy[ind];

            // Non leaf node
            if (ss != se) {
                lazy[2 * ind] += lazy[ind];
                lazy[2 * ind + 1] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // No overlap case
        if (qe < ss || se < qs) {
            return INT_MAX;
        }

        // Complete overlap
        if (qs <= ss and se <= qe) {
            return tree[ind];
        }

        // partially overlap
        int mid = (ss + se) / 2;
        int left = queryLazy(tree, ss, mid, qs, qe, 2 * ind);
        int right = queryLazy(tree, mid + 1, qe, qs, qe, 2 * ind + 1);
        int ans = min(left, right);
        return ans;
    }



    void printValues(int* tree, int ss, int se, int ind) {
        if (ss == se) {
            cout << tree[ind] << sp;
            return;
        }

        int mid = (ss + se) / 2;
        printValues(tree, ss, mid, 2 * ind);
        printValues(tree, mid + 1, se, 2 * ind + 1);
    }

    void printTree(int* tree, int n) {
        for (int i = 1; i <= 2 * n + 1; i++) {
            cout << tree[i] << sp;
        }
        cout << nl;
    }
};



int32_t main(){
    fastIO();
    Solution sol;

    int nums[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(nums)/sizeof(nums[0]);

    int *tree = new int[4*n + 1];
    sol.buildSegmentTree(nums, 0, n-1, tree, 1);

    sol.printValues(tree, 0, n - 1, 1); // 1 3 2 -5 6 4
    cout<<nl;

    sol.updateRangeLazy(tree, 0, n-1, 0, 2, 10, 1);
    sol.updateRangeLazy(tree, 0, n-1, 0, 4, 10, 1);
    
    sol.printValues(tree, 0, n - 1, 1); // 1 3 2 -5 6 4
    cout << nl;


    cout<<sol.queryLazy(tree, 0, n-1, 1, 1, 1)<<nl; // 23
    sol.printValues(tree, 0, n - 1, 1); // 21 23 22 -5 6 4 
    cout << nl;

    cout<<sol.queryLazy(tree, 0, n-1, 3, 5, 1)<<nl; // 4
    sol.printValues(tree, 0, n - 1, 1); // 21 23 22 -5 6 4
    cout << nl;

    
    return 0;
}
    
    