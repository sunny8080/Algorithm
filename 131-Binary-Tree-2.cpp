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


// Series - https://www.youtube.com/watch?v=OYqYEM1bMK8&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=1


struct node {
    int data;
    node* left, * right;
    node():data(0), left(NULL), right(NULL) {};
    node(int val) { data = val, left = right = NULL; }
    node(int val, node* left, node* right):data(val), left(left), right(right) {};
};





class Solution4 {
public:
    bool nodePathHelp(node* root, vi& nums, int x) {
        if (!root) return false;
        // do inorder traversal
        nums.push_back(root->data);
        if (root->data == x) return true;
        if (nodePathHelp(root->left, nums, x) || nodePathHelp(root->right, nums, x)) return true;
        nums.pop_back();
        return false;
    }

    // return path from root to a node // TC - O(N) // SC - O(H)
    vi nodePath(node* root, int x) {
        vi ans;
        if (!root) return ans;
        nodePathHelp(root, ans, x);
        return ans;
    }

    bool isSame(node* p, node* q) {
        if (!p || !q) return p == q;
        return (p->data == q->data) && isSame(p->left, q->left) && isSame(p->right, q->right);
    }

    // return true if q is subtree of p 
    bool isSubtree(node* p, node* q) {
        if (q == NULL) return 1;
        if (p == NULL) return 0;

        if (p->data == q->data && isSame(p, q)) return 1;
        if (p->left && isSubtree(p->left, q)) return 1;
        if (p->right && isSubtree(p->right, q))return 1;
        return 0;
    }



    // return LCA(Lowest Common Ancestor) of p and q
    node* lca(node* root, node* p, node* q) {
        if (root == NULL || root == p || root == q) return root;
        node* left = lca(root->left, p, q);
        node* right = lca(root->right, p, q);

        if (left == NULL) return right;
        if (right == NULL) return left;
        return root; // lca found
    }



    int widthOfBT(node* root) {
        int ans = 0;
        if (!root) return ans;

        queue<pair<node*, int>> q;
        q.push({ root, 0 });

        while (!q.empty()) {
            int size = q.size();
            int mini = q.front().second; // to make the id starting from 0
            int first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                // substract mini to avoid overflow
                node* cur = q.front().first;
                int cur_id = q.front().second - mini;
                q.pop();

                if (i == 0) first = cur_id;
                if (i == size - 1) last = cur_id;

                if (cur->left) q.push({ cur->left, 2 * cur_id + 1 });
                if (cur->right) q.push({ cur->right, 2 * cur_id + 2 });
            }
            ans = max(ans, last - first + 1);
        }

