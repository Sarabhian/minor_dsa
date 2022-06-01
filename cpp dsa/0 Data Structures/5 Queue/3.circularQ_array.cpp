//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ********** circular queue using array ************* static memory allocation of queue **************//


// main logic : instead rear++ use (rear +1)%max and front++ use (front +1 )%max

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

class Cqueue{
    int front,rear;

    

public:
    int a[MAX];  // storage array of queue with max size MAX

    Cqueue(){ front = rear = -1;} // default constructor initialising queue with front = rear = -1;

    void enqueue(int x);
    int dequeue();
    int peek();
    bool isempty();
    bool isfull();
    void display();
};

////////////////////////////////////////  2. enqueue()  ///////////////////////////////////////////////////////////////////////////////////////////////////

void Cqueue::enqueue(int x){
    if((rear +1)%MAX == front){
        cout<<"overflow condition : queue is full"<<endl;
        return;
    }
    else if (front == -1 && rear ==-1){
        front = rear =0;
        a[rear]=x;
    }
    else{
        rear = (rear +1)%MAX;
        a[rear]=x;
    }
}

////////////////////////////////////////   3.dequeue()    ////////////////////////////////////////////////////////////////////////////////////////////////////

int Cqueue::dequeue(){
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
        front = (front +1)%MAX;
        return x;
    }
    return -1;  // condition for removing attribute parser error : not keeping return type null to avoid any conflict
}
///////////////////////////////////////   4. peek()   ////////////////////////////////////////////////////////////////////////////////////////////////////

int Cqueue::peek(){
     if(front == -1&& rear ==-1){
        cout<<"underflow condition : queue is empty";
        return -1;
    }
    int x = a[front]; // the only difference in pop and peek is , pop makes the top value as garbage and decrease size of stack 
                    // where peek return only top value and disturb the stack size;
    return x;
}
///////////////////////////////////////  5. Display  /////////////////////////////////////////////////////////////////////////////////////////////////////
void Cqueue::display(){
    int i = front;
    
    if(front ==-1 && rear ==-1){cout<<" empty"<<endl; return;}
    while(i!=rear){
        cout<<a[i]<<" ";
        i = ( i+1)%MAX;
    }
    cout<<a[rear]<<endl;
   
}
///////////////////////////////////////  6. isempty() ///////////////////////////////////////////////////////////////////////////////////////////////////

bool Cqueue::isempty(){
    if(front == -1 && rear ==-1)
    return true;
    else 
    return false;
}

//////////////////////////////////////   7. isfull() ////////////////////////////////////////////////////////////////////////////////////////////////////

bool Cqueue::isfull(){
    if((rear +1)%MAX == front)
    return true;
    else 
    return false;
}

int main(){
    Cqueue s;
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
    s.enqueue(10);
    cout<<"the queue after enqueue is : ";
    s.display();
    cout<<"the element at top is :"<<s.peek()<<endl;
    cout<<"is queue full :"<<s.isfull()<<endl;

   return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//output format
/*
is queue empty :1
enter queue size :8
enter elements in queue1 2 3 4 5 6 7 8
the queue is : 1 2 3 4 5 6 7 8
the queue after dequeue is : 2 3 4 5 6 7 8
the queue after enqueue is : 2 3 4 5 6 7 8 10
the element at top is :2
is queue full :0
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////