#include<iostream>
using namespace std;

/*
functions :
A function is a set of statements that take inputs,
 do some specific computation and produces output.
The idea is to put some commonly or repeatedly done task together and make a function 
so that instead of writing the same code again and again for different inputs, 
we can call the function.

return_type function_name([ arg1_type arg1_name, ... ]) { code }  

 

*/
//  Function declarations :
    // It is always recommended to declare a function before it is used
//A function that takes two integers as parameters
//and returns an integer
int max(int, int);
  
//  A function that takes an int pointer and an int variable as parameters
// and returns a pointer of type int
int *swap(int*,int);
  
// A function that takes a charas parameters
// and returns an reference variable
char *call(char b);
  
// A function that takes a char and an int as parameters
// and returns an integer
int fun(char, int);

/*  Parameter Passing to functions:
in below code  
actual parameters : a,b ( parqms passed to function)
formal parameter : x,y (declared while defining  function) */ 
int max( int x , int y )
{ 
    if (x> y)
    return x;
    else 
    return y;
}

int main(){
    int a =10 , b=3 ;
    cout<< max(a ,b);
}

/*
Pass by Value:
 In this parameter passing method, values of actual parameters are copied to function’s formal parameters 
and the two types of parameters are stored in different memory locations. 
So any changes made inside functions are not reflected in actual parameters of caller.

Parameters are always passed by value in C
 however we can use pointers to get the effect of pass-by reference

Pass by Reference:
 Both actual and formal parameters refer to same locations,
 so any changes made inside the function are actually reflected in actual parameters of caller.
*/

