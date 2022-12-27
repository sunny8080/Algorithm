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


// QUE :- https://leetcode.com/problems/rotting-oranges/
// Soln 1 :- https://www.youtube.com/watch?v=yf3oUhkvqA0&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=11
// Soln 2 :- https://www.youtube.com/watch?v=pUAPcVlHLKA&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=83

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int vis[n][m];

        //{r, c, t}
        queue<vector<int>> q;
        int cntFresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({ i, j, 0 });
                    vis[i][j] = 1;
                } else {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1) cntFresh++;
            }
        }

        int tm = 0;
        int drow[] = { 1, -1, 0, 0 };
        int dcol[] = { 0, 0, 1, -1 };
        int cnt = 0;
        while (!q.empty()) {
            int r, c, t;
            tie(r, c, t) = make_tuple(q.front()[0], q.front()[1], q.front()[2]);
            tm = max(tm, t);
            q.pop();

            for (int w = 0; w < 4; w++) {
                int i = r + drow[w], j = c + dcol[w];
                if (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && grid[i][j] == 1) {
                    q.push({ i, j, t + 1 });
                    vis[i][j] = 1;
                    cnt++;
                }
            }
        }

        return (cnt == cntFresh) ? tm : -1;
    }
};



class Solution2 {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) tot++;
                if (grid[i][j] == 2) rotten.push({ i, j });
            }
        }

        int dx[4] = { 0, 0, 1, -1 };
        int dy[4] = { 1, -1, 0, 0 };

        while (!rotten.empty()) {
            int k = rotten.size();
            cnt += k;
            while (k--) {
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    rotten.push({ nx, ny });
                }
            }
            if (!rotten.empty()) days++;
        }

        return tot == cnt ? days : -1;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




