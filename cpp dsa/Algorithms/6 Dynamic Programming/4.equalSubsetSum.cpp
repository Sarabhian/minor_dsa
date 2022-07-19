#include<bits/stdc++.h>
using namespace std;

bool subsetSum_topdown(int arr[], int n, int target){
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
   
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
        }
    // cout<<endl;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            // cout<<dp[i-1][j-1]<<" ";
         if(arr[i-1]<= j){
            dp[i][j] = (dp[i-1][j - arr[i-1]] || dp[i-1][j]) ;
         } 
         else dp[i][j]= dp[i-1][j];

        }
        // cout<<endl;
    }
    // cout<<endl;
  
    return dp[n][target];
 }

 bool equalSubsetSum(int arr[],int n){
    int sum = accumulate(arr,arr+n,0);
    if(sum%2!=0) return false;
    bool i = subsetSum_topdown(arr,n,sum/2);
    return i;
 }

int main(){
    int n;
        cout<<"enter values for n ";
        cin>>n;
        
        int A[n];
        
        cout<<"enter elements of array :";
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>A[i];
             
        bool y = equalSubsetSum(A,n);
        cout<<endl<<"does array has equal partition sum ? : "<<y<<endl;
   return 0;
}