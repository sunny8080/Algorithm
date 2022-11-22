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



struct node {
	int data;
	node* left, * right;
	node():data(0), left(NULL), right(NULL) {};
	node(int val) { data = val, left = right = NULL; }
	node(int val, node* left, node* right):data(val), left(left), right(right) {};
};


class Solution {

public:
	// return node containing data as val // iterative approach 
	// TC - O(logN) // SC - O(1)
	node* searchNode1(node* root, int val) {
		while (root && root->data != val) {
			root = (val < root->data) ? root->left : root->right;
		}
		return root;
	}


	// return node containing data as val // recursive approach 
	// TC - O(logN) // SC - O(logN)
	node* searchNode2(node* root, int val) {
		if (!root || root->data == val) return root;
		if (val < root->data) return searchNode2(root->left, val);
		return searchNode2(root->right, val);
	}


	// return ceil of key // a minimum val such that, val >= key
	int findCeil(node* root, int key) {
		int ceil = -1;
		while (root) {
			if (root->data == key) return root->data;
			if (key > root->data) root = root->right;
			else {
				ceil = root->data;
				root = root->left;
			}
		}
		return ceil;
	}


	// return floor of key // a maximum val such that, val <= key
	int findFloor(node* root, int key) {
		int floor = -1;
		while (root) {
			if (root->data == key) return root->data;
			if (root->data > key) root = root->left;
			else {
				floor = root->data;
				root = root->right;
			}
		}
		return floor;
	}


	// insert a val in BST // O(logN) // Iterative approach // O(logN)
	// return updated node // duplicates are not allowed
	node* insertNode1(node* root, int val) {
		if (!root) return new node(val);
		node* cur = root;

		while (1) {
			// duplicate are not allowed
			if (val == cur->data) break;
			else if (val < cur->data) {
				if (cur->left) cur = cur->left;
				else {
					cur->left = new node(val);
					break;
				}
			} else {
				if (cur->right) cur = cur->right;
				else {
					cur->right = new node(val);
					break;
				}
			}
		}

		return root;
	}


	// insert a val in BST // O(logN) // Recursive approach // O(logN)
	// return updated node // duplicates are not allowed
	node* insertNode2(node* root, int val) {
		if (!root) return new node(val);
		if (val < root->data) root->left = insertNode2(root->left, val);
		else if (val > root->data) root->right = insertNode2(root->right, val);
		return root;
	}


	node* buildBST(vi& nums) {
		node* root = NULL;
		for (auto x : nums) {
			root = insertNode1(root, x);
			// root = insertNode2(root, x);
		}
		return root;
	}



	// delete a node, if presence // O(H) // H - ht of BST
	node* deleteNode(node* root, int val) {
		if (!root) return NULL;
		if (root->data == val) return deleteNode_help(root);

		node* dummy = root;
		while (root) {
			if (val < root->data) { // go left
				if (root->left && root->left->data == val) { // found
					root->left = deleteNode_help(root->left);
					break;
				} else {
					root = root->left;
				}
			} else { // go right
				if (root->right && root->right->data == val) { // found
					root->right = deleteNode_help(root->right);
					break;
				} else {
					root = root->right;
				}
			}
		}
		return dummy;
	}

	// update left and right nodes of deleted node 
	node* deleteNode_help(node* del) {
		if (!del->left) return del->right;
		if (!del->right) return del->left;

		node* rightChild = del->right;
		node* lastRight = del->left;
		while (lastRight->right) lastRight = lastRight->right;
		lastRight->right = rightChild;
		return del->left;
	}



};



class Solution0 {

public:
	// Recurssive Approarch // TC - O(N) // SC - O(1)
	void preOrder(node* root, vi& nums) {
		if (root) {
			nums.push_back(root->data);
			preOrder(root->left, nums);
			preOrder(root->right, nums);
		}
	}

	vi preOrder0(node* root) {
		vi nums;
		preOrder(root, nums);
		return nums;
	}

