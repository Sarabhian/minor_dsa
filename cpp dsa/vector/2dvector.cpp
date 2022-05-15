#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> arr;
    arr ={
        { 1,3,4},
        { 4 ,5,7},
        { 2 ,3,5,6,7,8,},
        { 2 ,3,4,6,6}
       

    };
    int n = arr.size();
    cout<<"no of rows :"<<n<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"size of " <<i<<"th row : "<<arr[i].size()<<endl;
    }
    
    // accessing values 
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }   
        cout << endl;
    }
}