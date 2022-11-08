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

// Related to game theory

// QUE :- The Game // https://www.spoj.com/problems/QCJ3/   
// Normal game :- person who picks coin last, wins the game
class Solution {

public:
    void solve(int n, vi& nums) {
        int XOR = 0;
        for (int i = 1; i <= n; i++) {
            // Assume each coin as a pile
            // and height of pile is index of nums array (1-based indexing)
            // then XOR = XOR^( xor(all the heights) )

            // in this case for a particular height i, if no_of_piles is even then it will contribute 0 to our our XOR
            int height = i;
            int no_of_piles = nums[i];

            if ((no_of_piles % 2) == 0) XOR ^= 0;
            else XOR ^= height;
        }
        if (XOR != 0) cout << "Tom Wins" << nl;
        else cout << "Hanks Wins" << nl;
    }

};





// QUE :- M&M Game  //   https://www.spoj.com/problems/MMMGAME/
// Misere game :- person who picks coin last, loses the game
class Solution2 {

public:
    void solve(int n, vi& nums) {
        int XOR = 0;
        int allOne = 1;
        for (auto t : nums) {
            XOR ^= t;
            if (t != 1) allOne = 0;
        }

        if (allOne) {
            if ((n & 1)) cout << "Brother" << nl;
            else cout << "John" << nl;
        } else {
            if (XOR != 0) cout << "John" << nl;
            else cout << "Brother" << nl;
        }
    }
};





int32_t main() {
    fastIO();

    {
        Solution sol;
        vi nums;

        wt(t) {
            int n; cin >> n;
            nums.resize(n + 1);
            for (int i = 1; i <= n; i++) cin >> nums[i];
            sol.solve(n, nums);
        }
    }



    {
        Solution2 sol2;
        vi nums;

        wt(t) {
            int n; cin >> n;
            nums.resize(n);
            for (auto& x : nums) cin >> x;
            sol2.solve(n, nums);

        }
    }

    return 0;
}

