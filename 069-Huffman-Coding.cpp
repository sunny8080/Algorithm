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


// Huffman Coding :- https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/

// QUE :- https://www.geeksforgeeks.org/huffman-coding-using-priority-queue/?ref=rp
// Greedy Algo used // O(NlogN)



// Huffman node
class treeNode {
public:
    char data;
    int freq;
    treeNode* left, * right;
    treeNode(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};


// Comparator required in min heap priority queue
class compare {
public:
    bool operator()(treeNode* a, treeNode* b) {
        return a->freq > b->freq;
    }
};

class Solution {
    treeNode* generateTree(priority_queue<treeNode*, vector<treeNode*>, compare>& pq) {
        // pop two node and and a new node by adding their popped nodes to new nodes
        while (pq.size() > 1) {
            treeNode* left = pq.top();
            pq.pop();

            treeNode* right = pq.top();
            pq.pop();

            treeNode* tmp = new treeNode('\0', left->freq + right->freq);
            tie(tmp->left, tmp->right) = make_pair(left, right);
            pq.push(tmp);
        }
        return pq.top();
    }

    void generateCodes(treeNode* root, vi& arr, int cur, map<char, string>& codes) {
        if (root->left) {
            arr[cur] = 0;
            generateCodes(root->left, arr, cur + 1, codes);
        }

        if (root->right) {
            arr[cur] = 1;
            generateCodes(root->right, arr, cur + 1, codes);
        }

        // if node is leaf node then arr[0...cur-1]  is code for that node
        if (!root->left && !root->right) {
            string str;
            for (int i = 0; i < cur; i++) {
                str += to_string(arr[i]);
            }
            codes[root->data] = str;
        }
    }

public:
    void huffmanManCodes(vector<char>& data, vi& freq, int n, map<char, string>& codes) {
        // Create a min heap of nodes and push all the nodes
        // Min heap is requirred in huffman coding
        priority_queue<treeNode*, vector<treeNode*>, compare> pq;

        for (int i = 0; i < n; i++) {
            treeNode* tmp = new treeNode(data[i], freq[i]);
            pq.push(tmp);
        }

        treeNode* root = generateTree(pq);

        // Traverse and find the codes for each chars
        vi arr(n);
        generateCodes(root, arr, 0, codes);
    }

    string encode(string str, map<char, string>& codes) {
        vi tmp(26);
        for (auto ch : str) {
            tmp[ch - 'a']++;
        }

        // Find chars and their frequency
        vector<char> data;
        vector<int> freq;
        for (int i = 0; i < 26; i++) {
            if (tmp[i]) {
                data.push_back(i + 'a');
                freq.push_back(tmp[i]);
            }
        }
        // PRT(data);
        // PRT(freq);
        int n = data.size();
        huffmanManCodes(data, freq, n, codes);

        string s;
        for (auto ch : str) {
            s += codes[ch];
        }
        return s;
    }

    string decode(string str, map<char, string>& codes) {
        // convert [char -> string] to [string -> char] 
        map<string, char> mpp;
        for (auto x : codes) {
            mpp[x.second] = x.first;
        }

        string ans;
        string tmp;
        for (int i = 0; i < str.size(); i++) {
            tmp += str[i];
            if (mpp[tmp]) {
                ans += mpp[tmp];
                tmp = "";
            }
        }
        return ans;
    }

};





int32_t main() {
    fastIO();
    Solution sol;


    vector<char> data = { 'a', 'b', 'c', 'd' };
    vector<int> freq = { 5, 9, 12, 13, 16, 45 };
    int n = data.size();

    map<char, string> codes;
    sol.huffmanManCodes(data, freq, n, codes);
    for (auto x : codes) {
        cout << x.first << sp << x.second << nl;
    }
    cout << nl << nl;






    string str, encoded, decoded;
    map<char, string> codes2;

    str = "abbccda";
    cout << "Original : " << str << nl;

    encoded = sol.encode(str, codes2);
    cout << "Encoded  : " << encoded << nl;

    decoded = sol.decode(encoded, codes2);
    cout << "Decodedd : " << decoded << nl;

    for (auto x : codes2) {
        cout << x.first << sp << x.second << nl;
    }
    cout << nl << nl;

    return 0;
}

