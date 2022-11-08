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


// QUE :- https://leetcode.com/problems/lfu-cache/
// Soln :- https://youtu.be/0PSB9y8ehbk?list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj
// Soln :- https://youtu.be/mzqHlAW7jeE?list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj


struct node {
    int key, val, fre;
    node* next, * prev;
    node(int key, int val) {
        tie(this->key, this->val, this->fre) = make_tuple(key, val, 1);
        prev = next = NULL;
    }
};


struct List {
    int size;
    node* head, * tail;
    List() {
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(node* newnode) {
        newnode->next = head->next;
        newnode->prev = head;
        head->next->prev = newnode;
        head->next = newnode;
        size++;
    }

    void removeNode(node* delnode) {
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
        size--;
    }
};


class LFUCache {
    map<int, node*> keyNode;
    map<int, List*> freqListMap;
    int size;
    int cap;
    int minFreq;

    void updateFrqListMap(node* nod) {
        freqListMap[nod->fre]->removeNode(nod);
        if (nod->fre == minFreq && freqListMap[minFreq]->size == 0) {
            minFreq++;
        }

        List* nextHigherFreqList = new List();
        if (freqListMap.find(nod->fre + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[nod->fre + 1];
        }
        nod->fre += 1;
        nextHigherFreqList->addFront(nod);
        freqListMap[nod->fre] = nextHigherFreqList;
        keyNode[nod->key] = nod;
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
        size = 0;
    }


    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) return -1;
        node* nod = keyNode[key];
        int val = nod->val;
        updateFrqListMap(nod);
        return val;
    }

    void put(int key, int value) {
        if (cap == 0) return;
        if (keyNode.find(key) != keyNode.end()) {
            node* nod = keyNode[key];
            nod->val = value;
            updateFrqListMap(nod);
        } else {
            if (size == cap) {
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                size--;
            }
            size++;

            minFreq = 1;
            List* listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            }

            node* nod = new node(key, value);
            listFreq->addFront(nod);
            keyNode[key] = nod;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */






int32_t main() {
    fastIO();

    LFUCache lfu(2);
    lfu.put(1, 1);
    lfu.put(2, 2);
    cout << lfu.get(1) << nl;
    lfu.put(3, 3);
    cout << lfu.get(2) << nl;
    cout << lfu.get(3) << nl;
    lfu.put(4, 4);
    cout << lfu.get(1) << nl;
    cout << lfu.get(3) << nl;
    cout << lfu.get(4) << nl;




    return 0;
}


// OUT:-
//
// 1
// - 1
// 3
// - 1
// 3
// 4