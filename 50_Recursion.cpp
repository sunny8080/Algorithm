#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
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

const ll cnst = 1e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //    #ifndef ONLINE_JUDGE
    //        freopen("input.txt", "r", stdin);
    //        freopen("output.txt", "w", stdout);
    //    #endif
}


class Solution {

public:

    // Time - O(N) // Space - O(N)
    int fact(int n) {
        if (n == 0) return 1;
        return n * fact(n - 1);
    }

    // Time - O(N) // Space - O(N)
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        return fib(n - 1) + fib(n - 2);
    }

    void printDec(int n) {
        if (n == 0) return;
        cout << n << sp;
        printDec(n - 1);
    }

    void printInc(int n) {
        if (n == 0) return;
        printDec(n - 1);
        cout << n << sp;
    }

    bool isSorted(int* a, int n) {
        if (n == 0 or n == 1) return true;

        if (a[0] < a[1] and isSorted(a + 1, n - 1)) {
            return true;
        }
        return false;
    }

    int firstOccurance(int* a, int n, int key) {
        if (n == 0) return -1;
        if (a[0] == key) return 0;
        int i = firstOccurance(a + 1, n - 1, key);
        if (i == -1) return 0;
        return i + 1;
    }

    int lastOccurance(int* a, int n, int key) {
        //base case
        if (n == 0) return -1;
        int ind = lastOccurance(a + 1, n - 1, key);
        if (ind == -1) {
            if (a[0] == key) return 0;
            else return -1;
        }
        return ind + 1;
    }

    void allOccurance(int* a, int i, int n, int key) {
        if (i == n) return;
        if (a[i] == key) cout << i << sp;
        allOccurance(a, i + 1, n, key);
    }

    // Return no. of occurances 
    int allOcc(int* a, int i, int n, int key, int* out, int j) {
        if (i == n) return j;
        if (a[i] == key) {
            out[j++] = i;
        }
        return allOcc(a, i + 1, n, key, out, j);
    }

    int linearSearch(int* a, int i, int n, int key) {
        if (i == n) return -1;
        if (n == 0) return -1;
        if (a[i] == key) return i;
        return linearSearch(a, i + 1, n, key);
    }

    // array should be sorted
    int binarySearch(int* a, int l, int r, int key) { // i, j included
        if (r < l) return -1;
        int mid = (r - l + 1) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) return binarySearch(a, mid + 1, r, key);
        if (a[mid] > key) return binarySearch(a, l, mid - 1, key);
        return mid;
    }


    int power(int a, int n) {
        if (n == 0)return 1;
        return a * power(a, n - 1);
    }

    int fastPower(int a, int n) {
        if (n == 0) return 1;
        int ans = fastPower(a, n / 2);
        ans *= ans;
        if ((n & 1)) return ans * a;
        return ans;
    }

    // Bubble Sort
    void bubbleSort(int arr[], int n) {
        if (n == 1) return;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
        bubbleSort(arr, n - 1);
    }

    void bubbleSortRecursive(int arr[], int j, int n) {
        if (n == 1) return;
        if (j == n - 1) {
            return bubbleSortRecursive(arr, 0, n - 1);
        }
        if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        bubbleSortRecursive(arr, j + 1, n);
    }

    void merge(int arr[], int l, int r) {
        int mid = (l + r) / 2;
        int i = l, j = mid + 1, k = 0;
        int tmp[r - l + 1];

        while ((i <= mid) && (j <= r)) {
            if (arr[i] < arr[j]) tmp[k++] = arr[i++];
            else if (arr[i] >= arr[j]) tmp[k++] = arr[j++];
        }

        while (i <= mid) tmp[k++] = arr[i++];
        while (j <= r) tmp[k++] = arr[j++];

        for (int i = l; i <= r; i++) arr[i] = tmp[i - l];
    }

    // Merge sort
    void mergeSort(int arr[], int l, int r) {
        if (l >= r) return;
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        // Merge two sorted array - [l ... mid] and [mid+1 ... r]
        merge(arr, l, r);
    }



    int mergeCount(int arr[], int l, int r) {
        int mid = (r + l) / 2;
        int i = l;
        int j = mid + 1;
        int k = 0;
        int tmp[r - l + 1];
        int cnt = 0;

        while ((i <= mid) && (j <= r)) {
            if (arr[i] <= arr[j]) tmp[k++] = arr[i++];
            else {
                tmp[k++] = arr[j++];
                cnt += mid - i + 1;
            }
        }

        while (i <= mid) tmp[k++] = arr[i++];
        while (j <= r) tmp[k++] = arr[j++];

        for (int i = l; i <= r; i++) arr[i] = tmp[i - l];
        return cnt;
    }

    // Count pair of (i, j) such that, arr[i] > arr[j] and i<j
    int inversionCount(int arr[], int l, int r) {
        if (l >= r) return 0;
        int mid = (r + l) / 2;
        int x = inversionCount(arr, l, mid);
        int y = inversionCount(arr, mid + 1, r);
        int z = mergeCount(arr, l, r);
        return x + y + z;
    }


    // Partition for quicksort
    int partition(int* arr, int l, int r) {
        // Inplace ( can't take extra memory)
        int i = l - 1, j;
        int pivot = arr[r]; // last element is assumed to be pivot

        for (j = l; j <= r - 1; j++) {
            if (arr[j] <= pivot) {
                i = i + 1;
                swap(arr[i], arr[j]);
            }
        }
        // place the oivot element in the correct index
        i++;
        swap(arr[i], arr[r]);
        return i; // index of pivot
    }

    // QuickSort
    void quickSort(int* arr, int l, int r) {
        if (l >= r) return;
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p, r);
    }


    // Find no. of ways to Climb n ladder. One can take 1,2, 3 .. or k  steps at a time
    int ladderProblem(int n, int k) {
        if (n == 0) return 1;
        if (n < 0) return 0;

        int ans = 0;
        for (int i = 1;i <= k; i++) {
            ans += ladderProblem(n - i, k);
        }
        return ans;
    }

    // Tower of honoi
    void toiMove(int n, char src, char helper, char dest, int *steps ) {
        if (n == 0) return;
        toiMove(n - 1, src, dest, helper, steps);
        // printf("Shift disk %d from %c to %c\n", n, src, dest);
        toiMove(n - 1, helper, src, dest, steps);
        *steps += 1;
    }


};


