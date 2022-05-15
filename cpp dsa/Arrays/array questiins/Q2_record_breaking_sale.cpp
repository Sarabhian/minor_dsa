#include<bits/stdc++.h>
using namespace std;

/*
 a salesman has to decide in which day it had been record breaking sale 
 in such a way day that sale should be maximum before the all the days and one day after the that sale 

 i,e, a[i]>max(a[i-1],a[i-2],...a[0]) and a[i]>a[i+1]
*/
int main(){
    int n ;
    cout<<"enter value of n :";
    cin >> n;

    int a[n+1];
    cout<<"\nEnter array : ";
    for(int i=0 ; i<n; i++){cin>>a[i];}
   a[n]=-1; // to check if last element is record breaking
    int mx =-1;
    int ans=0;
    if (n ==1)
    { cout<<a[0];
      return 0;
    }

    for(int i=0 ; i<n ; i++){
        mx =max(mx ,a[i]);
        if(a[i]==mx && a[i]>a[i+1]){
            cout<<"record breaking day is :"<<i+1<<" with sales value : "<<a[i]<<endl;
            ans++;}
    }
    cout<<"total record breaking days :"<<ans;
    return 0;

        
}