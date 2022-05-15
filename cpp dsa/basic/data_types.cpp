#include<iostream>
using namespace std;

/*
data types 

    1. premitive data types : int , char , bool , float , double ,
                                void , wide char
    2. derived data types : function , array , pointer , reference ,

    3.abstract or use defined data types : class , stucture , union , enumeration , typedef defined datatype 

data modifiers :

 signed , unsigned , long , short 

 int : all modifiers 
 char : signed , unsigned 
 double : long 
 long-prefix : signed , unsigned 
 short prefix : signed , unsigned 

*/

// understanding the size of datatypes 
int main ()
{
    
    cout<< "size of double  "<< __SIZEOF_DOUBLE__<<endl;
    cout<< "size of  int "<< sizeof( int)<<endl;
    cout<< "size of  long int "<< sizeof(long int)<<endl;
    cout<< "size of  short int "<< sizeof( short int)<<endl;
    cout<< "size of  long long int "<< sizeof(long long int)<<endl;
    cout<< "size of  unsigned int "<< sizeof(unsigned int)<<endl;
    cout<< "size of  signed int "<< sizeof(signed int)<<endl;
}