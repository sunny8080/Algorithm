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



// Heap - It is complete binary tree [ almost complete binary tree + perfect binary tree (PBT) ] // and stored as an array
// maximum nodes at any height h = 2^h (h is from above)
// maximum nodes at any height h = ceil(N/2^(h+1)) (h is from below) // leaf nodes are at height = 0
// maximum nodes in the entire PBT = max size of the array of PBT = (2^(h+1) - 1 )
// in perfect binary tree, h = log2N
// height of PBT, h = floor(log2N)


// if indexing is based on 0 
// parent is i // left child = 2*i+1  // right child = 2*i+2
// parent(i) = floor((i-1)/2) = ceil(i/2) - 1
// range of leaves - [floor(N/2) to (N-1)]
// range of internal nodes - [0 to floor(N/2)-1]

// if indexing is based on 1 
// parent is i // left child = 2*i  // right child = 2*i+1
// parent(i) = floor((i-1)/2) + 1 = floor(i/2) 
// range of leaves - [floor(N/2)+1 to (N)]
// range of internal nodes - [1 to floor(N/2)]



// Types :-
// 1) Max heap - root node should always be greater than left and right node // all nodes follows the same
// 2) Min heap - root node should always be lesser than left and right node // all nodes follows the same

// Heapify - the process of rearranging the heap by comparing each parent with its children recursively is known as heapify 
// we can heapify index i, if all elements on the left and right subtree follow heap property




// max heap // 0 indexed
class maxHeap {

public:
    // heapify // TC - O(logN) // SC - O(logn)
    // place the node cur to the correct position in the tree
    void heapifyMax(vector<int>& heap, int cur, int size) {
        if (size == 0) return;
        int largest = cur;
        int left = 2 * cur + 1; // left child 
        int right = 2 * cur + 2; // right child

        if (left<size && heap[left] > heap[largest]) largest = left;
        if (right<size && heap[right] > heap[largest]) largest = right;

        if (largest != cur) {
            swap(heap[cur], heap[largest]);
            heapifyMax(heap, largest, size);
        }
    }


    // build heap // TC - O(N) // SC - O(logn) // Bottom - up // not O(N*logN) X //
    vector<int> buildHeap(vi& nums) {
        vi heap = nums;
        int n = heap.size();

        // traverse all internal nodes [(n/2 -1)  to  0] // becoz leaf nodes are already sorted
        for (int i = n / 2 - 1; i >= 0; i--) heapifyMax(heap, i, n);


        // vi heap;
        // for (auto x : nums) insert(heap, x);

        return heap;
    }


    // heap sort - sorting using heap // O(NlogN)
    void heapSort(vector<int>& nums) {
        vector<int> heap = buildHeap(nums);
        int size = heap.size();

        for (int i = size - 1; i > 0; i--) {
            swap(heap[0], heap[i]);
            heapifyMax(heap, 0, i);
        }

        // while(size>1){
        //     swap(heap[0], heap[size-1]);
        //     size--;
        //     heapifyMax(heap, 0, size);
        // } 

        nums = heap;
    }


    // pop / delete / extract max // TC - O(logN) // SC - O(logn)
    int extractMax(vi& heap) {
        int n = heap.size();
        if (n == 0) return INT_MIN;
        int ans = heap[0];

        swap(heap[0], heap[n - 1]);
        heap.pop_back(), n--;

        heapifyMax(heap, 0, n - 1);
        return ans;
    }



    // find max // O(1)
    int findMax(vi& heap) {
        return heap.size() ? heap[0] : INT_MIN;
    }



    // find min // O(N)
    int findMin(vi& heap, int ind = 0) {
        int l = 2 * ind + 1, r = 2 * ind + 2, n = heap.size();
        if (n == 0 or ind >= n) return INT_MAX;

        // check it is leaf node 
        if (l >= n) return heap[ind];

        int left = findMin(heap, l);
        int right = findMin(heap, r);
        return min(left, right);
    }



    // heap push // insert an element at last level from left to right // TC - O(logN) // SC - O(1) // bottom up
    void insert(vi& heap, int val) {
        // add at the last and percolate up
        heap.push_back(val); // push element to end of the heap

        int cur = heap.size() - 1, par = (cur - 1) / 2;
        // percolate-up
        while (cur > 0 && heap[par] < heap[cur]) {
            swap(heap[par], heap[cur]);
            cur = par;
            par = (cur - 1) / 2;
        }
    }



