#include<bits/stdc++.h>
using namespace std;

/* You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.
refer leetcode 11. : https://leetcode.com/problems/container-with-most-water/

*/

int maxArea(vector<int>& height) {
        int maxA=0, curA=0 , i =0 , j=height.size()-1;
        while(i<j){
           curA = min(height[i],height[j])*(j-i);
           maxA =max(curA,maxA);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxA;
    }

int main(){
   int n;
    cout<<" enter array length: " ;
    cin>>n;
    cout<<"enter array elements :";
    vector<int> a(n);
    for(int i =0 ; i< n ; i++){ cin>>a[i];}
    cout<<"max water in tank is : "<<maxArea(a)<<endl;
   return 0;
}