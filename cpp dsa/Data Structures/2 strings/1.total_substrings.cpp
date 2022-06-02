#include<bits/stdc++.h>
using namespace std;

 // prints total substring s of a given string 


 vector<string> total_substrings(string s){
     vector<string> res;
     for(int i =0 ;i<s.length();i++){
         string temp;
         for(int j =i ; j< s.length(); j++){
             temp += s[j];
             res.push_back(temp);
         }
     }
     return res;
 }

int main(){
   string S = "ABCDE";
   vector<string> substrings = total_substrings(S);
   for(int i =0 ; i< substrings.size();i++){cout<<substrings[i]<<endl;}
   return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// output format 
/*
A
AB
ABC
ABCD
ABCDE
B
BC
BCD
BCDE
C
CD
CDE
D
DE
E
*/