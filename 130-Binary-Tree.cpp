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








class Solution {
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



    // TC - O(N) // SC - O(N)
    vvi levelOrder(node* root) {
        vvi ans;
        if (!root) return ans;
        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vi level;
            for (int i = 0; i < size; i++) {
                node* tmp = q.front();
                q.pop();
                level.push_back(tmp->data);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            ans.push_back(level);
        }

        return ans;
    }



    // Iterative Approarch // TC - O(N) // SC - O(N)
    vi preOrderIter(node* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<node*> stk;
        stk.push(root);

        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            ans.push_back(root->data);

            // insert right subtree first // so that in the next iteration left can be used first
            if (root->right) stk.push(root->right);
            if (root->left) stk.push(root->left);
        }
    }


    // Iterative Approarch // TC - O(N) // SC - O(N)
    vi inOrderIter(node* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<node*> stk;

        while (1) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                if (stk.empty()) break;
                root = stk.top();
                stk.pop();
                ans.push_back(root->data);
                root = root->right;
            }
        }
        return ans;
    }


    // Iterative Approarch // TC - O(N) // SC - O(2*N)
    vi postOrderIter1(node* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<node*> stk1, stk2;
        stk1.push(root);

        while (!stk1.empty()) {
            root = stk1.top();
            stk1.pop();
            stk2.push(root);
            if (root->left) stk1.push(root->left);
            if (root->right) stk1.push(root->right);
        }

        while (!stk2.empty()) {
            ans.push_back(stk2.top()->data);
            stk2.pop();
        }
        return ans;
    }


    // Iterative Approarch // TC - O(2*N) // SC - O(N)
    vi postOrderIter2(node* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<node*> stk;
        node* cur = root, * tmp;

        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                tmp = stk.top()->right;
                if (tmp == NULL) {
                    tmp = stk.top(), stk.pop();
                    ans.push_back(tmp->data);

                    while (!stk.empty() && tmp == stk.top()->right) {
                        tmp = stk.top(), stk.pop();
                        ans.push_back(tmp->data);
                    }
                } else {
                    cur = tmp;
                }

            }
        }
        return ans;
    }


    void preInPostTraversal(node* root) {
        if (!root) return;
        stack<pair<node*, int>> stk;
        vi pre, in, post;

        stk.push({ root, 1 });

        while (!stk.empty()) {
            auto it = stk.top();
            stk.pop();

            if (it.second == 1) {
                // this is part of the pre
                // increment 1 to 2
                // push the left side of the tree 

                pre.push_back(it.first->data);
                it.second++;
                stk.push(it);

                if (it.first->left) stk.push({ it.first->left, 1 });
            } else if (it.second == 2) {
                // this is part of the in
                // increment 2 to 3
                // push the right side of the tree 

                in.push_back(it.first->data);
                it.second++;
                stk.push(it);
                if (it.first->right) stk.push({ it.first->right , 1 });
            } else {
                // this is part of the post
                // don't push it back again

                post.push_back(it.first->data);
            }
        }

        cout << "PreOrder : ";
        PRT(pre);
        cout << "InOrder : ";
        PRT(in);
        cout << "PostOrder : ";
        PRT(post);
    }



    vvi zigZagLevelOrderTraversal(node* root) {
        vvi ans;
        if (!root) return ans;
        queue<node*> q;
        q.push(root);
        bool leftToRight = 1; // tells about the direction // root direction is always from L to R

        while (!q.empty()) {
            int size = q.size();
            vi level(size);
            for (int i = 0; i < size; i++) {
                node* tmp = q.front();
                q.pop();

                // find index a/c to direction
                int ind = leftToRight ? i : (size - i - 1);
                level[ind] = tmp->data;

                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            ans.push_back(level);
            leftToRight ^= 1; // change the direction
        }
        return ans;
    }




    vvi verticalTravesal(node* root) {
        // map< vertical, map< level, multiset< nodes->data >>> mpp
        map<int, map<int, multiset<int>>> mpp;

        // q < pair< node*, pair< row, col>>> q;
        queue<pair<node*, pair<int, int>>> q;

        vvi ans;
        if (!root) return ans;

        q.push({ root, {0, 0} });

        // do level order traversal // any order traversal can be used
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();

            node* cur = tmp.first;
            // x = vertical // y = level
            int x = tmp.second.first, y = tmp.second.second;
            mpp[x][y].insert(cur->data);

            if (cur->left) q.push({ cur->left, {x - 1, y + 1} });
            if (cur->right) q.push({ cur->right, {x + 1, y + 1} });
        }

        for (auto x : mpp) { // x = vertical
            vi col;
            for (auto y : x.second) {
                col.insert(col.end(), y.second.begin(), y.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }



    // return a list of nodes visible from the top view from left to right in binary tree 
    // TC- O(N) // SC- O(N)
    vi topView(node* root) {
        vi ans;
        if (!root) return ans;
        map<int, int> mpp;
        queue<pair<node*, int>> q;
        q.push({ root, 0 });

        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            node* cur = tmp.first;
            int line = tmp.second;
            if (mpp.count(line) == 0) mpp[line] = cur->data;

            if (cur->left) q.push({ cur->left, line - 1 });
            if (cur->right) q.push({ cur->right, line + 1 });
        }

        for (auto x : mpp) {
            ans.push_back(x.second);
        }

        return ans;
    }




    // return a list of nodes visible from the bottom view from left to right in binary tree 
    // TC - O(N) // SC - O(N)
    vi bottomView(node* root) {
        vi ans;
        if (!root) return ans;
        map<int, int> mpp;
        queue<pair<node*, int>> q;
        q.push({ root, 0 });

        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            node* cur = tmp.first;
            int line = tmp.second;
            mpp[line] = cur->data;

            if (cur->left) q.push({ cur->left, line - 1 });
            if (cur->right) q.push({ cur->right, line + 1 });
        }

        for (auto x : mpp) {
            ans.push_back(x.second);
        }

        return ans;
    }



    // return a list of nodes visible from the right side from top to bottom in binary tree 
    // it can be done by recursive traversing or by level order traversing 
    // here recursive fun is shown // becoz it take less space and easy to code
    // TC - O(N) // SC - O(H) // H height of tree // N no of nodes
    void rightView(node* root, int level, vi& nums) {
        if (!root) return;
        // if node is visited first node of the level, insert it
        if (level == nums.size()) nums.push_back(root->data);

        // visit right first then left
        if (root->right) rightView(root->right, level + 1, nums);
        if (root->left) rightView(root->left, level + 1, nums);
    }


    // return a list of nodes visible from the left side from top to bottom in binary tree 
    // it can be done by recursive traversing or by level order traversing 
    // here recursive fun is shown // becoz it take less space and easy to code
    // TC - O(N) // SC - O(H) // H height of tree // N no of nodes
    void leftView(node* root, int level, vi& nums) {
        if (!root) return;
        // if node is visited first node of the level, insert it
        if (level == nums.size()) nums.push_back(root->data);

        // visit left first then right
        if (root->left) leftView(root->left, level + 1, nums);
        if (root->right) leftView(root->right, level + 1, nums);
    }

};






