#include<iostream>
#include<cmath>
using namespace std;


//  find the all possible subarrays
/*
total subarrays = nc2 + n = n*(n+1)/2;
total subsequences = 2^n ;

sum of all subarrays

ex: A ={1, 2, 3} ==> {1 } ,{1,2}, { 1 , 2 ,3} ,{2} ,{ 2,3}, {3} 
n= 3 , total subarrays = 3*4/2 = 6

algo: pointer i , j, iterate one over array , iterate another over pointer , calculate array 


*/

int main(){
    int n ;
    cout<<"enter value of n :";
    cin >> n;

    int a[n];
    cout<<"\nEnter array : ";
    for(int i=0 ; i<n; i++){cin>>a[i];}

    for(int i =0 ; i<n ; i++){
       int current_sum = 0;
        for(int j = i ;j<n; j++ ){
            current_sum+=a[j];
            cout<<"sum :"<<current_sum<<endl;
        }
    }


}