int32_t main() {
    fastIO();

    Solution sol;

    int arr[] = { 1, 2, 3, 7, 4, 5, 6, 7, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << sol.fact(5) << nl; // 120
    cout << sol.fib(4) << nl; // 3
    sol.printDec(12);cout << nl; // 12 11 10 9 8 7 6 5 4 3 2 1 
    sol.printInc(12);cout << nl; // 11 10 9 8 7 6 5 4 3 2 1 12

    cout << sol.isSorted(arr, n) << nl; // 0
    cout << sol.firstOccurance(arr, n, 7) << nl; // 3
    cout << sol.lastOccurance(arr, n, 7) << nl; // 7
    sol.allOccurance(arr, 0, n, 7); cout << nl; // 3 7

    int out[n];
    int cnt = sol.allOcc(arr, 0, n, 7, out, 0);
    cout << "Count : " << cnt << " => ";
    for (int i = 0; i < cnt; i++) cout << out[i] << sp; // Count : 2 => 3 7  
    cout << nl;

    cout << sol.linearSearch(arr, 0, n, 7) << nl; // 3
    cout << sol.binarySearch(arr, 0, n - 1, 7) << nl; // 3 

    cout << sol.power(5, 4) << nl; // 625 
    cout << sol.power(5, 4) << nl; // 625 
    cout << nl;

    PRT(arr); // 1 2 3 7 4 5 6 7 10 
    // sol.bubbleSort(arr, n); // 1 2 3 4 5 6 7 7 10
    // sol.bubbleSortRecursive(arr, 0, n); // 1 2 3 4 5 6 7 7 10
    // sol.mergeSort(arr, 0, n-1); // 1 2 3 4 5 6 7 7 10
    PRT(arr); // 1 2 3 4 5 6 7 7 10


    // Count pair of (i, j) such that, arr[i] > arr[j] and i<j
    int arr2[] = { 1, 5, 2, 6, 3, 0 };
    n = sizeof(arr2) / sizeof(arr2[0]);
    PRT(arr2); // 1 5 2 6 3 0 
    cout << sol.inversionCount(arr2, 0, n - 1) << nl; // 8

    int arr3[] = { 1, 5, 2, 6, 3, 0 };
    PRT(arr3); // 1 5 2 6 3 0 
    sol.quickSort(arr3, 0, n - 1);
    PRT(arr3); // 0 1 2 3 5 6
    cout << nl;

    cout << sol.ladderProblem(4, 3) << nl; // 7

    int steps=0;
    sol.toiMove(3, 'A', 'B', 'C', &steps);
    cout<<"No. of steps : "<<steps<<nl; // 7


    return 0;
}

