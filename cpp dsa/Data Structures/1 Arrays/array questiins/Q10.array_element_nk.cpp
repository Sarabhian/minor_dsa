#include<bits/stdc++.h>
using namespace std;

/*
Given an array of size n and a number k, 
find all elements that appear more than n/k times

Consider k = 4, n = 9 
Given array: 3 1 2 2 2 1 4 3 3 
then output : 
*/
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void printvector(vector<int> arr)
{   int n = arr.size();
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main(){
   int n,k;
   cout<<"enter array size ;";
   cin>> n;
   int arr[n];
   cout<<"enter array elements :";
   for(int i =0;i<n;i++){cin>>arr[i];}
   cout<<"enter k value :";
   cin>>k;
   vector<int> ans;
   unordered_map<int,int> mp;

   for( int i=0; i<n;i++){
    mp[arr[i]]++;
    if(mp[arr[i]]>=n/k){
        ans.push_back(arr[i]);
        mp[arr[i]]=0;
    }
   }
    printvector(ans);
   return 0;
}