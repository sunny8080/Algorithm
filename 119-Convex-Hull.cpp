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


// QUE :- https://codeforces.com/problemset/problem/166/B


struct point {
    int x, y;
    bool operator<(point p) {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }

    bool operator==(point p) {
        return x == p.x && y == p.y;
    }
};



class Solution {

    // check points {a, b, c} are in clockwise or not
    bool cw(point& a, point& b, point& c) {
        return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
    }

    // counter clockwise
    bool ccw(point& a, point& b, point& c) {
        return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
    }


    // collinear
    bool col(point& a, point& b, point& c) {
        return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) == 0;
    }

public:
    // create a convex hull 
    vector<point> convexHull(vector<point>& p) {
        int n = p.size();
        if (n <= 2) return p;
        sort(p.begin(), p.end());

        // p1 = bottom left point // p2 = top right point
        point p1 = p[0], p2 = p[n - 1];
        vector<point> up, down;
        up.push_back(p[0]);
        down.push_back(p[0]);

        for (int i = 0; i < n; i++) {
            // now we have to check out current point is in lower half or in upper half

            if (i == n - 1 || !ccw(p1, p[i], p2)) {
                // p[i] is in upper half
                while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], p[i])) {
                    up.pop_back();
                }
                up.push_back(p[i]);
            }

            if (i == n - 1 || !cw(p1, p[i], p2)) {
                // p[i] is in lower half
                while (down.size() >= 2 && cw(down[down.size() - 2], down[down.size() - 1], p[i])) {
                    down.pop_back();
                }
                down.push_back(p[i]);
            }
        }

        // up and down contains all points including the points p1 and p2
        vector<point> ans;
        for (int i = 0; i < up.size(); i++) ans.push_back(up[i]);
        for (int i = 0; i < down.size(); i++) ans.push_back(down[i]);

        // ans vector contains all the points from up as well as down
        sort(ans.begin(), ans.end());
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
        return ans;
    }




    // QUE :- https://codeforces.com/problemset/problem/166/B
    void solve(vector<point>& a, vector<point>& b) {
        map<pair<int, int>, int> mpp;
        for (auto x : b) {
            a.push_back(x);
            mpp[{x.x, x.y}]++;
        }

        auto ans = convexHull(a);

        for (auto x : ans) {
            if (mpp.count({ x.x, x.y })) {
                cout << "NO";
                return;
            }
        }

        cout << "YES";
    }
};









// QUE :- https://leetcode.com/problems/erect-the-fence/
class Solution2 {
    bool ccw(vector<int>& a, vector<int>& b, vector<int>& c) {
        return a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]) > 0;
    }

    bool cw(vector<int>& a, vector<int>& b, vector<int>& c) {
        return a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]) < 0;
    }

public:
    vector<vector<int>> convexHull(vector<vector<int>>& p) {
        int n = p.size();
        if (n <= 2) return p;

        sort(p.begin(), p.end());
        vector<int> p1 = p[0], p2 = p[n - 1];

        vector<vector<int>> up, down;
        up.push_back(p1);
        down.push_back(p1);

        for (int i = 1; i < n; i++) {

            // chek it is in upper half or not
            if (i == n - 1 || !ccw(p1, p[i], p2)) {
                while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], p[i])) {
                    up.pop_back();
                }
                up.push_back(p[i]);
            }

            if (i == n - 1 || !cw(p1, p[i], p2)) {
                while (down.size() >= 2 && cw(down[down.size() - 2], down[down.size() - 1], p[i])) {
                    down.pop_back();
                }
                down.push_back(p[i]);
            }

        }

        // take union and remove duplicate
        vector<vector<int>> ans;
        for (auto x : up) ans.push_back(x);
        for (auto x : down) ans.push_back(x);

        sort(ans.begin(), ans.end());
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
        return ans;
    }


    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        return convexHull(trees);
    }
};



int32_t main() {
    fastIO();

    // {
    //     Solution sol;
    //     int n; cin >> n;
    //     vector<point> p(n);
    //     for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

    //     auto ans = sol.convexHull(p);
    //     for (auto x : ans) {
    //         cout << x.x << sp << x.y<<nl;
    //     }
    //     cout<<nl;
    // }


    int n; cin >> n;
    vector<point> a(n);
    for (auto& x : a) cin >> x.x >> x.y;

    int m; cin >> m;
    vector<point> b(m);
    for (auto& x : b) cin >> x.x >> x.y;

    Solution sol;
    sol.solve(a, b);

    return 0;
}

