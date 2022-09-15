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
    //    #ifndef ONLINE_JUDGE
    //        freopen("input.txt", "r", stdin);
    //        freopen("output.txt", "w", stdout);
    //    #endif
}


// Fenwick Tree or BIT (Binary Indexed Tree)
// In BIT , BIT array is in 1-based indexing manner
// So BIT[i] stores ans in range [l, r] // l=1-2^p -1, r=i  // p=position of rightmost set bit in i
// To moving forward :-  i = i + (i&(-i))    // to <=n
// To moving backward :-  i = i - (i&(-i))   // to > 0


// QUE here :- An array is given, query and update is also given
// Query :- find sum in [1 ... i] 

class Solution {

public:
    // Build fenwick tree // O(NlogN)
    void buildTree(int* nums, int n, int* BIT) {
        for (int i = 0; i < n; i++) {
            update(BIT, i + 1, nums[i], n);
        }
    }


    // update BIT // increment nums[ind] by inc  // ind is 1-based  // O(LogN)
    void update(int* BIT, int ind, int inc, int n) {
        while (ind <= n) {
            BIT[ind] = BIT[ind] + inc;
            ind += (ind & (-ind));  // moving toward right
        }
    }


    // Return sum of elements from [1 to i]  // O(LogN)
    int query(int* BIT, int i) {
        int ans = 0;
        while (i > 0) {
            ans += BIT[i];
            i -= (i & (-i));  // moving toward left
        }
        return ans;
    }


    void printPrefixSum(int* BIT, int n) {
        for (int i = 1; i <= n; i++) {
            cout << query(BIT, i) << sp;
        }
        cout << nl;
    }
};






//QUE :-  Range Maximum Query  // Find max in [1 ... x]
class Solution2 {

public:
    void buildTree(vi& nums, vi& BIT) {
        for (int i = 0; i < BIT.size(); i++) {
            BIT[i] = INT_MIN;
        }

        for (int i = 0; i < nums.size(); i++) {
            update(BIT, i + 1, nums[i]);
        }
    }

    // update BIT,  such that nums[ind] = val
    void update(vi& BIT, int ind, int val) {
        int n = BIT.size();
        while (ind < n) {
            BIT[ind] = max(BIT[ind], val);
            ind += (ind & (-ind));
        }
    }


    // Return max in [1 ... x]
    int query(vi& BIT, int x) {
        int ans = INT_MIN;
        while (x > 0) {
            ans = max(ans, BIT[x]);
            x -= (x & (-x));
        }
        return ans;
    }

    void printMaxTillI(vi& BIT) {
        for (int i = 1; i < BIT.size(); i++) {
            cout << query(BIT, i) << sp;
        }
        cout << nl;
    }
};


// QUE :- for Inversion count go to 60


int32_t main() {
    fastIO();
    Solution sol;

    int nums[] = { 4, 7, 1, 9, 2 };
    int n = sizeof(nums) / sizeof(nums[0]);
    int BIT[n + 1] = { 0 };
    sol.buildTree(nums, n, BIT);


    cout << sol.query(BIT, 1) << nl; // 4
    sol.printPrefixSum(BIT, n); // 4 11 12 21 23

    // Find sum in [l ... r]
    cout << sol.query(BIT, 5) - sol.query(BIT, 3 - 1) << nl; // 12

    sol.update(BIT, 2, 10, n);
    sol.printPrefixSum(BIT, n); // 4 21 22 31 33
    cout << "FLAG 1" << nl << nl;





    Solution2 sol2;
    vi nums2 = { -4, -10, 7, 2, 9, 1, 12 };
    int n2 = nums2.size();
    vi BIT2(n2 + 1);

    sol2.buildTree(nums2, BIT2);
    sol2.printMaxTillI(BIT2); // -4 -4 7 7 9 9 12
    cout << sol2.query(BIT2, 4) << nl; // 7

    sol2.update(BIT2, 4, 100);
    sol2.printMaxTillI(BIT2); // -4 -4 7 100 100 100 100
    cout << sol2.query(BIT2, 4) << nl; // 100
    cout << "FLAG 2" << nl << nl;


    return 0;
}

