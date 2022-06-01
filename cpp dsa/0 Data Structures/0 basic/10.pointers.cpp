#include<iostream>
using namespace std;

int main(){
    int a =10 ;
    int *p;
    p = &a;
    cout<<"a :"<<a<<endl;
    cout<<"*p :"<<*p<<endl;
    cout<<"p :"<<p<<endl;
    cout<<"***********\n"<<endl;

    cout<<"(*P)++ :"<<(*p)++ <<endl;
    cout<<"p :"<<p<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"***********\n"<<endl;

    cout<<"p++ :"<<p++ <<endl;
    cout<<"p :"<<p<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"***********\n"<<endl;
    
    cout<<"++(*p) :"<< ++(*p)<<endl;
    cout<<"p :"<<p<<endl;
    cout<<"a: "<<a<<endl;

    int b, *p1 ,*p2;
    b = 20 ;
    p1 = &b;
    p2 = &(*p1);

    cout<<"*p1 : "<<*p1<<endl;
    cout<<"*p2 :"<<*(&*p2)<<endl;
    // cout<<"**p2 :"<<p1<<endl;

return 0;


}