#include<bits/stdc++.h>
using namespace std;
/* ---------------------- SUBTSET SUM -------------------------------------
you are given an array of size N, and a target sum, 
what you need to find is whether this array has any sequence whose sum == target sum
ex:
A ={ 1,2,3,5,8,3,8,36} ,n= 8
Sum = 12;

ans : True  ... there exist a sequence {1,3,8} 
*/
// recursive approach 
bool subsetSum(int arr[],int n,int target,bool ans){
    cout<<"n: "<<n<<" target :"<<target<<" subsetsum :"<<ans<<endl;
    if(n==0 && target ==0) {ans = 1;return ans;}
    if(n==0) {ans= 0;return ans;}
    if(target==0) return true; 
    if(arr[n-1]<=target){
        ans = subsetSum(arr,n-1,target-arr[n-1],ans) || subsetSum(arr,n-1,target,ans);
        return ans;
    }
    ans = subsetSum(arr,n-1,target,ans);
    return ans;
}
int main(){
   int n,Sum;
        cout<<"enter values for n ";
        cin>>n;
        
        int A[n];
        
        cout<<"enter elements of array :";
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>A[i];
        // enter target sum 
        cout<<"enter the target sum value :";
        cin>>Sum;
        //calling method knapSack()
        cout<<"there exist a subset sum  :";
        
        cout<<subsetSum(A,n,Sum,0)<<endl;
   return 0;
}