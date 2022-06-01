///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ********** STACK using array ************* static memory allocation of stack **************//

#include<iostream>
using namespace std;

/* STACk 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Content of file :                                                                                                   ||
1. create stack                                                                                                     ||
2. push()                                                                                                           ||
3. pop()                                                                                                            ||
4. display stack                                                                                                    ||
5. peek()   -- return top element                                                                                   ||
6. isempty()                                                                                                        ||
7. isfull()                                                                                                         ||
.                                                                                                                   ||
*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////// 1. create stack ///////////////////////////////////////////////////////////////////////////////////////////////////////

#define  MAX 10  //max size of stack

class Stack{
    int top;

    

public:
    int a[MAX];  // storage array of stack with max size MAX

    Stack(){ top = -1;} // default constructor initialising stack with top =-1

    void push(int x);
    int pop();
    int peek();
    bool isempty();
    bool isfull();
    void display();
};

////////////////////////////////////////  2. push()  ///////////////////////////////////////////////////////////////////////////////////////////////////

void Stack::push(int x){
    if(top == MAX -1){
        cout<<"overflow condition : stack is full"<<endl;
        return;
    }
    a[++top]= x;
}

////////////////////////////////////////   3.pop()    ////////////////////////////////////////////////////////////////////////////////////////////////////

int Stack::pop(){
    if(top == -1){
        cout<<"underflow condition : stack is empty";
        return -1;
    }
    int x = a[top--]; //x = a[top] ; top --;
    return x;
}
///////////////////////////////////////   4. peek()   ////////////////////////////////////////////////////////////////////////////////////////////////////

int Stack::peek(){
     if(top == -1){
        cout<<"underflow condition : stack is empty";
        return -1;
    }
    int x = a[top]; // the only difference in pop and peek is , pop makes the top value as garbage and decrease size of stack 
                    // where peek return only top value and disturb the stack size;
    return x;
}
///////////////////////////////////////  5. Display  /////////////////////////////////////////////////////////////////////////////////////////////////////
void Stack::display(){
    int i = top;
    while(i!=-1){
        cout<<a[i]<<" ";
        i--;
    }
    cout<<endl;
}
///////////////////////////////////////  6. isempty() ///////////////////////////////////////////////////////////////////////////////////////////////////

bool Stack::isempty(){
    if(top == -1)
    return true;
    else 
    return false;
}

//////////////////////////////////////   7. isfull() ////////////////////////////////////////////////////////////////////////////////////////////////////

bool Stack::isfull(){
    if(top == MAX-1)
    return true;
    else 
    return false;
}

int main(){
    Stack s;
    cout<<"is stack empty :"<<s.isempty()<<endl;

    cout<<"enter stack size :";

    int n ,x;
    cin>>n;
   
    cout<<"enter elements in stack";
    for(int i=0 ; i<n;i++){ cin>>x; s.push(x); }
    
    cout<<"the stack is : ";
    s.display();
    s.pop();
    cout<<"the stack after pop is : ";
    s.display();
    cout<<"the element at top is :"<<s.peek()<<endl;



   return 0;
}