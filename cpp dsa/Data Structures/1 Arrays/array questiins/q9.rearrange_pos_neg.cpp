#include<bits/stdc++.h>
using namespace std;
//Rearrange array in alternating positive & negative items with O(1) extra space
/*
Input :
arr[] = {-2, 3, 4, -1}
Output :
arr[] = {-2, 3, -1, 4} OR {-1, 3, -2, 4} 
*/

 void rearrange(int arr[],int n){
    int i=0,j=n-1;
    while(i<j){
        if(i<n && arr[i]> 0){
            i++;
        }
        if(j>=0 && arr[j]<0){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    if( i==0 || i==n) return;

    int k =0;
    while(k<n &&i<n){
        swap(arr[k],arr[i]);
        i++;
        k+=2;
    }
    
 }
// Utility function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver code
int main()
{
    int arr[] = { 2, 3, -4, -1, 6, -9 };
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, n);
 
    rearrange(arr, n);
 
    cout << "Rearranged array is \n";
    printArray(arr, n);
 
    return 0;
}
//=====================================================================================================================================================
// output format 
/*
Given array is 
2 3 -4 -1 6 -9 
Rearranged array is 
-1 6 -4 2 -9 3 
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////