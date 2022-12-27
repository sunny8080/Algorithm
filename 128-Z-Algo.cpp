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


// Z algorith,
// z[i] = the length of the longest substring starting at ith index, which is also the prefix of s
// prefix = s[0...(i-1)]   // substring = s[i...(n-1)]
// YT :- https://youtu.be/CpZh4eF8QBw

class Solution {

public:
    // O(N^2)
    vi zFun1(string s) {
        int n = s.size();
        vi z(n, 0);

        for (int i = 1; i < n; i++) {
            // int j = 0, k = i;
            // while (j < n && k < n && s[k] == s[j]) z[i]++, k++, j++;

            // z[i]=0, always
            while ((z[i] + i < n) && s[z[i]] == s[z[i] + i]) z[i]++;
        }
        return z;
    }


    // O(N) // best
    vi zFun2(string s) {
        int n = s.size();
        vi z(n, 0);
        z[0] = 0;
        int l = 0, r = 0;

        for (int i = 1; i < n; i++) {
            if (i > r) {
                //start trivial matching from index i
                l = r = i;

                // each time r=l, sol (r-l) will start from 0 // so we are matching prefix from 0 and substring from i
                while (r < n && s[r] == s[r - l]) r++;
                r--;
                z[i] = r - l + 1;
            } else {
                // we are inside the range [l...r] // s[l...r] is also a prefix
                int k = i - l;

                // if value does not expand till right boundry then just copy it
                if (z[k] + i <= r) {
                    z[i] = z[k];
                } else {
                    // may be we can expand the range [i...r] further
                    l = i;
                    while (r < n && s[r] == s[r - l])r++;
                    r--;
                    z[i] = r - l + 1;
                }
            }
        }

        return z;
    }


    // O(N) // short code
    vi zFun3(string s) {
        int n = s.size(), l = 0, r = 0;
        vi z(n, 0);
        z[0] = 0;

        for (int i = 1; i < n; i++) {
            if (i <= r) z[i] = min(z[i - l], r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[z[i] + i]) z[i]++; // expand z[i]
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
        }

        return z;
    }


    // return all occurence of pattern in a text // O(N+M)
    vi findOccur(string txt, string pat) {
        vi occ;
        string str = pat + "%" + txt;
        vi z = zFun2(str);

        for (int i = pat.size(); i < str.size(); i++) {
            if (z[i] == pat.size()) occ.push_back(i - pat.size() - 1);
        }
        return occ;
    }


    // find the longest palindromic prefix  
    string longestPalindromicPrefix(string s) {
        int n = s.size();
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        string str = s + "$" + tmp;
        vi z = zFun2(str);

        // length longest palindromic prefix is [ the length of longest suffix which is also the prefix ]
        // so find the length of longest suffix which is also the prefix
        int len = 0;
        for (int i = 0; i < str.size(); i++) {
            if (i + z[i] == str.size()) {
                len = max(len, z[i]);
            }
        }

        return s.substr(0, len);
    }


};



int32_t main() {
    fastIO();
    Solution sol;

    string s = "abaabababaababa";
    auto z1 = sol.zFun1(s);
    auto z2 = sol.zFun2(s);
    auto z3 = sol.zFun3(s);

    PRT(s);  // a b a a b a b a b a a b a b a 
    PRT(z1); // 0 0 1 3 0 3 0 8 0 1 3 0 3 0 1 
    PRT(z2); // 0 0 1 3 0 3 0 8 0 1 3 0 3 0 1 
    PRT(z3); // 0 0 1 3 0 3 0 8 0 1 3 0 3 0 1 
    cout << nl;


    string txt = "abaabababaababa";
    string pat = "aba";
    vi occ = sol.findOccur(txt, pat);
    PRT(occ); // 0 3 5 7 10 12 
    cout << nl;


    cout << sol.longestPalindromicPrefix("abaab") << nl;  // aba
    cout << sol.longestPalindromicPrefix("abcdef") << nl; // a




    return 0;
}




