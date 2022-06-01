#include<iostream>
#include<cmath>

using namespace std;

// interpolation >> binary >> jump >> linear (performance)
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
    // cout<< jumpSearch(arr, n,key);
    cout<< interpolationSearch(arr , 0 , n , key);

    return 0;
}

