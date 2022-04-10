#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define wt(x) int x; cin>>x; while( x-- )

// find next permutation of given arr
class Solution1 {
    public:
    // void Next_permutation( vector<int> &arr ){
    //     int x=-1,y;
    //     for( int i=0; i<arr.size()-1; i++ ) // Traverse from front
    //         if( arr[i] < arr[i+1] )
    //             x=i;
    //     if( x != -1 ){
    //         for( int i=x+1; i<arr.size(); i++ ) // Traverse from front
    //             if( arr[i] > arr[x])
    //                 y = i;
    //         swap( arr[x],arr[y] );
    //         reverse( arr.begin()+x+1, arr.end() );
    //     }
    //     else 
    //         reverse(arr.begin(), arr.end() );
    // }
    

    void Next_permutation( vector<int> & arr ){
        int x,y;
        int n = arr.size();
        for( x=n-2; x>=0; x-- ) // Traverse from back
            if( arr[x] < arr[x+1] )
                break;
        if( x >= 0 ){
            for( y=n-1; y>=x+1; y-- ) // Traverse from back
                if( arr[y] > arr[x] )
                    break;
            swap( arr[x],arr[y] );
            reverse( arr.begin()+x+1, arr.end() );
        } 
        else // if( x < 0)
            reverse( arr.begin(), arr.end() );
    }
};



// to find kth Permutation arr[ 1, 2, 3, ..., n ]
class Solution21 {
    vector<int> fact, digits;
    void solve( string &ans, int n, int k ){
        if( n == 1 ){
            ans += to_string(digits.back() );
            return;
        }
        int indx = k/fact[n-1];
        if( k%fact[n-1] == 0 )
            indx--;

        ans += to_string( digits[indx] );
    
        digits.erase( digits.begin()+indx );
        // k = k - (size of blocks)*(number of blocks);
        k -= fact[n-1]*indx;
        solve( ans, n-1, k );
    }
public:
    string getPermutation(int n, int k) {
        fact.push_back(1);;
        for( int i=1; i<n; i++ )
            fact.push_back( fact[i-1]*i); 
        for( int i=1; i<=n; i++ )
            digits.push_back(i);
        string ans = "";
        solve(ans,n,k);
        return ans;
    }
    // n=3, k=1
    // ans = "123"
};

// to find kth Permutation arr[ 1, 2, 3, ..., n ]// Best Approach 
class Solution22 {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> nums;
        for( int i=1; i<=n-1; i++ ){
            nums.push_back(i);
            fact *= i;
        }
        nums.push_back(n);
        k = k-1; // due to 0 indexing
        string ans = "";
        while( true ){
            ans = ans + to_string( nums[k/fact] );
            nums.erase( nums.begin() + k/fact );

            if( nums.size() == 0 ) break;

            k = k%fact ;
            fact /= nums.size();
        }
        return ans;
    }
    // n = 4, k = 9   // "2314"
    // n = 3, k = 3   // "213"
};



// find all permutation of a array and return it
class Solution31 {
    vector<int> next_permu( vector<int> &num ){
        int k, l, n=num.size();
        for( k=n-2; k>=0; k-- )
            if( num[k] < num[k+1] )
                break;
        if( k < 0 ){
            reverse(num.begin(), num.end());
        }else{
            for( l=n-1; l>k; l-- )
                if( num[l] > num[k] )
                    break;
            swap( num[k], num[l] );
            reverse( num.begin()+k+1, num.end() );
        }
        return num;
    }

    public :
    vector<vector<int>> permute(vector<int>& nums) {
        int fact=1, n=nums.size();
        for( int i=1; i<=n; i++ )
            fact *= i;
        vector<vector<int>> permu;
        if( n==0 ) return permu;
        permu.push_back(nums);
        fact--;
        while( fact-- )
            permu.push_back( next_permu(nums) );
        return permu;
    }
};

// find all permutation of a array and return it // Better approach
class Solution32 {
    void solve( vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[] ){
        if( ds.size() == nums.size() ){
            ans.push_back( ds );
            return;
        }
        for( int i=0; i<nums.size(); i++ ){
            if( !freq[i] ){
                freq[i] = 1;
                ds.push_back(nums[i]);
                solve( ds, nums, ans, freq );
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    public :
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[n];
        memset( freq,0, sizeof(freq) );
        solve( ds, nums, ans, freq );
        return ans;
    }  
};

// find all permutation of a array and return it // Best approach
class Solution33 {
    void solve( int ind, vector<int> &nums, vector<vector<int>> &ans ){
        if( ind == nums.size() ){
            ans.push_back(nums);
            return ;
        }
        for( int i=ind; i<nums.size(); i++ ){
            swap( nums[ind], nums[i] );
            solve( ind+1, nums, ans);
            swap( nums[ind], nums[i] );
        }
    }

    public :
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve( 0, nums, ans );
        return ans;
    }
};




int main(){
    Solution1 sol1;
    int n;  cin>>n;
    vector<int> arr(n);
    for( auto &i:arr )  cin>>i;
    cout<<"\n";

    int number_of_permutation = 5;  // let say 5

    while( number_of_permutation--){
        sol1.Next_permutation( arr );
        for( auto i:arr )   
            cout<<i<<" ";
        cout<<"\n";

        // if( next_permutation(arr.begin(),arr.end() ) ) {
        //     for( auto i:arr )   
        //         cout<<i<<" ";
        //     cout<<"\n";
        // }
        // else {
        //     cout<<"Previous permutation is Greatest permutation \n";
        //     break;
        // }

    }


    
    return 0;
}


/*
9
5 1 7 6 3 9 8 4 2

5 1 7 6 4 2 3 8 9 
5 1 7 6 4 2 3 9 8 
5 1 7 6 4 2 8 3 9 
5 1 7 6 4 2 8 9 3 
5 1 7 6 4 2 9 3 8

*/

/*
5
5 4 3 2 1

1 2 3 4 5 
1 2 3 5 4 
1 2 4 3 5 
1 2 4 5 3 
1 2 5 3 4

//Previous permutation is Greatest permutation
*/