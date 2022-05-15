#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


int diagonalDifference(vector<vector<int>> arr) {
    int lrdiag = 0, rldiag =0;
    int n = arr.size();
    
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
       if (i == j){
           lrdiag +=arr[i][j];}
       
       if ((i + j)==n){ 
           rldiag += arr[i][j];}
       
      }
    }
    int diff = abs(rldiag-lrdiag);
    return diff; 
}

int main(){
    vector<vector<int>> arr;
    arr ={
        { 1,3,4},
        { 4 ,5,7},
        { 1,3,9}

    };

    cout<<"\ndiagonal diff : "<<diagonalDifference(arr)<<endl;
    return 0;
}


