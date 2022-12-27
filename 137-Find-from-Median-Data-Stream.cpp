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

const ll N = 1e8 + 0;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}





// QUE - https://leetcode.com/problems/find-median-from-data-stream/
// Soln - https://www.youtube.com/watch?v=1LkOrc-Le-Y&list=PLEJXowNB4kPyP2PdMhOUlTY6GrRIITx28&index=15



/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


 // METHOD -1 
class MedianFinder1 {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder1() {}

    void addNum(int num) {
        int lsize = maxHeap.size();
        int rsize = minHeap.size();

        if (lsize == 0) { // heap is empty // push on maxHeap sure
            maxHeap.push(num);
        } else if (lsize == rsize) { // maxHeap_size = minHeap_size // push on maxHeap sure
            if (num < minHeap.top()) {
                maxHeap.push(num);
            } else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
        } else { // maxHeap_size = minHeap_size+1 // push on the minHeap
            if (rsize == 0) {
                if (num >= maxHeap.top()) {
                    minHeap.push(num);
                } else {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(num);
                }
            } else if (num >= maxHeap.top()) {
                minHeap.push(num);
            } else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);

            }
        }

    }

    double findMedian() {
        int lsize = maxHeap.size();
        int rsize = minHeap.size();
        if (lsize > rsize) return (double)maxHeap.top();
        return (double)(maxHeap.top() + minHeap.top()) / 2;

    }
};






// METHOD -2 
class MedianFinder2 {
    priority_queue<long> maxHeap, minHeap;
public:
    MedianFinder2() {}

    void addNum(int num) {
        maxHeap.push(num);
        // -ve val used to convert maxheap to min heap // also for avoid overflow long is used
        minHeap.push(-maxHeap.top());
        maxHeap.pop();

        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(-minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        return maxHeap.size() > minHeap.size() ? (maxHeap.top()) : (maxHeap.top() - minHeap.top()) / 2.0;
    }
};




// METHOD -3
class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<long>> minHeap;
public:
    MedianFinder() {}

    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        return maxHeap.size() > minHeap.size() ? (maxHeap.top()) : (maxHeap.top() + minHeap.top()) / 2.0;
    }
};







/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */






int32_t main() {
    fastIO();


    MedianFinder1 sol1;
    MedianFinder2 sol2;
    MedianFinder sol3;

    sol3.addNum(2);
    sol3.addNum(3);
    cout << sol3.findMedian() << nl; // 2.5

    sol3.addNum(4);
    cout << sol3.findMedian() << nl; // 3

    sol3.addNum(5);
    sol3.addNum(6);
    cout << sol3.findMedian() << nl; // 4

    return 0;
}





