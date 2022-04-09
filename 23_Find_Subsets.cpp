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

// By Bit Manipulation, find all subset 
class Solution {
    public:
    vector<vector<int>> findSubsets( vector<int> &nums ){
        sort( nums.begin(), nums.end() );
        int n = nums.size();
        vector<vector<int>> ans;
        int total = (1<<n);
        for( int num=0; num<total; num++ ){
            vector<int> tmp;
            for( int i=0; i<n; i++ ){
                if( (num & (1<<i) ) > 0 )
                    tmp.push_back( nums[i] );
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

// By recursion, find all subset
class Solution2 {
    void solve( int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ansList ){
        ansList.push_back(ds);
        for( int i=ind; i<nums.size(); i++ ){
            // if( i != ind && nums[i] == nums[i-1] ) continue; // if nums contain duplicate element
            ds.push_back( nums[i] );
            solve( i+1, nums, ds, ansList );
            ds.pop_back();
        }
    }
    public:
    vector<vector<int>> findSubsets( vector<int> &nums ){
        sort( nums.begin(), nums.end() ); // to store subset in sorted order
        vector<vector<int>> ans;
        vector<int> ds;
        solve( 0, nums, ds, ans );
        return ans;
    }
};

// To find sum of all subset 
class Solution3 {
    void solve( int ind, vector<int> &nums, int N, vector<int> &sumSet, int sum ){
        if( ind == N ){
            sumSet.push_back(sum);
            return ;
        }
        solve( ind+1, nums, N, sumSet, sum + nums[ind] );
        solve( ind+1, nums, N, sumSet, sum );
    }
    public:
    vector<int> findSumSubset( vector<int> &nums ){
        sort( nums.begin(), nums.end() );
        vector<int> sumSet;
        solve( 0, nums, nums.size(), sumSet, 0 );
        sort( sumSet.begin(), sumSet.end() );
        return sumSet;
    }
};

int32_t main(){
    Solution sol;
    Solution2 sol2;
    Solution3 sol3;

    vector<int> arr;
    vector<vector<int>> subset;
    vector<int> sumSet;

    arr.operator=({1,2,3});
    // subset = sol.findSubsets(arr);
    subset = sol2.findSubsets(arr);



    for( int i=0; i<subset.size(); i++ ){
        cout<<i+1<<". ";
        for( int j=0; j<subset[i].size(); j++ )
            cout<<subset[i][j]<<sp;
        cout<<nl;
    }


    sumSet = sol3.findSumSubset(arr);
    PRT(sumSet);
    
    return 0;
}