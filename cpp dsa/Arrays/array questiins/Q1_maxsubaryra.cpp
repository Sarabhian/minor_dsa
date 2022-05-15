#include<bits/stdc++.h>
using namespace std;

// length of maximum contiguous (difference between subarray elemets is same)subarray in array
int main(){
    int n;
    cout<<" enter array length: " ;
    cin>>n;
    cout<<"\nenter array elements :";
    int a[n];
    for(int i =0 ; i< n ; i++){cin>>a[i];}

    //main code 
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