#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll               long long
#define ff               first
#define ss               second
#define pb               push_back
#define mp               make_pair
#define pii              pair<int,int>
#define vi               vector<int>
#define vll              vector<long long> 
#define vvi              vector< vector<int>>
#define vvll             vector< vector<long long>>
#define mii              map<int,int>
#define pqb              priority_queue<int>
#define pqs              priority_queue<int, vector<int>, greater<int>>
#define setbits(x)       __builtin_popcountll(x)
#define zrobits(x)       __builtin_ctzll(x)
#define mod              1000000009
#define inf              1e18
#define ps(x,y)          fixed<<setprecision(y)<<x
#define mk(arr, n, type) type *arr=new type[n];
#define wt(x)            int x; cin>>x; while( x-- )
#define rep(i,a,b)       for( int i=a; i<=b; i++ )
#define repi(i,a,b)      for( int i=a; i>=b; i-- )
#define sp               ' '
#define nl               char(10)
#define endl             char(10)
#define PRT(ar)          for( auto i : ar )cout<<i<<sp;cout<<nl;
#define mem(x,ch)        memset(x,ch,sizeof(x))
#define sortv(x)         sort(x.begin(),x.end())
#define sortvr(x)        sort(x.rbegin(),x.rend())

const ll cnst = 1e6 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    #endif
}

bool isOdd(int n){
	return (n&1);
}
int getBit(int n, int i){
	int mask = (1<<i);
	int bit = (n & mask) > 0 ? 1 : 0;
	return bit;
}
int setBit(int n, int i ){
	int mask = (1<<i);
	n = (n | mask) ;
	return n;    
}
int clearBit(int n, int i){
	int mask = ~(1<<i);
	n = (n & mask) ;
	return n; 
}
int updateBit(int &n, int i, int v ){
	int mask = ~(1<<i);
	int cleared_n = (n & mask);
	n = cleared_n | (v << i);
	return n;
}

int getFirstSetBitPos( int n ){
    // n = (n & ~(n-1));
    n = (n & -n);    
    return log2(n);
}

int clearLastIBits(int n, int i ){
	// clear bit from position i+1 to 0
	// int mask = ((~0) << i ); 
	int mask = (-1 << i ); 
	n = (n & mask) ;
	return n;
}
int clearRangeItoJ( int n, int i, int j ){
	int ones=(~0);
	int a = ones << (j+1);
	int b = (1<<i) - 1;
	int mask = a | b ;
	n = (n & mask);
	return n;
}

int countSetBits(int n){
	/* Method 1*/

	// int ans=0;
	// while( n > 0){
	//     ans += (n&1);
	//     n = n>>1;
	// }
	// // return ans;

	/* Method 2 */

	// int ans=0;
	// while( n > 0){
	//     n = n&(n-1);
	//     ans++;
	// }
	// return ans;

	/* Method 3 - Inbuid fn */

	// return __builtin_popcountll(n); // for long long int
	return __builtin_popcount(n); // for integer

}

int decimalToBinary( int n ){
	int ans=0;
	int p=1;
	while(n>0){
		ans += p*(n&1);
		p = p*10;
		n = n>>1;
	}
	return ans;
}

void uniqueNo1( vector<int> &n ){
	int ans=0;
	for( auto x : n ) ans = ans^x;
	cout<<ans<<nl;
}

void uniqueNo2( vector<int> &arr ){
        int ans=0;
        for( auto x : arr ) ans ^= x; // ans = a^b

        // find position of 1st set bit to create mask
        int tmp = ans, pos=0;
        while( (tmp&1) != 1 ){
            pos++;
            tmp = tmp>>1;
        }
        
        int mask = (1<<pos);
        int m=0;
        for( auto x : arr ){
            if( (x&mask) > 0 ){
                m = m^x;
            }
        }
        int n = (ans ^ m);
        cout<<min(m,n)<<sp<<max(m,n)<<nl; 
}

void uniqueNo3( vector<int> &arr ){
        // int m = *max_element( arr.begin(), arr.end() );
        // int n=0;
        // while(m){
        //     n++;
        //     m = (m>>1);;
        // }

        // int ans=0;
        // for( int pos=0; pos<n; pos++ ){
        //     int sum=0;
        //     for( auto &x : arr ){
        //         sum += (x & 1 );
        //         x = x>>1;
        //     }
        //     if( sum%3 != 0 ){
        //         ans = (ans | (1<<pos) ); // set pos th bit of ans
        //     }
        // }
        // cout<<ans<<nl;

		/* Method 2 */
        int cnt[64]={0};
        int n =  arr.size();

        for( int i=0; i<n; i++ ){
            int j=0;
            int x=arr[i];
            while( x > 0 ){
                int last_bit = (x & 1);
                cnt[j] += last_bit;
                j++;
                x = x>>1;
            }
        }

        int ans=0;
        for( int i=0; i<n; i++ ){
            cnt[i] %= 3;
            if( cnt[i] == 1 ){
                ans = (ans| ( 1<<i )); // set ith bit of ans
            }
        }
        cout<<ans<<nl;
}

// Fast Exponentiation / power using bit masking ( O(logN) when N is power of a )
    ll findPwr( ll a, ll n ){
        ll ans=1;
        while( n ){
            int last_bit = (n&1);
            if( last_bit ){
                ans *= a;
            }
            n = n>>1; // Discard the last bit of N
            a = a*a; // Square up
        }
        return ans;
}

class Solution {
    
    public:
    void printSubsequence( string &s ){
        int n=s.size();
        int noOfSubSeq = (1<<n) - 1;
        for( int i=0; i<=noOfSubSeq; i++ ){

            // Filter chars
            string ans="";
            int tmp=i, j=0;
            while(tmp){
                if( (tmp&1) ){
                    ans += s[j];
                }
                j++;
                tmp = tmp>>1;
            }
            cout<<ans<<sp;
        }
        cout<<nl;
    }       
};

int32_t main(){
	fastIO();
	
	int n=9; // 9 = 001001

	cout<<isOdd(n)<<nl; // 1
	cout<<getBit(n, 0)<<nl; // 1
	cout<<setBit(n, 1)<<nl; // 11
	cout<<clearBit(n, 3)<<nl; // 1
	cout<<updateBit(n, 3, 0)<<nl; // 1
	cout<<updateBit(n, 1, 1)<<nl; // 3
	cout<<nl;

    cout<<getFirstSetBitPos(8)<<nl; // 3
    cout<<getFirstSetBitPos(10)<<nl; // 1
    cout<<getFirstSetBitPos(12)<<nl; // 2
    cout<<getFirstSetBitPos(1000)<<nl; // 3 
    cout<<nl;

	n=15; // 15 = 001111
	cout<<clearLastIBits(n, 2)<<nl; // 12

	n=31; // 31 = 0011111
	cout<<clearRangeItoJ(31, 1, 3)<<nl; // 17

	cout<<countSetBits(11)<<nl; // 3 // 14 = 1011

	cout<<decimalToBinary(19)<<nl; // 10011

	vector<int> arr;

	arr.assign({2, 3, 5, 5, 3});
	uniqueNo1(arr ); // 2

	arr.assign({7, 3, 5, 5, 3, 9});
	uniqueNo2(arr); // 7 9
	cout<<nl;

	arr.assign({5, 3, 3, 3, 9, 9, 9, 7, 7, 7});
	uniqueNo3(arr); // 5
	cout<<nl;

	cout<<findPwr(7,3)<<nl; // 343

	// find no. of subsequenes/subsets
    string s="abc";
    (new Solution())->printSubsequence(s); //  a b ab c ac bc abc


	return 0;
}
	
	