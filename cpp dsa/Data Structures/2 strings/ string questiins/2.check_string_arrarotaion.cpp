#include<bits/stdc++.h>
using namespace std;
// check whether string s2 is rotation of s1
bool check_rotation(string a , string b){
    if(a.length()!=b.length())
    return 0;
    string temp = a +a ;
    return (temp.find(b)!=string::npos);  // if string::npos is -1 , if itr ==-1 then 0 else 1 ;
}

int main(){
   string s1= "hello" , s2 ="elloh" , s3 = "olleh";
   
   cout<<check_rotation(s1,s2)<<":"<<check_rotation(s1,s3)<<endl;
   return 0;
}