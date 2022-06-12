#include<bits/stdc++.h>
using namespace std;
// print elements from 1 to n 
/*
for any recursion problem we need 3 conditions
1. hypothesis : trust that function runs well on n-1 th recursion : recursive relation
2. induction : the manupulating function/pattern/operation which decides the flow of recursion 
3. base case/ terminating case : the condition at which our hypothesis fails and recursion no longer works below this kth recusrion recursion
.                                it's end of recusrion 
first write the hypothesis 
then go base case and in the end write induction function
*/

void print_1to_N(int n){
    if(n==1) {             //base case
        cout<<1<<endl;
        return;
        }
    
    print_1to_N(n-1);    // hypothesis : trust thefunction  that it will print first 1 to n-1 elements
    // now remaining is nth element that we will print by induction function.
    cout<<n<<endl; // induction 
}

void print_N_to_1(int n){
    if(n==1){             //base case
        cout<<1<<endl;
        return;
        }
    // now we know our function will print N-1 elements from N-1 tp 1 , we trust our function
    // but we need to print nth element befor our hypothesis function prints n-1 elemetns 
    cout<<n<<endl;  //induction

    print_N_to_1(n-1);

}
int main(){
   cout<<"1 to N:"<<endl;
   print_1to_N(5);
   cout<<"\nN to 1"<<endl;
   print_N_to_1(5);
   return 0;
}