class Solution2 {
    bool isLeaf(node* root) {
        return (!root->left && !root->right);
    }


    // rev=1, denotes that we have to traverse from bottom to up
    void addLeftBoundry(node* root, vi& res, bool rev) {
        vi tmp;
        node* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) tmp.push_back(cur->data);
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }

        if (rev) {
            // for (int i = tmp.size() - 1; i >= 0; i--) res.push_back(tmp[i]);
            res.insert(res.end(), tmp.rbegin(), tmp.rend());
        } else {
            // for (int i = 0; i < tmp.size(); i--) res.push_back(tmp[i]);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }


    }


    // rev=1, denotes that we have to traverse from right to left
    void addLeaves(node* root, vi& res, bool rev) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }

        // traverse right first if rev=1
        if (rev) {
            if (root->right) addLeaves(root->right, res, rev);
            if (root->left) addLeaves(root->left, res, rev);
        } else {
            if (root->left) addLeaves(root->left, res, rev);
            if (root->right) addLeaves(root->right, res, rev);
        }
    }



    // rev=1, denotes that we have to traverse from bottom to up
    void addRightBoundry(node* root, vi& res, bool rev) {
        vi tmp;
        node* cur = root->right;
        while (cur) {
            if (!isLeaf(cur)) tmp.push_back(cur->data);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }

        if (rev) {
            // for (int i = tmp.size() - 1; i >= 0; i--) res.push_back(tmp[i]);
            res.insert(res.end(), tmp.rbegin(), tmp.rend());
        } else {
            // for (int i = 0; i < tmp.size(); i--) res.push_back(tmp[i]);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
    }

public:
    vi printBoundryAntiClockWise(node* root) {
        vi res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->data);

        addLeftBoundry(root, res, 0);
        addLeaves(root, res, 0);
        addRightBoundry(root, res, 1);

        return res;
    }

    vi printBoundryClockWise(node* root) {
        vi res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->data);

        addRightBoundry(root, res, 0);
        addLeaves(root, res, 1);
        addLeftBoundry(root, res, 1);

        return res;
    }

};





