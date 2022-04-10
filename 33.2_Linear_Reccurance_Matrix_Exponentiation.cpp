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


// Question Discussed here
// Linear Reccurance Matrix Exponentiation
// https://www.spoj.com/problems/SPP/


vll b,c;
ll k, MOD ;

class Solution {
	vector<vector<ll>> multiply( vector<vector<ll>> A, vector<vector<ll>> B, ll size ){
        
        vector<vector<ll>> C(size+1, vector<ll>(size+1) );
        // Multiply two vectors
        for( int i=1; i<=size; i++ ){
            for( int j=1; j<=size; j++ ){
                for( int t=1; t<=size; t++ ){
                    C[i][j] = ( C[i][j] + (A[i][t]*B[t][j])%MOD)%MOD;
                }
            }
        }
        return C;
    }

    vector<vector<ll>> pwr( vector<vector<ll>> M, ll n, ll size ){
        if( n == 1 ) return M;
        if( n&1 ){
            return multiply(M,pwr(M, n-1, size), size);
        }
        vector<vector<ll>> tmp = pwr(M,n/2, size);
        return multiply(tmp, tmp, size);
    }

	// Not require for this Question
	// Previous Q :- https://www.spoj.com/problems/SEQ/
	ll findAn(ll n ){
        if( n == 0 ) return 0;
        if( n <= k ) return b[n-1];

        // array to store f(n) - F1(n) 
        // 1 based indexing
        vll F1(k+1);
        for( ll i=1; i<=k; i++ ) F1[i] = b[i-1];

        // create Transformation Matrix
        vector<vector<ll> > T(k+1, vector<ll>(k+1) );

        for( int i=1; i<=k; i++ ){
            for( int j=1; j<=k; j++ ){
                if( i<k ){
                    if( j == i+1 ){
                        T[i][j] = 1;
                    }else{
                        T[i][j] = 0;
                    }
                }else{
                    T[i][j] = c[k-j];
                }
            }
        }

        // Step - 3 // T -> T^n
        T = pwr(T, n-1, k );

        // step - 4 // Matrix[1][i] * vector[i]
        ll ans = 0;
        for( int i=1; i<=k; i++ ){
            ans = (ans + (T[1][i]*F1[i]) %MOD )%MOD;
        }
        return ans;
    }

	ll sum( ll n ){
		if( n == 0 ) return 0;
		if( n <= k ) return accumulate(b.begin(), b.begin()+n, 0);

		// array 1 based Indexing
		vll F1(k+2);
		F1[1] = 1;
		for( int i=1; i<=k+1; i++ ){
			if( i == 1 ){
				F1[i] = accumulate(b.begin(), b.end(), 0);
			}else{
				F1[i] = b[i-2];
			}
		}
		
		// create Transformation matrix
		vector<vector<ll>> T(k+2, vector<ll>(k+2));
		
		for( ll i=1; i<=k+1; i++ ){
			for( ll j=1; j<=k+1; j++ ){
				if( i == 1 ){
					if( j == 1 ) T[i][j] = 1;
					else T[i][j] = c[k-j+1];
				}else if( i == k+1 ){
					if( j == 1 ) T[i][j] = 0;
					else T[i][j] = c[k-j+1];
				}else{
					if( j == i+1 ) T[i][j] = 1;
					else T[i][j] = 0;
				}
			}
		}

		// for(auto x : T) { PRT(x); } // Transformation Matrix

		// step -3
		T = pwr(T, n-k, k+1);

		// for(auto x : T) { PRT(x); }

		// step-4
		ll sum=0;
		for( ll i=1; i<=k+1; i++ ){
			sum = ( sum + (T[1][i]*F1[i]) % MOD) %MOD;
		}


		return sum;
	}


	public:

	ll solve( ll m, ll n ){
		ll cnt1 = sum(m-1);
		ll cnt2 = sum(n);

		// cout<<"sum(m-1) : "<<cnt1<<nl<<nl;
		// cout<<"sum(n) : "<<cnt2<<nl;

		ll ans = ( ( cnt2 - cnt1 )%MOD + MOD ) % MOD ;
		return ans;
	}
};

int32_t main(){
	fastIO();
	

	wt(t){
		cin>>k;
		ll x;
		for( ll i=0; i<k; i++ ){ cin>>x; b.pb(x); }
		for( ll i=0; i<k; i++ ){ cin>>x; c.pb(x); }
		ll m, n; 
		cin>>m>>n>>MOD;

		cout<<(new Solution())->solve(m ,n)<<nl;

		b.clear();
		c.clear();
	}

	
	return 0;
}
	
	
// 1
// 2
// 1 1
// 1 1
// 2 10 1000003
// output :- 
// 142
