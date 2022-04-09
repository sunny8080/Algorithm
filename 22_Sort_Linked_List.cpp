#include<bits/stdc++.h>
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

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode( int val ) : val(val), next(nullptr){}
    ListNode( int val, ListNode *next) : val(val), next(next){}
};


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // if( !head || !head->next ) return head;
        // vector<int> vec;
        // ListNode* ptr=head;
        // while( ptr ) vec.push_back(ptr->val), ptr=ptr->next;
        // sort( vec.begin(), vec.end() );
        // ptr=head;
        // for( int x : vec ) ptr->val=x, ptr=ptr->next;
        // return head;

        // Using Merge Sort // TOP-DOWN
        if( !head || !head->next ) return head;
        ListNode *mid = getMid( head );
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return mergeList( left, right );
    }
    ListNode *mergeList( ListNode *head1, ListNode *head2 ){
        ListNode *dummy = new ListNode(0), *ptr=dummy ;
        while( head1 && head2 )
            if( head1->val < head2->val )
                ptr->next=head1, head1=head1->next, ptr=ptr->next;
            else 
                ptr->next=head2, head2=head2->next, ptr=ptr->next;
        if( head1 ) ptr->next = head1;
        else ptr->next = head2;
        return dummy->next;
    }
    ListNode *getMid( ListNode *head ){
        if( !head || !head->next ) return head;
        ListNode *midPrev=NULL;
        while( head && head->next ){
            midPrev = (midPrev==NULL) ? head : midPrev->next;
            head = head->next->next;
        }
        ListNode *mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
    }


    ListNode *getMiddle( ListNode *head ){
        if( !head || !head->next ) return head;
        ListNode *slow=head;
        ListNode *fast=head;
        while( fast->next && fast->next )
            slow=slow->next, fast=fast->next->next;
        return slow;
    }
    ListNode *createList( vector<int>& nums ){
        if( nums.size() ==0 ) return NULL; 
        ListNode *dummy = new ListNode;
        ListNode *ptr=dummy;
        for( int x : nums )
            ptr->next = new ListNode(x), ptr=ptr->next;
        return dummy->next;
    }
    void printList( ListNode *head ){
        cout<<"List : ";
        while( head )
            cout<<head->val<<sp, head=head->next; 
        cout<<nl;
    }
};

// Merge Sort // BOTTOM - UP approach
class Solution2 {
    ListNode *tail = new ListNode(0);
    ListNode *nextSubList = new ListNode(0);
    public:
    ListNode* sortList(ListNode* head) {
        if( !head || !head->next ) return head;
        int n=countLength(head);
        ListNode *start=head;
        ListNode dummyNode(0);
        for( int size=1; size<n; size*=2 ){
            tail = &dummyNode;
            while( start ){
                if( !start->next ){
                    tail->next=start;
                    break;
                }
                ListNode *mid = split( start, size );
                merge( start, mid );
                start = nextSubList;
            }
            start = dummyNode.next;
        }
        return dummyNode.next;
    }
    ListNode *split( ListNode *start, int size ){
        ListNode *midPrev = start;
        ListNode *end = start->next;
        for( int i=1; i<size && ( midPrev->next || end->next ); i++ ){
            if( midPrev->next ) midPrev=midPrev->next;
            if( end->next ) end=(end->next->next) ? end->next->next : end->next;
        }

        ListNode *mid=midPrev->next;
        nextSubList = end->next;
        midPrev->next = nullptr;
        end->next = nullptr;
        return mid;
    }
    void merge( ListNode *head1, ListNode *head2 ){
        ListNode *dummy = new ListNode(0);
        ListNode *newTail=dummy;
        while( head1 && head2 )
            if( head1->val < head2->val )
                newTail->next=head1, head1=head1->next, newTail=newTail->next;
            else 
                newTail->next=head2, head2=head2->next, newTail=newTail->next;
        newTail->next = (head1) ? head1 : head2; 
        while( newTail->next ) newTail=newTail->next;
        
        tail->next = dummy->next;
        tail = newTail;
    }
    int countLength( ListNode *head ){
        int cnt=0;
        while( head ) cnt++, head=head->next;
        return cnt;
    }
};

// Sorting of Linked List by Insertion Sort 
class Solution3 {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        while( head ){
            ListNode *ptr=dummy;
            while( ptr->next && ptr->next->val < head->val )
                ptr = ptr->next;
            ListNode *nex = head->next;
            head->next = ptr->next;
            ptr->next = head;
            head = nex;
        }      
        return dummy->next;
    }
};


// Driver part
int32_t main(){
    Solution sol;
    Solution2 sol2;
    Solution3 sol3;
    vector<int> arr;

    arr.operator=({ 5, 8, 1, -5, 10, 15, 12, 36 });
    ListNode *head = sol.createList(arr);
    sol.printList(head); // List : 5 8 1 -5 10 15 12 36 

    //head = sol.sortList(head);
    //head = sol2.sortList(head);
    head = sol3.insertionSortList(head);
    sol.printList(head); // List : -5 1 5 8 10 12 15 36
    
    return 0;
}