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


// Trie is also called as prefix tree
// Trie data str is a tree like data str 



// QUE 1 :- https://leetcode.com/problems/implement-trie-prefix-tree/
// QUE 2 :- https://practice.geeksforgeeks.org/problems/shortest-unique-prefix-for-every-word/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article




// terminal = true means => there is word ending at that index 
// terminal = false means => it is just a key prefix 
struct Node {
    char data;
    map<char, Node*> child;
    bool terminal;
    int cnt; // no of words starting from given node

    Node(char d) {
        tie(data, terminal) = make_tuple(d, false);
        cnt = 0;
    }
};




class Trie {
    Node* root;
    char ch;
public:
    Trie() {
        ch = '\0';
        root = new Node(ch);
    }


    // insert a string
    void insert(string word) {
        Node* temp = root;
        for (auto ch : word) {
            if (temp->child.count(ch) == 0) {
                temp->child[ch] = new Node(ch);
            }
            temp->cnt += 1;
            temp = temp->child[ch];
        }
        temp->cnt += 1;
        temp->terminal = true;
    }


    // check is the string word is present is the trie or not
    bool search(string word) {
        Node* tmp = root;
        for (auto ch : word) {
            if (tmp->child.count(ch) == 0) return 0;
            tmp = tmp->child[ch];
        }

        // check the last char is a terminal char or not
        return tmp->terminal;
    }


    // check a string starts with the prefix, prefix, or not
    bool startsWith(string prefix) {
        Node* tmp = root;
        for (auto ch : prefix) {
            if (tmp->child.count(ch) == 0) return 0;
            tmp = tmp->child[ch];
        }
        return 1;
    }


    // return a unique prefix for the string s, if not found return "-1"
    string uniquePrefix(string s) {
        string ans = "";
        Node* tmp = root;

        for (auto ch : s) {
            if (tmp->child.count(ch) == 0) return "-1";
            ans += ch;
            if (tmp->child[ch]->cnt == 1) return ans;
            tmp = tmp->child[ch];
        }
        if (tmp->cnt != 1) return "-1";  // cobra cobras
        return ans;
    }

    // return no of strings which start with the prefix pre
    int name_with_prefix(string pre) {
        Node* cur = root;
        for (auto ch : pre) {
            if (cur->child.count(ch) == 0) return 0;
            cur = cur->child[ch];
        }
        return cur->cnt;
    }


    // return how many strings are smaller than string name
    int lexicographically_smaller(string name) {
        Node* cur = root;
        int ans = 0;
        for (auto ch : name) {
            for (char c = 'a'; c != ch; c++) {
                if (cur->child[c] != NULL) ans += cur->child[c]->cnt;
            }

            if (cur->child.count(ch) == 0) return ans;
            cur = cur->child[ch];
        }
        return ans;
    }



    // return is there any substring, which matches with the given pattern
    bool stringMatching(string text, string pat) {
        // construct trie // insert all suffix substring  // root should NULL
        for (int i = 0; i < text.size(); i++) {
            insert(text.substr(i));
        }
        return startsWith(pat);
    }
};



/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */












struct node2 {
    node2* nxt[26];
    bool ended;
    node2() {
        for (int i = 0; i < 26; i++) nxt[i] = NULL;
        ended = false;
    }
};


class Trie2 {
    node2* root;
public:
    Trie2() {
        root = new node2();
    }

    void insert(string s) {
        node2* cur = root;
        for (auto ch : s) {
            int t = ch - 'a';
            if (cur->nxt[t] == NULL) cur->nxt[t] = new node2();
            cur = cur->nxt[t];
        }
        cur->ended = true;
    }

    bool search(string s) {
        node2* cur = root;
        for (auto ch : s) {
            int t = ch - 'a';
            if (cur->nxt[t] == NULL) return 0;
            cur = cur->nxt[t];
        }
        return cur->ended;
    }

    bool startsWith(string prefix) {
        node2* cur = root;
        for (auto ch : prefix) {
            int t = ch - 'a';
            if (cur->nxt[t] == NULL) return 0;
            cur = cur->nxt[t];
        }
        return 1;
    }


    // return is there any substring, which matches with the given pattern
    bool stringMatching(string text, string pat) {
        // construct trie // insert all suffix substring  // root should NULL
        for (int i = 0; i < text.size(); i++) {
            insert(text.substr(i));
        }
        return startsWith(pat);
    }

};




int32_t main() {
    fastIO();


    {
        Trie t;
        vector<string> words = { "cobra", "cobras", "dog", "dove", "duck" }; // -1 cobras dog dov du
        int n = words.size();

        for (int i = 0; i < n; i++)
            t.insert(words[i]);

        cout << t.search("cobra") << nl; // 1
        cout << t.search("dog") << nl; // 1
        cout << t.search("ace") << nl; // 0
        cout << t.startsWith("hell") << nl; // 0

        for (int i = 0; i < n; i++) cout << t.uniquePrefix(words[i]) << sp;
        cout << nl;

        cout << t.name_with_prefix("co") << nl; // 2
        cout << t.name_with_prefix("coa") << nl; // 0

        cout << t.lexicographically_smaller("aaaaaaaaaaaaaa") << nl; // 0
        cout << t.lexicographically_smaller("dove") << nl; // 3
        cout << t.lexicographically_smaller("zzzzzzzzzzzzzz") << nl; // 5

    }
    cout << nl;


    {
        string text = "abaacadbacad";
        string pat = "aaca";
        string pat2 = "axyz";

        // // O(N*M)
        // int fnd = 0;
        // for (int i = 0; i + pat.size() <= text.size(); i++) {
        //     if (text.substr(i, pat.size()) == pat) {
        //         cout << "Found at index : " << i << nl;
        //         fnd = 1;
        //         break;
        //     }
        // }
        // if (!fnd) cout << "Not found" << nl;

        Trie t;
        cout << t.stringMatching(text, pat) << nl; // 1
        cout << t.stringMatching(text, pat2) << nl; // 0

        Trie2 t2;
        cout << t2.stringMatching(text, pat) << nl; // 1
        // cout << t2.search(text) << nl; // 1
        cout << t2.stringMatching(text, pat2) << nl; // 0
    }



    return 0;
}

