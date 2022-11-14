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


// MO's algo
// used in Query based problem
// first comes to brute force solution, then use MO's
// for offline queries // means all queries should be in hand // so that we can sort it
// no update


//QUE :- https://www.spoj.com/problems/DQUERY/


int freq[1000005];
int distinct;

struct query {
    int l, r, q_ind, block_ind;
    bool operator<(query& q2) {
        if (block_ind < q2.block_ind) return 1;
        if (block_ind > q2.block_ind) return 0;
        return (r < q2.r);
    }
};


class Solution {
    // add x to freq
    void add(int x) {
        if (freq[x] == 0) distinct++;
        freq[x]++;
    }

    // remove x from freq
    void remove(int x) {
        freq[x]--;
        if (freq[x] == 0) distinct--;
    }


    // adjust {cur_l, cur_r} a/c to {l, r}
    void adjust(int& cur_l, int& cur_r, int l, int r, vi& nums) {
        // fix l
        while (l < cur_l) {
            add(nums[--cur_l]);
        }

        while (cur_l < l) {
            remove(nums[cur_l++]);
        }

        // fix r
        while (r < cur_r) {
            remove(nums[cur_r--]);
        }

        while (cur_r < r) {
            add(nums[++cur_r]);
        }
    }

public:
    vi solve(vi& nums, vector<query>& q) {
        int n = nums.size(), m = q.size(), rn = sqrt(n);;
        vi ans(m);
        mems(freq, 0);
        distinct = 0;

        sort(all(q)); // sort all queries

        // first, solve first query then others
        int cur_l = q[0].l, cur_r = q[0].r;
        for (int i = cur_l; i <= cur_r; i++) {
            add(nums[i]);
        }
        ans[q[0].q_ind] = distinct;

        for (int i = 1; i < q.size(); i++) {
            adjust(cur_l, cur_r, q[i].l, q[i].r, nums);
            ans[q[i].q_ind] = distinct;
        }

        return ans;
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    int n; cin >> n;
    int rn = sqrt(n);
    vi nums(n);
    for (auto& x : nums) cin >> x;

    int m; cin >> m;
    vector<query> q(m);

    for (int i = 0; i < m; i++) {
        int l, r; cin >> l; cin >> r;
        tie(q[i].l, q[i].r, q[i].q_ind, q[i].block_ind) = make_tuple(l - 1, r - 1, i, l / rn);
    }

    auto ans = sol.solve(nums, q);
    for (auto x : ans) cout << x << nl;

    return 0;
}