	// Recurssive Approarch// TC - O(N) // SC - O(1)
	void inOrder(node* root, vi& nums) {
		if (root) {
			inOrder(root->left, nums);
			nums.push_back(root->data);
			inOrder(root->right, nums);
		}
	}

	vi inOrder0(node* root) {
		vi nums;
		preOrder(root, nums);
		return nums;
	}


	// Recurssive Approarch // TC - O(N) // SC - O(1)
	void postOrder(node* root, vi& nums) {
		if (root) {
			postOrder(root->left, nums);
			postOrder(root->right, nums);
			nums.push_back(root->data);
		}
	}

	vi postOrder0(node* root) {
		vi nums;
		postOrder(root, nums);
		return nums;
	}



	// TC - O(N) // SC - O(N)
	vi levelOrder(node* root) {
		vi nums;
		vvi ans;
		if (!root) return nums;
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

		// // return level order traversal level wise
		// return ans; 

		for (auto x : ans) for (auto y : x) nums.push_back(y);
		return nums;
	}
};




class Solution2 {

public:
	int noOfNodes(node* root) {
		int cnt = 0;
		if (!root) return cnt;
		// do preorder traversal
		stack<node*> stk;
		stk.push(root);

		while (!stk.empty()) {
			root = stk.top();
			stk.pop();
			cnt++;

			if (root->right) stk.push(root->right);
			if (root->left) stk.push(root->left);
		}
		return cnt;
	}



	// do in order traversal
	node* findKthSmallest_help(node* root, int& k) {
		if (!root) return NULL;

		node* left = findKthSmallest_help(root->left, k);
		if (left) return left;

		if (--k == 0) return root;

		return findKthSmallest_help(root->right, k);;
	}

	// return kth smallest node in the BST
	// do in order traversal
	node* findKthSmallest(node* root, int k) {
		return findKthSmallest_help(root, k);
	}






	// do inverse in order traversal
	node* findKthLargest_help(node* root, int& k) {
		if (!root) return NULL;

		node* right = findKthLargest_help(root->right, k);
		if (right) return right;

		if (--k == 0) return root;

		return findKthLargest_help(root->left, k);
	}



	// return kth largest node in the BST
	// do inverse in order traversal
	// or find (n-k+1)th smallest node in the BST
	node* findKthLargest(node* root, int k) {
		// int n = noOfNodes(root);
		// return findKthSmallest(root, n - k + 1);
		return findKthLargest_help(root, k);
	}


	bool isValidBST_help(node* root, int minVal, int maxVal) {
		if (!root) return true;
		if (root->data <= minVal and root->data >= maxVal) return false;
		return isValidBST_help(root->left, minVal, maxVal) && isValidBST_help(root->right, root->data, maxVal);
	}

	// check given tree is BST or not
	bool isValidBST(node* root) {
		return isValidBST_help(root, INT_MIN, INT_MAX);
	}

};




class Solution3 {

public:
	// LCA - Lowest common ancestor // TC - O(H) // SC - O(1)
	node* findLca(node* root, node* p, node* q) {
		if (!root) return NULL;
		// find 1st split, where p and q are on different side 
		if (root->data > p->data && root->data > q->data) return findLca(root->left, p, q);
		if (root->data < p->data && root->data < q->data) return findLca(root->right, p, q);
		return root;
	}


	node* buildBSTfromPreorder_help(vi& pre, int& ind, int upBound) {
		if (ind == pre.size() || pre[ind] > upBound) return NULL;
		node* root = new node(pre[ind++]);

		// build left subtree
		// for left child  : upper bound = parent->data
		// for right child : upper bound = parent->upBound
		root->left = buildBSTfromPreorder_help(pre, ind, root->data);
		root->right = buildBSTfromPreorder_help(pre, ind, upBound);
		return root;
	}


