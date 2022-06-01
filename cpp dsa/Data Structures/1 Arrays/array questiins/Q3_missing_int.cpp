///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Q Given array consists of  positive and negative elements , find all the elements which are missing in the array and print the smallest and
  biggest missing +ve integer among given values

 ex : { 0 ,-9 , 1, 3, -4 , 5,7}
 ans : smallest missing = 2 , biggest missing = 6

 soln : create on boolian check array which will mark true if +ve int is present and check false in the end for missing vlaues 
 A = { 0 ,-9 , 1, 3, -4 , 5,7} ==> present +ve int ={ 1 ,3,5,7}==> bool array ={1 ,0 ,1 ,0,1,0,1}
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
using namespace std;




int main(){

    int n ;
    cout<<"enter value of n";
    cin >> n;

    int a[n];
    cout<<"enter array :";
    for(int i=0 ; i<n; i++){cin>>a[i];}
// create check array with all zeroes
    const int N = 1e6+2 ;
    bool check[N];
    for(int i=0 ; i<N;i++){check[i]=0;}


    for(int i =0 ; i<n ; i++){
        if(a[i]>0){check[a[i]]=1;}  // if element is present then index value of that array will be true.
    }
    vector<int> ans;
    int idx;
    for(int i =1 ; i<N ; i++){
        if(check[i]==0){ans.push_back(i);}
        if(check[i]==1){idx =i;}
    }
    // cout<<idx;

    cout<<"\nmissing array :";
    int i=0 ;
    while(ans[i]<=idx-1){
        cout<<ans[i]<<" ";
        i++;
    }
    cout<<"\nmax int missing :"<< idx-1;
    cout<<"\nmin int missing :"<<ans[0];
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//output format 
/*
enter value of n9
enter array :1 3 5 7 9 12 15 14 18

missing array :2 4 6 8 10 11 13 16 17 
max int missing :17
min int missing :2
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////