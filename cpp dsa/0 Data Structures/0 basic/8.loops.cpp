#include<iostream>
#include<algorithm> // for_each is defined here
using namespace std;

void printx2(int a){
        cout<<a*2<<endl;
    }

/*
entry controlled : for , while
exit  controlled : do while 

for ( i = m; i< n ; i++){
    .....
}
or 
i=m;
for(i<n){
    i++;
}
i=m
while(i<n)
{
    ....
    i++;
}


do{
    ....
    i++;
}while(i<n);

========================================================

Ranged based for loops
for ( range_declaration : range_expression ) 
    {loop_statement}

    range_declaration ==> int n
    range_expression ==> range array
    loop_statement ==> mmain body
========================================================
for_each
for_each (InputIterator start_iter, InputIterator last_iter, Function fnc)
start iter : start from
last iter : end iteration here
function fnc : the code which need to be executed

refer more : https://www.geeksforgeeks.org/for_each-loop-c/
*/

int main() 
{ 
    for (int i = 1; i <= 10; i++) 
    { 
        cout << "Hello World in for loop\n"; 
    } 
    int j =0 ;
    while( j<8){
        cout<<"Hello World in while loop\n";
        j++;
    }
    int k=0;
    do{
        cout<<"Hello World in do-while loop\n";
        k++;
    }while(k<8); 

    for(int n : {1 ,2 ,3, 4,5}){
        cout<<"Hello World in range for loop\n";
    }
     
    int arr[8] ={ 1,2 ,3 ,4,5,6,7,8};
    
    for_each(arr , arr+8, printx2);
    return 0;
} 