class Solution3 {
public:
    // find height // TC - O(N) // SC - O(N)
    int height(node* root) {
        if (!root) return 0;
        int lh = height(root->left); // left subtree height
        int rh = height(root->right); // right subtree height
        return 1 + max(lh, rh);
    }


    // find height // TC - O(N) // SC - O(N)
    int height2(node* root) {
        if (!root) return 0;
        int level = 0;
        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                node* tmp = q.front();
                q.pop();
                if (tmp->left || tmp->right) level++;
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
        return level;
    }



    // check tree is balanced or not // O(N^2)
    bool isBalanced_brute(node* root) {
        if (!root) return 1;
        int lh = height(root->left);
        int rh = height(root->right);
        if (abs(rh - lh) > 1) return 0;

        bool left = isBalanced_brute(root->left);
        bool right = isBalanced_brute(root->right);
        if (!left || !right) return 0;
        return 1;
    }


    // check tree is balanced or not  // O(N)
    // if balanced return height of tree otherwise -1
    int dfs_height(node* root) {
        if (!root) return 0;
        int lh = isBalanced(root->left);
        if (lh == -1) return -1;

        int rh = isBalanced(root->right);
        if (rh == -1 || abs(lh - rh) > 1) return -1;
        return max(lh, rh) + 1;
    }


    // O(N)
    int isBalanced(node* root) {
        // for balanced tree
        // height(left) - height(right) <= 1
        return dfs_height(root) != -1;
    }


    // find diameter // longest path // maximum width of the tree
    // METHOD - 1 // brute // O(N^2)  
    void findDiameter_brute(node* root, int& maxDia) {
        if (!root) return;
        int lh = height(root->left);
        int rh = height(root->right);
        maxDia = max(maxDia, lh + rh);
        findDiameter_brute(root->left, maxDia);
        findDiameter_brute(root->right, maxDia);
    }


    // find diameter // longest path // maximum width of the tree
    // METHOD - 2 // O(N)
    int findDiameter(node* root, int& maxDia) {
        if (!root) return 0;
        int lh = findDiameter(root->left, maxDia);
        int rh = findDiameter(root->right, maxDia);
        maxDia = max(maxDia, lh + rh);
        return 1 + max(lh, rh);
    }


    int maxPathSum(node* root, int& maxi) {
        if (!root) return 0;
        // if the path sum is -ve, don't take it
        int lsum = max(0, maxPathSum(root->left, maxi));
        int rsum = max(0, maxPathSum(root->right, maxi));
        maxi = max(maxi, lsum + rsum + root->data);
        return max(lsum, rsum) + root->data;
    }


