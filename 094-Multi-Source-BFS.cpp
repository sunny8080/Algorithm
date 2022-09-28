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

const ll N = 1e3 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}


// QUE:- https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/
// Soln :- https://www.youtube.com/watch?v=xvi8PqRrAyU


int n, m;
int vis[N][N];
int lev[N][N];
int arr[N][N];
vector<pair<int, int>> direcs = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };


class Solution {

public:

    void reset() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = 0;
                lev[i][j] = INT_MAX;
            }
        }
    }

    bool isValidCord(int i, int j) {
        return(i >= 0 && i < n&& j >= 0 && j < m);
    }

    int multiSourceBFS() {

        // Find max value in the array
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mx = max(mx, arr[i][j]);
            }
        }

        int ans = 0;
        queue<pair<int, int>> q;  // contains x cord and y cord of node

        // Insert the co-ordinates in which value is mx value
        // also these are at level 0 // as well as visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == mx) {
                    q.push({ i,j });
                    lev[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int p_x, p_y;
            tie(p_x, p_y) = p;

            // go to its nbrs and if not visited insert it in queue // as we do this in BFS
            for (auto dir : direcs) {
                int nbr_x, nbr_y;
                tie(nbr_x, nbr_y) = make_pair(dir.first + p_x, dir.second + p_y);

                // check coordinates is out of bounds or not
                if (!isValidCord(nbr_x, nbr_y)) continue;

                // if that cell is already visited
                if (vis[nbr_x][nbr_y]) continue;

                q.push({ nbr_x, nbr_y });
                vis[nbr_x][nbr_y] = 1;
                lev[nbr_x][nbr_y] = lev[p_x][p_y] + 1;

                // ans will be max of all distances
                ans = max(ans, lev[nbr_x][nbr_y]);
            }
        }
        return ans;
    }

};



int32_t main() {
    fastIO();
    Solution sol;

    wt(t) {

        // reset the array for the next test case

        sol.reset();
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }

        cout << sol.multiSourceBFS() << nl;
    }



    return 0;
}

