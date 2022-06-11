#include<bits/stdc++.h>
using namespace std;

// given a value k, find the longest subarray whose sum is k,

// algo : use two pointers one will write the sum other will check if sum is greater than k if greater it will reduce that element from sum,
// TC : O(n);

int len_maxSubarray(int k , vector<int> nums){
    int i =0, j= 0 , maxlen = INT_MIN, curr_sum =0;

    while(j<nums.size()){
        curr_sum+=nums[j];
        while(i<j&&curr_sum>k){
            curr_sum-=nums[i++];
        }
        if(k==curr_sum)
            maxlen=max(maxlen,j-i+1);
        j++;
    }
    if(maxlen==INT_MIN) return -1;
    return maxlen;
}

int main(){
   
    int n;
    cout<<" enter array length: " ;
    cin>>n;
    cout<<"\nenter array elements :";
    vector<int> a(n);
    for(int i =0 ; i< n ; i++){ cin>>a[i];}
    
    int k;
    cout<<"enter sum value k :";
    cin>>k;
    cout<<"maximum length of subarray is :"<<len_maxSubarray(k , a)<<endl;
   return 0;
}
// how to find minimum subarray whose sum is k ?  
// answer is simple first find sum of entire array then subtract the k from it , then we will get (sum-k) as new_k value
//  now we need to find longest subbarray whose sum is new_k , the subarray will indirectly minimize the subbarray whose sum is k and
// will find the length of minimum subbarray whose sum is k, 
// and len of min subaray will be size - maxlen_of_new_k_subbarray.