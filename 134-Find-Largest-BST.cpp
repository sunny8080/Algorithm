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


// Series - https://www.youtube.com/watch?v=p7-9UvDQZ3w&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=41

// QUE :- https://www.geeksforgeeks.org/find-the-largest-subtree-in-a-tree-that-is-also-a-bst/
// Soln : https://www.youtube.com/watch?v=X0oXMdtUDwo&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=54


struct node {
    int val;
    node* left, * right;
    node():val(0), left(NULL), right(NULL) {};
    node(int val) { val = val, left = right = NULL; }
    node(int val, node* left, node* right):val(val), left(left), right(right) {};
};



class nodeVal {
public:
    int maxi, mini, maxSize;
    nodeVal(int mini, int maxi, int maxSize): mini(mini), maxi(maxi), maxSize(maxSize) {};
};


class Solution {

public:
    // do post order traversal and modify it
    nodeVal* largestBSTSubtre_help(node* root) {
        // an empty tree is a BSt of size of 0
        if (!root) return new nodeVal(INT_MAX, INT_MIN, 0);

        // get values from left and right subtree of current node
        auto left = largestBSTSubtre_help(root->left);
        auto right = largestBSTSubtre_help(root->right);

        // current node is greater than max in left and smaller than min in right, it is a BST
        if (left->maxi < root->val && root->val < right->mini) {
            // it is a BST
            return new nodeVal(min(root->val, left->mini), max(root->val, right->maxi), 1 + left->maxSize + right->maxSize);
        }

        // otherwise root is not BST, return [-inf, inf, max(l_size, r_size)], so that parent can't be a valid BST
        return new nodeVal(INT_MIN, INT_MAX, max(left->maxSize, right->maxSize));
    }



    // Return no of largest BST
    // METHOD 1 - for every node check it is valid or not, if yes find no of nodes // O(N^2)
    // METHOD 2 - do post order traversal and modify it// TC - O(N) // SC - O(N)
    int largestBSTSubtre(node* root) {
        return largestBSTSubtre_help(root)->maxSize;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




