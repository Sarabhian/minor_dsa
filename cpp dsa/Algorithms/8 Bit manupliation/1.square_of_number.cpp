#include<bits/stdc++.h>
using namespace std;

int sqre(int N){
    if(N==0) return 0;
    if(N<0) N=-N;
    if(N%2==0){
        return 4*sqre(N/2);
    }
    return 4*sqre(floor(N/2)) + 4*floor(N/2) +1;
}
int main(){
   int N;
   cin>>N;
   cout<<"square of "<<N<<" is :"<<sqre(N)<<endl;
   return 0;
}