        return ans;
    }



    // children sum property : val(parent) = val(left child) + val(right child) 
    // convert a tree such that after converting it follows children sum property
    // TC - O(N) // SC - O(H)
    void changeTreeToChildrenSum(node* root) {
        if (!root) return;
        int child = 0;
        if (root->left) child += root->left->data;
        if (root->right) child += root->right->data;

        if (child < root->data) {
            if (root->left) root->left->data = root->data;
            else if (root->right) root->right->data = root->data;
        }

        changeTreeToChildrenSum(root->left);
        changeTreeToChildrenSum(root->right);

        // backtracking
        child = 0;
        if (root->left) child += root->left->data;
        if (root->right) child += root->right->data;
        // if it is not leaf not update its value
        if (root->left or root->right) root->data = child;
    }



    // return all nodes and their parent
    unordered_map<node*, node*> markParents(node* root) {
        unordered_map<node*, node*> par;
        if (!root) return par;

        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            node* cur = q.front();
            q.pop();

            // mark parent of left and right child as current node
            if (cur->left) {
                par[cur->left] = cur;
                q.push(cur->left);
            }
            if (cur->right) {
                par[cur->right] = cur;
                q.push(cur->right);
            }
        }
        return par;
    }




    // return all nodes which are at a distance of k from the given target
    vector<int> distanceK(node* root, node* target, int k) {
        vi ans;
        if (!root || !target) return ans;
        unordered_map<node*, node*> par = markParents(root);

        unordered_map<node*, bool> vis;
        queue<node*> q;
        q.push(target); // push the target, mark as visited, and as current dist as 0
        vis[target] = 1;
        int cur_dist = 0;

        // do BFS to go upto k dist from target node by using vis, par table
        while (!q.empty()) {
            if (cur_dist++ == k) break;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                node* cur = q.front();
                q.pop();

                // visit current node's left, right and its parent node // if it exists and not visited
                if (cur->left && !vis[cur->left]) {
                    vis[cur->left] = 1;
                    q.push(cur->left);
                }
                if (cur->right && !vis[cur->right]) {
                    vis[cur->right] = 1;
                    q.push(cur->right);
                }
                if (par[cur] && !vis[par[cur]]) {
                    vis[par[cur]] = 1;
                    q.push(par[cur]);
                }
            }
        }

        // nodes present in q are at a dist of k from target
        while (!q.empty()) {
            ans.push_back(q.front()->data);
            q.pop();
        }
        return ans;
    }



    // return a node address of a value if present, otherwise NULL
    node* findNode(node* root, int target) {
        if (!root) return NULL;
        if (root->data == target) return root;
        node* left = findNode(root->left, target);
        return (left ? left : findNode(root->right, target));
    }


    // return time to burn the tree, if we start the burning from target node
    // find maximum distance to any node from target 
    int timeToBurnTree(node* root, int startVal) {
        int maxi = 0;
        if (!root) return maxi;
        node* target = findNode(root, startVal);
        if (!target) return INT_MAX; // if start value is not present return INt_MAX

        unordered_map<node*, node*> par = markParents(root);
        unordered_map<node*, bool> vis;
        queue<node*> q;

        q.push(target);
        vis[target] = 1;
        while (!q.empty()) {
            int sz = q.size();
            int burn = 0;
            for (int i = 0; i < sz; i++) {
                node* cur = q.front();
                q.pop();

                if (cur->left && !vis[cur->left]) {
                    vis[cur->left] = 1;
                    q.push(cur->left);
                    burn++;
                }
                if (cur->right && !vis[cur->right]) {
                    vis[cur->right] = 1;
                    q.push(cur->right);
                    burn++;
                }
                if (par[cur] && !vis[par[cur]]) {
                    vis[par[cur]] = 1;
                    q.push(par[cur]);
                    burn++;
                }
            }
            if (burn) maxi++;
        }

        return maxi;
    }


    int leftHeight(node* root) {
        int ht = 0;
        while (root) {
            root = root->left;ht++;
        }
        return ht;
    }

    int rightHeight(node* root) {
        int ht = 0;
        while (root) {
            root = root->right;ht++;
        }
        return ht;
    }

    // return no of nodes in a complete binary tree
    // we can use any any traversal but it will take O(N)
    // For this algo, TC - O(logN^2)
    int countNodesOfCompleteBT(node* root) {
        if (!root) return 0;
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if (lh == rh) return (1 << lh) - 1;
        return 1 + countNodesOfCompleteBT(root->left) + countNodesOfCompleteBT(root->right);
    }
};




class Solution5 {

public:
    // Recurssive Approarch // TC - O(N) // SC - O(1)
    void preOrder(node* root, vi& nums) {
        if (root) {
            nums.push_back(root->data);
            preOrder(root->left, nums);
            preOrder(root->right, nums);
        }
    }


    // Recurssive Approarch// TC - O(N) // SC - O(1)
    void inOrder(node* root, vi& nums) {
        if (root) {
            inOrder(root->left, nums);
            nums.push_back(root->data);
            inOrder(root->right, nums);
        }
    }


    // Recurssive Approarch // TC - O(N) // SC - O(1)
    void postOrder(node* root, vi& nums) {
        if (root) {
            postOrder(root->left, nums);
            postOrder(root->right, nums);
            nums.push_back(root->data);
        }
    }






    node* buildTreePreIn_Help(vi& pre, int preStart, int preEnd, vi& in, int inStart, int inEnd, map<int, int>& inMap) {
        // return NULL if it is leaf node
        if (inStart > inEnd || preStart > preEnd) return NULL;

        // start node of pre order is root
        node* root = new node(pre[preStart]);
        int root_in_ind = inMap[root->data]; // root of the root val in inorder traversal
        int numsLeft = root_in_ind - inStart; // no of nodes in the left side of the root

        // After root known
        // left subtree  : pre - [ preStart + 1, preStart + numsLeft ] || in - [ inStart, root_in_ind - 1 ]
        // right subtree : pre - [ preStart + numsLeft + 1, preEnd ]   || in - [ root_in_ind + 1, inEnd ] 

        // build left and right substree
        root->left = buildTreePreIn_Help(pre, preStart + 1, preStart + numsLeft, in, inStart, root_in_ind - 1, inMap);
        root->right = buildTreePreIn_Help(pre, preStart + numsLeft + 1, preEnd, in, root_in_ind + 1, inEnd, inMap);
        return root;
    }


    // build the Binary Tree if pre order and in order traversal is given
    // TC - O(NlogN) // SC - O(N)
    node* buildTreePreIn(vi& pre, vi& in) {
        map<int, int> inMap;
        for (int i = 0; i < in.size(); i++) inMap[in[i]] = i;
        return buildTreePreIn_Help(pre, 0, pre.size() - 1, in, 0, in.size() - 1, inMap);
    }





