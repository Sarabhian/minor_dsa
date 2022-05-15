#include<bits/stdc++.h>
using namespace std;

/*
find array element which is repeating , the condition is that the array element must have smallest index among all repeating elements

or 
 find the first repeating element int the array
  ex : 1 2 3 4 5 4 5 ; here 4 and 5 are repeating but 4 comes first so answer is 4 with index 3;

  solution : store index of each repeating element with idx[a[i]]=i ; and for next 
*/

int main(){
    int n ;
    cout<<"enter value of n :";
    cin >> n;

    int a[n];
    cout<<"\nEnter array : ";
    for(int i=0 ; i<n; i++){cin>>a[i];}

    const int N = 1e6+2;
    int idx[N];
    for(int i =0 ; i<N ; i++){idx[i]=-1;} //creating an index array with initial value = -1 ;

    int minidx = INT_MAX;
    for(int i =0 ; i< n; i++){

        if(idx[a[i]]!=-1){
            minidx = min(minidx , idx[a[i]]);
        }
        else{
            idx[a[i]]=i; // assigning index value of repeating integer at it's place
        }

    }
    if(minidx==INT_MAX){cout<< "there is no repeating pair"; return 0;}

    cout<<"min repeating value is "<<a[minidx]<<" with min index "<<minidx;

}