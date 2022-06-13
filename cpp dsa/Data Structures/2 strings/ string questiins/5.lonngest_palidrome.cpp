#include<bits/stdc++.h>
using namespace std;

// for a given find the longest palindromic substring 

string longestPalin (string S) {
        int n =S.length();
        if(n<2) return S;
        int maxlen =0 , start =0 , low ,high;
        for(int i =0 ; i<n ; i++){
            low =i-1;
            high = i+1;
            while(high<n&&S[high]==S[i]){high++;}
            while(low>=0&&S[low]==S[i]){low--;}
            while(low>=0&&high<n && S[low]==S[high]){low--;high++;}
            
            int len = high -low -1 ;
            if(maxlen<len){maxlen = len ; start = low+1;}
        }
        return S.substr(start ,maxlen);
    }



int main(){
   string s = "aabbaacscaabbaa";
   cout<<"given string is :"<<s<<endl;
   cout<<"the longest palindromic substring is :"<<longestPalin(s)<<endl;
   return 0;
}