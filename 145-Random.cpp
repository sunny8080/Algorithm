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



//class Solution {
//
//public:
//
//};

int randomFun(int j) {
    return rand() % j;
}


int32_t main() {
    fastIO();
    // Solution sol;


    {
        // #include<cstdlib> defined
       // to generate sequence different each time
        srand(time(0));

        // use rand() with srand() always
        cout << RAND_MAX << nl; // 32767
        cout << rand() << nl; // [0, RAND_MAX)
        cout << rand() % 19 << nl; // [0 ... 19)
        cout << rand() % (19 - 15 + 1) + 15 << nl; // [15 ... 19] // rand()%(ub - lb + 1 ) + lb 
        cout << nl;
    }


    {
        // random_shuffle() uses rand()
        vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        random_shuffle(arr.begin(), arr.end());
        PRT(arr);
        cout << nl;
    }


    {
        vector<int> arr2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        random_shuffle(arr2.begin(), arr2.end(), randomFun);
        PRT(arr2);
        cout << nl;
    }

    {
        // shuffle() uses urng(), which is a better random generator
        // shuffle() is improvement over random_shuffle(), so we should use shuffle()
        vector<int> arr3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        unsigned int seed = 0;
        shuffle(arr3.begin(), arr3.end(), default_random_engine(seed));
        PRT(arr3);
    }



    return 0;
}




