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

// Sprague–Grundy theorem
// QUE :- https://www.hackerrank.com/challenges/game-of-stones-1/problem


int grundy[1000];

class Solution {
    // mex() fun return min excludent // minimum non-neg number which is not in the set
    int calculateMex(unordered_set<int>& st) {
        int m = 0;
        while (st.find(m) != st.end()) m++;
        return m;
    }

    // A fun to compuet grundy num of n
    // Only this fun varies according to the game
    int calculateGrandNum(int n) {
        // base case
        if (n == 0) return 0;
        if (grundy[n] != -1) return grundy[n];

        // A hash table
        unordered_set<int> st;
        if (n >= 2) st.insert(calculateGrandNum(n - 2));
        if (n >= 3) st.insert(calculateGrandNum(n - 3));
        if (n >= 5) st.insert(calculateGrandNum(n - 5));
        return grundy[n] = calculateMex(st);
    }
public:
    void solve(int n) {
        int XOR = 0;
        XOR ^= calculateGrandNum(n);
        if (XOR) cout << "First" << nl;
        else cout << "Second" << nl;
    }


    void solve2(int n, vi& piles) {
        int XOR = 0;
        for (auto x : piles) {
            XOR ^= calculateGrandNum(x);
        }
        if (XOR != 0) cout << "Player 1 wins" << nl;
        else cout << "Player 2 wins" << nl;
    }
};



int32_t main() {
    fastIO();
    Solution sol;
    memset(grundy, -1, sizeof(grundy));

    // {
    //     wt(t) {
    //         int n; cin >> n;
    //         sol.solve(n);
    //     }
    // }


    {
        sol.solve(4); // First
        sol.solve(7); // Second
    }

    {
        int n = 4;
        vi piles = {4, 5, 7, 4}; 
        sol.solve2(n, piles); // Player 1 wins  
    }


    return 0;
}

