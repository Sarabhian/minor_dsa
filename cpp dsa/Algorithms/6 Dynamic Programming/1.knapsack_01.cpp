#include<bits/stdc++.h>
using namespace std;
 
    int memoization(vector<vector<int>>&dp , int W, int wt[], int val[], int n){
        if(n==0 || W==0) return 0;
        if(dp[n][W]!=-1) return dp[n][W];
        
        if(wt[n-1]<=W)
        {
          return  dp[n][W] = 
          max( memoization(dp,W,wt,val,n-1), val[n-1]+memoization(dp,W-wt[n-1],wt,val,n-1) );
        }
        else return dp[n][W] = memoization(dp,W,wt,val,n-1);
        
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        return memoization(dp,W,wt,val,n);
        
    }

int main()
 {
    //taking total testcases
    
        //reading number of elements and weight
        int n, w;
        cout<<"enter values for n and W";
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        cout<<"enter val array :";
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        cout<<"enter weight array :";
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<"the max profit is :";
        cout<<knapSack(w, wt, val, n)<<endl;
        
    
	return 0;
 }