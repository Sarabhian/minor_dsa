#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>&d,int n){
    if(n==1) { return 1;}
    int i=0;
    while(1){
        if(d[i]){
            d.erase(d.begin()+i);i++;
        }

        if(d[i%n +1]) d.erase(d.begin()+i%n +1);
        else {return 0;}

    }
}

int main(){
   int t,c,r,temp;
   cin>>t;
   int T =t;
   vector<string> s;
   while(t--){
    cin>>r;
    vector<int> d(r,0);
    for(int i =0 ; i<r; i++){
        
        cin>>temp;
        d[i]=temp;
        
    }
    bool b =solve(d,r);
    if(b){ cout<<"Mike";}
    else{cout<<"Joe";}
    d.clear();
    cout<<endl;
    if(t==0) return 0;
   }
  
   

   return 0;
}