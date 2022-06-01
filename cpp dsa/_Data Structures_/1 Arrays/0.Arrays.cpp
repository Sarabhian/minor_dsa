#include<iostream>
using namespace std;

/*
Arrays in cpp 


*/


int main(){
// declaration
int arr[5]= {1 ,3 ,4 ,5 ,6 };
char charr[3]={'a','s','f'};

// traversal : accesing the array

for (int i =0 ; i< 5; i++){
    cout<<arr[i]<<" ";
    
}

cout<< endl<<"other method"<<endl;

for (int i = 0; i < (sizeof(arr)/sizeof(int)); i++)
{
    cout<<i[arr]<<" ";
}



}