	// METHOD 1 - Traverse pre and find where each node should be inserted // TC - O(N^2) // SC - O(N)
	// METHOD 2 - after sorting pre becomes inorder, now create BST from pre and in 
	// TC - O(NlogN + N) // SC - O(N) 
	// METHOD 3 - use upper bound concept // TC - O(N) // SN - O(1)
	node* buildBSTfromPreorder(vi& pre) {
		int ind = 0;
		return buildBSTfromPreorder_help(pre, ind, INT_MAX);
	}



	// METHOD 1 - do inorder traversal ==> ans = first val > val // TC - O(N) // SC - O(1)
	// METHOD 2 - think about what successor is  // TC - O(H) // SC - O(1)
	node* inorderSuccessor(node* root, node* p) {
		node* ans = NULL;
		while (root) {
			if (root->data <= p->data) root = root->right;
			else {
				// may be this is the Successor
				ans = root;
				root = root->left;
			}
		}
		return ans;
	}



	// METHOD 1 - do inorder traversal ==> ans = first val > val // TC - O(N) // SC - O(1)
	// METHOD 2 - think about what predecesoor is  // TC - O(H) // SC - O(1)
	node* inorderPredecesoor(node* root, node* p) {
		node* ans = NULL;
		while (root) {
			if (root->data < p->data) {
				// may be this is the predecesoor
				ans = root;
				root = root->right;
			} else {
				root = root->left;
			}
		}
		return ans;
	}

};






// we can use reverse bool technique to use 1 class as two class
// instead of creating two function
class BSTIterator {
	stack<node*> stk;
	stack<node*> stk2;
public:
	BSTIterator(node* root) {
		pushAllLeft(root);
		pushAllRight(root);
	}

	void pushAllLeft(node* root) {
		for (; root; stk.push(root), root = root->left);
	}

	void pushAllRight(node* root) {
		for (; root; stk2.push(root), root = root->right);
	}

	// check we have a next smallest element or not
	bool hasNext() {
		return !stk.empty();
	}

	// check we have a next largest element or not
	bool hasPrev() {
		return !stk2.empty();
	}

	// return the next smallest element
	// Inorder traversal - [ left root right] -> ascending order
	int next() {
		if (!hasNext()) return INT_MAX;
		node* tmp = stk.top();
		stk.pop();

		// push all left nodes of current nodes
		pushAllLeft(tmp->right);
		return tmp->data;
	}

	// return the next largest element
	// inverse Inorder traversal - [ right root left] -> descending order
	int prev() {
		if (!hasPrev()) return INT_MAX;
		node* tmp = stk2.top();
		stk2.pop();

		// push all left nodes of current nodes
		pushAllRight(tmp->left);
		return tmp->data;
	}

};




class Solution4 {

public:
	// return true if it is possible to add two no of BST which gives the result k
	// METHOD 1 - apply two pointers approach on preorder of BST // TC - O(N) // SC - O(N)
	// METHOD 2 - apply two pointers approach on BST iterator (next, prev) // TC - O(N) // SC - O(H)
	bool twoSumPossible(node* root, int k) {
		if (!root) return false;

		BSTIterator bit(root);

		int l = bit.next(), r = bit.prev();
		while (l < r) {
			if (l + r == k) return true;
			else if (l + r < k) l = bit.next();
			else r = bit.prev();
		}
		return false;
	}






	node* prev, * first, * middle, * last; // used in recoverBST_help

	// do inorder traversal
	void recoverBST_help(node* root) {
		if (!root) return;
		recoverBST_help(root->left);

		// prev is the node just after root comes // i.e [ ... prev, root, ... ]
		// mismatched found // becoz in inorder root->data > prev->data
		if (prev && root->data < prev->data) {
			// if this is first violation/mismatched nodes
			if (first == NULL) {
				first = prev;
				middle = root;
			} else {
				// if this is second violation, mark this node as last
				last = root;
			}
		}

		// mark this node as previous
		prev = root;
		recoverBST_help(root->right);
	}





