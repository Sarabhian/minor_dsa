#include<iostream>
#include<cmath>
using namespace std;

//  find the max element till ith element in an ARRAY

int main(){
    int mx = -1999999;
    int n ;
    cout<<"enter value of n";
    cin >> n;

    int a[n];

    for(int i=0 ; i<n; i++){cin>>a[i];}

    for(int i =0 ; i<n ; i++){
        mx = max(a[i],mx);
        cout<<mx<<endl;
    }
}