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
#define sp               ' '
#define nl               char(10)
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



// QUE 1 :- https://leetcode.com/problems/next-greater-element-i/
// QUE 2 : https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution1 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mpp;
        stack<int> stk;
        int n = nums2.size();

        for (int i = n - 1; i >= 0; i--) {
            // remove all elements of stack which are lesser or equal to current element
            while (!stk.empty() && stk.top() <= nums2[i]) {
                stk.pop();
            }

            // mark current element's next greater element
            mpp[nums2[i]] = stk.empty() ? -1 : stk.top();
            stk.push(nums2[i]);
        }

        vector<int> ans;
        for (auto x : nums1) {
            ans.push_back(mpp[x]);
        }
        return ans;
    }


    vector<int> nextSmallerElement(vector<int>& nums) {
        stack<int> stk;
        vector<int> res(nums.size());

        for (int i = nums.size() - 1; i >= 0; i--) {
            // remove all elements of stack which are larger or equal to current element
            while (!stk.empty() && stk.top() >= nums[i]) stk.pop();

            res[i] = stk.empty() ? -1 : stk.top();
            stk.push(nums[i]);
        }
        return res;
    }
};



// array can be circular
// QUE 2 : https://leetcode.com/problems/next-greater-element-i/
class Solution2 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> stk;

        for (int ind = 2 * n - 1; ind >= 0; ind--) {
            int i = ind % n;

            while (!stk.empty() && stk.top() <= nums[i]) {
                stk.pop();
            }

            if (ind < n) {
                ans[ind] = stk.empty() ? -1 : stk.top();
            }
            stk.push(nums[i]);
        }
        return ans;
    }
};





// Largest rectangle in histogram
// QUE : https://leetcode.com/problems/largest-rectangle-in-histogram/description/ 
class Solution3 {
public:
    int largestRectangleArea1(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        int leftSmall[n], rightSmall[n];

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();

            leftSmall[i] = stk.empty() ? 0 : stk.top() + 1;
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        int maxA = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();

            rightSmall[i] = stk.empty() ? n - 1 : stk.top() - 1;
            stk.push(i);

            maxA = max(maxA, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
        }

        return maxA;
    }


    // optimized
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int maxA = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            while (!stk.empty() && (i == n || heights[stk.top()] >= heights[i])) {
                int ht = heights[stk.top()];
                stk.pop();

                int rs = i;
                int ls = stk.empty() ? -1 : stk.top();
                int width = rs - ls - 1;

                // int width = stk.empty() ? i : (i - stk.top() - 1);
                maxA = max(maxA, ht * width);
            }
            stk.push(i);
        }
        return maxA;
    }
};

int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




