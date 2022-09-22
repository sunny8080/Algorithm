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
#define int_max 999999

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


// Travelling Salesman Problem
// QUE : https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/
// Soln : https://www.youtube.com/watch?v=JE0JE8ce1V0&t=335s


class Solution {

public:
    int tsp(int mask, int pos, int dist[100][100], int dp[100][100], int n) {
        // if all cities have been visited // mask = (111 ... 111) -> ((1<<n)-1)
        if (mask == ((1 << n) - 1)) {
            return dist[pos][0]; // becoz we started from 0
        }

        if (dp[mask][pos] != -1) return dp[mask][pos];

        int ans = int_max; // user defined int_max
        for (int city = 0; city < n; city++) {
            // go to unvisited city
            if ((mask & (1 << city)) == 0) {
                int tmp = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp, n);
                ans = min(ans, tmp);
            }
        }
        return dp[mask][pos] = ans;
    }

};



int32_t main() {
    fastIO();
    Solution sol;

    int n = 4;
    int dist[100][100] = { {0, 20, 42, 25},
                            {20, 0, 30, 34},
                            {42, 30, 0, 10},
                            {25, 34, 10, 0}
    };


    int dp[1000][100];
    memset(dp, -1, sizeof(dp));

    int ans = sol.tsp(1, 0, dist, dp, n);
    cout << "Min wt hamiltonian path costs (TSP) : " << ans << nl; // 85


    return 0;
}


// OUT :-
//
// Min wt hamiltonian path costs(TSP) : 85
