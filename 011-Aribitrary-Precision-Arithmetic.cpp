#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
#define ll long long
#define wt(x) int x; cin>>x; while( x-- )
typedef vector<int> lnum;
const int base = 1000*1000*1000;
#define nl "\n"

// PRINT long integer A
void printLnum( lnum a ){
    printf("%d",a.empty() ? 0 : a.back() );

    for( int i=(int)a.size()-2; i>=0; i-- )
        printf("%09d", a[i] );  // as base is of 9 digits
    cout<<endl;
}

// TO REMOVE LEADING ZERO FROM A
void remove_zero( lnum & a ){
    while( a.size() > 1 && a.back()==0 )
        a.pop_back();
}

// TAKE INPUT WHEN STRING IS C++ BASED STRING AND RETURN THAT NUM
lnum takeinput( string s ){ 
    //cout<<"C++String"<<endl;
    lnum a;
    for( int i=(int)s.length(); i>0; i-=9 ){
        if( i<9 )
            a.push_back( atoi( s.substr( 0,i).c_str() ) );
        else 
            a.push_back( atoi( s.substr(i-9,9).c_str() ) );
    }
    remove_zero(a);
    return a;
}

// TAKE INPUT WHEN STRING IS C-BASED STRING AND RETURN THAT NUM
lnum takeinput( char s[] ){
    //cout<<"C char string"<<endl;
    lnum a;
    for( int i=(int)strlen(s); i>0; i-=9 ){
        s[i]=0;
        a.push_back( atoi(i>=9 ? s+i-9 : s ) );
    }
    remove_zero(a);
    return a;
}

// ADD A AND B AND RESTRORE IT IN A AND RETURN A
lnum add( lnum a, lnum b ){
    int carry = 0;
    for( size_t i=0; i<max(a.size(), b.size()) || carry ; i++ ){
        if( i == a.size() ) 
            a.push_back(0);
        a[i] += carry + ( i<b.size() ? b[i] : 0 );
        carry =( a[i] >= base );
        if( carry ) 
            a[i] -= base;
    }   
    return a;
}

// SUBSTRACT B FROM A( A>= B ) AND STORE IT IN A
lnum subtract( lnum a, lnum b ){
    int carry=0;
    for( size_t i=0; i<b.size() || carry ; i++ ){
        if( i == a.size() )
            a.push_back(0);
        a[i] -= carry + ( i<b.size() ? b[i]:0 );
        carry = ( a[i]<0 );
        if( carry ) 
            a[i]+= base;
    }
    remove_zero(a);
    return a;
} 

// Multiply long integer a by short integer b (b<base) and store result in a
lnum mul( lnum a, int b ){
    ll carry = 0;
    for( size_t i=0; i<a.size() || carry; i++){
        if( i == a.size() )
            a.push_back(0);
        ll cur = carry + a[i]*1LL*b ;
        a[i] = int(cur%base) ; // slower
        carry = int( cur / base );
        // a[i] = int(cur - carry * base) ; // faster
    }
    remove_zero(a);
    return a;
}

// Multiply long integers a and b and store result in c
lnum mul( lnum a, lnum b ){
    lnum c(a.size()+b.size() );
    ll carry=0 ;
    for( size_t i=0; i<a.size(); i++ ){
        for( int j=0, carry=0; j<(int)b.size() || carry ; j++ ){
            ll cur = c[i+j] + carry + a[i]*1LL*( j<(int)b.size() ? b[j]:0 )  ;
            c[i+j] = int( cur % base );
            carry = int( cur/base);
            //c[i+j] = int( cur - carry*base );
        }
    }
    remove_zero(c);
    return c;
}

// Divide long integer a by short integer b (b<base), store integer result in a and remainder in carry
lnum divide( lnum a, int b ){
    int carry=0;
    for( int i=(int)a.size()-1; i>=0; i-- ){
        ll cur = a[i] + carry*1LL*base;
        a[i] = int(cur/b);
        carry = int(cur%b);
    }
    remove_zero(a);
    return a;
}

