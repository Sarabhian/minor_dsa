#include<bits/stdc++.h>
using namespace std;

long n_factorial( int n){
    if( n==1|| n==0) return 1;

    return n_factorial(n-1)*n;
}

int main(){
    int n;
    cout<<"enter value for n :";
    cin>>n;
   cout<<"the factorial of "<< n << " : "<<n_factorial(n)<<endl;
   return 0;
}