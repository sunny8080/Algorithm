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
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}


// Greedy Approach used
// Useful only in case of indian currency 
class Solution {

public:
    int make_change(vi& coins, int money) {
        int ans = 0;
        while (money > 0) {
            int idx = upper_bound(all(coins), money) - coins.begin() - 1;
            money -= coins[idx];
            ans++;
            cout << coins[idx] << sp;
        }
        cout << nl;
        return ans;
    }

};





// QUE :- https://www.spoj.com/problems/BUSYMAN/

bool comp(pair<int, int> a, pair<int, int> b) {
    // if (a.second < b.second) return true;
    // if (a.second > b.second) return false;
    // if (a.first < b.first) return true;
    // if (a.first > b.first) return false;
    // return false; // can't be "return true;"" // it will give runtime error

    return a.second < b.second;
}

class Solution2 {

public:
    int maxActivity(vector<pair<int, int>>& nums) {
        int n = nums.size();
        sort(all(nums), comp);

        int ans = 0;
        int last = 0;
        for (auto x : nums) {
            if (x.first >= last) {
                ans++;
                last = x.second;
            }
        }
        return ans;
    }
};






int32_t main() {
    fastIO();
    Solution sol;

    vi coins = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
    int ans = sol.make_change(coins, 134);
    cout << "Coins needed : " << ans << nl;



    // Solution2 sol2;
    // wt(t) {
    //     int n; cin >> n;
    //     vector<pair<int, int>> nums(n);
    //     for (int i = 0; i < n; i++) {
    //         int s, e; cin >> s >> e;
    //         nums[i] = make_pair(s, e);
    //     }
    //     cout << sol2.maxActivity(nums) << nl;
    // }

    return 0;
}

