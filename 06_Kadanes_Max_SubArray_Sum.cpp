// Kadane's Algorithm
#include<iostream>
#include<vector>
#include<limits>
#include<limits.h>
#include<algorithm>
using namespace std;
#define ll long long
#define wt(x) int x; cin>>x; while( x-- )

// Kadane's Algorithm
int maxSubSum( vector<int> arr ){
    int sum=0, ans = arr[0] ;
    int ans_l =0, ans_r=0, minus_pos = -1 ; // for find subarray
    
    for( int i=0; i<arr.size(); i++ ){
        sum = sum + arr[i];
        if( sum > ans ){
            ans = sum;
            ans_l = minus_pos+1;
            ans_r = i;
        }
        if( sum <0 ){
            sum = 0;
            minus_pos = i;
        }
    }
    cout<<"Subarray which gives max sum : ";
    for( int i=ans_l; i<=ans_r; i++ )
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"Maximum subarray sum : "<<ans<<endl;

    return ans;
}

/*
int maxSubSum( vector<int> arr ){
    int n = arr.size(), ans=arr[0], sum=0, min_sum=0;
    int min_pos, ans_l,ans_r;
    for( int i=0; i<n; i++ ){
        sum += arr[i];
        int cur = sum-min_sum;
        if( cur > ans ){
            ans = cur;
            ans_l = min_pos+1;
            ans_r = i;
        }
        if( sum <  min_sum ){
            min_sum = sum;
            min_pos = i;
        }
    }
    cout<<"Subarry which gives max sum : ";
    for( int i=ans_l; i<=ans_r; i++ )
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"Maximum subarray sum : "<<ans<<endl;

    return ans;
}
*/

int main(){
    vector<int> arr{ -2, -3, 4, -1, -2, 1, 5, -3 };
    
    int maxi = maxSubSum( arr );
    cout<<"Maximum subarray sum : "<<maxi<<endl;
    
    return 0;
}

// Subarry which gives max sum : 4 -1 -2 1 5 
// Maximum subarray sum : 7
// Maximum subarray sum : 7