#include<bits/stdc++.h>
using namespace std;
/*
you are given a array and subset diff s1 - s2 = k, find how many such subset pairs exist.

count subset sum with given difference.

*/

/*

solution : arr sum = S , sunset sums s1,s2, 
s1-s2 = k ;
s1+s2 = S ;
s1 = (k+S)/2   so if we get a subset of sum k+s/2 then we will get s1-s2 =k   diff pair.

so problem is just to find count of subsets with target sum = T = (k+s)/2.
*/
void printdp( vector<vector<int>> arr);
int CountSubsetSumDiff(int arr[],int n, int k )
{
    int T = (accumulate(arr,arr+n,0) + k )/2 ;
    
    vector<vector<int>> dp(n+1,vector<int>(T+1,0)); 
    for(int i=0;i<n+1;i++){
        dp[i][0]= 1;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<T+1;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
            else dp[i][j]= dp[i-1][j];
        }
    }
    cout<<endl;
    printdp(dp);
    cout<<"count of  subset sums  :";
    return dp[n][T];
}

void printdp( vector<vector<int>> arr){
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }   
        cout << endl;
    }
}
int main(){
   
   int n,k;
        cout<<"enter values for n ";
        cin>>n;
        
        int A[n];
        
        cout<<"enter elements of array :";
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>A[i];
        // enter target difference
        cout<<"enter the target difference value :";
        cin>>k;
       
        
         //calling recursive approach
         
        cout<<CountSubsetSumDiff(A,n,k)<<endl;
   return 0;
}