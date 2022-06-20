#include<bits/stdc++.h>
using namespace std;
// print all permutations of given string
/*
Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .
*/
 vector<string> ans;
	    void solve(string s,int i ){
	        if(i==s.size()){
	            ans.push_back(s);
	            return;
	        }
	        //hypothesis 
	        for(int j=i;j<s.size();j++){
	            swap(s[i],s[j]);
	            solve(s,i+1);
	            swap(s[i],s[j]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		  solve(S,0);
		  map<string,int> mp;
		  for(int i=0;i<ans.size();i++){
		      mp[ans[i]]++;
		  }
		  vector<string> a;
		  for(auto i:mp){
		      a.push_back(i.first);
		  }
		  return a;
		}
int main(){
        cout<<"enter string :";
	    string S;
	    cin >> S;
	    
	    vector<string> ans = find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// output format
/*
enter string :ABC
ABC ACB BAC BCA CAB CBA 
*/