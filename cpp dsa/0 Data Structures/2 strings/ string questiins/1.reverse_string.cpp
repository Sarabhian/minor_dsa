#include<bits/stdc++.h>
using namespace std;

void reverse( string &s){
    int i =0 , j= s.size()-1;
    char temp;
    while(i<=j){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++ ;j--;
    }
    // return s;
}

int main(){
   string s1;
   s1 = "hello";
   cout<<s1<<endl;
   
   reverse(s1);
   cout<<s1<<endl;
   return 0;
}