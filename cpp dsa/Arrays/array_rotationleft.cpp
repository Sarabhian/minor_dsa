#include<iostream>
using namespace std;
//Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements
// input arr = { 2 ,3,4,5,6,}  
// output arr = { 4 ,5 ,6 ,2,3} if d=2 

/*  algo :
        1. shift sigle element :  temp =arr[0] , assign arr[i]=arr[i+1] and  and arr[n-1] = temp
        2. shift d element : run above code d times in loop
*/

// Printing an Array 
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Left shift of array elements by 1 element
int left_shift_arr(int arr[] , int n)
{
    int temp = arr[0];
    for (int i = 0; i < n; i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp; 
    return 0;  
}

// left shift of array k time 
int main(){
    int arr[] = {1,3,4,6,5,7};
    int d= 2;
    int n = sizeof(arr)/sizeof(int);
    for (int i = 0; i < n; i++)
    {
       if (i<d){
           left_shift_arr(arr,n);
       }
    }
   printArray(arr ,n);
    return 0;
}