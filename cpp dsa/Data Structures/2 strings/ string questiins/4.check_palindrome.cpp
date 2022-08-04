#include<bits/stdc++.h>
using namespace std;
// check if first half of string is equal to last half in reverse way.
bool check_palindrome(string s){
    if(equal(s.begin(),s.begin() + s.size()/2 ,s.rbegin())) 
        return true;
    return false;
}
int main(){
   string S = "abcdcba",A = "aaaaaab";
   cout<<"is S palindrome :"<<check_palindrome(S)<<endl<<"is A palindrome :"<<check_palindrome(A)<<endl;
   cout << "git check !";
   return 0;

}