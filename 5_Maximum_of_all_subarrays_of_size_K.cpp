#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
#define wt(x) int x; cin>>x; while( x-- )


// Store indexes in Deque
void printKMax( int arr[], int n, int k ){
    deque<int> Qi(k);
    int i;
    for( i=0; i<k; i++ ){
        // For every element, the previous smaller elements are useless so 
		// remove them from Qi
        while( (! Qi.empty()) && arr[i] >= arr[Qi.back()] )
            Qi.pop_back();
        Qi.push_back(i);
    }
    // i is last index of every window
    for( ; i<n; i++ ){
        cout<<arr[Qi.front()]<<" ";
        // remove element which should not present in next window
        while( (!Qi.empty()) && Qi.front() <= i-k ) 
            Qi.pop_front();

        // Remove all elements smaller than the currently 
		// being added element (remove useless elements) 
        while( (!Qi.empty()) && arr[i] >= arr[Qi.back()] )
            Qi.pop_back();
        Qi.push_back(i) ; 
    }
    cout<<arr[Qi.front()]<<" ";
}

// Driver Main
int main(){
    int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=3;
    printKMax( arr, n, k );

    return 0;
}

// 78 90 90 90 89