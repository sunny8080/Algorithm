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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}


// Persistent trie
// QUE :- https://www.codechef.com/problems/XRQRS



// All tries is numbered from [0 ... n] 
// trie[x] => root node of number x
// root[n] => gives the index of nth trie // n is the integer number
// so trie[root[n]] => root node of nth number
// new_ptr => new upcoming number of trie // it gives a new node index
// n => no of integers which is inserted



struct node {
    // lf = left = 0 // rt = right = 1 // cnt = no of numbers which starts from this node
    int lf, rt, cnt;
};

const ll N = 500005 * (20 + 2); // each insertion operation use 22 numbers
node trie[N];
int root[N]; // return index of trie



// Persistent tre
class persistentTrie {
    int new_ptr = 0;
    int n = 0;

public:

    persistentTrie() {
        // initial configuration
        root[0] = 0;
        trie[0].lf = trie[0].rt = trie[0].cnt = 0;
        new_ptr = 1;
        n = 1;
    }

    // insert x in trie
    void insert(int x) {
        int temp = new_ptr++;
        root[n] = temp;
        int prev = root[n - 1];
        int cur = temp;
        trie[cur] = trie[prev]; // copy previous trie
        n++;

        for (int bit = 20; bit >= 0; bit--) {
            int set = ((x >> bit) & 1);
            if (set) {
                int new_ind = new_ptr++; // create new nodes
                trie[new_ind] = trie[trie[prev].rt];
                trie[new_ind].cnt++;

                trie[cur].rt = new_ind;
                cur = new_ind;
                prev = trie[prev].rt;
            } else {
                int new_ind = new_ptr++; // create new nodes
                trie[new_ind] = trie[trie[prev].lf];
                trie[new_ind].cnt++;

                trie[cur].lf = new_ind;
                cur = trie[cur].lf;
                prev = trie[prev].lf;
            }
        }

        return;
    }




    // return y such that x^y is maximize in a range [l...r] // prev = root[l-1], cur = root[r]
    int max_xor(int l, int r, int x) {
        int prev = root[l - 1];
        int cur = root[r];
        int y = 0; // y is number such as x^y is max

        for (int bit = 20; bit >= 0; bit--) {
            int set = ((x >> bit) & 1);

            if (set) { // try to find 0
                if (trie[trie[cur].lf].cnt > trie[trie[prev].lf].cnt) { // if (r-l)>0, then there must be some no withinh range
                    cur = trie[cur].lf;
                    prev = trie[prev].lf;
                } else {
                    cur = trie[cur].rt;
                    prev = trie[prev].rt;
                    y += (1 << bit);
                }
            } else { // try to find 1
                if (trie[trie[cur].rt].cnt > trie[trie[prev].rt].cnt) { // if (r-l)>0, then there must be some no withinh range
                    cur = trie[cur].rt;
                    prev = trie[prev].rt;
                    y += (1 << bit);
                } else {
                    cur = trie[cur].lf;
                    prev = trie[prev].lf;
                }
            }
        }

        return y;
    }


    // delete last k numbers from array ( from persistent tree)
    void delete_last_k(int k) {
        n -= k;
    }


    // return no of number less than equal to x in a range [l...r] // prev = root[l-1], cur = root[r]
    int less_than_equal_to(int l, int r, int x) {
        int prev = root[l - 1];
        int cur = root[r];
        int cnt = 0;

        for (int bit = 20; bit >= 0; bit--) {
            int set = ((x >> bit) & 1);

            if (set) {
                cnt += trie[trie[cur].lf].cnt - trie[trie[prev].lf].cnt;
                cur = trie[cur].rt;
                prev = trie[prev].rt;
            } else {
                cur = trie[cur].lf;
                prev = trie[prev].lf;
            }
        }
        cnt += trie[cur].cnt - trie[prev].cnt;
        return cnt;
    }



    // return kth smallest integer in a range [l...r] // prev = root[l-1], cur = root[r]
    int kth_smallest(int l, int r, int k) {
        int prev = root[l - 1];
        int cur = root[r];
        int ans = 0;

        for (int bit = 20; bit >= 0; bit--) {
            if (trie[trie[cur].lf].cnt - trie[trie[prev].lf].cnt >= k) {
                // go to left
                cur = trie[cur].lf;
                prev = trie[prev].lf;
            } else {
                k -= (trie[trie[cur].lf].cnt - trie[trie[prev].lf].cnt);
                cur = trie[cur].rt;
                prev = trie[prev].rt;
                ans += (1 << bit);
            }
        }

        return ans;
    }

};



int32_t main() {
    fastIO();

    persistentTrie sol;

    wt(q) {
        int c; cin >> c; // case
        int l, r, x, k;

        if (c == 0) {
            cin >> x;
            sol.insert(x);

        } else if (c == 1) {
            cin >> l >> r >> x;
            cout << sol.max_xor(l, r, x) << nl;

        } else if (c == 2) {
            cin >> k;
            sol.delete_last_k(k);

        } else if (c == 3) {
            cin >> l >> r >> x;
            cout << sol.less_than_equal_to(l, r, x) << nl;

        } else if (c == 4) {
            cin >> l >> r >> k;
            cout << sol.kth_smallest(l, r, k) << nl;

        }
    }


    return 0;
}



// OUT :-

// 10
// 0 8
// 4 1 1 1
// 0 2
// 1 2 2 7
// 1 2 2 7
// 0 1
// 3 2 2 2
// 1 1 2 3
// 3 1 3 5
// 0 6
//
//
// 8
// 2
// 2
// 1
// 8
// 2

