#include<bits/stdc++.h>
using namespace std;
vector<int> findcommon(vector<vector<int>>arr){
    vector<int> ans;
    map<int,int> mp;
    int n = arr.size();
    // cout<<n<<endl;
    for(int i=0;i<arr[0].size();i++){
        mp[arr[0][i]]=1;
    }
    for(int i=1;i<arr.size();i++){
        cout<<i<<" :   ";
        for(int j=0;j<arr[i].size();j++){
            if(mp[arr[i][j]]==i){ mp[arr[i][j]]=i+1;
            cout<<arr[i][j]<<" ";
            }

            if(i==n-1 &&mp[arr[i][j]]==n){
                ans.push_back(arr[i][j]);
                // cout<<arr[i][j]<<endl;
            }
        }
        cout<<endl;
    }
    cout<<endl;
    return ans;
}

int main(){
    vector<vector<int>> arr;
   arr = {{1, 2, 1, 4,8,8 ,7},
             {3, 7, 8, 5, 1,7},
             {8, 5, 3, 1 ,8},
             {8, 1, 2, 9, 9},
            };

    vector<int> a = findcommon(arr);
    cout<<"common elements are : ";
    for(int i=0;i<a.size();i++){cout<<a[i]<<" ";}
    cout<<endl;
    
   return 0;
}