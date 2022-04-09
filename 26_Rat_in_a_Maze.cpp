#include<bits/stdc++.h>
#define ll long long
#define wt(x) int x; cin>>x; while( x-- )
#define REP(i,n) for( int i=0; i<n; i++ )
#define REPc(i,a,b) for( int i=a; i<b; i++ )
#define REPi(i,n) for( int i=n-1; i>=0; i-- )
#define REPci(i,a,b) for( int i=a; i>=b; i-- )
#define sp ' '
#define nl char(10)
#define endl char(10)
#define MOD 1000000007
#define vi vector<int>
#define vvi vector< vector<int> >
#define vll vector<long long> 
#define vvll vector< vector<long long> >
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define PRT(ar) for( auto i : ar )cout<<i<<sp;cout<<nl;
using namespace std;


// QUE :- https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
class Solution {
    void solve(int i, int j, int n, string path, vector<vector<int>>& m, vector<vector<int>>& vis, vector<string>& ans, pair<int, int> way[]) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }
        string dir = "DLRU";
        for (int ind = 0; ind < 4; ind++) {
            int nexti = i + way[ind].first;
            int nextj = j + way[ind].second;

            if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < n && vis[nexti][nextj] == 0 && m[nexti][nextj] == 1) {
                vis[i][j] = 1;
                solve(nexti, nextj, n, path + dir[ind], m, vis, ans, way);
                vis[i][j] = 0;
            }
        }
    }
public:
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        pair<int, int> way[4] = { {1,0}, {0,-1}, {0,1}, {-1,0} }; // DLRU
        if (m[0][0] == 1) solve(0, 0, n, "", m, vis, ans, way);
        return ans;
    }
};


int32_t main() {
    Solution sol;
    vector<vector<int>> maze;
    vector<string> ans;
    int N;


    N = 4;
    maze = { {1, 0, 0, 0},
             {1, 1, 0, 1},
             {1, 1, 0, 0},
             {0, 1, 1, 1} };

    ans = sol.findPath(maze, N);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << nl;
    }

    return 0;
}


// DDRDRR
// DRDDRR