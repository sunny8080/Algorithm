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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution{
    public:
    // To create a LinkedList if a vector is given;
    ListNode* createList( vector<int> &nums ){
        if( nums.size() == 0 ) return NULL;
        ListNode *head = new ListNode(0);
        ListNode *ptr=head;
        for( int x : nums )
            ptr->next = new ListNode(x), ptr=ptr->next;
        return head->next;
    }

    // To print values
    void printList( ListNode *head ){
        cout<<"List : ";
        while( head )
            cout<<head->val<<sp, head = head->next;
        cout<<nl;
    }
    ListNode* mergeList( ListNode *head1, ListNode *head2 ){
        // if( !head1 ) return head2;
        // if( !head2 ) return head1;
        // ListNode *dummy=new ListNode(0);
        // ListNode *ptr=dummy;
        // while( head1 && head2 ){
        //     if( head1->val < head2->val )
        //         ptr->next = head1, ptr=ptr->next, head1=head1->next;
        //     else 
        //         ptr->next=head2, ptr=ptr->next, head2=head2->next;
        // }
        // if( head1 ) ptr->next = head1;
        // else ptr->next = head2;
        // return dummy->next;


        if( !head1 ) return head2;
        if( !head2 ) return head1;
        if( head1->val > head2->val ) swap(head1,head2);
        ListNode *res=head1;
        while( head1 && head2 ){
            ListNode *tmp=NULL;
            while( head1 && head1->val <= head2->val ){
                tmp=head1, head1=head1->next;
            }
            tmp->next=head2;
            swap(head1,head2);
        }
        return res;
    }
};
int32_t main(){
    Solution sol;
    vector<int> arr1;
    vector<int> arr2;

    arr1.operator=({1,5,7,9,12,15});
    arr2.operator=({6,10,12,14,20,25});

    ListNode *head1=sol.createList(arr1), *head2=sol.createList(arr2);
    ListNode *res=sol.mergeList(head1,head2);
    sol.printList(res);



    return 0;
}



// List : 1 5 6 7 9 10 12 12 14 15 20 25