#include<bits/stdc++.h>
using namespace std;
//////////////////////////////// Longest Substring Without Repeating Characters //////////////////////////////////////////////////////////////////////////////
/*
Given a string s, find the length of the longest substring without repeating characters.
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

refer leetcode 3 : https://leetcode.com/problems/longest-substring-without-repeating-characters/

*/
//========================================================================================================================================

int lengthOfLongestSubstring(string s) {
        // solution 1 : using vector mapping
        // vector<int> dict(256, -1);
        // int maxLen = 0, start = -1;
        // for (int i = 0; i != s.length(); i++) {
        //     if (dict[s[i]] > start)
        //         start = dict[s[i]];
        //     dict[s[i]] = i;
        //     maxLen = max(maxLen, i - start);
        // }
        // return maxLen;
        
        // solution 2 : using hashmap
         unordered_map<char,int> mp;
        int low=0,high=0,count=0,maxlen=0;
        while(high<s.size()){
           if(mp[s[high]]){
             while(mp[s[low]]>=1){
                 count--;
                 mp[s[low]]--;
                 low++;
                 // cout<<s[low]<<endl;
             }  
           }
            else{
                mp[s[high]]++;
                high++;count++;
                maxlen=max(count,maxlen);
            }
           
        }
        return maxlen;
        
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
   string s ="abcabcbbc";
   cout<<lengthOfLongestSubstring(s)<<endl;
   return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// how to find the substring , s.substr(s.begin()+low, maxlen)?