    // increase key - set value at index to a higher val inc // TC - O(logN) // SC - O(1) // bottom up
    int increaseKey(vi& heap, int ind, int inc) {
        // if value is alredy higher
        if (heap[ind] > inc) return INT_MAX;

        int prev = heap[ind];
        int cur = ind, par = (cur - 1) / 2;
        while (cur > 0 && heap[cur] > heap[par]) {
            swap(heap[cur], heap[par]);
            cur = par;
            par = (cur - 1) / 2;
        }

        return prev;
    }


    // decrease key - set value at index to a lower val dec // TC - O(logN) // SC - O(logN) // top down
    int decreaseKey(vi& heap, int ind, int dec) {
        // if value is alredy lower
        if (heap[ind] < dec) return INT_MAX;

        int prev = heap[ind];
        heap[ind] = dec;
        heapifyMax(heap, ind, heap.size());
        return prev;
    }

    // delete random element // O(N)
    // search random element // O(N)


};



class maxHeap2 {
public:
    int arr[N + 1];
    int size = 0;


    void insert(int val) {
        if (size >= N) return;
        arr[size++] = val;
        int cur = size - 1, par = (cur - 1) / 2;
        while (cur > 0 && arr[par] < arr[cur]) {
            swap(arr[cur], arr[par]);
            cur = par;
            par = (cur - 1) / 2;
        }
    }

    void print() {
        for (int i = 0;i < size; i++) cout << arr[i] << sp;
        cout << nl;
    }

    int deleteOrPop() {
        if (size == 0) return INT_MIN;
        int maxi = arr[0];
        size--;

        int cur = 0;
        while (cur < size) {
            int largest = cur, left = 2 * cur + 1, right = 2 * cur + 2;

            if (left < size && arr[left] > arr[largest]) largest = left;
            if (right < size && arr[right] > arr[largest]) largest = right;

            if (largest != cur) {
                swap(arr[largest], arr[cur]);
                cur = largest;
            } else {
                break;
            }
        }
        return maxi;
    }

};





// Min heap
class minHeap {

public:
    void heapifyMin(vector<int>& heap, int ind, int size) {
        if (size == 0) return;
        int left = 2 * ind + 1, right = 2 * ind + 2, smallest = ind;

        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;

        if (smallest != ind) {
            swap(heap[smallest], heap[ind]);
            heapifyMin(heap, smallest, size);
        }
    }

    int extractMin(vector<int>& heap) {
        int n = heap.size();
        if (n == 0) return INT_MAX;
        int mini = heap[0];
        heap[0] = heap[n - 1];
        heap.pop_back();
        heapifyMin(heap, 0, heap.size());
        return mini;
    }

    void insert(vector<int>& heap, int val) {
        heap.push_back(val);
        int cur = heap.size() - 1, par = (cur - 1) / 2;
        while (cur > 0 && heap[par] > heap[cur]) {
            swap(heap[cur], heap[par]);
            cur = par;
            par = (cur - 1) / 2;
        }
    }

    vector<int> buildMinHeap(vector<int>& nums) {
        vector<int> heap = nums;
        int n = heap.size();
        for (int i = n / 2 - 1; i >= 0; i--) heapifyMin(heap, i, n);
        return heap;
    }

};





int32_t main() {
    fastIO();
    maxHeap mxHp2;

    {
        maxHeap mxHp1;
        vi nums = { 50, 55, 53, 52, 54 };
        vi heap = mxHp1.buildHeap(nums);
        PRT(heap); // 55 54 53 52 50 // or // 55 54 53 50 52

        cout << mxHp1.findMax(heap) << nl; // 55
        cout << mxHp1.findMin(heap) << nl; // 50
        cout << mxHp1.extractMax(heap) << nl; // 55
        PRT(heap);

        PRT(nums); // 50 55 53 52 54 
        mxHp1.heapSort(nums);
        PRT(nums); // 52 53 54 55 50
    }
    cout << nl;


    {
        minHeap minHp;
        vi nums = { 50, 55, 53, 52, 54 };
        vi heap = minHp.buildMinHeap(nums);
        PRT(heap);



    }
    cout << nl;

    {
        // stl heap in c++ - priority queue // default max heap
        vi nums = { 50, 55, 53, 52, 54 };
        priority_queue<int> pq1; // max heap
        for (auto x : nums) pq1.push(x);
        cout << pq1.top() << nl;  // 55
        cout << pq1.size() << nl; // 5


        priority_queue<int, vector<int>, greater<int> > pq2; // min heap
        for (auto x : nums) pq2.push(x);
        cout << pq2.top() << nl;  // 50
        cout << pq2.size() << nl; // 5

    }
    cout << nl;




    return 0;
}




