#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll               long long
#define ull              unsigned long long
#define ff               first
#define ss               second
#define pb               push_back
#define mp               make_pair
#define pii              pair<int,int>
#define vi               vector<int>
#define vll              vector<ll> 
#define vvi              vector< vector<int>>
#define vvll             vector< vector<ll>>
#define mii              map<int,int>
#define pqb              priority_queue<int>
#define pqs              priority_queue<int, vector<int>, greater<int>>
#define setbits(x)       __builtin_popcountll(x)
#define zrobits(x)       __builtin_ctzll(x)
#define mod              1000000007
#define inf              1e18
#define ps(x,y)          fixed<<setprecision(y)<<x
#define mk(arr, n, type) type *arr=new type[n];
#define wt(x)            int x; cin>>x; while( x-- )
#define rep(i,a,b)       for( int i=a; i<=b; i++ )
#define repi(i,a,b)      for( int i=a; i>=b; i-- )
#define sp               ' '
#define nl               char(10)
#define endl             char(10)
#define PRT(ar)          for( auto i : ar ) cout<<i<<sp; cout<<nl;
#define mems(x,ch)       memset(x,ch,sizeof(x))
#define sortv(x)         sort(x.begin(),x.end())
#define sortvr(x)        sort(x.rbegin(),x.rend())
#define all(x)           x.begin(), x.end()

const ll N = 1e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //    #ifndef ONLINE_JUDGE
    //        freopen("input.txt", "r", stdin);
    //        freopen("output.txt", "w", stdout);
    //    #endif
}


class Solution {

public:
    int a[N + 1], primeCount[N + 1], mobius[N + 1];


    // METHOD - 1
    int calMobius(int n) {
        int cntPrime = 0; // to count how many primes in prime factorization

        // Check for prime=2
        if (n % 2 == 0) {
            n /= 2, cntPrime++;

            // return 0, if no. is squared
            if (n % 2 == 0) return 0;
        }

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                n /= i, cntPrime++;

                // return 0, if no. is squared
                if (n % i == 0) return 0;
            }
        }

        if( n>1 ) cntPrime++;
        
        int ans = ans%2 == 0 ? 1 : -1;
        return ans;
    }



    // METHOD - 1
    // Cal mobius for all N in [1...N]
    // Prime Sieve of Eratosthenes is used // So O(N * logLogN)
    void calMobiusForAll() {
        for (int i = 1; i <= N; i++) a[i] = 1;

        for (int i = 2; i <= N; i++) {
            // Check prime
            if (primeCount[i] == 0) {
                // Mark multiples of j
                for (int j = i; j <= N; j += i) {
                    a[j] *= i;
                    primeCount[j]++;
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            // Check i is squared free or not
            if (a[i] == i) {

                // If prime count is even m[x]=1, odd m[x]=-1   
                if (primeCount[i] % 2 == 0) mobius[i] = 1;
                else mobius[i] = -1;
            } else {
                mobius[i] = 0;
            }
        }
    }

};


// QUE :- https://codeforces.com/problemset/problem/803/F
// Inclusioin-Exclusion principle with Mobius Function on Number theory 
class Solution2 {

public:
    int a[N + 1], primeCount[N + 1], mobius[N + 1];
    int freq[N], p2[N]; // freq for hashing // p2[i] means pow(2, i)%mod 

    void calMobius() {
        for (int i = 1; i <= N; i++) a[i] = 1;

        for (int i = 2; i <= N; i++) {
            // Check prime
            if (primeCount[i] == 0) {
                // Mark mulyiple of i
                for (int j = i; j <= N; j += i) {
                    a[j] = a[j] * i;
                    primeCount[j]++;
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            // Ccheck squared free or not
            if (a[i] == i) {
                if (primeCount[i] % 2 == 0) mobius[i] = 1;
                else mobius[i] = -1;
            } else {
                mobius[i] = 0;
            }
        }
    }


    void solve(vi& b) {
        // Hashing
        for (int i = 0; i < b.size(); i++) {
            freq[b[i]] ++;
        }

        calMobius();

        // Calculate p2 // pow(2,i) % mod
        p2[0] = 1;
        for (int i = 1; i < N; i++) {
            p2[i] = (p2[i - 1] * 2) % mod;
        }

        int ans = 0; // Total subsequences requirred

        for (int i = 1; i < N; i++) {
            int cnt = 0; // find no. of values divisible by i
            for (int j = i; j < N; j += i) {
                cnt += freq[j];
            }

            int totalSubseq = p2[cnt] - 1;
            ans += totalSubseq * mobius[i];
            ans %= mod;
        }

        ans = (ans + mod) % mod;
        cout << ans;
    }

};

int32_t main() {
    fastIO();

    Solution sol;
    sol.calMobiusForAll();
    for (int i = 1; i <= 10; i++) {
        cout << i << ". " << sol.mobius[i] << nl;
    }
    cout<<nl;

    cout<<"1. "<<sol.calMobius(1)<<nl;
    cout<<"3. "<<sol.calMobius(3)<<nl;
    cout<<"6. "<<sol.calMobius(6)<<nl;
    cout<<"30. "<<sol.calMobius(30)<<nl;
    cout<<nl;


    // Solution2 sol2;
    // int n; cin>>n;
    // vi b(n);
    // for( auto &x : b ) cin>>x;
    // sol2.solve( b );

    return 0;
}

// For Solution class
// 1. 1
// 2. -1
// 3. -1
// 4. 0
// 5. -1
// 6. 1
// 7. -1
// 8. 0
// 9. 0
// 10. 1

// for QUE :-
// 3
// 1 2 3
// OUT:- 5
//
// 7
// 1 3 5 15 3 105 35
// OUT:- 100
