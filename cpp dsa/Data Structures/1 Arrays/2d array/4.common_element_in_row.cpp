#include<bits/stdc++.h>
using namespace std;
vector<int> findcommon(vector<vector<int>>arr){
    vector<int> ans;
    map<int,int> mp;
    for(int i=0;i<arr[0].size();i++){
        mp[arr[0][i]]=1;
    }
    for(int i=1;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            if(mp[arr[i][j]]==i) mp[arr[i][j]]=i+1;
        }
    }
    for(auto i:mp){
        if(i =)
    }
}

int main(){
    vector<vector<int>> arr;
   arr = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };
    
   return 0;
}