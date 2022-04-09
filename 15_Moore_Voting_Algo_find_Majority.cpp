#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
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

// By Moore Voting Algorithm 
class Solution3 {
    int findCandidate( vector<int> &nums ){
        int candidate;
        int cnt=0;
        for( int i=0; i<nums.size(); i++ ){
            if( cnt == 0 )
                candidate = nums[i];
            if( candidate == nums[i] )
                cnt++;
            else 
                cnt--;
        }
        return candidate;
    }
    bool isMajority( vector<int> &nums, int cand ){
        int cnt = count( nums.begin(), nums.end(), cand );
        if( cnt > nums.size()/2 )
            return true;
        else 
            return false;
    }

    public:
    void printMajority( vector<int> &nums ){
        int cand = findCandidate(nums);
        if( isMajority(nums, cand ) )
            cout<<"Majority element : "<<cand<<nl;
        else 
            cout<<"No majority element found"<<nl;
    }
    
};

// Using HashMap
class Solution2 {
    
    public:
    void printMajority( vector<int> &nums ){
        unordered_map<int,int> mpp;
        for( int x : nums ){
            mpp[x]++;

            if( mpp[x] > nums.size()/2 ){
                cout<<"Majority element : "<<x<<nl;
                return ;
            }
        }
        // for( auto i : mpp )
        //     if( i.second > nums.size()/2 ){
        //         cout<<"Majority element : "<<i.first<<nl;
        //         return ;
        //     }
        cout<<"No majority element found"<<nl;
        
    }
    
};

// Using Brute Force
class Solution1 {
    
    public:
    void printMajority( vector<int> &nums ){

        for( int x : nums ){
            int cnt = count(nums.begin(), nums.end(), x );
            if( cnt > nums.size()/2 ){
                cout<<"Majority element : "<<x<<nl;
                return;
            }
        }
        cout<<"No majority element found"<<nl;
        

        // sort(nums.begin(), nums.end() );
        // int prev = nums[0];
        // int cnt=1;
        // for( int i=1; i<nums.size(); i++ ){
        //     if( prev == nums[i] ) cnt++;
        //     else{
        //         prev = nums[i];
        //         cnt=1;
        //     }
        //     if( cnt > nums.size()/2 ){
        //         cout<<"Majority element : "<<nums[i]<<nl;
        //         return;
        //     }
        // }
        // cout<<"No majority element found"<<nl;

    }
    
};


int32_t main(){
    int n;
    n = 8;

    //Solution1 sol;
    //Solution2 sol;
    Solution3 sol;

    vector<int> arr = { 2, 2, 1, 1, 2, 1, 3, 1, 1 }; // 1
    //PRT(arr);
    sol.printMajority(arr);

    arr.operator=( {7, 7, 7, 7, 5, 9, 5 } ); // 7
    //PRT(arr);
    sol.printMajority(arr);

    arr.operator=( {2, 3, 7, 3, 4} ); // NO
    //PRT(arr);
    sol.printMajority(arr);
    
    return 0;
}