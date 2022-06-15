#include<bits/stdc++.h>
using namespace std;

// Given a string s, return the longest palindromic substring in s.
//  refer leetcode 5 : https://leetcode.com/problems/longest-palindromic-substring/
string longestPalindrome(string s) {
        string ans="";
        int l , r , i;
        for(i=0;i<s.size();i++){
            l=i;
            r=i;
            //odd size
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(ans.size()<r-l+1)
                    ans=s.substr(l,r-l+1);
                l-=1;
                r+=1;
            }
            l=i;
            r=i+1;
            //even size
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(ans.size()<r-l+1)
                    ans=s.substr(l,r-l+1);
                l-=1;
                r+=1;
            }
        }
        return ans;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
   string s = "abcdefeffedca";
   cout<<"longest palindromic substring is " <<longestPalindrome(s)<<endl;
   return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////