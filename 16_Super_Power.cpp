#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
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
#define vi vector<int>
#define vvi vector< vector<int> >
#define vll vector<long long> 
#define vvll vector< vector<long long> >
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define PRT(ar) for( auto i : ar )cout<<i<<sp;cout<<nl;
using namespace std;

// To find Power of a no., where pow is too large so pow is given in form of array // with modulus = 1337
// https://leetcode.com/problems/super-pow/

class Solution {
    int MOD = 1337;
    int modPow( int a, int n ){
        long long res=1L;
        a %= MOD;
        while( n ){
            if( n&1 )
                res = (res*1LL*a)%MOD ;
            a = (a*1LL*a)%MOD ;
            n /= 2;
        }
        return res;
    }
public:
    int superPow(int a, vector<int>& b) {
        if( b.size() == 1 ) return ( modPow(a,b[0]) );
        int last = b.back();
        b.pop_back();
        int result = ( modPow( superPow(a,b), 10) *1LL* modPow(a,last) )%MOD;
        return result;
    }
};

int32_t main(){
    Solution sol;
    vector<int> arr;
    
    arr.operator=( {3} );
    cout<<sol.superPow(2,arr )<<nl; // 8
    
    arr.operator=( {1,0} );
    cout<<sol.superPow(2,arr )<<nl; // 1024
    
    arr.operator=( {4,3,3,8,5,2} );
    cout<<sol.superPow(1,arr )<<nl; // 1
    
    arr.operator=( {2,0,0} );
    cout<<sol.superPow(2147483647,arr )<<nl; // 1198 

    arr.operator=( {1,2,3,4,5,6,7} );
    cout<<sol.superPow(235,arr )<<nl; // 424

    return 0;
}

// 8
// 1024
// 1
// 1198
// 4