	// it is given that two nodes of BST are swapped // so recover BST from given incorrect BST
	// METHOD 1 - do inorder traversal after that match BST with preorder, if some nodes 
	// don't match change the value of node of BST // TC - O(NlogN + N) // SC - O(N)
	// METHOD 2 - do inorder traversal and on middle find mismatched nodes // TC - O(N) // SC - O(N)
	node* recoverBST(node* root) {
		first = middle = last = NULL;
		prev = new node(INT_MIN);
		recoverBST_help(root);

		// if mismatched found swap it
		// case 1- mismatched nodes are first and last
		// else case 2- mismatched nodes are first and middle
		if (first && last) swap(first->data, last->data);
		else if (first && middle)swap(first->data, middle->data);
		return root;
	}




};




int32_t main() {
	fastIO();
	Solution0 sol0;
	Solution sol;
	Solution2 sol2;
	Solution3 sol3;
	Solution4 sol4;


	vi nums = { 4, 8, 2, 1, 3, 10, 20, 10 };
	node* root = sol.buildBST(nums);

	/*
	{
		PRT(sol0.preOrder0(root));  // 4 2 1 3 8 10 20
		PRT(sol0.postOrder0(root)); // 1 3 2 20 10 8 4
		PRT(sol0.inOrder0(root));   // 1 2 3 4 8 10 20
		PRT(sol0.levelOrder(root)); // 4 2 8 1 3 10 20

		// node *tmp1 = sol.searchNode1(root, 20);
		node* tmp1 = sol.searchNode2(root, 20);
		// node *tmp2 = sol.searchNode1(root, 25);
		node* tmp2 = sol.searchNode2(root, 25);
		cout << tmp1->data << nl; // 20
		cout << (tmp2 == NULL) << nl; // 1

		cout << sol.findCeil(root, 18) << nl; // 20
		cout << sol.findCeil(root, 100) << nl; // -1
		cout << sol.findFloor(root, 9) << nl; // 8
		cout << sol.findFloor(root, -5) << nl; // -1

		root = sol.deleteNode(root, 2);
		PRT(sol0.levelOrder(root)); // 4 1 8 3 10 20
	}
	cout<<nl;
	*/


	/*
	{
		cout << sol2.findKthSmallest(root, 5)->data << nl; // 8
		cout << (sol2.findKthSmallest(root, 10) == NULL) << nl; // 1
		cout << sol2.findKthLargest(root, 5)->data << nl; // 3
		cout << (sol2.findKthLargest(root, 10) == NULL) << nl; // 1
		cout << sol2.noOfNodes(root) << nl; // 7
		cout << sol2.isValidBST(root) << nl; // 1
	}
	cout<<nl;
	*/



	{
		node* p = sol.searchNode1(root, 3);
		node* q = sol.searchNode1(root, 10);
		cout << sol3.findLca(root, p, q)->data << nl; // 4

		vi pre = sol0.preOrder0(root);
		node* root2 = sol3.buildBSTfromPreorder(pre);
		PRT(sol0.preOrder0(root2)); // 4 2 1 3 8 10 20

		cout << sol3.inorderSuccessor(root, sol.searchNode1(root, 10))->data << nl; // 20
		cout << sol3.inorderPredecesoor(root, sol.searchNode1(root, 10))->data << nl; // 8
	}
	cout << nl;



	/*
	{
		BSTIterator bit(root);
		cout << bit.next() << nl; // 1
		cout << bit.next() << nl; // 2
		cout << bit.next() << nl; // 3
		cout << bit.hasNext() << nl; // 1

		cout << bit.prev() << nl; // 20
		cout << bit.prev() << nl; // 10
		cout << bit.prev() << nl; // 8
		cout << bit.hasPrev() << nl; // 1
	}
	cout << nl;
	*/

	{
		cout << sol4.twoSumPossible(root, 30) << nl; // 1
		cout << sol4.twoSumPossible(root, 100) << nl; // 0

		node *root3 = sol4.recoverBST(root);
		PRT(sol0.inOrder0(root3)); // 4 2 1 3 8 10 20
	}







	return 0;
}




