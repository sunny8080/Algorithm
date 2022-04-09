#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
#define wt(x) int x; cin>>x; while( x-- )

ll maxProduct( vector<int> nums ){
    int n = nums.size();
    ll mini = nums[0];
    ll maxi = nums[0];
    ll prod = nums[0];
    for( int i=1; i<n; i++ ){
        if( nums[i] < 0 )    
            swap( mini, maxi );
        maxi = max( (ll)nums[i], nums[i]*1LL*maxi );
        mini = min( (ll)nums[i], nums[i]*1LL*mini );
        prod = max( maxi, prod );
    }
    return prod;
}

int main(){
    int n;  cin>>n;
    vector<int> nums(n);
    for( int i=0; i<n; i++ )    cin>>nums[i];

    cout<<maxProduct( nums )<<endl;; 
    
    return 0;
}

// 4
// -5 -2 2 -30
//
// 120