#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
#define int              long long
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



// Rabin Karp Algo
// QUE :- https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

// Due to p, it does not give correct ans always
class Solution {
    int p = 787;
    int invP; // inverse of p 
    int pm; // (p^(m-1))%mod
public:
    // string hashing
    int poly_hash_string(string s) {
        int p_pwr = 1;
        int hash = 0;
        for (auto ch : s) {
            hash = (hash + p_pwr * (ch - 'a' + 1)) % mod;
            p_pwr = (p_pwr * p) % mod;
        }
        return hash;
    }

    int modPow(int a, int n) {
        int res = 1;
        while (n) {
            if ((n & 1LL)) res = (res * a) % mod;
            a = (a * a) % mod;
            n /= 2;
        }
        return res;
    }

    int modInv(int x) {
        return modPow(x, mod - 2);
    }

    int rolling_hash(string txt, char prev, char cur, int txt_hash) {
        // remove first char
        txt_hash = (txt_hash - (prev - 'a' + 1) + mod) % mod;
        txt_hash = (txt_hash * invP) % mod;

        // add last char
        txt_hash = (txt_hash + (cur - 'a' + 1) * pm) % mod;
        return txt_hash;
    }


    // METHOD -1 // Rolling hash
    // return index of first occurence pattern in text 
    int firstOcc1(string txt, string pat) {
        int n = txt.size(), m = pat.size();
        if (n < m) return -1;

        int pat_hash = poly_hash_string(pat);
        int txt_hash = poly_hash_string(txt.substr(0, m));
        if (txt_hash == pat_hash) return 0;
        invP = modInv(p);
        pm = modPow(p, m - 1);

        for (int i = 1; i + m <= n; i++) {
            txt_hash = rolling_hash(txt, txt[i - 1], txt[i + m - 1], txt_hash);
            if (txt_hash == pat_hash) return i;

            // // cross check
            // if (txt_hash == pat_hash){
            //     for(int j=0; j<m; j++){
            //         if( txt[i+j] != pat[j] ) break;
            //     }
            //     return i;
            // }
        }

        return -1;
    }



    // METHOD -2 // prefix sum hash
    // return index of first occurence pattern in text 
    int firstOcc2(string txt, string pat) {
        int n = txt.size(), m = pat.size();
        if (n < m) return -1;

        int pat_hash = poly_hash_string(pat);

        // calculate prefix hash
        int prefix[n];
        for (int i = 0; i < n; i++) {
            prefix[i] = ((txt[i] - 'a' + 1) * modPow(p, i)) % mod;
            if (i >= 1) prefix[i] = (prefix[i] + prefix[i - 1]) % mod;
        }

        for (int i = 0; i + m <= n; i++) {
            // substring from s[l...r] // l=i // r=i+m-1
            int txt_hash = prefix[i + m - 1];
            if (i >= 1) txt_hash = (txt_hash - prefix[i - 1] + mod) % mod;

            if (txt_hash == (pat_hash * modPow(p, i)) % mod) return i;
        }

        return -1;
    }


    int strStr(string haystack, string needle) {
        return firstOcc1(haystack, needle);
        // return firstOcc2(haystack, needle);
    }


};





class Solution2 {

public:
    // rabin carp rolling algo
    // return no of times pattern occured in txt
    // rolling hash is used in opposite fashion -> "ABC" -> A*31*31 + B*31 + C*1
    // in this it is easy to remove 1st char from window
    int countMatch1(string txt, string pat) {
        ll m = txt.size(), n = pat.size();
        if (m < n) return 0;
        ll p1 = 29, pow1 = 1;
        ll hash1 = 0, hash2 = 0;

        for (ll i = n - 1; i >= 0; i--) {
            hash1 = (hash1 + (pat[i] - 'a' + 1) * pow1) % mod;
            hash2 = (hash2 + (txt[i] - 'a' + 1) * pow1) % mod;
            pow1 = (pow1 * p1) % mod;
        }

        ll cnt = 0;
        pow1 = 1;
        for (ll i = 1; i <= n - 1; i++) pow1 = (pow1 * p1) % mod;
        if (hash1 == hash2) cnt++;

        for (ll i = n; i < m; i++) {
            hash2 = (hash2 - (txt[i - n] - 'a' + 1) * pow1 + mod) % mod; // remove 1st char
            hash2 = ((hash2 * p1) % mod + (txt[i] - 'a' + 1)) % mod; // add current char
            if (hash1 == hash2) cnt++;
        }

        return cnt;
    }


    int countMatch2(string txt, string pat) {
        ll m = txt.size(), n = pat.size();
        if (m < n || txt == "" || pat == "") return 0;

        ll pwr1 = 1, p = 31, patCode = 0, txtCode = 0;
        for (int i = 0; i < n; i++) patCode = (patCode * p + pat[i]) % mod, pwr1 = (pwr1 * p) % mod;

        int cnt = 0;
        for (int i = 0; i < txt.size(); i++) {
            txtCode = (txtCode * p + txt[i]) % mod;
            if (i < n - 1) continue;
            if (i >= n) txtCode = (txtCode - txt[i - n] * pwr1) % mod;
            if (txtCode < 0) txtCode += mod;
            if (txtCode == patCode && txt.substr(i - n + 1, n) == pat) cnt++;
        }
        return cnt;
    }



    vi findAllOcc(string txt, string pat) {
        int patHash = 0, hash = 0, p = 31, pwr = 1, k = pat.size();
        vi occ;

        for (int i = 0; i < k; i++) patHash = (patHash * p + pat[i] + mod) % mod, pwr = (pwr * p) % mod;

        for (int i = 0; i < txt.size(); i++) {
            hash = (hash * p + txt[i]) % mod;
            if (i >= k) hash = (hash - txt[i - k] * pwr + mod) % mod;
            if (hash < 0) hash += mod;
            if (i >= k - 1 && hash == patHash) {
                // if (txt.substr(i - k + 1, k) == pat) occ.push_back(i - k + 1);
                occ.push_back(i - k + 1);
            }
        }

        return occ;
    }

};


int32_t main() {
    fastIO();
    Solution sol;

    string s = "ababaab";
    cout << sol.poly_hash_string(s) << nl; // 854448426

    string txt, pat;
    // cin >> txt >> pat;
    cout << sol.firstOcc1("abbabcabbcabba", "abb") << nl; // 0
    cout << sol.firstOcc1("abbabcabbcabba", "cabb") << nl; // 5
    cout << sol.firstOcc1("abbabcabbcabba", "xyz") << nl; // -1
    cout << sol.firstOcc1("abbabcabbcabba", "xyasdfasdfsadfasdfasdf") << nl; // -1
    cout << sol.firstOcc1("THIS IS A TEST TEXT", "TEST") << nl; // 10
    cout << sol.firstOcc1("abc", "c") << nl; // 2 
    cout << nl << nl;


    cout << sol.firstOcc2("abbabcabbcabba", "abb") << nl; // 0
    cout << sol.firstOcc2("abbabcabbcabba", "cabb") << nl; // 5
    cout << sol.firstOcc2("abbabcabbcabba", "xyz") << nl; // -1
    cout << sol.firstOcc2("abbabcabbcabba", "xyasdfasdfsadfasdfasdf") << nl; // -1
    cout << sol.firstOcc2("THIS IS A TEST TEXT", "TEST") << nl; // -1 // wrong ans 
    cout << sol.firstOcc2("abc", "c") << nl; // 2
    cout<<nl;

    {
        Solution2 sol2;
        auto nums = sol2.findAllOcc("absajhabtabsabs", "abs"); // 0 9 12
        PRT(nums);
    }

    return 0;
}

