#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
#define wt(x) int x; cin>>x; while( x-- )

struct Workshop{
    int start_time, end_time, duration;
};

struct Activity{
    int n;
    Workshop *arr;
};

Activity * create_Activity( int start_time[], int duration[], int n ){
    Activity *ptr = new Activity;
    ptr->n = n ;
    ptr->arr = new Workshop[n];
    for( int i=0; i<n; i++ ){
        ptr->arr[i].start_time = start_time[i];
        ptr->arr[i].duration = duration[i];
        ptr->arr[i].end_time= start_time[i] + duration[i] ;
    }
    return ptr;
}

bool compare_workshop( Workshop w1, Workshop w2 ){
    return (w1.end_time < w2.end_time );
}

void calculateMaxWork( Activity* work ){
    int n = work->n;
    Workshop *tm = work->arr;
    sort( tm, tm+n, compare_workshop );

    int i=0;
    int cnt=1;
    cout<<"Workshop can be done : ";
    cout<<"("<<tm[i].start_time<<" "<<tm[i].end_time<<") ";
    for( int j=1; j<n; j++ ){
        if( tm[j].start_time >= tm[i].end_time ){
            i=j; 
            cout<<"("<<tm[i].start_time<<" "<<tm[i].end_time<<") ";
            cnt++;
        }
    }
    cout<<endl;
    cout<<"Maximum workshops : "<<cnt<<endl;
}

int main(){
    int n;
    cout<<"Enter No. of intervals : ";  cin>>n;
    int start_time[n], duration[n];
    for( int i=0; i<n; i++ )
        cin>>start_time[i];
    for( int i=0; i<n; i++ )
        cin>>duration[i];

    Activity *work = create_Activity( start_time, duration, n );
    calculateMaxWork( work );

    return 0;
}

// Enter No. of intervals : 6
// 1 3 0 5 5 8
// 1 1 6 2 4 1
// Workshop can be done : (1 2) (3 4) (5 7) (8 9) 
// Maximum workshops : 4