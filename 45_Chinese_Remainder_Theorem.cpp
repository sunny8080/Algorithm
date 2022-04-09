#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vector<int>, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define wt(x) \
    int x;    \
    cin >> x; \
    while (x--)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repi(i, a, b) for (int i = a; i >= b; i--)
#define sp ' '
#define nl char(10)
#define endl char(10)
#define PRT(ar)          \
    for (auto i : ar)    \
        cout << i << sp; \
    cout << nl;
#define mems(x, ch) memset(x, ch, sizeof(x))
#define sortv(x) sort(x.begin(), x.end())
#define sortvr(x) sort(x.rbegin(), x.rend())
#define all(x) x.begin(), x.end()

const ll cnst = 1e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //    #ifndef ONLINE_JUDGE
    //        freopen("input.txt", "r", stdin);
    //        freopen("output.txt", "w", stdout);
    //    #endif
}

// Chinese Remainder Theorem // find Min X for System of Linear Congruence
// QUE :- https://www.geeksforgeeks.org/chinese-remainder-theorem-set-1-introduction/
// and :- https://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/

class Solution
{

public:
    // METHOD - 1
    // find Min value of X By hit and trial  // O(M) // M is product of all num
    int findMinX(vi nums, vi rem){
        int x=1;
        while(1){
            int i=0;
            for( ; i<nums.size(); i++ ){
                if( x%nums[i] != rem[i] ){
                    break;
                }
            }

            // If all rem matched then it our ans
            if( i == nums.size() ){
                return x;
            }
            x++;
        }
        return x;
    }


    void extendedEuclid( int a, int b, int &x, int &y, int &gcd){
        if( b == 0 ){
            x=1, y=0, gcd=a;
            return;
        }

        extendedEuclid(b, a%b, x, y, gcd );

        int cX = y;
        int cY = x - (a/b)*y;

        x = cX, y=cY;
    }


    int modInv( int a, int m ){
        if( __gcd(a,m) != 1 ) return INT_MAX;

        int x, y, gcd;
        extendedEuclid(a, m, x, y, gcd);
        x = (x%m + m)%m;
        return x;
    }


    int modInvItr(int a, int m){
        if( m == 1 ) return 0;

        int x=1, y=0, m0=m;

        while( a > 1 ){
            int q = a/m;

            // RHH = gcd(a, m) = gcd(m, a%m)
            tie(a, m) = make_pair(m, a%m);

            // Update x and y
            tie(x,y) = make_pair(y, x-q*y);
        }

        // Make +ve if x is -ve
        x = (x%m0 + m0)%m0;

        return x;
    }

    // METHOD - 2
    // Find min value of x // By CRT // O(N * logN) 
    // all no. in nums must be coprime pairwise 
    int findMinXByCRT(vi nums, vi rem)
    {
        int prod = 1;
        for (auto x : nums)
            prod *= x;

        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int pp = prod / nums[i];

            // By CRT formula
            // result += (rem[i] * pp * modInv(pp, nums[i]));
            result += (rem[i] * pp * modInvItr(pp, nums[i]));
        }

        // to find smallest X, take mod by prod
        result = (result % prod);

        return result;
    }
};

int32_t main()
{
    fastIO();

    Solution sol;

    cout << sol.findMinX({3, 4, 5}, {2, 3, 1}) << nl; // 11 
    cout << sol.findMinX({3, 4, 5}, {2, 2, 1}) << nl; // 26
    cout << sol.findMinX({2, 3, 7}, {1, 0, 5}) << nl; // 33
    cout<<nl;

    cout << sol.findMinXByCRT({3, 4, 5}, {2, 3, 1}) << nl; // 11 
    cout << sol.findMinXByCRT({3, 4, 5}, {2, 2, 1}) << nl; // 26
    cout << sol.findMinXByCRT({2, 3, 7}, {1, 0, 5}) << nl; // 33

    return 0;
}
