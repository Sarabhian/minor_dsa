#include<bits/stdc++.h>
using namespace std;
/* ---------------------- SUBTSET SUM -------------------------------------
you are given an array of size N, and a target sum, 
what you need to find is whether this array has any sequence whose sum == target sum
ex:
A ={ 1,2,3,5,8,3,8,36} ,n= 8
Sum = 12;

ans : True  ... there exist a sequence {1,3,8} 

A={ 1,2 ,3,4}, n=4
sum = 12;
ans = false;
*/
// recursive approach 
bool subsetSum(int arr[],int n,int target,bool ans){
    // cout<<"n: "<<n<<" target :"<<target<<" ans :"<<ans<<endl;

    if(target ==0) return ans = 1;
    if(n==0) return ans= 0;

    if(arr[n-1]<=target){
        
        return ans = subsetSum(arr,n-1,target-arr[n-1],ans) || subsetSum(arr,n-1,target,ans);
    }
    
    return ans = subsetSum(arr,n-1,target,ans);
}

// memoization
 bool subsetSum_memoize( int arr[],int dp[],int n,int target){
    
    if(target==0) return 1;
    if(n==0) return 0;
   
    if(arr[n-1]<=target){
       return  dp[n] = subsetSum_memoize(arr,dp,n-1,target-arr[n-1]) || subsetSum_memoize(arr,dp,n-1,target); 
    }
    return dp[n] = subsetSum_memoize(arr,dp,n-1,target);
 }

 //  top down
 bool subsetSum_topdown(int arr[], int n, int target){
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
   
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
        }
    cout<<endl;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            cout<<dp[i-1][j-1]<<" ";
         if(arr[i-1]<= j){
            dp[i][j] = (dp[i-1][j - arr[i-1]] || dp[i-1][j]) ;
         } 
         else dp[i][j]= dp[i-1][j];

        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Does there exist a subset sum ? :";
    return dp[n][target];
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
       
        
         //calling recursive approach
        //  cout<<"Does there exist a subset sum ? :";
        // cout<<subsetSum(A,n,Sum,0)<<endl;

        // calling memoization method;
        int dp[n+1];
        // cout<<subsetSum_memoize(A,dp,n,Sum)<<endl;

        // calling top down menthod.
        cout<<subsetSum_topdown(A,n,Sum)<<endl;
   return 0;
}