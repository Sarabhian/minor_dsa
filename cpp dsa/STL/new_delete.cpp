#include<iostream>
using namespace std;

/*
C uses malloc() and calloc() function to allocate memory dynamically at run time 
and uses free() function to free dynamically allocated memory. 
C++ supports these functions and also has two operators new and delete 
that perform the task of allocating and freeing the memory in a better and easier way.

How is it different from memory allocated to normal variables? 
For normal variables like “int a”, “char str[10]”, etc, memory is automatically allocated and deallocated.
For dynamically allocated memory like “int *p = new int[10]”, it is programmers responsibility to deallocate memory when no longer needed.
If programmer doesn’t deallocate memory, it causes memory leak (memory is not deallocated until program terminates). 

New Operator :
The new operator denotes a request for memory allocation on the Free Store.
 If sufficient memory is available, new operator initializes the memory 
 and returns the address of the newly allocated and initialized memory to the pointer variable. 

 syntax : 

 pointer-variable = new data type;

 delete operator

Since it is programmer’s responsibility to deallocate dynamically allocated memory, programmers are provided delete operator by C++ language. 
Syntax: 
 

// Release memory pointed by pointer-variable
delete pointer-variable;

// Release block of memory 
// pointed by pointer-variable
delete[] pointer-variable;  

Example:
   // It will free the entire array
   // pointed by p.
   delete[] p;
 
*/


int main(){

    // Pointer initialized with NULL
    // Then request memory for the variable

    int *p = NULL;
    p = new int;

    // Combine declaration of pointer 
    // and their assignment
    int *ps= new int; 

    /*Initialize memory: 
    We can also initialize the memory for built-in data types using new operator. 
    For custom data types a constructor is required (with the data-type as input) for initializing the value.
     */
     int *q = new int(25);
 

    // allocating block of memory / array allocation 

    // pointer-variable = new data-type[size];

    int *r = new int[10];

   

    ///driver function;

    
 
    // Request memory for the variable
    // using new operator
    p = new(nothrow) int;
    if (!p)
        cout << "allocation of memory failed\n";
    else
    {
        // Store value at allocated address
        *p = 29;
        cout << "Value of p: " << *p << endl;
    }
 
    // Request block of memory
    // using new operator
    float *f = new float(75.25);
 
    cout << "Value of r: " << *f<< endl;
 
    // equest block of memory of size n
    int n = 5;
    int *t = new(nothrow) int[n];
 
    if (!t)
        cout << "allocation of memory failed\n";
    else
    {
        for (int i = 0; i < n; i++)
            t[i] = i+1;
 
        cout << "Value store in block of memory: ";
        for (int i = 0; i < n; i++)
            cout << t[i] << " ";
    }
 
    // freed the allocated memory
    delete p;
    delete r;
 
    // freed the block of allocated memory
    delete[] q;
 
    return 0;
}


