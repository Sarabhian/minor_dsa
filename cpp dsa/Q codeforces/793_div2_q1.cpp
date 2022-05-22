#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int check_palindrome(string s)
        {
        if(equal(s.begin(), s.begin() + s.size()/2, s.rbegin()) )
            return 1;
        else
        return 0;
        }
int main(){

   int i,t,n,j=0,count;
    cin>>t ;
    string temp;
    vector<string> a;
    for( i =0; i<t ; i++){
        cin>>n;
        cin>>temp;
        a.push_back(temp);
    }
    for( i =0 ; i<a.size(); i++){
        count =0;
        for( j =0 ; j<a[i].size();j++){
            temp = a[i];
            temp.erase(temp.begin()+j);
            if(check_palindrome(temp)) count++;
            
        }
        cout<<count<<endl;
    }
   return 0;
}
