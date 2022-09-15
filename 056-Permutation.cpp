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

void fastIO(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    #endif
}

/*
    For more backtracking, After this program go to :-

    1_Next_Permutation.cpp
    24_N_Queen.cpp
    25_Sudoku_Solver.cpp
*/

class Solution {
    
    public:

    // Store all unique permutation of array in in set st
    void permute( char *in, int i, set<string> &st){
        if( ! in[i] ){
            // cout<<in<<sp;
            st.insert(in);
            return;
        }

        // rec case
        for( int j=i; in[j]!='\0'; j++ ){
            swap(in[i], in[j]);
            permute(in, i+1, st);

            // Backtracking
            swap(in[j], in[i]);
        }
    }
};


int32_t main(){
    fastIO();
    
    Solution sol;

    char in1[] = { "132" };
    set<string> st1;
    sol.permute(in1, 0, st1);
    PRT(st1); // 123 132 213 231 312 321 
    cout<<nl;

    char in2[] = { "123" };
    set<string> st2;
    sol.permute(in2, 0, st2); // 123 132 213 231 321 312
    PRT(st2); // 123 132 213 231 312 321
    cout<<nl;

    char in3[] = { "122" };
    set<string> st3;
    sol.permute(in3, 0, st3); // 123 132 213 231 321 312
    PRT(st3); // 122 212 221
    cout<<nl;
    
    return 0;
}
    
    