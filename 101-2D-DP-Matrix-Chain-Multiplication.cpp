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

// 2D DP
// QUE :- https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// Soln : https://www.youtube.com/watch?v=D1U74eFLg_g


// To multiply the matrices A[r1, c1] and B[r2, c2]
// to of multiplication steps or cost = r1*c1*c2


class Solution {
public:
    // Bottom up // O(N^3)
    int matrixMultiplication(int n, int arr[]) {
        // arr[] :- r1 r2 r3 .... rn cn 
        // cost to multiply the matrices is diff with diff combination
        n--;
        long long int dp[n][n] = { 0 };
        // dp[r][c] :- minimum steps/cost to multiply matrices from [r...c] // r<=c
        // dp[r][r] = 0

        // traverse the dp diagonally  
        for (int j = 1; j < n; j++) {
            int r = 0, c = j;

            while (c < n) {
                long long int val = INT_MAX;

                // dp[x][y] = multiply (dp[x][k], dp[k][y]) then mulipky these two subparts
                // dp[x][y] = min{ dp[x][k] + dp[k+1][y] + arr[x]*arr[k+1]*arr[y+1]   :- for all k in [x, y-1] } 
                // here k is pivot 
                for (int pivot = r; pivot <= c - 1; pivot++) {
                    val = min(val, dp[r][pivot] + dp[pivot + 1][c] + arr[r] * 1LL * arr[pivot + 1] * 1LL * arr[c + 1]);
                }
                dp[r][c] = val;
                r++, c++;
            }
        }
        return dp[0][n - 1];
    }
};


int32_t main() {
    fastIO();
    Solution sol;

    {
        int arr[] = { 4, 2, 3, 1, 3 };
        int n = sizeof(arr) / sizeof(arr[0]);
        cout << sol.matrixMultiplication(n, arr) << nl; // 26
    }
    cout << nl;

    {
        int arr[] = { 20, 15, 30, 5, 40 };
        int n = sizeof(arr) / sizeof(arr[0]);
        cout << sol.matrixMultiplication(n, arr) << nl; // 4500
    }


    return 0;
}