    int areTreeSame(node* p, node* q) {
        if (!p || !q) return (p == q);
        return ((p->data == q->data) && areTreeSame(p->left, q->left) && areTreeSame(p->right, q->right));
    }


    bool isSymmetricHelp(node* left, node* right) {
        if (!left || !right) return left == right;
        // modified inorder traversal // Root - Left - Right || Root - Right - Left
        if (left->data != right->data) return 0;
        return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
    }

    bool isSymmetric(node* root) {
        return root == NULL || isSymmetricHelp(root->left, root->right);
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


    Solution sol;
    Solution2 sol2;
    Solution3 sol3;


    /*
    {
        vi pre1, in1, post1;
        sol.preOrder(root, pre1);
        sol.inOrder(root, in1);
        sol.postOrder(root, post1);

        vi pre2 = sol.preOrderIter(root);
        vi in2 = sol.inOrderIter(root);
        vi post2 = sol.postOrderIter1(root);
        vi post3 = sol.postOrderIter2(root);

        PRT(pre1);  // 1 2 4 5 3 6 7
        PRT(pre2);  // 1 2 4 5 3 6 7
        PRT(in1);   // 4 2 5 1 6 3 7
        PRT(in2);   // 4 2 5 1 6 3 7
        PRT(post1); // 4 5 2 6 7 3 1
        PRT(post2); // 4 5 2 6 7 3 1
        PRT(post3); // 4 5 2 6 7 3 1

        sol.preInPostTraversal(root);
        cout << nl;

        auto level = sol.levelOrder(root);
        for (auto x : level) {
            // new level for each x
            for (auto y : x) cout << y << sp; // 1     2 3     4 5 6 7
            cout << "    ";
        }
        cout << nl;


        vvi zigZag = sol.zigZagLevelOrderTraversal(root);
        for (auto x : zigZag) {
            // new level for each x
            for (auto y : x) cout << y << sp; // 1     3 2     4 5 6 7
            cout << "    ";
        }
        cout << nl;


        vvi vertical = sol.verticalTravesal(root);
        for (auto x : vertical) {
            // new column x
            for (auto y : x) cout << y << sp;// 4     2     1 5 6     3     7
            cout << "    ";
        }
        cout << nl;


        vi topview = sol.topView(root);
        vi bottomview = sol.bottomView(root);

        vi leftview, rightview;
        sol.rightView(root, 0, rightview);
        sol.leftView(root, 0, leftview);

        PRT(topview); // 4 2 1 3 7
        PRT(bottomview); // 4 2 6 3 7
        PRT(rightview); // 1 3 7
        PRT(leftview); // 1 2 4

    }
    cout << nl << nl;
    */






    /*
    {
        vi arr1 = sol2.printBoundryClockWise(root); // 1 3 7 6 5 4 2
        vi arr2 = sol2.printBoundryAntiClockWise(root); // 1 2 4 5 6 7 3
        PRT(arr1);
        PRT(arr2);
    }
    cout << nl << nl;
    */





    /*
    {
        cout << sol3.height(root) << nl; // 3
        cout << sol3.height2(root) << nl; // 3
        cout << sol3.isBalanced_brute(root) << nl; // 1
        cout << sol3.isBalanced(root) << nl; // 1

        int dia1 = 0, dia2 = 0;
        sol3.findDiameter_brute(root, dia1);
        sol3.findDiameter(root, dia2);
        cout << dia1 << sp << dia2 << nl; // 4 4


        int maxi = INT_MIN;
        sol3.maxPathSum(root, maxi);
        cout << maxi << nl; // 18

        cout << sol3.areTreeSame(root, root) << nl; // 1

        cout << sol3.isSymmetric(root) << nl;
    }
    cout << nl << nl;
    */




















    return 0;
}




