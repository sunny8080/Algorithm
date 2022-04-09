#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
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

// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size(),prev;
        sort(nums.begin(),nums.end());
        for( int i=0; i<n; i ){
            for( int j=i+1; j<n; j ){
                int target2 = target-nums[i]-nums[j];
                int left=j+1, right=n-1;
                while( left < right ){
                    int sum = nums[left]+nums[right] ;
                    if(  sum == target2 ){
                        ans.push_back({ nums[i], nums[j], nums[left], nums[right] } );
                        left++, right--;

                        while( left < right && nums[left] == nums[left-1] ) left++;
                        while( left < right && nums[right] == nums[right+1] ) right--; 
                    } 
                    else if( sum < target2 )
                        left++;
                    else
                        right--;
                }
                j++;
                while( j<n && nums[j] == nums[j-1] ) j++;
            }
            i++;
            while( i<n && nums[i] == nums[i-1] ) i++;
        }
        return ans;
    }
};

// https://leetcode.com/problems/4sum/solution/
class Solution2 {
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
        vector<vector<int>> res;
        int lo = start, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if (sum < target || (lo > start && nums[lo] == nums[lo - 1]))
                ++lo;
            else if (sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1]))
                --hi;
            else
                res.push_back({ nums[lo++], nums[hi--]});
        }
        return res;
    }
    // vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
    //     vector<vector<int>> res;
    //     unordered_set<int> s;
    //     for (auto i = start; i < nums.size(); ++i) {
    //         if (res.empty() || res.back()[1] != nums[i])
    //             if (s.count(target - nums[i]))
    //                 res.push_back({ target - nums[i], nums[i]});
    //         s.insert(nums[i]);
    //     }
    //     return res;
    // }

    public:
    vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
        vector<vector<int>> res;
        if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
            return res;
        if (k == 2)
            return twoSum(nums, target, start);
        for (int i = start; i < nums.size(); ++i){
            if (i == start || nums[i - 1] != nums[i]){
                for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1) ) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(set), end(set));
                }
            }
        }
        return res;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }
};

int32_t main(){
    Solution sol;
    vector<vector<int>> ans;
    vector<int> arr;

    arr.operator=({1,0,-1,0,-2,2});
    ans = sol.fourSum(arr,0);
    for( auto i : ans ){
        for( int j : i )
            cout<<j<<sp;
        cout<<nl;
    }
    cout<<nl;
    
    arr.operator=({2,2,2,2,2});
    ans = sol.fourSum(arr,8);
    for( auto i : ans ){
        for( int j : i )
            cout<<j<<sp;
        cout<<nl;
    }


    return 0;
}