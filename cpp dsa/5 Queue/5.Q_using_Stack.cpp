#include<iostream>
using namespace std;



///////////////////////////// 1. create stack ///////////////////////////////////////////////////////////////////////////////////////////////////////

#define  MAX 10  //max size of stack

class Stack{
   

    

public:
    int top;
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

/////////////////////////////////////////////////////////// QUEUE  using stack ///////////////////////////////////////////////////////////////////////////
/*
the queue is implemented using two stacks ;
stack 1 to store push elements and stack2 to store pop elements;
approach used has enque o(1) and deque o(n)

*/

class Qs{

    public:
    Stack s1 , s2;
    int count =0;

////////////////////////////////////////  2. enqueue()  /////////////////////////////////////////////////////////////////////////////////////////////////
    void nq(int x){
        s1.push(x); // stack s1 is our queue with top  being rear and bottom bwing front of queue
        count++;
    }

////////////////////////////////////////  3. dequeue()  /////////////////////////////////////////////////////////////////////////////////////////////////
    int dq(){
        int i ;
        if(s1.top == -1 && s2.top ==-1){ cout<<"queue is empty"<<endl; return -1;}
        for( i =0 ; i<count; i++){
            //pop element from s1  and push it to s2 so that we will get top element of s2 as front of queue
                s2.push(s1.pop());
        }
        int b = s2.pop(); //front of the queue
        count --;
        for ( i = 0; i < count; i++)
        {
            s1.push(s2.pop());
        }
        return b;
    }
////////////////////////////////////////  4. peek()  ////////////////////////////////////////////////////////////////////////////////////////////////////
    int peek(){
        if(s1.top == -1 && s2.top ==-1){ cout<<"queue is empty"<<endl; return -1;}
        return s1.a[0];
    }
////////////////////////////////////////  5. display()  /////////////////////////////////////////////////////////////////////////////////////////////////
    void display(){
        int i =0;
        if(s1.top ==-1){cout<<" empty "<<endl; return;}
        while(i !=s1.top){
            cout<<s1.a[i]<<" ";
            i++;
        }
        cout<<s1.a[i]<<endl;
        
    }
////////////////////////////////////////  6. isempty()  /////////////////////////////////////////////////////////////////////////////////////////////////
    bool isempty(){
        return s1.isempty();
    }
////////////////////////////////////////  7. isfull()  /////////////////////////////////////////////////////////////////////////////////////////////////
   bool isfull(){
       return s1.isfull();
   }
};

//////////////////////////////////////////// main function////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    Qs s;
    cout<<"is queue empty :"<<s.isempty()<<endl;

    cout<<"enter queue size :";

    int n ,x;
    cin>>n;
   
    cout<<"enter elements in queue";
    for(int i=0 ; i<n;i++){ cin>>x; s.nq(x); }
    
    cout<<"the queue is : ";
    s.display();
    s.dq();
    cout<<"the queue after dequeue is : ";
    s.display();
    cout<<"the element at top is :"<<s.peek()<<endl;
    s.nq(10);
    cout<<"the queue after enqueue is : ";
    s.display();
    cout<<"is queue full :"<<s.isfull()<<endl;

   return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//output format
/*
is queue empty :1
enter queue size :6
enter elements in queue1 2 3 4 5 6
the queue is : 1 2 3 4 5 6
the queue after dequeue is : 2 3 4 5 6
the element at top is :2
the queue after enqueue is : 2 3 4 5 6 10
is queue full :0
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////