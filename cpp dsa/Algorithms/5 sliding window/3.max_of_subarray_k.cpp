#include<bits/stdc++.h>
using namespace std;
/* Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.
Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3 
Output: 3 3 4 5 5 5 6
Explanation: 
Maximum of 1, 2, 3 is 3
Maximum of 2, 3, 1 is 3
Maximum of 3, 1, 4 is 4
Maximum of 1, 4, 5 is 5
Maximum of 4, 5, 2 is 5 
Maximum of 5, 2, 3 is 5
Maximum of 2, 3, 6 is 6
*/

int main(){
   int n,k;
   cout<<"enter sizeof array: ";
   cin>>n;
   int arr[n];
   cout<<"enter array elements : ";
   for(int i =0;i<n ;i++){cin>>arr[i];}
   cout<<"enter subarray size k : ";
   cin>>k;
    vector<int> maxi(n-k+1,0);
   int i =0,j=0;
   while(j<=n){
    j=i;
    for(j =i;j<i+k;j++){
        maxi[i] = max(maxi[i],arr[j]);
    }
    i++;
   }
   for(int i =0;i<n-k+1 ;i++){cout<<maxi[i]<<" ";}
   cout<<endl;



   return 0;
}