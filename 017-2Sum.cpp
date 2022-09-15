#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<climits>
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

// https://leetcode.com/problems/two-sum/
// return indices (i,j) ST ==> nums[i]+nums[j] = target

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        // // METHOD 1
        // for( int i=0; i<nums.size(); i++ ){
        //     int t = target-nums[i];
        //     vector<int>::iterator it;
        //     if( (it = find(nums.begin()+i+1, nums.end(), t) )!= nums.end() ){
        //         ans.push_back(i);
        //         ans.push_back(it-nums.begin());
        //     }
        // }

        // // METHOD 2
        // vector<pair<int,int>> tmp;
        // for( int i=0; i<nums.size(); i++ ){
        //     tmp.push_back(make_pair(nums[i],i));
        // }
        // sort(tmp.begin(), tmp.end());
        // int i=0, j=nums.size()-1;
        // while(i<j){
        //     if( tmp[i].first + tmp[j].first == target )
        //         break;
        //     if( tmp[i].first + tmp[j].first > target ){
        //         j--;
        //     }
        //     else 
        //         i++;
        // }
        // ans.push_back(tmp[i].second);
        // ans.push_back(tmp[j].second);

        // METHOD 3
        unordered_map<int,int> mpp;
        for( int i=0; i<nums.size(); i++ ){
            if( mpp.find(target-nums[i]) != mpp.end() ){
                ans.push_back(mpp[target-nums[i] ] );
                ans.push_back(i);
            }
            mpp[nums[i]] = i;
        }

        return ans;
    }
};
int32_t main(){

    Solution sol;
    vector<int> arr;

    arr.operator=({2,7,11,15});
    PRT(sol.twoSum(arr,9) );

    arr.operator=({3,2,4});
    PRT(sol.twoSum(arr,6) );

    arr.operator=({3,3});
    PRT(sol.twoSum(arr,6) );


    return 0;
}