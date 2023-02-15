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



// Manacher algo :-
// It is used to find all sub-palindrome in a string in O(N)
// It can be used to find longest palindrome in a string in O(N)

// In this algo, expand there is expand concept, 
// we assume a index as center and we expand our current range as much as possible ( till our left and right char matches )

// It is used only in case of odd length palindrome string, so to work properly we insert '$' or '#' at every index 
// to make it a string with odd length (2*n + 1)
// Ex : abaccabe => $a$b$a$c$c$a$b$e$    // (8 => 2*8+1=17)



// QUE :- https://leetcode.com/problems/longest-palindromic-substring/

// YT 1 - https://www.youtube.com/watch?v=QfZvw8_jz1w
// YT 2 - https://www.youtube.com/watch?v=V-sEwsca1ak&t=72s
// YT 3 - https://www.youtube.com/watch?v=IvakBbsAhUU

// Cp-algo : https://cp-algorithms.com/string/manacher.html



class Solution {
    int expand(string& s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) l--, r++;
        return r - l - 1;
    }

public:
    // brute force // TC : O(N^2) // SC : O(1)
    string longestPalindrome1(string s) {
        int len = 1, start_i = 0;
        for (int i = 0; i < s.size(); i++) {
            int odd = expand(s, i, i);
            int even = expand(s, i, i + 1);
            int tmp = max(odd, even);

            if (len < tmp) {
                // for even length center chars :- s[i] and s[i+1]
                // for odd length center chars :- s[i] 
                start_i = i - (tmp - 1) / 2;
                len = tmp;
            }
        }
        return s.substr(start_i, len);
    }




    // Manacher algo // TC - O(N) // SC - O(N)
    string longestPalindrome(string s) {
        // size of string should be odd // so add '#'
        string str = "#";
        for (auto ch : s) str = str + ch + "#";
        // cout << str << nl;

        int n = str.size();
        vector<int> p(n, 0);
        int center = 0, right = 0;
        int longestCenter = 0, longestLength = 0;

        for (int i = 0; i < n; i++) {
            // copy mirror value of palindrome, if it comes under range
            int mirror = 2 * center - i;
            if (i < right) p[i] = min(p[mirror], right - i);

            // expand the palindrome, if you can 
            int a = i - (p[i] + 1); // new left pointer
            int b = i + (p[i] + 1); // new right pointer
            while (a >= 0 && b < n && str[a] == str[b]) a--, b++, p[i]++;

            if (i + p[i] > right) {
                // new palindrome found
                right = i + p[i];
                center = i;
            }

            // found a palindrome
            if (p[i] > longestLength) {
                longestLength = p[i];
                longestCenter = i;
            }
        }

        int l = longestCenter - longestLength, r = longestCenter + longestLength;
        string tmp = str.substr(l, r - l + 1);

        // remove extra '#'
        string ans;
        for (auto ch : tmp) {
            if (ch != '#') ans += ch;
        }
        return ans;
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    cout << sol.longestPalindrome("babad") << nl; // bab
    cout << sol.longestPalindrome("cbbd") << nl; // bb



    return 0;
}




