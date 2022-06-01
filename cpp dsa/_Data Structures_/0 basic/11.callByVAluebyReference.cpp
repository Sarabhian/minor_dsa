#include<iostream>
using namespace std;

int sum(int a , int b){int c = a+b ; return c;}
void swap(int a , int b){int temp = a ; a= b ; b = temp;}
void swaptr(int *a , int *b){int temp = *a ; *a= *b ; *b = temp;} // value  at address changes 
void swapReference( int &a , int&b){int temp = a ; a= b ; b = temp;}

int main(){

    int x = 10 , y= 20;

    cout <<"x :"<< x << "y:"<<y<<endl;
    swap(x,y); //won't work 
    cout <<"call by value \nx :"<< x << "y:"<<y<<endl;
    swaptr(&x,&y);
    cout <<"using ptr as call by reference \nx :"<< x << "y:"<<y<<endl;
    x= 10 ,y = 20;
    swapReference(x,y);
    cout <<"using refernce variables \nx :"<< x << "y:"<<y<<endl;

    return 0 ;
}