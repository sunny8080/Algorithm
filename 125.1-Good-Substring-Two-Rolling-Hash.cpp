#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll                 long long
#define int                long long
#define ull                unsigned long long
#define ff                 first
#define ss                 second
#define pb                 push_back
#define mp                 make_pair
#define pii                pair<int,int>
#define vi                 vector<int>
#define vll                vector<ll> 
#define vvi                vector< vector<int>>
#define vvll               vector< vector<ll>>
#define vpii               vector<pair<int,int>>
#define mii                map<int,int>
#define pqb                priority_queue<int>
#define pqs                priority_queue<int, vector<int>, greater<int>>
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define mod                1000000007
#define inf                1e18
#define ps(x,y)            fixed<<setprecision(y)<<x
#define mk(arr, n, type)   type *arr=new type[n];
#define wt(x)              int x; cin>>x; while( x-- )
#define sp                 ' '
#define nl                 char(10)
#define PRT(ar)            for( auto i : ar ) cout<<i<<sp; cout<<nl;
#define mems(x,ch)         memset(x,ch,sizeof(x))
#define sortv(x)           sort(x.begin(),x.end())
#define sortvr(x)          sort(x.rbegin(),x.rend())
#define all(x)             x.begin(), x.end()
#define fr(t,a,b)          for( int t=(a); t<=(b); t++)
#define frr(t,a,b)         for( int t=(a); t>=(b); t--)
#define cn(x)              int x; cin>>x;
#define ri(x)              cin >> x
#define rii(x, y)          cin >> x >> y
#define riii(x, y, z)      cin >> x >> y >> z
#define riiii(x, y, z, w)  cin >> x >> y >> z >> w
#define rv(nums)           for (auto& x : nums) cin >> x;
#define dri(x)             int x; cin >> x
#define drs(s)             string s; cin >> s
#define drii(x, y)         int x, y; cin >> x >> y
#define driii(x, y, z)     int x, y, z; cin >> x >> y >> z
#define driiii(x, y, z, w) int x, y, z, w; cin >> x >> y >> z >> w
#define drv(nums, n)       vector<int> nums(n); for (auto& x : nums) cin >> x;

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


// QUE :- https://codeforces.com/problemset/problem/271/D
// Focus on rolling hash with two prime to avoid collision



struct node {
    node* nxt[26];
    bool ended;
    int cnt;
    node() {
        for (int i = 0; i < 26; i++) nxt[i] = NULL;
        cnt = ended = 0;
    }
};

class Trie {
    node* root;
public:
    Trie() {
        root = new node();
    }


    void insert(string& s) {
        node* cur = root;
        for (auto ch : s) {
            int t = ch - 'a';
            if (cur->nxt[t] == NULL) cur->nxt[t] = new node();
            cur->cnt++;
            cur = cur->nxt[t];
        }
        cur->cnt++;
        cur->ended = 1;
    }

    bool search(string& s) {
        node* cur = root;
        for (auto ch : s) {
            int t = ch - 'a';
            if (cur->nxt[t] == NULL) return 0;
            cur = cur->nxt[t];
        }
        return cur->ended;
    }
};



class Solution {

public:
    // Giving TLE 
    int solve1(string s, string good, int k) {
        unordered_map<char, int> mpp;
        for (int i = 0; i < 26; i++) mpp[i + 'a'] = good[i] == '1' ? 1 : 0;

        int n = s.size();
        unordered_map<string, int> mpp2;

        for (int i = 0; i < n; i++) {
            string str = "";
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (mpp[s[j]]) {
                    str += s[j];
                    mpp2[str] = 1;
                } else if (cnt < k) {
                    cnt++;
                    str += s[j];
                    mpp2[str] = 1;
                } else break;
            }
        }
        // cout << mpp2.size() << nl;
        return mpp2.size();
    }


    // Giving TLE 
    int solve2(string& s, string& good, int k) {
        int n = s.size(), ans = 0;
        map<char, int> mpp;
        for (int i = 0; i < 26; i++) mpp[i + 'a'] = good[i] == '1' ? 1 : 0;

        Trie trie;
        for (int i = 0; i < n; i++) {
            string str = "";
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (mpp[s[j]]) {
                    str += s[j];
                } else if (cnt < k) {
                    cnt++;
                    str += s[j];
                } else break;

                if (trie.search(str) == 0) trie.insert(str), ans++;
            }
        }
        return ans;
    }



    // Works fine // O(N^2)
    int solve(string& s, string& bad, int k) {
        int n = s.size();
        set<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            // creating rolling hash with one prime can give collision
            // so use two prime to avoid collision (31, 29)
            // and compare pairs instead of a numbers
            int hash1 = 0, hash2 = 0;
            int p1 = 31, p2 = 29;
            int pow1 = 1, pow2 = 1;
            int badCnt = 0;

            for (int j = i; j < n; j++) {
                badCnt += bad[s[j] - 'a'] == '0' ? 1 : 0;
                if (badCnt > k) break;

                hash1 = (hash1 + (s[j] - 'a' + 1) * pow1) % mod;
                hash2 = (hash2 + (s[j] - 'a' + 1) * pow2) % mod;

                pow1 = (pow1 * p1) % mod;
                pow2 = (pow2 * p2) % mod;

                st.insert({ hash1, hash2 });
            }
        }
        return st.size();
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    string s; cin >> s;
    string good; cin >> good;
    dri(k);

    cout << sol.solve(s, good, k) << nl;

    return 0;
}




