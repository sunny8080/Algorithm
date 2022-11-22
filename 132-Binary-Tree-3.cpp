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



class Solution6 {

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



    // Encodes a tree to a single string.
    string serialize(node* root) {
        if (!root) return "";
        // do level order traversal
        string str;
        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            node* cur = q.front();
            q.pop();

            if (cur == NULL) str.append("#,");
            else str.append(to_string(cur->data) + ",");
            if (cur) {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return str;
    }



    // Decodes your encoded data to tree.
    node* deserialize(string data) {
        if (data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        queue<node*> q;

        // build the root
        getline(s, str, ',');
        node* root = new node(stoi(str));
        q.push(root);

        while (!q.empty()) {
            node* cur = q.front();
            q.pop();

            // build the left and right subtree of current node
            getline(s, str, ',');
            if (str == "#") {
                cur->left = NULL;
            } else {
                node* left = new node(stoi(str));
                cur->left = left;
                q.push(left);
            }

            getline(s, str, ',');
            if (str == "#") {
                cur->right = NULL;
            } else {
                node* right = new node(stoi(str));
                cur->right = right;
                q.push(right);
            }
        }

        return root;
    }
};



class Solution7 {

public:
    // Return in order traversal by Using Morris Traversal (it uses TBT (Threaded Binary Tree))
    // Inorder - Left Root Right
    // TC - O(N) // SC - O(1)
    vi getInOrderMorris(node* root) {
        vi inorder;
        node* cur = root;

        while (cur) {
            if (cur->left == NULL) {
                // push the current value
                inorder.push_back(cur->data);
                cur = cur->right;
            } else {
                node* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    // create a new thread to current node and go to left
                    prev->right = cur;
                    cur = cur->left;
                } else { // prev->right == cur
                    // thread already present
                    // push the current value 
                    // break the current thread and go to right of current node
                    inorder.push_back(cur->data);
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }




    // Return pre order traversal by Using Morris Traversal (it uses TBT (Threaded Binary Tree))
    // Preorder - Root Left Right
    // TC - O(N) // SC - O(1)
    vi getPreOrderMorris(node* root) {
        vi preorder;
        node* cur = root;

        while (cur) {
            if (cur->left == NULL) {
                // push the current value
                preorder.push_back(cur->data);
                cur = cur->right;
            } else {
                node* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    // create a new thread to current node and go to left
                    // push the current value 
                    preorder.push_back(cur->data);
                    prev->right = cur;
                    cur = cur->left;
                } else { // prev->right == cur
                    // thread already present
                    // break the current thread and go to right of current node
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return preorder;
    }


    node* copyBT(node* p) {
        if (!p) return NULL;
        node* q = new node(p->data);
        q->left = copyBT(p->left);
        q->right = copyBT(p->right);
        return q;
    }
};


class Solution8 {
    node* prev = NULL;
public:
    // METHOD - 1 // TC - O(N) // SC - O(1)
    // By Reverse of preorder - (Right Left Root )
    void flatternBT1(node* root) {
        if (!root) return;

        // do reverse preorder traverse - [ Right Left Root ]
        flatternBT1(root->right);
        flatternBT1(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }


    // METHOD - 2 // TC - O(N) // SC - O(N)
    // Using stack
    void flatternBT2(node* root) {
        stack<node*> stk;
        while (!stk.empty()) {
            node* cur = stk.top(); stk.pop();
            if (cur->right) stk.push(cur->right);
            if (cur->left) stk.push(cur->left);

            if (!stk.empty()) cur->right = stk.top();
            cur->left = NULL;
        }
    }


    // METHOD - 3 // TC - O(N) // SC - O(1)
    // Using linked list concept
    void flatternBT3(node* root) {
        node* cur = root;
        while (cur) {
            if (cur->left) {
                node* rightMost = cur->left;
                while (rightMost->right) rightMost = rightMost->right;
                rightMost->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }

    }

};



int32_t main() {
    fastIO();
    // Solution sol;

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


    Solution6 sol6;
    Solution7 sol7;
    Solution8 sol8;


    /*
    {
        vi pre4, pre5;
        sol6.preOrder(root, pre4);
        PRT(pre4);

        string data = sol6.serialize(root);
        cout<<data<<nl;

        node *root6 = sol6.deserialize(data);
        sol6.preOrder(root6, pre5);
        PRT(pre5);
    }
    cout<<nl;
    */

    {
        vi pre5, pre6, in5, in6;
        sol6.inOrder(root, in5);
        sol6.preOrder(root, pre5);

        in6 = sol7.getInOrderMorris(root);
        pre6 = sol7.getPreOrderMorris(root);
        PRT(in5);  // 4 2 5 1 6 3 7
        PRT(in6);  // 4 2 5 1 6 3 7 
        PRT(pre5); // 1 2 4 5 3 6 7 
        PRT(pre6); // 1 2 4 5 3 6 7


        node* root7 = sol7.copyBT(root);
        vi pre9;
        sol6.preOrder(root7, pre9);
        PRT(pre9); // 1 2 4 5 3 6 7
    }
    cout << nl;






    node* root8 = sol7.copyBT(root);
    sol8.flatternBT1(root8);
    vi pre7, pre8;
    sol6.preOrder(root, pre7);
    sol6.preOrder(root8, pre8);
    PRT(pre7); // 1 2 4 5 3 6 7 
    PRT(pre8); // 1 2 4 5 3 6 7


    node* root9 = sol7.copyBT(root);
    sol8.flatternBT2(root9);
    vi pre10;
    sol6.preOrder(root9, pre10);
    PRT(pre10); // 1 2 4 5 3 6 7

    node* root10 = sol7.copyBT(root);
    sol8.flatternBT3(root10);
    vi pre11;
    sol6.preOrder(root10, pre11);
    PRT(pre11); // 1 2 4 5 3 6 7




    return 0;
}




