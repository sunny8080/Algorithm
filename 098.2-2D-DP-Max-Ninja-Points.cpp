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


// Link :- https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?leftPanelTab=0



class Solution {

public:

    int solve1(int day, int last, vector< vector<int>>& dp, vector< vector<int>>& pts) {
        if (day == 0) {
            int maxi = INT_MIN;
            for (int task = 0; task <= 2; task++)
                if (task != last) maxi = max(maxi, pts[0][task]);
            return maxi;
        }
        if (dp[day][last] != -1) return dp[day][last];
        int maxi = INT_MIN;
        for (int task = 0; task <= 2; task++) {
            if (task != last) maxi = max(maxi, pts[day][task] + solve1(day - 1, task, dp, pts));
        }
        return dp[day][last] = maxi;
    }



    int solve2(int day, int last, vector< vector<int>>& dp, vector< vector<int>>& pts) {
        if (day < 0) return 0;
        if (dp[day][last] != -1) return dp[day][last];

        int maxi = INT_MIN;
        for (int task = 0; task <= 2; task++) {
            if (task != last) maxi = max(maxi, pts[day][task] + solve2(day - 1, task, dp, pts));
        }
        return dp[day][last] = maxi;
    }




    // TC :- O(N*4*3) // SC :- O(N + 4*N)
    int ninjaTraining1(int n, vector<vector<int>>& pts) {
        vector< vector<int>> dp(n, vector<int>(4, -1));
        // return solve1(n - 1, 3, dp, pts);
        return solve2(n - 1, 3, dp, pts);
    }




    // TC :- O(N*4*3) // SC :- O(4*N)
    int ninjaTraining2(int n, vector<vector<int>>& pts) {
        vector< vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = max(pts[0][1], pts[0][2]);
        dp[0][1] = max(pts[0][0], pts[0][2]);
        dp[0][2] = max(pts[0][0], pts[0][1]);
        dp[0][3] = max({ pts[0][0], pts[0][1], pts[0][2] });

        for (int day = 1; day < n; day++) {
            for (int last = 0; last < 4; last++) {
                int maxi = 0;
                for (int task = 0; task < 3; task++) {
                    if (task != last)
                        maxi = max(maxi, pts[day][task] + dp[day - 1][task]);
                }
                dp[day][last] = maxi;
            }
        }
        return dp[n - 1][3];
    }



    // TC :- O(N*4*3) // SC :- O(4)
    int ninjaTraining(int n, vector<vector<int>>& pts) {
        vector<int> prev(4, 0);
        prev[0] = max(pts[0][1], pts[0][2]);
        prev[1] = max(pts[0][0], pts[0][2]);
        prev[2] = max(pts[0][0], pts[0][1]);
        prev[3] = max({ pts[0][0], pts[0][1], pts[0][2] });

        for (int day = 1; day < n; day++) {
            vector<int> tmp(4, 0);
            for (int last = 0; last < 4; last++) {
                int maxi = 0;
                for (int task = 0; task < 3; task++) {
                    if (task != last)
                        maxi = max(maxi, pts[day][task] + prev[task]);
                }
                tmp[last] = maxi;
            }
            prev = tmp;
        }
        return prev[3];
    }

};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



