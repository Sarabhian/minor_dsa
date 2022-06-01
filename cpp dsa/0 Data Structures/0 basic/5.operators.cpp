#include<iostream>
using namespace std;

/*
Operators : 
functions which help us to do arithmatic and logical operations 
built in operators : 
1  Arithmatic
    a. Unary operators : ++ , --
    b. Binary operators : + ,- , * ,/
2 Relational : == , >= ,<= ,<,>,!=
3 logical : && , ||
4 Bitwise : & ,| , ^ (bitwise xor) , << (left shift), >> (right shift), ~ ( bitwise not)
5 Assignment : = , += ,-= ,*=,/=
6 other operators : sizeof() , comma , conditional ,
*/


int main ()
{
    int a=0  , b=0;
//  unary operator: ++ 

cout<< "\n----------------------- Unary operators----------------------------------- "<<endl;

a = 2 ;
b = a++;

cout << "--------"<<"unary operator : (++) ------"<<endl;
cout << " post fix assignment ,b=a++ "<<endl;
cout<< "value of a " << a <<endl << "value of b  "<<b <<endl;
cout<< "address of a " << &a <<endl << "address of b  "<<&b<<endl ;

a = 5 ;b = ++a ;
cout << " prefix fix assignment , b=++a "<<endl;
cout<< "value of a " << a <<endl << "value of b  "<<b<<endl ;
cout<< "address of a " << &a <<endl << "address of b  "<<&b <<endl;
cout << "--------"<<"unary operator : (--) ------"<<endl;
//  unary operator : --
a = 2 ;
b = a--;

cout << " post-fix assignment , b=a-- "<<endl;
cout<< "value of a " << a <<endl << "value of b  "<<b <<endl;
cout<< "address of a " << &a <<endl << "address of b  "<<&b<<endl ;

a = 5 ;b = --a ;
cout << " pre fix assignment , b=--a "<<endl;
cout<< "value of a " << a <<endl << "value of b  "<<b<<endl ;
cout<< "address of a " << &a <<endl << "address of b  "<<&b ;

// relational  operators 
cout<< "\n----------------------- relational operators----------------------------------- "<<endl;
cout<<"enter value of a ";
cin >> a ;
cout << "enter value of b ";
cin >> b ;
cout<< "a==b : "<<(a==b) <<endl;
cout<< "a<=b : "<<(a<b) <<endl;
cout<< "a>=b : "<<(a>b) <<endl;
cout<< "a!=b : "<<(a!=b) <<endl;
//
cout<< "\n----------------------- Bitwise operators----------------------------------- "<<endl;
cout<<"enter binary value of a ";
cin >> a ;
cout << "enter binary value of b ";
cin >> b ;
cout<< "a & b :"<<(a & b) <<endl;
cout<< "a | b :"<<(a | b) <<endl;
cout<< "a ^ b :"<<(a ^ b) <<endl;
cout<< "a << b :"<<(a << b )<<endl;
cout<< "a >> b :"<<(a >> b )<<endl;
cout<< "a ~ b :"<< (~b)<<endl;

cout<< "\n----------------------- Other operators----------------------------------- "<<endl;
cout<< "\n------- sizeof operator--------"<<endl;
cout<< "sizeof(a)"<<sizeof(a)<<endl;
cout<< "sizeof(int)"<<sizeof(int)<<endl;


cout<< "\n------- comma operator--------"<<endl;
b= (false,4) ;
a=(4,5);
cout<< "a = (4 , 5) : ==> a="<<a<<"\nb = (false,4) : ==> b="<<b<<endl;

cout<< "\n------- conditional operator--------"<<endl;
cout <<"exp1 ? exp2 : exp3 "<<endl;
// if exp1 is true then exp2 will return its value as output else exp3 will execute ,
//  The ternary operator has return type. The return type depends on exp2, 
//  and convertibility of exp3 into exp2 as per usual\overloaded conversion rules. If they are not convertible, the compiler throws an error. 

// simple expression 
cout << "enter values of a and b "<<endl;
cin>>a>>b;
cout <<(a ? b: 4) <<endl;
// error expression 

// cout << "enter values of a and c "<<endl;
// char c[7];
// cin>>a>>c;
// cout <<(a ? c: 4) <<endl;
}
