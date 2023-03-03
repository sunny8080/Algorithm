#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll                 long long
// #define int                long long
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
#define rvi(nums)          for (auto& x : nums) cin >> x;
#define dri(x)             int x; cin >> x
#define drs(s)             string s; cin >> s
#define drii(x, y)         int x, y; cin >> x >> y
#define driii(x, y, z)     int x, y, z; cin >> x >> y >> z
#define driiii(x, y, z, w) int x, y, z, w; cin >> x >> y >> z >> w
#define drvi(nums, n)      vector<int> nums(n); for (auto& x : nums) cin >> x;
#define iff(x, y)  if(x) y

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
// Soln :- https://www.youtube.com/watch?v=NPZn9jBrX8U&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=26
// Soln :- https://youtu.be/-zI4mrF2Pb4?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY




// return length of LCS
class Solution1 {
    int lcsHelp1(int i, int j, vector< vector<int>>& dp, string& s1, string& s2) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) return 1 + lcsHelp1(i - 1, j - 1, dp, s1, s2);
        int op1 = lcsHelp1(i - 1, j, dp, s1, s2);
        int op2 = lcsHelp1(i, j - 1, dp, s1, s2);
        return dp[i][j] = max(op1, op2);
    }


    int lcsHelp2(int i, int j, vector< vector<int>>& dp, string& s1, string& s2) {
        if (i == 0 || j == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i - 1] == s2[j - 1]) return 1 + lcsHelp2(i - 1, j - 1, dp, s1, s2);
        int op1 = lcsHelp2(i - 1, j, dp, s1, s2);
        int op2 = lcsHelp2(i, j - 1, dp, s1, s2);
        return dp[i][j] = max(op1, op2);
    }

public:
    // Top Down :- TCO(N*M)  // SCO(N*M + N+M )
    int lcs1(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        // vector< vector<int>> dp(n, vector<int>(m, -1));
        // return lcsHelp1(n - 1, m - 1, dp, s1, s2);

        // // coordinate shift right by 1
        vector< vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return lcsHelp2(n, m, dp, s1, s2);

    }


    // Bottom Up :- TCO(N*M)  // SCO(N*M)
    int lcs2(string s1, string s2) {
        // // coordinate shift right by 1
        int n = s1.size(), m = s2.size();
        vector< vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int j = 0; j <= m; j++) dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }



    // Bottom Up Space optimized :- TCO(N*M)  // SCO(2*N)
    int lcs(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> prev(m + 1, 0), cur(m + 1, 0);
        for (int j = 0; j <= m; j++) prev[j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) cur[j] = 1 + prev[j - 1];
                else cur[j] = max(prev[j], cur[j - 1]);
            }
            prev = cur;
        }
        return prev[m];
    }
};



class Solution2 {

public:
    string getLCS(string s1, string s2) {
        // first create dp table
        // // coordinate shift right by 1
        int n = s1.size(), m = s2.size();
        vector< vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int j = 0; j <= m; j++) dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // get the string by traversing dp table
        int len = dp[n][m], i = n, j = m, ind = len - 1;
        string ans;
        for (int i = 0; i < len; i++) ans += '$';

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                ans[ind--] = s1[i - 1];
                i--, j--;
            } else if (dp[i][j] = dp[i][j - 1]) j--;
            else i--;
        }
        return ans;
    }

};








// QUE :- https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
class Solution3 {
public:
    // find length of longest common substring
    int longestCommonSubstr(string s1, string s2, int n, int m) {
        vector< vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // for(int i=0; i<=n; i++ ) dp[i][0] = 0;
        // for(int j=0; j<=n; j++ ) dp[0][j] = 0;

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};



int32_t main() {
    fastIO();

    {
        Solution1 sol1;
        string s1 = "ABCDGH";
        string s2 = "AEDFHR";
        cout << sol1.lcs(s1, s2) << nl; // 3
        cout << sol1.lcs(s1, s2) << nl; // 3
        cout << nl;
    }

    {
        Solution2 sol2;
        string s1 = "abcde", s2 = "bdgek";
        cout << sol2.getLCS(s1, s2) << nl; // bde
        cout<<nl;
    }

    {
        Solution3 sol3;
        int n = 6, m = 6;
        string s1 = "ABCDGH", s2 = "ACDGHR";
        cout << sol3.longestCommonSubstr(s1, s2, n, m) << nl; // 4
        cout<<nl;
    }


    return 0;
}




