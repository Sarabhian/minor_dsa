#include<bits/stdc++.h>
using namespace std;
#define N 3
void rotate90clockwise(int arr[N][N]){
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[N-1-j][i];
            arr[N-1-j][i] = arr[N-1-i][N-1-j];
            arr[N-1-i][N-1-j] = arr[j][N-1-i];
            arr[j][N-1-i] =temp;
        }
    }
}
int main(){
    int A[3][3]={{1 ,2,3},{4 ,5,6},{7,8,9}};
   // print 
    for (int i =0; i<3; i++){
        for(int j=0 ; j<3 ; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<" "<<endl;
    }
    cout<<endl<<"array after rotation"<<endl;
    rotate90clockwise(A);

    for (int i =0; i<3; i++){
        for(int j=0 ; j<3 ; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<" "<<endl;
    }
   return 0;
}