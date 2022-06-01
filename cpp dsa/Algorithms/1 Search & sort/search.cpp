#include<bits/stdc++.h>
using namespace std;

/*
=====================================================================================================================
Content of file :                                                                                                   ||
1. create queue                                                                                                     ||
2. push()                                                                                                           ||
3. pop()                                                                                                            ||
4. display queue                                                                                                    ||
5. peek()   -- return top element                                                                                   ||
6. isempty()                                                                                                        ||
.                                                                                                                   ||
=====================================================================================================================



find whether the element is present in aray or not 

linear search : O(n)
binary search : O(log(n))
exponential : O(log(n)) but faster than binary search in edge element finding
// interpolation =<>= exponential search >>  binary >> jump >> linear (performance)
*/
// 1. linear Search
//---------------------------------------------------------------------------------------------------------------------
int linearSearch(int arr[],int n,int key){
    for(int i=0; i<n; i++){
        if(arr[i]==key){return i;}
    }
    return -1;
}

// 2. Binary serach
//......................................................................................................................
// iterative
int BinarySearch( int arr[],int n , int key){
    int s = 0 , e =n ;
    while(s<=e){
      int  mid = (s + e) /2 ;
      if(arr[mid]== key){ return mid;}
      else if ( arr[mid]< key){ s = mid +1;}
      else {e = mid-1;}
    }
    return -1;
}

// recursive
int bs_recursive(int arr[], int l , int r , int key ){
     if (r >= l)
    {
        int mid = l + (r - l)/2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == key)
            return mid;
 
        // If element is smaller than mid, then it
        // can only be present n left subarray
        if (arr[mid] > key)
            return bs_recursive(arr, l, mid-1, key);
 
        // Else the element can only be present
        // in right subarray
        return bs_recursive(arr, mid+1, r, key);
    }
 
    // We reach here when element is not present
    // in array
    return -1;
}

// 3. exponential search 
// -------------------------------------------------------------------------------------------------------------------------
int exponentialSearch(int arr[], int n , int key){
    if (arr[0]==key)return 0;
     int i =1 ;
     while(arr[i]<key && i<n){
         i = i*2 ;
     }

     return bs_recursive(arr ,i/2 , min(i , n), key );
}

// 4. jump serach
//---------------------------------------------------------------------------------------------------------------------------
int jumpSearch(int arr[], int n , int key)
{
int step = sqrt(n);
int prev =0;
    while(arr[min(step , n)-1]<key)
    {
        prev = step ;
        step += sqrt(n);
        if(prev >= n) return -1;

    }
    while(arr[prev]<key){
        prev++;
        if(prev==min(step , n)) {return -1 ;}
        if( arr[prev]==key) {return prev;}
    }
    return -1;
}
//5. interpolation search 
// -----------------------------------------------------------------------------------------------------------------------------
int interpolationSearch(int arr[],int low, int high, int key){
    int pos ;
     if(low<=high && key >= arr[low] && key<= arr[high]){
         pos = low + ((double)(high - low)/(arr[high]-arr[low]))*(key - arr[low]);
         if (arr[pos]==key) return pos;
         if( arr[pos]< key) return interpolationSearch(arr , pos+1 , high , key);
         if( arr[pos]>key) return interpolationSearch(arr , low , pos-1 , key);
     }
     return -1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    int n ;
    cout << " enter array length:";
    cin >> n;
    int arr[n];
    cout << "\nenter array elements :";
    for(int i =0 ; i<n; i++){cin>>arr[i];}
    cout<< "\nenter key element :";
    int key;
    cin >>key;

    // cout<< BinarySearch(arr, n,key);
    // cout<<linearSearch(arr,n,key);
    // cout<<exponentialSearch(arr , n , key);
    // cout<< jumpSearch(arr, n,key);
    cout<< interpolationSearch(arr , 0 , n , key);

    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
