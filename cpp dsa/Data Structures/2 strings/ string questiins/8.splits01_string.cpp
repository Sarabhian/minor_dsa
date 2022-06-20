#include<bits/stdc++.h>
using namespace std;

/* Split the binary string into substrings with equal number of 0s and 1s 
The task is to find the maximum count of consecutive substrings str can be divided into such that all the substrings are balanced 
i.e. they have an equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then return -1.

Input:
S = "0100110101"
Output: 4
Explanation: 
The required substrings are 01, 0011, 01 and 01.

*/
int maxSubStr(string str){
        int c0=0,count =0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='0'){
                c0++;
            }
            else{
                c0--;
            }
            if(c0==0){
                count++;
            }
        }
        if(c0==0) return count;
        return -1;
        
}
int main(){
  
	    string str;
        cout<<"enter string :";
	    cin >> str;

	    int ans = maxSubStr(str);
	    cout << ans<<endl;
	
   return 0;
}