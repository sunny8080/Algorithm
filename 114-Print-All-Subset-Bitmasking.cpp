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


// print all the subsets by bitmasking
// so N can be upto 64 // if we use long long


class Solution {
    bool isSet(int n, int i) {
        return (n & (1 << i));
    }
public:
    void printSubset(vi& nums) {
        int n = nums.size();
        int mask = 0;

        for (int i = 0; i < n; i++) {
            mask = (mask | (1 << i));
        }
        // cout << mask << nl;

        for (int m = mask; m != 0; m = (m - 1) & mask) {
            vector<int> ans;
            for (int i = 0; i < n; i++) {
                if (isSet(m, i)) ans.pb(nums[i]);
            }
            PRT(ans);
        }
    }


    // subset of selected items
    void printSubset2(vi& nums, int mask) {
        int n = nums.size();
        // cout << mask << nl;

        for (int m = mask; m != 0; m = (m - 1) & mask) {
            vector<int> ans;
            for (int i = 0; i < n; i++) {
                if (isSet(m, i)) ans.pb(nums[i]);
            }
            PRT(ans);
        }
    }

};



int32_t main() {
    fastIO();
    Solution sol;


    {
        vi nums = { 0,1, 2 };
        sol.printSubset(nums);
    }
    cout << nl;

    {
        vi nums = { 0,1, 2, 3, 4, 5, 6, 7 };
        int mask = 84; // 84 == 0101 0100 // so find subset of {2, 4, 6}

        string binary = bitset<64>(mask).to_string(); 
        binary.erase(0, binary.find_first_not_of('0'));
        cout<<binary<<nl;
        
        sol.printSubset2(nums, mask);
    }
    cout<<nl;


    // base conversion
    {
        int n=14;
        char buffer[64];
        
        sprintf(buffer, "%o", n); // to oct
        cout<<buffer<<nl;

        sprintf(buffer, "%x", n); // to hex
        cout<<buffer<<nl;

        string binary = bitset<64>(n).to_string();
        binary.erase(0, binary.find_first_not_of('0'));
        cout << binary << nl; // to binary
    }



    return 0;
}