    node* buildTreePostIn_Help(vi& post, int postStart, int postEnd, vi& in, int inStart, int inEnd, map<int, int>& inMap) {
        // return NULL if it is leaf node
        if (inStart > inEnd || postStart > postEnd) return NULL;

        // start node of pre order is root
        node* root = new node(post[postEnd]);
        int root_in_ind = inMap[root->data]; // root of the root val in inorder traversal
        int numsLeft = root_in_ind - inStart; // no of nodes in the left side of the root

        // After root known
        // left subtree  : post - [ postStart, postStart + numsLeft - 1 ] || in - [ inStart, root_in_ind - 1 ]
        // right subtree : post - [ postStart + numsLeft, postEnd - 1 ]   || in - [ root_in_ind + 1, inEnd ]

        // build left and right substree
        root->left = buildTreePostIn_Help(post, postStart, postStart + numsLeft - 1, in, inStart, root_in_ind - 1, inMap);
        root->right = buildTreePostIn_Help(post, postStart + numsLeft, postEnd - 1, in, root_in_ind + 1, inEnd, inMap);
        return root;
    }



    // build the Binary Tree if post order and in order traversal is given
    // TC - O(NlogN) // SC - O(N)
    node* buildTreePostIn(vi& post, vi& in) {
        map<int, int> inMap;
        for (int i = 0; i < in.size(); i++) inMap[in[i]] = i;
        return buildTreePostIn_Help(post, 0, post.size() - 1, in, 0, in.size() - 1, inMap);
    }

};





int32_t main() {
    fastIO();

    // BT :-
    //     1
    //  2     3
    // 4 5   6 7

    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);


    Solution4 sol4;
    Solution5 sol5;


    /*
    {
        auto path1 = sol4.nodePath(root, 7);
        auto path2 = sol4.nodePath(root, 5);
        auto path3 = sol4.nodePath(root, 10);
        PRT(path1); // 1 3 7
        PRT(path2); // 1 2 5
        PRT(path3); //


        node* root2 = new node(2);
        root2->left = new node(4);
        root2->right = new node(5);
        cout << sol4.isSubtree(root, root2) << nl;


        node* p = root->left->left, * q = root->left->right;
        node* tmp = sol4.lca(root, p, q);
        cout << tmp->data << nl; // 2

        cout << sol4.widthOfBT(root) << nl; // 4


        node* root3 = new node(1);
        root3->left = new node(2);
        root3->left->left = new node(4);
        root3->left->right = new node(5);
        root3->right = new node(3);
        root3->right->left = new node(6);
        root3->right->right = new node(7);
        sol4.changeTreeToChildrenSum(root3);
        cout << root3->data << nl; // 22
        cout << root->data << nl; // 1


        vi ans = sol4.distanceK(root, root->left, 2);
        PRT(ans); // 3

        node* tmp2 = sol4.findNode(root, 6);
        node* tmp3 = sol4.findNode(root, 10);
        cout << (tmp2 ? tmp2->data : -1) << nl; // 6
        cout << (tmp3 ? tmp2->data : -1) << nl; // -1

        cout << sol4.timeToBurnTree(root, 2) << nl; // 3
        cout << sol4.timeToBurnTree(root, 20) << nl; // 2147483647

        cout << sol4.countNodesOfCompleteBT(root) << nl; // 7
    }
    cout<<nl<<nl;
    */




    /*
    {
        vi pre = { 3, 9, 20, 15, 7 };
        vi in = { 9, 3, 15, 20, 7 };
        node* root4 = sol5.buildTreePreIn(pre, in);
        vi pre1, post1, in1;
        sol5.preOrder(root4, pre1);
        sol5.inOrder(root4, in1);
        sol5.postOrder(root4, post1);
        PRT(pre1); // 3 9 20 15 7
        PRT(in1); // 9 3 15 20 7
        PRT(post1); // 9 15 7 20 3



        vi post3 = { 40, 50, 20, 60, 30, 10 };
        vi in3 = { 40, 20, 50, 10, 60, 30 };
        node* root5 = sol5.buildTreePostIn(post3, in3);
        vi pre2, post2, in2;
        sol5.postOrder(root5, post2);
        sol5.inOrder(root5, in2);
        sol5.preOrder(root5, pre2);
        PRT(post2); // 40 50 20 60 30 10
        PRT(in2); // 40 20 50 10 60 30
        PRT(pre2); // 10 20 40 50 30 60
    }
    cout<<nl;
    */






    return 0;
}




