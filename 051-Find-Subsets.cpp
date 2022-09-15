#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
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

const ll cnst = 1e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //    #ifndef ONLINE_JUDGE
    //        freopen("input.txt", "r", stdin);
    //        freopen("output.txt", "w", stdout);
    //    #endif
}

class Solution {

public:

    // Generate all subsets and print those // no. of non-empty subsets = 2^n - 1 // n= no. of chars in array
    void generateSubsets(char* in, char* out, int i, int j, int* cnt) {
        if (in[i] == '\0') {
            out[j] = '\0';
            // print only non empty subsets
            if (j != 0) cout << out << sp;
            (*cnt)++;
            return;
        }

        // rec case
        // include current element
        out[j] = in[i];
        generateSubsets(in, out, i + 1, j + 1, cnt);

        // // Exclude the current element
        generateSubsets(in, out, i + 1, j, cnt);
    }

};



// Find all subsets
class Solution2 {

public:
    void findSubsets(vi& nums, vvi& st, int ind, vi ans) {
        if (ind == nums.size()) {
            if (ans.size() != 0) {
                st.pb(ans);
            }
            return;
        }

        ans.pb(nums[ind]);
        findSubsets(nums, st, ind + 1, ans);
        ans.pop_back();
        findSubsets(nums, st, ind + 1, ans);
    }
};

int32_t main() {
    fastIO();

    Solution sol;

    char arr[] = "ABC";
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout<<n<<nl; // 4
    char ar[n];
    int cnt = 0;

    sol.generateSubsets(arr, ar, 0, 0, &cnt); // ABC AB AC A BC B C  
    cout << "\nNumber of non-empty subsets : " << cnt - 1 << nl; // 7
    cout<<nl<<nl;


    vi nums = {1, 3, 2};
    vi ans;
    vvi st;
    Solution2 sol2;
    sol2.findSubsets(nums, st, 0, ans);
    cout<<st.size()<<nl;
    for( auto x : st){
        PRT(x);
    }

    return 0;
}


// OUT :-
// ABC AB AC A BC B C
// Number of non - empty subsets : 7
//
//
// 7
// 1 3 2
// 1 3
// 1 2
// 1
// 3 2
// 3
// 2