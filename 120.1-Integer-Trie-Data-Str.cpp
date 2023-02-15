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



// Trie to store numbers 
// 2 approarch
// For more go there :- https://leetcode.com/problems/k-divisible-elements-subarrays/description/


class Trie {
    unordered_map<int, Trie*> mpp;
    int cnt = 0;
public:

    // insert recursively
    int insert(int i, int k, int p, vector<int>& nums) {
        if (i == nums.size() || k - (nums[i] % p == 0) < 0) return 0;
        if (mpp[nums[i]] == NULL) mpp[nums[i]] = new Trie();
        mpp[nums[i]]->cnt++;
        return (mpp[nums[i]]->cnt == 1) + mpp[nums[i]]->insert(i + 1, k - (nums[i] % p == 0), p, nums);
    }
};




class Trie2 {
    struct node {
        unordered_map<int, node*> mpp;
        int cnt = 0;
    };
    node* root;
public:
    Trie2() {
        root = new node();
    }

    // insert iteratively
    int insert(int i, int k, int p, vector<int>& nums) {
        node* cur = root;
        int ans = 0, divCnt = 0;
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] % p == 0) divCnt++;
            if (divCnt > k) break;
            if (cur->mpp[nums[j]] == NULL) cur->mpp[nums[j]] = new node(), ans++;
            cur = cur->mpp[nums[j]];
            cur->cnt++;
        }
        return ans;
    }
};





int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



