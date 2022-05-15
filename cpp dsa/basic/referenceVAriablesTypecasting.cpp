#include<iostream>
using namespace std; 

int main(){
    // float value is by default double 
    float a = 34.4;
    float b = 35.4f;

    long double c = 34.4;
    long double d = 35.4l;

    cout<<sizeof(a)<<sizeof(b)<<sizeof(c)<<sizeof(d);

    // refernce variables 

    float x = 123 ;
    float &y = x ; // y has given refernce of x 

    cout <<"\n"<< x<<" " <<y ;

    // typecasting 

    cout<<"\n"<<a <<" "<< (int)a <<" "<<int(a)<<endl;
    int e= int(b);

    cout<< a + float(e)<<endl;
}