#include<iostream>
#include<vector>
#include<numeric>
using namespace std;




int main(){
    int n ;
     cin>>n;
     vector<vector<int>> a( n , vector<int>(n,1));
    //  cout<<"first"<<a[0][n-1]<<endl;
     for(int i =1;i<n ; i++){
         partial_sum(a[i-1].begin(),a[i-1].end(),a[i].begin());

     }
     cout<<a[n-1][n-1];
    return 0;
}