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

const ll N = 1e7 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //    #ifndef ONLINE_JUDGE
    //        freopen("input.txt", "r", stdin);
    //        freopen("output.txt", "w", stdout);
    //    #endif
}


// Inversion Count using Merge Sort  // METHOD - 1
// QUE  :- https://www.spoj.com/problems/INVCNT/	
// soln :- https://www.geeksforgeeks.org/counting-inversions/

class Solution {
    ll merge(vi& nums, int left, int mid, int right) {
        int i = left;
        int j = mid;
        ll cnt = 0;
        vi tmp;

        while ((i < mid) && (j <= right)) {
            if (nums[i] > nums[j]) {
                tmp.push_back(nums[j++]);
                cnt += (mid - i);
            } else {
                tmp.push_back(nums[i++]);
            }
        }

        while (i < mid) tmp.push_back(nums[i++]);
        while (j <= right) tmp.push_back(nums[j++]);

        for (int i = 0; i < tmp.size(); i++) {
            nums[left + i] = tmp[i];
        }
        return cnt;
    }

public:
    // Merge Sort :- Using Divide and Conquere method
    ll merge_sort(vi& nums, int low, int high) {
        ll cnt = 0;
        if (low < high) {
            int mid = (low + high) >> 1;

            // create two array - [low ... mid] and [mid+1 ... high]
            cnt += merge_sort(nums, low, mid);
            cnt += merge_sort(nums, mid + 1, high);
            cnt += merge(nums, low, mid + 1, high);
        }
        return cnt;
    }
};








// Inversion Count by Fenwick Tree  // METHOD - 2
vi BIT(N);

class Solution2 {

public:

    // n is length of BIT
    void update(int i, int inc, int n) {
        while (i < n) {
            BIT[i] += inc;
            i += (i & (-i));
        }
    }


    // return commulative sum
    // returns no. of points less than and equal to i
    int query(int i) {
        int ans = 0;
        while (i > 0) {
            ans += BIT[i];
            i -= (i & (-i));
        }
        return ans;
    }


    // return number of inversion counts of nums // n is size of nums
    int solve(vi& nums) {
        int n = nums.size();
        fill(all(BIT), 0);

        // METHOD - 1
        // Co-ordinate compression // Best // handle negative values
        set<int> st;
        for (int i = 0; i < n; i++) st.insert(nums[i]);
        map<int, int> mpp;

        int i = 1;
        for (auto x : st) {
            mpp[x] = i++;
        }

        vi tmp(n + 1);
        for (int i = 1; i <= n; i++) {
            tmp[i] = mpp[nums[i - 1]];
        }

        int ans = 0;

        for (int i = n; i >= 1; i--) {
            ans += query(tmp[i] - 1);
            update(tmp[i], 1, N);
        }

        // METHOD - 2 // -ve values will give errors
        // for (int i = n; i >= 1; i--) {
        // 	ans += query(nums[i] - 1);
        // 	update(nums[i], 1, N);
        // }


        // cout << ans << nl;
        return ans;

    }
};






int32_t main() {
    fastIO();
    Solution sol;
    Solution2 sol2;

    // wt(t) {
    //     int n; cin >> n;
    //     vi nums(n); for (auto& x : nums) cin >> x;
    //     cout << sol.merge_sort(nums, 0, n - 1) << nl;
    //    // cout << sol2.solve(nums) << nl;
    //     // PRT(nums);
    // }


    {
        int n = 3;
        vi nums = { 3, 2, 1 };
        cout << sol2.solve(nums)<< nl; // 3
        cout << sol.merge_sort(nums, 0, n - 1) << nl; // 3
        PRT(nums); // 1 2 3
    }

    

    return 0;
}


// 2
// 5
// 1 1 1 2 2
// 5
// 2 1 3 1 2
// // 0 4


// 2
// 4
// 1 2 4 3
// 3
// 3 2 1
// // 1 3