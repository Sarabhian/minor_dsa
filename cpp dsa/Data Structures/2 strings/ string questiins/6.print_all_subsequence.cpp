#include<bits/stdc++.h>
using namespace std;
// given a string , print all possible subsequences of the string 

// pick and don't pick method : refer more https://www.geeksforgeeks.org/print-subsequences-string/

void printSubsequence(string input,string output,vector<string>&ans){
    if(input.empty()) {
      ans.push_back(output);
      return;
    }
    printSubsequence(input.substr(1), output + input[0],ans);
    printSubsequence(input.substr(1), output,ans);
}

int main(){
   vector<string> ans;
   string s = "abcd";
   printSubsequence(s,"",ans);
   for(int i =0;i<ans.size();i++){cout<<ans[i]<<endl;}
   return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//output format 
/*
abcd
abc
abd
ab
acd
ac
ad
a
bcd
bc
bd
b
cd
c
d
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////