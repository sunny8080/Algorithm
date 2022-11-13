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



// QUE :- https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// QUE 2 :- https://practice.geeksforgeeks.org/problems/a512e4b2e812b6df2159b19cc7090ffc1ab056dd/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


struct node {
    node* left; // denotes 0
    node* right; // denites 1
    node() {
        left = right = NULL;
    }
};


// Trie data str
class Solution {
    node* root;
public:
    Solution() {
        root = new node();
    }

    void insert(int n) {
        node* tmp = root;
        for (int i = 31; i >= 0; i--) {
            int bit = ((n >> i) & 1);

            if (bit == 0) {
                if (tmp->left == NULL) tmp->left = new node();
                tmp = tmp->left;
            } else {
                if (tmp->right == NULL) tmp->right = new node();
                tmp = tmp->right;
            }
        }
    }


    //  x^n = maxXor ==> return maxXor 
    int maxXorHelp(int n) {
        int ans = 0;
        node* tmp = root;
        for (int i = 31; i >= 0; i--) {
            int bit = ((n >> i) & 1);

            if (bit == 0) {
                // search for bit 1, if possible
                if (tmp->right != NULL) {
                    ans += (1 << i);
                    tmp = tmp->right;
                } else tmp = tmp->left;
            } else {

                // search for bit 0, if possible
                if (tmp->left != NULL) {
                    ans += (1 << i);
                    tmp = tmp->left;
                } else tmp = tmp->right;
            }
        }
        return ans;
    }


    // return maximum pair xor in array
    int findMaximumXOR(vector<int>& nums) {
        int maxXor = 0;
        for (int i = 0; i < nums.size(); i++) {
            insert(nums[i]);
            maxXor = max(maxXor, maxXorHelp(nums[i]));
        }
        return maxXor;
    }


    int maxSubarrayXOR(vector<int>& nums) {
        //code here
        int n = nums.size();
        vector<int> cXor(n + 1); // cumulative xor
        cXor[0] = 0;
        for (int i = 1; i <= n; i++) {
            cXor[i] = cXor[i - 1] ^ nums[i - 1];
        }
        return findMaximumXOR(cXor);
    }


    // return an integer x such that  x^y is maximized
    int maximum_xor(int y) {
        node* cur = root;
        int x = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = ((y >> i) & 1);

            if (bit == 0) {
                if (cur->right != NULL) {
                    x += 1 * (1 << i);
                    cur = cur->right;
                } else {
                    x += 0 * (1 << i);
                    cur = cur->left;
                }
            } else {

                if (cur->left != NULL) {
                    x += 0 * (1 << i);
                    cur = cur->left;
                } else {
                    x += 1 * (1 << i);
                    cur = cur->right;
                }

            }
        }

        return x;
    }
};







// using array pointers
class Trie2 {
    struct node {
        node* nxt[2];
        int cnt;
        node() {
            nxt[0] = nxt[1] = NULL; cnt = 0;
        }
    };
    node* root;
public:

    Trie2() {
        root = new node();
    }


    void insert(int n) {
        node* cur = root;
        cur->cnt += 1;
        for (int i = 31; i >= 0; i--) {
            int bit = ((n >> i) & 1);
            if (cur->nxt[bit] == NULL) cur->nxt[bit] = new node();
            cur = cur->nxt[bit];
            cur->cnt += 1;
        }
    }


    // find x so that x^n is maximised
    int findX(int n) {
        node* cur = root;
        int x = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = ((n >> i) & 1);

            if (cur->nxt[(bit ^ 1)] != NULL) {
                x += (bit ^ 1) * (1 << i);
                cur = cur->nxt[bit ^ 1];
            } else {
                x += (bit) * (1 << i);
                cur = cur->nxt[bit];
            }
        }
        return x;
    }

    int maximumXOR(int n) {
        node* cur = root;
        int x = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = ((n >> i) & 1);

            if (cur->nxt[(bit ^ 1)] != NULL) {
                x += (1 << i);
                cur = cur->nxt[bit ^ 1];
            } else {
                cur = cur->nxt[bit];
            }
        }
        return x;
    }


    int maxPairXor(vector<int>& nums) {
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) insert(nums[i]);
        for (int i = 0; i < nums.size(); i++) maxi = max(maxi, (nums[i] ^ findX(nums[i])));
        return maxi;
    }

    int less_than_equal_to(int x) {
        node* cur = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = ((x >> i) & 1);
            if (cur == NULL) return ans;
            if (bit && cur->nxt[0]) ans += cur->nxt[0]->cnt;
            cur = cur->nxt[bit];
        }
        if (cur) ans += cur->cnt;
        return ans;
    }

    int kth_smallest(int k) {
        if (k == 0) return INT_MAX;
        int x = 0;
        node* cur = root;
        for (int i = 31; i >= 0; i--) {
            int bit = ((k >> i) & 1);
            if (cur == NULL) return INT_MAX;

            if (cur->nxt[0] && cur->nxt[0]->cnt >= k) {
                // go to left
                cur = cur->nxt[0];
            } else {
                if (cur->nxt[0]) k -= cur->nxt[0]->cnt;
                x += (1 << i);
                cur = cur->nxt[1];
            }
        }
        return x;
    }
};




int32_t main() {
    fastIO();
    Solution sol;


    {
        vi nums = { 3, 10, 5, 25, 2, 8 };
        cout << sol.findMaximumXOR(nums) << nl; // 28
        cout << sol.maxSubarrayXOR(nums) << nl; // 31

        cout << sol.maxXorHelp(5) << nl; // 28  // 5^25 = 28
        cout << sol.maximum_xor(5) << nl; // 25
        cout << nl;
    }



    {
        Trie2 t;
        vi nums = { 3, 10, 5, 3, 25, 2, 8 };
        cout << t.maxPairXor(nums) << nl; // 28
        cout << t.less_than_equal_to(5) << nl; // 4
        cout << t.less_than_equal_to(4) << nl; // 3
        cout << t.less_than_equal_to(0) << nl; // 0
        cout << t.less_than_equal_to(50) << nl; // 7

        for (int i = 1; i <= 8; i++) cout << t.kth_smallest(i) << sp; // 2 3 3 5 8 10 25 2147483647
        cout << nl;

    }

    return 0;
}

