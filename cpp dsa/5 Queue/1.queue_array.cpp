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

    void enqueue(int x);
    int dequeue();
    int peek();
    bool isempty();
    bool isfull();
    void display();
};

////////////////////////////////////////  2. enqueue()  ///////////////////////////////////////////////////////////////////////////////////////////////////

void queue::enqueue(int x){
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

////////////////////////////////////////   3.dequeue()    ////////////////////////////////////////////////////////////////////////////////////////////////////

int queue::dequeue(){
    if(front == -1&&rear ==-1){
        cout<<"underflow condition : queue is empty";
        return -1;
    }
    else if(front == rear){
        int x = a[front];
        front = rear = -1;
        // if both are equal means queue is having only one element , if we remove it , queue will become nill;
        // so reassign front and rear to -1 and let the garbage value be there 
        return x;
    }
    else{
        int x = a[front];
        front++;
        return x;
    }
    return -1;  // condition for removing attribute parser error : not keeping return type null to avoid any conflict
}
///////////////////////////////////////   4. peek()   ////////////////////////////////////////////////////////////////////////////////////////////////////

int queue::peek(){
     if(front == -1&& rear ==-1){
        cout<<"underflow condition : queue is empty";
        return -1;
    }
    int x = a[front]; // the only difference in pop and peek is , pop makes the top value as garbage and decrease size of stack 
                    // where peek return only top value and disturb the stack size;
    return x;
}
///////////////////////////////////////  5. Display  /////////////////////////////////////////////////////////////////////////////////////////////////////
void queue::display(){
    int i = front;
    
    if(front ==-1 && rear ==-1){cout<<" empty"<<endl; return;}
    while(i<=rear){
        cout<<a[i]<<" ";
        i++;
    }
    cout<<endl;
}
///////////////////////////////////////  6. isempty() ///////////////////////////////////////////////////////////////////////////////////////////////////

bool queue::isempty(){
    if(front == -1 && rear ==-1)
    return true;
    else 
    return false;
}

//////////////////////////////////////   7. isfull() ////////////////////////////////////////////////////////////////////////////////////////////////////

bool queue::isfull(){
    if(rear == MAX-1)
    return true;
    else 
    return false;
}

int main(){
    queue s;
    cout<<"is queue empty :"<<s.isempty()<<endl;

    cout<<"enter queue size :";

    int n ,x;
    cin>>n;
   
    cout<<"enter elements in queue";
    for(int i=0 ; i<n;i++){ cin>>x; s.enqueue(x); }
    
    cout<<"the queue is : ";
    s.display();
    s.dequeue();
    cout<<"the queue after dequeue is : ";
    s.display();
    cout<<"the element at top is :"<<s.peek()<<endl;
    cout<<"is queue full :"<<s.isfull()<<endl;

   return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//output format
/*
is queue empty :1
enter queue size :4
enter elements in queue1 2 3 4
the queue is : 1 2 3 4 
the queue after dequeue is : 2 3 4 
the element at top is :2
is queue full :0
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////