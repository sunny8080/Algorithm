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




// stack using array // LIFO - last in first out
class Stack {
    int top, * arr, cap;
public:
    Stack(int cap) {
        top = -1;
        this->cap = cap;
        arr = new int[cap];
    }

    int push(int x) {
        if (top == cap - 1) return INT_MAX; // overflow 
        arr[++top] = x;
    }

    int pop() {
        return (top != -1 ? arr[top--] : INT_MAX);
    }

    bool isEmpty() {
        return top == -1;
    }

    int topp() {
        return (top != -1 ? arr[top] : INT_MAX);
    }

    int size() {
        return top + 1;
    }

    void sortStack(stack<int>& stk) {
        if (stk.empty()) return;
        int top = stk.top();
        stk.pop();
        sortStack(stk);
        stack<int> tmp;
        while (!stk.empty() && stk.top() > top) tmp.push(stk.top()), stk.pop();
        stk.push(top);
        while (!tmp.empty()) stk.push(tmp.top()), tmp.pop();
    }

    void print(stack<int>& stk) {
        stack<int> tmp = stk;
        while (!tmp.empty()) cout << tmp.top() << sp, tmp.pop();
        cout << nl;
    }
};



// queue using array // FIFO - First in first out
class Queue {
    int front, rear, * arr, cap, curSize;
public:
    Queue(int cap) {
        front = rear = -1;
        this->cap = cap;
        arr = new int[cap];
        curSize = 0;
    }

    int push(int x) {
        if (curSize == cap) return INT_MAX;
        if (front == -1) front = 0;
        arr[(++rear) % cap] = x;
        curSize++;
    }

    int pop() {
        if (front == -1) return INT_MAX;
        int popped = arr[front];
        if (curSize == 1) front = rear = -1;
        else front = (front + 1) % cap;
        curSize--;
        return popped;
    }

    bool isEmpty() {
        return front == -1;
    }

    int size() {
        return curSize;
    }

    int frontt() {
        return (front == -1 ? INT_MAX : arr[front]);
    }

    int back() {
        return (rear == -1 ? INT_MAX : arr[rear]);
    }
};




// Stack using Queue
// QUE : https://leetcode.com/problems/implement-stack-using-queues/
class MyStack {
    queue<int> q;
public:
    void push(int x) {
        // // using two queue
        // queue<int> tmp;
        // tmp.push(x);
        // while (q.size()) tmp.push(q.front()), q.pop();
        // q = tmp;

        // using one queue
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) q.push(q.front()), q.pop();
    }

    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};



// Queue using stack
// QUE :- https://leetcode.com/problems/implement-queue-using-stacks/
class MyQueue1 {
    stack<int> stk;
public:
    void push(int x) {
        stack<int> tmp;
        while (stk.size()) tmp.push(stk.top()), stk.pop();
        tmp.push(x);
        while (tmp.size()) stk.push(tmp.top()), tmp.pop();
    }

    int pop() {
        int ans = stk.top();
        stk.pop();
        return ans;
    }

    int peek() {
        return stk.top();
    }

    bool empty() {
        return stk.empty();
    }
};



// Queue using stack // time complexity amortized 
class MyQueue {
    stack<int> input, output;
public:
    void push(int x) {
        input.push(x);
    }

    int pop() {
        if (output.empty()) {
            while (input.size()) output.push(input.top()), input.pop();
        }
        int ans = output.top();
        output.pop();
        return ans;
    }

    int peek() {
        if (output.empty()) {
            while (input.size()) output.push(input.top()), input.pop();
        }
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};











int32_t main() {
    fastIO();
    // Solution sol;


    /*
    {
        Stack stk(5);
        stk.push(4);
        stk.push(7);
        stk.push(9);
        cout << stk.pop() << nl; // 9
        cout << stk.size() << nl; // 2
        cout << stk.pop() << nl; // 7
        cout << stk.pop() << nl; // 4
        cout << stk.pop() << nl; // 2147483647


        // STL
        stack<int> stk2;
        stk2.push(4);
        stk2.push(7);
        stk2.push(9);
        cout << stk2.top() << nl; // 9
        stk2.pop();
        cout << stk2.top() << nl; // 7

    }
    cout<<nl;
    */



    /*
    {
        Queue q1(5);
        q1.push(4);
        q1.push(7);
        q1.push(9);
        cout << q1.pop() << nl; // 4
        cout << q1.size() << nl; // 2
        cout << q1.frontt() << nl; // 7
        cout << q1.pop() << nl; // 7
        cout << q1.pop() << nl; // 9
        cout << q1.pop() << nl; // 2147483647


        queue<int> q2;
        q2.push(4);
        q2.push(7);
        q2.push(9);
        cout << q2.front() << nl; // 4
        q2.pop();
        cout << q2.size()<< nl; // 2
        cout << q2.front() << nl; // 7
    }
    */


    return 0;
}




