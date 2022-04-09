#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #include<functional> // for less<>

using namespace std;
using namespace __gnu_pbds;

// Policy Based Data Structure (PBDS)

// template is used for more specific
template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main(){

    // For set or Ordered set

    oset<int> st;
    st.insert(10);
    st.insert(20);
    st.insert(3);
    st.insert(5);
    st.insert(45);
    st.insert(9);
    st.insert(9); // doubles not allowed
    
    // find_by_order() : kth largest element till now
    for( int i=0; i<st.size(); i++ ){
        cout<<i<<" "<< *st.find_by_order(i)<< "\n";
    }

    // 0 3
    // 1 5
    // 2 9
    // 3 10
    // 4 20
    // 5 45

    // order_of_key(n) : return no. of items strictly less than n // as st is less PBDS
    cout<<st.order_of_key(10)<<endl; // 3
    cout<<st.order_of_key(13)<<endl; // 4
    cout<<endl<<endl;



    // For pair or Map
    oset<pair<int,int>> pst;
    // {value, key} or {value, index} // index or key should be unique
    pst.insert({5, 0});
    pst.insert({10, 4}); 
    pst.insert({3, 3}); 
    pst.insert({35, 15}); 
    pst.insert({35, 10}); 
    pst.insert({35, 20}); 
    pst.insert({64, 7});
    pst.insert(make_pair(80, 10)); 

    // value at ith index
    cout<<"Contains of map : "<<endl;
    for( auto i=0; i<pst.size(); i++ ){
        auto pr = pst.find_by_order(i);
        cout<<i<<" : ( "<<pr->first<<", "<<pr->second<<" )"<<endl;
    }
    cout<<endl;

    // Contains of map :
    // 0 : ( 3, 3 )
    // 1 : ( 5, 0 )
    // 2 : ( 10, 4 )
    // 3 : ( 35, 10 )
    // 4 : ( 35, 15 )
    // 5 : ( 35, 20 )
    // 6 : ( 64, 7 )
    // 7 : ( 80, 10 )

    // index of pair(64, 7 ) // pair present
    cout<<"Index of pair(64,7) : "<< pst.order_of_key({64,7})<<endl; // 6

    // index of pair(64, 10 ) // pair not present
    cout<<"Index of pair(64, 10) : "<< pst.order_of_key({64, 10})<<endl; // 7

    // index of pair(40, 5) // pair not present
    cout<<"Index of pair(40, 5) : "<< pst.order_of_key({40, 5})<<endl; // 6

    
    return 0;
}

// 0 3
// 1 5
// 2 9
// 3 10
// 4 20
// 5 45
// 3
// 4

// Contains of map :
// 0 : ( 3, 3 )
// 1 : ( 5, 0 )
// 2 : ( 10, 4 )
// 3 : ( 35, 10 )
// 4 : ( 35, 15 )
// 5 : ( 35, 20 )
// 6 : ( 64, 7 )
// 7 : ( 80, 10 )

// Index of pair(64,7) : 6
// Index of pair(64, 10) : 7
// Index of pair(40, 5) : 6