#include<bits/stdc++.h>
using namespace std;


int main(){
   vector<int> ans ={} ,level ={1 ,2,3,4,5};
   ans.insert(ans.end(),level.begin(),level.end());
   // ans.push_back(level);
   for(int i =0 ; i< ans.size(); i++){cout<<ans[i]<<" ";}
   return 0;
}