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

// Interactive problems

// To flush the buffer
// fflush(stdout);       in c++ ()(if using printf scanf)
// cout<<flush;          in c++ ()(if using cin cout)
// System.out.flush();   in Java
// stdout.flush()        in python

// endl actually works as cout<<'\n'<<flush;






// QUE :- https://codeforces.com/problemset/gymProblem/101021/1
class Solution1 {
    // return 0, if get the input < 
    // return 1, if get the input >= 
    int query(int mid) {
        cout << mid << endl;
        string s; cin >> s;
        if (s == "<") return 0;
        return 1;
    }
public:
    void solve() {
        int l = 1, r = 1e6, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (query(mid) == 0) {
                r = mid - 1;
            } else {
                ans = mid;
                l = mid + 1;
            }
        }
        cout << "! " << ans << endl;
    }
};





// QUE :- https://codeforces.com/problemset/problem/1167/B
class Solution2 {
    int query(int i, int j) {
        cout << "? " << i << sp << j << endl;
        int t; cin >> t;
        return t;
    }
public:
    void solve() {
        vi nums = { 4, 8, 15, 16, 23, 42 };
        vi a(4);

        for (int i = 0; i < 4; i++) {
            a[i] = query(i + 1, i + 2);
        }

        do {
            int can = 1;
            for (int i = 0; i <= 3; i++) {
                if (nums[i] * nums[i + 1] != a[i]) {
                    can = 0;
                    break;
                }
            }
            if (can) {
                cout << "! ";
                for (auto x : nums) cout << x << sp;
                cout << endl;
                break;
            }
        } while (next_permutation(nums.begin(), nums.end()));
    }
};





// QUE :- https://codeforces.com/problemset/problem/1207/E
class Solution3 {
public:
    void solve() {
        cout << "? " << nl;
        for (int i = 1; i <= 100; i++) {
            cout << i << sp;
        }
        cout << endl;
        int n1; cin >> n1;

        cout << "? " << nl;
        for (int i = 1; i <= 100; i++) {
            int t = (i << 7);
            cout << t << sp;
        }
        cout << endl;
        int n2; cin >> n2;

        int x = 0;
        for (int i = 0; i < 7; i++) {
            if ((n2 >> i) & 1) x |= (1 << i);
        }
        for (int i = 7; i < 14; i++) {
            if ((n1 >> i) & 1) x |= (1 << i);
        }
        cout << "! " << x << endl;
    }
};








int main() {
    fastIO();

    {
        Solution1 sol1;
        sol1.solve();
    }


    {
        Solution2 sol2;
        sol2.solve();
    }

    {
        Solution3 sol3;
        sol3.solve();
    }


    return 0;
}

