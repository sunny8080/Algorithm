#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
#define int 			 long long
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


// We have used, Monotonic Search Space
// Aggressive Cows
// QUE :- https://www.spoj.com/problems/AGGRCOW/
// Soln :- https://www.youtube.com/watch?v=wSOfYesTBRk

class Solution {
    bool canPlaceCows(vi& stalls, int cows, int min_step) {
        // place first cow in first place
        int last_cow = stalls[0];
        int cnt = 1;

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - last_cow >= min_step) {
                last_cow = stalls[i];
                cnt++;
                if (cnt == cows) return true;
            }
        }
        return false;
    }

public:
    int solve(vi& stalls, int cows) {
        // make a search space as [l ... r]
        int l = 0;
        int r = stalls[stalls.size() - 1] - stalls[0];
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (canPlaceCows(stalls, cows, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};






// Another example :-
// Book Allocation
// QUE :- https://www.geeksforgeeks.org/allocate-minimum-number-pages/
// Soln :- https://www.youtube.com/watch?v=gYmWHvRHu-s
class Solution2 {
    bool isPossible(vi& nums, int m, int curr_min) {  // greedy approach
        int studentUsed = 1;
        int page_reading = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (page_reading + nums[i] > curr_min) {
                studentUsed++;
                page_reading = nums[i];

                if (studentUsed > m) return false;
            } else {
                page_reading += nums[i];
            }
        }
        return true;
    }
public:
    int findPage(vi& nums, int m) {
        // count no. of pages
        int sum = 0;
        for (auto x : nums) sum += x;

        int l = *max_element(all(nums));
        int r = sum;
        int ans = 0;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (isPossible(nums, m, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

};




int32_t main() {
    fastIO();
    Solution sol;
    // wt(t) {
    //     int n, cows; cin >> n >> cows;
    //     vi stalls(n); for (auto& x : stalls) cin >> x;
    //     sortv(stalls);
    //     cout << sol.solve(stalls, cows) << nl;
    // }

    {
        int n = 5, cows = 3;
        vi stalls = { 1, 2, 8, 4, 9 };
        sortv(stalls);
        cout << sol.solve(stalls, cows) << nl; // 3
        cout << nl;
    }



    Solution2 sol2;

    // wt(t){
    //     int n, m; cin>>n>>m;
    //     vi nums(n); 
    //     for( auto &x: nums ) cin>>x;
    //     cout<<sol2.findPage(nums, m)<<nl;
    // }

    {
        int n = 4;
        int m = 2;
        vi nums = { 10, 20, 30, 40 };
        cout << sol2.findPage(nums, m) << nl; // 60
        cout<<nl;
    }


    return 0;
}

