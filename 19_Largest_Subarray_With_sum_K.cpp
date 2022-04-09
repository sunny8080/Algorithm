#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
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

// https://www.youtube.com/watch?v=xmguZ6GbatA&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=25
// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

class Solution {
public:
    // To find length of largest SubArray Having sum equals to k
    int maxLenSubSumK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int sum=0, maxi=0;
        for( int i=0; i<nums.size(); i++ ){
            sum += nums[i];
            if( sum == k )
                maxi=i+1;
            if( mpp.find(sum-k) != mpp.end() )
                maxi = max(maxi,i-mpp[sum-k]);
            if( mpp.find(sum) == mpp.end() )
                mpp[sum] = i;
        }
        return maxi;
    }

    // To find length of largest SubArray Having sum equals to 0
    int maxLen0Sum(vector<int> &nums )
    {
        unordered_map<int,int> mpp;
        int maxi=0, sum=0;
        for( int i=0; i<nums.size(); i++ ){
            sum += nums[i];
            if( sum == 0 )
                maxi = i;
            if( mpp.find(sum) != mpp.end() )
                maxi = max(maxi,i-mpp[sum]);
            else{
                mpp[sum] = i;
                //mpp.insert({sum,i});
            } 
        }
        return maxi;
    }
};

// To count no. of subarray with with sum K
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int cnt=0;
        // for( int i=0; i<nums.size(); i++ ){
        //     int sum=0;
        //     for( int j=i; j<nums.size(); j++){
        //         sum += nums[j];
        //         if( sum == k ) cnt++;
        //     }
        // }
        // return cnt;

        unordered_map<int,int> mpp;
        int cnt=0, sum=0;
        for( int x : nums ){
            sum += x;
            if( sum == k ) cnt++;
            if( mpp.find(sum-k) != mpp.end() ) cnt += mpp[sum-k];
            mpp[sum]++;
        }
        return cnt;
    }
};

int32_t main(){
    Solution sol;
    vector<int> arr;

    arr.operator=( {10, 5, 2, 7, 1, 9} );
    cout<<sol.maxLenSubSumK(arr,15)<<nl; // 4

    arr.operator=( {1,2,3} );
    cout<<sol.maxLenSubSumK(arr,3)<<nl; // 2

    arr.operator=({15,-2,2,-8,1,7,10,23});
    cout<<sol.maxLen0Sum(arr)<<nl; // 5
    cout<<sol.maxLenSubSumK(arr,0)<<nl; // 5
    cout<<nl;


    Solution2 sol2;
    arr.operator=({1,2,3});
    cout<<sol2.subarraySum(arr,3)<<nl; // 2

    arr.operator=({1,2,1,2,1});
    cout<<sol2.subarraySum(arr,3)<<nl; // 4

    arr.operator=({-1,-1,1});
    cout<<sol2.subarraySum(arr,0)<<nl; // 1
 
    arr.operator=({0,0,0,0,0,0,0,0,0,0});
    cout<<sol2.subarraySum(arr,0)<<nl; // 55

    
    return 0;
}