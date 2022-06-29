#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
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

class Solution {

public:
    // Binary search in [ l ... r ] // array should be sorted // {l, r }-> {left, right }
    // METHOD - 1 // Recursive Approach
    int binarySearchRec(vi& nums, int l, int r, int key) {
        if (l > r) return -1;
        int mid = (l + r) / 2;
        if (nums[mid] == key) return mid;
        if (nums[mid] < key) return binarySearchRec(nums, mid + 1, r, key);
        if (nums[mid] > key) return binarySearchRec(nums, l, mid - 1, key);
        return -1;
    }


    // METHOD - 2 // Iterative Approach  // O(logN)
    int binarySearch(vi& nums, int key) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == key) return mid;
            else if (nums[mid] < key) l = mid + 1;
            else if (nums[mid] > key) r = mid - 1;
        }
        return -1;
    }

    int firstOccurence(vi& nums, int key) {
        int l = 0;
        int r = nums.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == key) {
                ans = mid;
                // do not stop but explore the left part of the array
                r = mid - 1;
            } else if (nums[mid] < key) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }


    int lastOccurence(vi& nums, int key) {
        int l = 0;
        int r = nums.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == key) {
                ans = mid;
                // do not stop but explore the right part of the array
                l = mid + 1;
            } else if (nums[mid] < key) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }


    // Find value when array is rotated
    int findArrRot(vi& nums, int key) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == key) return mid;
            else if (nums[mid] >= nums[l]) { // left part is sorted

                // 2 cases -> Element lies on the left or the right of the mid 
                if (key >= nums[l] && key < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else if (nums[mid] <= nums[r]) { // right part is sorted
                if (key > nums[mid] && key <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};


int32_t main() {
    fastIO();
    Solution sol;

    vi nums = { 4, 5, 2, 8, 10, 20, 5 };
    sort(all(nums));
    PRT(nums); // 2 4 5 5 8 10 20 

    cout << sol.binarySearchRec(nums, 0, nums.size() - 1, 10) << nl; // 5
    cout << sol.binarySearchRec(nums, 0, nums.size() - 1, 20) << nl; // 6
    cout << sol.binarySearchRec(nums, 0, nums.size() - 1, 2) << nl; // 0
    cout << sol.binarySearchRec(nums, 0, nums.size() - 1, 150) << nl; // -1
    cout << nl;

    // cout << sol.binarySearch(nums, 10) << nl; // 5
    // cout << sol.binarySearch(nums, 20) << nl; // 6
    // cout << sol.binarySearch(nums, 2) << nl; // 0
    // cout << sol.binarySearch(nums, 150) << nl; // -1
    // cout << nl;

    // // binary_search() -> C++ STL function
    // cout << binary_search(nums.begin(), nums.end(), 10) << nl; // 1
    // cout << binary_search(nums.begin(), nums.end(), 20) << nl; // 1
    // cout << binary_search(nums.begin(), nums.end(), 2) << nl; // 1
    // cout << binary_search(nums.begin(), nums.end(), 150) << nl; // 0
    // cout << nl << nl;


    // nums = { 1, 2, 5, 8, 8, 8, 8, 10, 12, 15, 20 };
    // cout << sol.firstOccurence(nums, 8) << nl; // 3
    // cout << sol.lastOccurence(nums, 8) << nl; // 6
    // cout << sol.firstOccurence(nums, 100) << nl; // -1
    // cout << sol.lastOccurence(nums, 100) << nl; // -1
    // cout << nl;

    // // lower_bound() -> return index of >= key
    // // upper_bound() -> return index of > key
    // cout << lower_bound(nums.begin(), nums.end(), 8) - nums.begin() << nl; // 3
    // cout << upper_bound(nums.begin(), nums.end(), 8) - nums.begin() << nl; // 7
    // cout << upper_bound(nums.begin(), nums.end(), 8) - lower_bound(nums.begin(), nums.end(), 8) << nl; // 4

    // cout << lower_bound(nums.begin(), nums.end(), 7) - nums.begin() << nl; // 3
    // cout << upper_bound(nums.begin(), nums.end(), 7) - nums.begin() << nl; // 3

    // cout << (lower_bound(nums.begin(), nums.end(), 700) == nums.end()) << nl; // 1
    // cout << (upper_bound(nums.begin(), nums.end(), 0) == nums.begin()) << nl; // 1
    // cout << nl << nl;


    // Find value when array is rotated
    nums = {1, 2, 3, 4, 5};
    vi rot_nums = {4, 5, 1, 2, 3}; // rotated array
    cout<<sol.findArrRot(rot_nums, 3)<<nl; // 4
    cout<<sol.findArrRot(rot_nums, 5)<<nl; // 1
    cout<<sol.findArrRot(rot_nums, 10)<<nl; // -1




    return 0;
}

