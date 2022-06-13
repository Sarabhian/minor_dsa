#include<bits/stdc++.h>
using namespace std;
/*
as usual we will use IBH rule for sorting

algo : 1.first write a hypothesis that our array can sort first n-1 elements in array of size n
.       2. find base case for array
.       3. in induction write a function which will insert the nth element at right position in n-1 sorted array
*/
void Insert(int key, vector<int>&arr){
    if(arr.size()==0||arr[arr.size()-1]<=key) {arr.push_back(key); return;}

    int temp = arr[arr.size()-1];
    arr.pop_back();
    Insert(key,arr);
    arr.push_back(temp);
}
void Sort(vector<int>&arr){
    if(arr.size()==1) return;

    int temp = arr[arr.size()-1];
    arr.pop_back();
    Sort(arr );
    Insert(temp,arr);
}

int main(){
   vector<int> a = {1,6,3,8,2,4,8};
   int n =7;
   Sort(a);
   for(int i =0 ;i<n;i++){cout<<a[i]<<" ";}
   cout<<endl;
   return 0;
}