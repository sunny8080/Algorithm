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


// QUE :- https://leetcode.com/problems/lru-cache/
// Soln :- https://youtu.be/xDEuM5qa0zg?list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj
// Soln :- https://youtu.be/Xc4sICC8m4M?list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj



struct node {
    int key, val;
    node* prev, * next;
    node(int key, int val) {
        tie(this->key, this->val) = make_tuple(key, val);
        prev = next = NULL;
    }
};



class LRUCache {
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int cap;
    unordered_map<int, node*> mpp;
    int size = 0;


    void addNode(node* newnode) {
        newnode->next = head->next;
        newnode->prev = head;
        head->next->prev = newnode;
        head->next = newnode;
        size++;
    }

    void deleteNode(node* delnode) {
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
        size--;
        // free(delnode);
    }


public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        // if (mpp.find(key) == mpp.end()) return -1;
        if (mpp[key] == 0) return -1;

        node* resnode = mpp[key];
        int res = resnode->val;
        deleteNode(resnode);
        addNode(resnode);
        mpp.erase(key);
        mpp[key] = head->next;
        return res;
    }

    void put(int key, int value) {
        // if (mpp.find(key) != mpp.end()) {
        if (mpp[key] != 0) {
            deleteNode(mpp[key]);
            // mpp.erase(key);
            addNode(new node(key, value));
            mpp[key] = head->next;
            return;
        }

        if (size == cap) {
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new node(key, value));
        mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */




int32_t main() {
    fastIO();
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout<<lru.get(1)<<nl;
    lru.put(3, 3);
    cout<<lru.get(2)<<nl;
    lru.put(4, 4);
    cout<<lru.get(1)<<nl;
    cout<<lru.get(3)<<nl;
    cout<<lru.get(4)<<nl;


    
    
    return 0;
}
    

// OUT:-
// 
// 1
// - 1
// - 1
// 3
// 4
    