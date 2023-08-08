#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
#define ll long long
#define wt(x) int x; cin>>x; while( x-- )
#define REP(i,n) for( int i=0; i<n; i++ )
#define REPc(i,a,b) for( int i=a; i<b; i++ )
#define REPi(i,n) for( int i=n-1; i>=0; i-- )
#define REPci(i,a,b) for( int i=a; i>=b; i-- )
#define sp ' '
#define nl char(10)
#define endl char(10)
#define MOD 1000000007
#define vi vector<int>
#define vvi vector< vector<int> >
#define vll vector<long long> 
#define vvll vector< vector<long long> >
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define PRT(ar) for( auto i : ar )cout<<i<<sp;cout<<nl;
using namespace std;




// gfg : https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/
// Leet : https://leetcode.com/problems/linked-list-cycle/
// Leet 2 : https://leetcode.com/problems/linked-list-cycle-ii/



struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};



class Solution {
public:
    // Floyd's Algorithm  or  Hare and Tortoise Algorithm
    // To check LinkedList have Cycle or Not
    bool hasCycle1(ListNode* head) {
        unordered_set<ListNode*> st;
        ListNode* cur = head;
        while (cur) {
            if (!st.insert(cur).second) return 1;
            cur = cur->next;
        }
        return 0;
    }

    bool hasCycle(ListNode* head) {
        ListNode* fast = head, * slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return 1;
        }
        return 0;
    }



    // returns node from where cycle starts if cycle present o/w returns NULL
    ListNode* detectCycle1(ListNode* head) {
        unordered_set<ListNode*> st;
        ListNode* cur = head;
        while (cur) {
            if (!st.insert(cur).second) return *st.insert(cur).first;
            cur = cur->next;
        }
        return NULL;
    }


    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next) return NULL;
        ListNode* fast = head, * slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) slow = slow->next, fast = fast->next;
                return slow;
            }
        }
        return NULL;
    }




    // To create a cycle if there was no cycle
    void makeCycle(ListNode* head, int pos) {
        if (!head) return;
        if (hasCycle(head)) {
            cout << "Already hava a Cycle, can't create other \n";
            return;
        }
        ListNode* ptr = head, * startNode;
        int cnt = 1;
        while (ptr->next) {
            if (cnt == pos)
                startNode = ptr;
            ptr = ptr->next;
            cnt++;
        }
        ptr->next = startNode;
    }




    // To Remove cycle if there is
    void removeCycle(ListNode* head) {
        if (!head) return;
        if (!hasCycle(head)) {
            cout << "LinkedList not have a cycle \n";
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        do {
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        fast = head;
        while (slow->next != fast->next)
            slow = slow->next, fast = fast->next;
        slow->next = NULL;
    }


    

    // To create a LinkedList if a vector is given;
    ListNode* createList(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        ListNode* head = new ListNode(0);
        ListNode* ptr = head;
        for (int x : nums)
            ptr->next = new ListNode(x), ptr = ptr->next;
        return head->next;
    }

    // To print values
    void printList(ListNode* head) {
        if (!head) return;
        if (hasCycle(head)) {
            cout << "List have cycle, first remove that\n";
            return;
        }
        cout << "List : ";
        while (head)
            cout << head->val << sp, head = head->next;
        cout << nl;
    }

};


int32_t main() {
    Solution sol;
    vector<int> arr;

    arr.operator=({ 1, 5, 7, 10, 15, 19, 25, 29, 30 });
    ListNode* head = sol.createList(arr);
    sol.printList(head); cout << nl;

    if (sol.hasCycle(head)) cout << "List have a cycle" << nl;
    else cout << "List have not a cycle" << nl << nl;

    sol.makeCycle(head, 3);
    if (sol.hasCycle(head)) cout << "List have a cycle" << nl;
    else cout << "List have not a cycle" << nl;
    sol.printList(head); cout << nl;

    sol.removeCycle(head);
    if (sol.hasCycle(head)) cout << "List have a cycle" << nl;
    else cout << "List have not a cycle" << nl;
    sol.printList(head);
    cout << "\n";

    return 0;
}


// List : 1 5 7 10 15 19 25 29 30 
//
// List have not a cycle
//
// List have a cycle
// List have cycle, first remove that
//
// List have not a cycle
// List : 1 5 7 10 15 19 25 29 30 
