#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
// #define int              long long
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

// QUE :- https://www.spoj.com/problems/KGSS/
// in query, we have to return node,  and not a value

struct node {
    int max1, max2;
};


class Solution {

public:
    void buildTree(vi& nums, int s, int e, node* tree, int ind) {
        if (s == e) {
            tree[ind].max1 = nums[s];
            tree[ind].max2 = 0;
            return;
        }

        int mid = (s + e) / 2;
        buildTree(nums, s, mid, tree, 2 * ind);
        buildTree(nums, mid + 1, e, tree, 2 * ind + 1);
        node left = tree[2 * ind], right = tree[2 * ind + 1];

        if (left.max1 > right.max1) {
            tree[ind].max1 = left.max1;
            tree[ind].max2 = max({ left.max2, right.max1, right.max2 });
        } else {
            tree[ind].max1 = right.max1;
            tree[ind].max2 = max({ left.max1, left.max2, right.max2 });
        }
    }

    void updateNode(node* tree, int ss, int se, int ind, int i, int val) {
        if (i < ss || se < i) return;

        if (ss == se) {
            tree[ind].max1 = val;
            return;
        }

        int mid = (ss + se) / 2;
        updateNode(tree, ss, mid, 2 * ind, i, val);
        updateNode(tree, mid + 1, se, 2 * ind + 1, i, val);
        node left = tree[2 * ind], right = tree[2 * ind + 1];

        if (left.max1 > right.max1) {
            tree[ind].max1 = left.max1;
            tree[ind].max2 = max({ left.max2, right.max1, right.max2 });
        } else {
            tree[ind].max1 = right.max1;
            tree[ind].max2 = max({ left.max1, left.max2, right.max2 });
        }
    }

    node query(node* tree, int ss, int se, int qs, int qe, int ind) {
        if (qe < ss || se < qs) {
            node tmp;
            tmp.max1 = tmp.max2 = INT_MIN;
            return tmp;
        }

        if (qs <= ss and se <= qe) {
            return tree[ind];
        }

        int mid = (ss + se) / 2;
        node left = query(tree, ss, mid, qs, qe, 2 * ind);
        node right = query(tree, mid + 1, se, qs, qe, 2 * ind + 1);

        node tmp;
        if (left.max1 > right.max1) {
            tmp.max1 = left.max1;
            tmp.max2 = max({ left.max2, right.max1, right.max2 });
        } else {
            tmp.max1 = right.max1;
            tmp.max2 = max({ left.max1, left.max2, right.max2 });
        }
        return tmp;
    }


};




    


int32_t main() {
    fastIO();
    Solution sol;

    int n; cin >> n;
    vi nums(n); for (auto& x : nums) cin >> x;
    node tree[4 * n + 1];
    sol.buildTree(nums, 0, n - 1, tree, 1);

    char ch;
    int l, r;

    wt(q) {
        cin >> ch >> l >> r;
        if (ch == 'Q') {
            l--, r--;
            node ans = sol.query(tree, 0, n - 1, l, r, 1);
            cout << (ans.max1 + ans.max2) << nl;
        } else {
            l--;
            sol.updateNode(tree, 0, n - 1, 1, l, r);
            // cout<<"Updated"<<nl;
        }
    }

    return 0;
}

