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

// KMP - Knuth Morris Pratt Algo
// Returns all indices where a pattern found in a text

// LPS - Longest Prefix Suffix 
// longest prefix which is equal to suffix

class Solution {

public:
    // Brute force // O(N^3)
    vi compute_lps_trivial(string s) {
        int n = s.size();
        vi lps(n, 0);
        for (int i = 0; i < n; i++) {
            for (int len = 0; len <= i; len++) {
                // check prefix == suffix
                if (s.substr(0, len) == s.substr(i - len + 1, len)) {
                    lps[i] = len;
                }
            }
        }
        return lps;
    }


    // O(2*N) = O(N)
    vi compute_lps(string s) {
        int n = s.size();
        vector<int> lps(n, 0);
        lps[0] = 0;


        // int i = 1, j = 0;
        // while (i < n) {
        //     if (s[i] == s[j]) {
        //         lps[i] = j + 1;
        //         i++; j++;
        //     } else if (j != 0) {
        //         // find the longest suffix which was also the prefix
        //         j = lps[j - 1];
        //     } else {
        //         lps[i++] = 0;
        //     }
        // }


        // better
        for (int i = 1; i < n; i++) {
            // find the longest suffix which was also the prefix, from index (i-1)
            int j = lps[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = lps[j - 1];
            }
            if (s[i] == s[j]) j++;
            lps[i] = j;
        }

        return lps;
    }



    // kmp - returns all occurances of a pattern in string
    vi kmp1(string txt, string pat) {
        int n = txt.size(), m = pat.size();
        vi occurances;
        vi lps = compute_lps(pat);
        int i = 0, j = 0;

        while (i < n) {
            if (txt[i] == pat[j]) i++, j++;
            else if (j != 0) {
                // find the lps value, As-
                // find the longest txt suffix which is equal to longest pattern prefix
                // since txt suffix is pattern suffix. so,
                // find the longest pattern suffix which is equal to longest pattern prefix 
                // i.e, lps[j-] // so, j = lps[j-1]

                j = lps[j - 1]; // back in the automata
            } else {
                i++;
            }

            if (j == m) {
                // pattern found
                occurances.push_back(i - m);
                j = lps[j - 1]; // back in the automata
            }
        }
        return occurances;
    }



    vi kmp2(string txt, string pat) {
        int n = txt.size(), m = pat.size();
        vi occurances;

        // caoncat both string with some chat which is not present in both strings
        // and then find lps of concated strings
        string s = pat + "$" + txt;
        // cout<<s<<nl;

        vi lps = compute_lps(s);
        for(int i=m+1; i<s.size(); i++){
            if( lps[i] == m ){
                occurances.push_back(i-2*m);
            }
        }

        return occurances;
    }


};



int32_t main() {
    fastIO();
    Solution sol;

    {
        string s = "abababbababa";
        auto lps1 = sol.compute_lps_trivial(s);
        auto lps2 = sol.compute_lps(s);
        PRT(s);     // a b a b a b b a b a b a 
        PRT(lps1);   // 0 0 1 2 3 4 0 1 2 3 4 5
        PRT(lps2);   // 0 0 1 2 3 4 0 1 2 3 4 5
    }
    cout << nl;

    {
        string txt = "abababbababa";
        string pat = "aba";
        auto occ1 = sol.kmp1(txt, pat); // 0 2 7 9
        auto occ2 = sol.kmp2(txt, pat); // 0 2 7 9
        PRT(occ1);
        PRT(occ2);
    }



    return 0;
}




