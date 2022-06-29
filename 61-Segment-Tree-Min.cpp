#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
// #define int              long long
#define ull              unsigned long long
#define ff               first
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

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //    #ifndef ONLINE_JUDGE
    //        freopen("input.txt", "r", stdin);
    //        freopen("output.txt", "w", stdout);
    //    #endif
}



// Segment Tree 
// Here Min Segment Tree is used for example
// Root is at index 1
// So left Node :- 2*ind,   Right node :- 2*ind + 1

// fact :-
// total no. of nodes :- 2*n - 1
// max size of array require to store values :- 4*N + 1 // (1 base indexing)   or 4*N (when root is at 0 or 0-indexing)


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


    // find min in a range [l ... r] // O(logN)
    // ss : Segment Start,  se : Segmant End, qs : Query Start,  qe : Query End
    int query(int* tree, int ss, int se, int qs, int qe, int ind) {
        // Complete overlap
        if (qs <= ss and se <= qe) {
            return tree[ind];
        }

        // No overlap
        if (qe <ss || qs > se) {
            return INT_MAX;
        }
        // Partial overlap
        int mid = (ss + se) / 2;
        int left = query(tree, ss, mid, qs, qe, 2 * ind);
        int right = query(tree, mid + 1, se, qs, qe, 2 * ind + 1);
        return min(left, right);
    }


    // Increment node at index i of nums, in tree  // O(logN)
    void updateNode(int* tree, int ss, int se, int i, int increment, int ind) {
        // Case when the i i out of bounds // i not lies in [ss ... se]
        if (i < ss || se < i) {
            return;
        }

        // leaf node // Node that have to update // leaf node
        if (ss == se) {
            tree[ind] = tree[ind] + increment;
            return;
        }

        // Otherwise // call both sides
        int mid = (ss + se) / 2;
        updateNode(tree, ss, mid, i, increment, 2 * ind);
        updateNode(tree, mid + 1, se, i, increment, 2 * ind + 1);
        tree[ind] = min(tree[2 * ind], tree[2 * ind + 1]);
    }


    // Update range // update values in [l ... r] // increment by inc // O(N) + O(logN)
    void updateRange(int* tree, int ss, int se, int l, int r, int inc, int ind) {
        // Out of bounds  // or No overlap
        if (r < ss || se < l) {
            return;
        }

        // Leaf node // update
        if (ss == se) {
            tree[ind] = tree[ind] + inc;
            return;
        }

        // Recursive case
        int mid = (ss + se) / 2;
        updateRange(tree, ss, mid, l, r, inc, 2 * ind);
        updateRange(tree, mid + 1, se, l, r, inc, 2 * ind + 1);
        tree[ind] = min(tree[2 * ind], tree[2 * ind + 1]);
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






int32_t main() {
    fastIO();
    Solution sol;

    int nums[] = { 1, 3, 2, -5, 6, 4 };
    int n = sizeof(nums) / sizeof(nums[0]);

    // Maximum node can be (4*N + 1)
    int* tree = new int[4 * n + 1];

    sol.buildSegmentTree(nums, 0, n - 1, tree, 1);
    sol.printTree(tree, n);
    sol.printValues(tree, 0, n - 1, 1); // 1 3 2 -5 6 4 
    cout << nl;
    cout << "FLAG 1\n\n";


    // find min in a range [l ... r]
    sol.printValues(tree, 0, n - 1, 1); // 1 3 2 -5 6 4 
    cout << nl;
    cout << sol.query(tree, 0, n - 1, 2, 4, 1) << nl; // -5 
    cout << sol.query(tree, 0, n - 1, 0, 2, 1) << nl; // 1
    cout << sol.query(tree, 0, n - 1, 5, 5, 1) << nl; // 4
    cout << "FLAG 2\n\n";


    // Update a node
    // upddate index 3 // add 15
    sol.updateNode(tree, 0, n - 1, 3, 15, 1);
    sol.printValues(tree, 0, n - 1, 1); // 1 3 2 10 6 4
    cout << nl;

    cout << sol.query(tree, 0, n - 1, 2, 4, 1) << nl; // 2 
    cout << sol.query(tree, 0, n - 1, 5, 5, 1) << nl; // 4
    cout << "FLAG 3\n\n";


    // Update range [0 ... 3] // increment values by 10
    sol.updateRange(tree, 0, n - 1, 0, 3, 10, 1);
    sol.printValues(tree, 0, n - 1, 1); // 11 13 12 20 6 4 
    cout << nl;

    cout << sol.query(tree, 0, n - 1, 0, 2, 1) << nl; // 11 
    cout << sol.query(tree, 0, n - 1, 5, 5, 1) << nl; // 4
    cout << "FLAG 4\n\n";

    return 0;
}

