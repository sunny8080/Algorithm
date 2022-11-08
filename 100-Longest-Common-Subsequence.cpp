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



// find LCS (longest common subsequence) length // and print it
// QUE :- https://leetcode.com/problems/longest-common-subsequence/
// QUE :- https://atcoder.jp/contests/dp/tasks/dp_f
// Soln - https://youtu.be/APG3S78OaLs
// Soln - https://www.youtube.com/watch?v=NPZn9jBrX8U
// Soln - https://youtu.be/-zI4mrF2Pb4?list=TLPQMTgxMDIwMjLqSfuKEAsMzA


class Solution {
    int lcs1_help(string& s1, string& s2, int i, int j, vvi& dp) {
        if (i == s1.length() or j == s2.length()) return 0;

        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + lcs1_help(s1, s2, i + 1, j + 1, dp);
        }
        int op1 = lcs1_help(s1, s2, i + 1, j, dp);
        int op2 = lcs1_help(s1, s2, i, j + 1, dp);
        return dp[i][j] = max(op1, op2);
    }


    string getLCS(string& s1, string& s2, vvi& dp, int len) {
        string str;
        int i = 0, j = 0;
        while (len > 0) {
            if (s1[i] == s2[j]) {
                str += s1[i], i++, j++, len--;
            } else {
                if (dp[i][j + 1] > dp[i + 1][j]) j++;
                else i++;
            }
        }
        return str;
    }
public:

    // return length of LCS
    // Top down // O(N^2)
    int lcs1(string& s1, string& s2) {
        int n1 = s1.size(), n2 = s2.size();
        vvi dp(n1 + 1, vector<int>(n2 + 1, -1));
        int len = lcs1_help(s1, s2, 0, 0, dp);

        // // to print it
        // string str = getLCS(s1, s2, dp, len);
        // cout << str << nl;

        return len;
    }


    // METHOD - 2
    // Bottom up
    int lcs2(string& s1, string& s2) {
        // index is shifted towards right by 1

        // METHOD - 2.1
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int j = 0; j <= m; j++) dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }


        // // To print lcs string
        // int len = dp[n][m];
        // string ans = "";
        // for (int i = 0; i < len; i++) ans += "$";
        // int ind = len - 1;
        // int i = n, j = m;
        // while (i > 0 && j > 0) {
        //     if (s1[i - 1] == s2[j - 1]) {
        //         ans[ind] = s1[i - 1];
        //         i--, j--, ind--;
        //     } else if (dp[i - 1][j] > dp[i][j - 1]) {
        //         i--;
        //     } else {
        //         j--;
        //     }
        // }
        // cout << ans << nl;


        return dp[n][m];




        // METHOD - 2.2 // space optimised
        // int n = s1.size(), m = s2.size();
        // vector<int> prev(m+1, 0), cur(m+1, 0);
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         if (s1[i - 1] == s2[j - 1]) cur[j] = 1 + prev[j - 1];
        //         else cur[j] = max(prev[j], cur[j - 1]);
        //     }
        //     prev = cur;
        // }
        // return prev[m];

    }





};





int32_t main() {
    fastIO();
    Solution sol;


    {
        string s1 = "ABCDGH";
        string s2 = "AEDFHR";
        cout << sol.lcs1(s1, s2) << nl; // 3
        cout << sol.lcs2(s1, s2) << nl; // 3
        cout << nl;
    }

    {
        // string s1, s2; cin >> s1 >> s2;
        // sol.lcs1(s1, s2);
        // sol.lcs2(s1, s2);
    }

    return 0;
}

