#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
// #define int              long long
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
#define vpii             vector<pair<int,int>>
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
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}



class Solution {

public:
    void solve(int* net, int friends) {
        // init a list & sort it
        multiset<int> mst;
        for (int i = 0; i < friends; i++) {
            if (net[i] != 0) {
                mst.insert(net[i]);
            }
        }

        int cnt = 0; // no of transaction
        // pop out two person (leftmost & rightmost) to settke down
        while (!mst.empty()) {
            auto left = mst.begin();
            auto right = prev(mst.end());

            // erase
            mst.erase(left);
            mst.erase(right);

            // debit -> giver (-ve) // credit -> receiver
            int debit, credit;
            tie(debit, credit) = make_pair(*left, *right);

            // settle
            int stl_amt = min(-debit, credit);
            debit += stl_amt;
            credit -= stl_amt;

            if (debit != 0) mst.insert(debit);
            if (credit != 0) mst.insert(credit);
            cnt++;
        }

        cout << "No. of transaction : " << cnt << nl;
    }
};



// find no. of transaction

class myCompare {
public:
    bool operator()(pair<string, int> p1, pair<string, int> p2) {
        return p1.second < p2.second;
    }
};


class Solution2 {

public:
    void solve(map<string, int>& net, int friends) {
        multiset<pair<string, int>, myCompare> mst;
        // Iterate over all the person
        for( auto x : net ){
            string person;
            int netAmt;
            tie( person, netAmt) = x;
            if( netAmt != 0 ){
                mst.insert({person, netAmt});
            } 
        }

        // settel
        int cnt=0; // no of transaction
        while( !mst.empty()){
            auto left = mst.begin();
            auto right = prev(mst.end());

            // erase
            mst.erase(left);
            mst.erase(right);

            int debit, credit;
            string debit_per, credit_per;
            tie(debit_per, debit) = *left;
            tie(credit_per, credit) = *right;

            // settel
            int stl_amt = min(-debit, credit);
            debit += stl_amt;
            credit -= stl_amt;

            if( debit != 0 ) mst.insert({debit_per, debit});
            if (credit != 0) mst.insert({ credit_per, credit });

            // print the transaction details
            cout<<debit_per<<" will pay "<<stl_amt<<" to "<<credit_per<<nl; 
            cnt++;
        }
        cout<<"No. of transaction : "<<cnt<<nl;
    }
};




int32_t main() {
    fastIO();

    // {
    //     Solution sol;
    //     int no_of_transaction, friends;
    //     cin >> no_of_transaction >> friends;

    //     // 1-d array to store the net amount of that each person will have to take at the end
    //     int net[100000] = { 0 };

    //     while (no_of_transaction--) {
    //         int x, y, amt; cin >> x >> y >> amt;
    //         net[x] -= amt;
    //         net[y] += amt;
    //     }
    //     sol.solve(net, friends);
    // }


    {
        Solution2 sol2;
        int no_of_transaction, friends;
        cin >> no_of_transaction >> friends;

        map<string, int> net;

        while (no_of_transaction--) {
            string x, y;
            int amt;
            cin >> x >> y >> amt;
            if (net.count(x) == 0) net[x] = 0;
            if (net.count(y) == 0) net[y] = 0;

            net[x] -= amt;
            net[y] += amt;
        }
        sol2.solve(net, friends);
    }


    return 0;
}

// OUT :-
//
// 3 3
// 0 1 100
// 1 2 50
// 2 0 30
//
// No.of transaction : 2
//
//
//
// 3 3
// Rahul Ajay 100
// Ajay Neha 50
// Neha Rahul 40
//
// Rahul will pay 50 to Ajay
// Rahul will pay 10 to Neha
// No.of transaction : 2