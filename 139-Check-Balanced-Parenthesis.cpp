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
#define sp               ' '
#define nl               char(10)
#define PRT(ar)          for( auto i : ar ) cout<<i<<sp; cout<<nl;
#define mems(x,ch)       memset(x,ch,sizeof(x))
#define sortv(x)         sort(x.begin(),x.end())
#define sortvr(x)        sort(x.rbegin(),x.rend())
#define all(x)           x.begin(), x.end()
#define fr(t,a,b)        for( int t=(a); t<=(b); t++)
#define frr(t,a,b)       for( int t=(a); t>=(b); t--)
#define cn(x)            int x; cin>>x;

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


// QUE :- https://leetcode.com/problems/valid-parentheses/

class Solution {
    bool isOpen(char ch) {
        return (ch == '(' || ch == '{' || ch == '[');
    }
    char closeB(char ch) {
        if (ch == '(') return ')';
        if (ch == '{') return '}';
        return ']';
    }

    int getTop(string& s, int ind) {
        int right = 0;
        while (ind >= 0) {
            if (isOpen(s[ind])) right--;
            else right++;
            if (right < 0) return ind;
            ind--;
        }
        return -1;
    }
public:
    // O(N) space
    bool isValid1(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (isOpen(s[i])) stk.push(s[i]);
            else {
                if (stk.empty()) return false;
                if (s[i] != closeB(stk.top())) return false;
                stk.pop();
            }
        }

        return (stk.empty() ? 1 : 0);
    }

    // O(1) space
    bool isValid(string& s) {
        int top = -1;
        for (int i = 0; i < s.size(); i++) {
            if (isOpen(s[i])) top = i;
            else {
                if (top == -1 || s[i] != closeB(s[top])) return false;
                else {
                    top = getTop(s, top - 1);
                }
            }
        }

        return top == -1;
    }

};


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



