/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Q length of maximum contiguous (difference between subarray elemets is same)subarray in array

// if arr = [1 2 3 4 5 7 9 11] then max sub array with same adjacent differenct is ;
// sub_arr = [ 1 2 3 4 5] diff=1  or [ 5 7 9 11] diff =2 
// max subarray = [ 1 2 3 4 5] ==> length = 5==ans***

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cout<<" enter array length: " ;
    cin>>n;
    cout<<"\nenter array elements :";
    int a[n];
    for(int i =0 ; i< n ; i++){cin>>a[i];}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//main logic :
    int prev_diff=a[1]-a[0];
    int ans =2;
    int current_subarray_length=2 ;
    int j =2;
    while(j<n){
        if(prev_diff==a[j]-a[j-1]){current_subarray_length++;}
        else{
            prev_diff =a[j]-a[j-1];
            current_subarray_length=2;
        }
        j++;
        ans = max(current_subarray_length,ans);
    }

    cout<<"max subarray : "<<ans<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// output format
/*
 enter array length: 8

enter array elements :1 2 3 4 5 7 9 11
max subarray : 5
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////