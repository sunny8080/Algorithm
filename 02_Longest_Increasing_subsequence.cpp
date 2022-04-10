#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
#define wt(x) int x; cin>>x; while( x-- )

// METHOD 1 // O(N*N)
int LICS( vector<int> arr, int n ){ // O(N*N)
    vector<int> lis(n);
    lis[0] = 1;
    for( int i=1; i<n; i++ ){
        lis[i] = 1;
        for( int j=0; j<i; j++ )
            if( lis[j]+1 > lis[i] && arr[j] < arr[i] )
                lis[i] = lis[j]+1;
    }

    // For print the longest Increasing sequence
    int ind=0;
    int maxi = lis[0];
    for( int i=n-1; i>0; i-- )
        if( maxi < lis[i] ){
            ind = i;
            maxi = lis[i];
        }
    
    vector<int> sq; // to store sequence
    sq.push_back(arr[ind] );
    for( int i=ind-1; i>=0; i-- ){
        if( lis[i]+1 == lis[ind] && arr[i] < arr[ind] ){
            ind = i;
            sq.push_back(arr[i] );
        }
    }
    reverse(sq.begin(), sq.end() );
    //cout<<"Length of Longest increasing Subsequence : "<<maxi<<"\n";
    cout<<"LICS : ";
    for( auto x : sq )
        cout<<x<<" ";
    cout<<endl;

    return ( *max_element(lis.begin(),lis.end() ) );
}

// METHOD 2 // O(N*logN)
// int LICS( vector<int> arr, int n ){
//     vector<int> seq;
//     seq.push_back(arr[0]);
//     for( int i=1; i<n; i++ ){
//         if( seq.back() < arr[i] )
//             seq.push_back(arr[i]);
//         else{
//             int indx = lower_bound( seq.begin(), seq.end(), arr[i] ) - seq.begin();
//             seq[indx] = arr[i]; 
//         } 
//     }
//     cout<<"LICS : ";
//     for( auto x : seq )
//         cout<<x<<" ";
//     cout<<endl;
//     return (seq.size() );
// }

int main(){
    int n; cin>>n;
    vector<int> arr(n);
    for( auto & i : arr )
        cin>>i;
    int len = LICS( arr, n );
    cout<<"Length of Longest increasing Subsequence : "<<len<<endl;
    
    return 0;
}

// EX :-
// 6
// 50 3 10 7 40 80
// LICS : 3 7 40 80 
// Length of Longest increasing Subsequence : 4

// 9
// 2 5 3 7 11 8 10 13 6
// LICS : 2 3 6 8 10 13 
// Length of Longest increasing Subsequence : 6
