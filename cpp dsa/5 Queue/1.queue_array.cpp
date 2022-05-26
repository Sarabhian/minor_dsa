//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ********** queue using array ************* static memory allocation of queue **************//

#include<iostream>
using namespace std;
/*queue 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Content of file :                                                                                                   ||
1. create queue                                                                                                     ||
2. push()                                                                                                           ||
3. pop()                                                                                                            ||
4. display queue                                                                                                    ||
5. peek()   -- return top element                                                                                   ||
6. isempty()                                                                                                        ||
7. isfull()                                                                                                         ||
.                                                                                                                   ||
*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////// 1. create queue ///////////////////////////////////////////////////////////////////////////////////////////////////////

#define  MAX 10  //max size of queue

class queue{
    int front,rear;

    

public:
    int a[MAX];  // storage array of stack with max size MAX

    queue(){ front = rear = -1;} // default constructor initialising stack with top =-1

    void push(int x);
    int pop();
    int peek();
    bool isempty();
    bool isfull();
    void display();
};

////////////////////////////////////////  2. push()  ///////////////////////////////////////////////////////////////////////////////////////////////////

void queue::push(int x){
    if(rear == MAX -1){
        cout<<"overflow condition : queue is full"<<endl;
        return;
    }
    else if (front == -1 && rear ==-1){
        front = rear =0;
        a[rear]=x;
    }
    else{
        rear++;
        a[rear]=x;
    }
}

////////////////////////////////////////   3.pop()    ////////////////////////////////////////////////////////////////////////////////////////////////////

int queue::pop(){
    if(front == -1&&rear ==-1){
        cout<<"underflow condition : queue is empty";
        return -1;
    }
    int x = a[top--]; //x = a[top] ; top --;
    return x;
}
///////////////////////////////////////   4. peek()   ////////////////////////////////////////////////////////////////////////////////////////////////////

int queue::peek(){
     if(top == -1){
        cout<<"underflow condition : queue is empty";
        return -1;
    }
    int x = a[top]; // the only difference in pop and peek is , pop makes the top value as garbage and decrease size of stack 
                    // where peek return only top value and disturb the stack size;
    return x;
}
///////////////////////////////////////  5. Display  /////////////////////////////////////////////////////////////////////////////////////////////////////
void queue::display(){
    int i = top;
    while(i!=-1){
        cout<<a[i]<<" ";
        i--;
    }
    cout<<endl;
}
///////////////////////////////////////  6. isempty() ///////////////////////////////////////////////////////////////////////////////////////////////////

bool queue::isempty(){
    if(top == -1)
    return true;
    else 
    return false;
}

//////////////////////////////////////   7. isfull() ////////////////////////////////////////////////////////////////////////////////////////////////////

bool queue::isfull(){
    if(top == MAX-1)
    return true;
    else 
    return false;
}

int main(){
    queue s;
    cout<<"is squeueempty :"<<s.isempty()<<endl;

    cout<<"enter queue size :";

    int n ,x;
    cin>>n;
   
    cout<<"enter elements in queue";
    for(int i=0 ; i<n;i++){ cin>>x; s.push(x); }
    
    cout<<"the queue is : ";
    s.display();
    s.pop();
    cout<<"the queue after pop is : ";
    s.display();
    cout<<"the element at top is :"<<s.peek()<<endl;



   return 0;
}