int main(){
    
    // string str = "123456789000123789111";
    // lnum a = takeinput(str); // 123456789000123789111
    // printLnum(a); // 123456789000123789111

    // char cs[] = "00011234501123";
    // lnum b = takeinput(cs);
    // printLnum(b); // 11234501123

    // lnum ad, mins, mult, multL, divd ;
    // ad = add(a,b);
    // printLnum(ad); // 123456789011358290234

    // mins = subtract(a,b);
    // printLnum(mins); // 123456788988889287988

    // mult = mul(a,10);
    // printLnum(mult); // 1234567890001237891110

    // multL = mul(a,b);
    // printLnum(multL); // 1386975434663864755906544671653

    // divd = divide(a,10);
    // printLnum(divd); // 12345678900012378911

    string a; cin>>a;
    int n; cin>>n;

    lnum a1,a2,a3;
    a1 = takeinput(a);
    printLnum( mul(a1,n) );
    
    return 0;
}


// 123456789000123789111
// 11234501123
// 123456789011358290234
// 123456788988889287988
// 1234567890001237891110
// 1386975434663864755906544671653
// 12345678900012378911

/*

int base=1000*1000*100;
typedef vector<int> lnum;

void remove_zero( lnum &a ){
    while( a.size()>1 && a.back()==0 )
        a.pop_back();
}
bool isNegative( lnum a ){
    return (a.back()<0);
}
lnum takeInput( string str ){
    lnum a;
    for( int i=(int)str.size(); i>0; i-=9 )
        if( i<8 )
            a.push_back( atoi(str.substr(0,i).c_str() ) );
        else    
            a.push_back( atoi(str.substr(i-8,8).c_str() ));
    remove_zero(a);
    if( str[0] == '-' ) { 
        if( a.back() >0 ) 
            a.back() = a.back()*1LL *(-1);
        //cout<<a.back()<<"\n";
    }
    return a;
}
void printLnum( lnum a ){
    printf("%d",a.empty()?0:a.back() );
    for( int i=(int)a.size()-2; i>=0; i-- )
        printf("%08d",a[i] );
    cout<<nl;
}

bool operator>( lnum a, lnum b ){
    if( isNegative(a) && !isNegative(b) ) return false;
    if( !isNegative(a) && isNegative(b) ) return true;
    if( !isNegative(a) && !isNegative(b) ){
        if( a.size() > b.size() ) return true;
        if( a.size() < b.size() ) return false;
        int i;
        for( i=a.size()-1; i>=0; i-- )
            if( a[i] > b[i] ) return true;

        return false;
    }
    if( isNegative(a) && isNegative(b) ){
        if( a.size() > b.size() ) return false;
        if( a.size() < b.size() ) return true;
        int i=a.size()-1;
        if( a[i] > b[i] ) return true;
         if( a[i] < b[i] ) return false ;
        for( i=a.size()-2; i>=0; i-- )
            if( a[i] > b[i] ) return false;
        if( i < 0 ) return false;
        return true;
    }
    return false;
}
lnum mul( lnum a, lnum b ){
    lnum c( a.size()+b.size() );
    ll carry;
    for( int i=0; i<(int)a.size(); i++ ){
        for( int j=0,carry=0; j<(int)b.size() || carry ; j++  ){
            ll curr = (ll)c[i+j] + carry + a[i]*1LL*( j<(int)b.size() ? b[j]:0 );
            c[i+j] = (int)(curr%base);
            carry = (int)(curr/base);
        }
    }
    remove_zero(c);
    return c;
}

lnum maxProduct( vector<lnum> arr, int n ){
    lnum mini = arr[0];
    lnum maxi = arr[0];
    lnum prod = arr[0];
    for( int i=1; i<n; i++ ){
        //printLnum(maxi);
        if( isNegative(arr[i]) )
            swap(mini, maxi);
        
        // printLnum(arr[i]);
        // printLnum(maxi);
        // printLnum(mul(arr[i],maxi) );
        maxi = (arr[i] > mul(arr[i],maxi) ) ? arr[i] : mul(arr[i],maxi) ; 
        mini = (arr[i] > mul(arr[i],mini) ) ? mul(arr[i],mini) : arr[i] ; 
        //maxi = max( arr[i], arr[i]*maxi );
        //mini = min( arr[i], arr[i]*mini );
        if( maxi > prod )
            prod = maxi;
        //printLnum(prod);
        //cout<<"\n";
    }
    //printLnum(maxi);
    return prod;
}

*/


