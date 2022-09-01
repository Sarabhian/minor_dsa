#include<bits/stdc++.h>
using namespace std;

void func(int a){
    if(a%5==0 && a%3==0) {cout<<" fizz buzz"; return;}
    if(a%5==0) {cout<<"fizz"; return;}
    if(a%3==0) {cout<<"buzz"; return;}
}

int main(){
   
   func(15);
   return 0;
}