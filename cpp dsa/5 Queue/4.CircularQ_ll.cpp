//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ********** circular queue using linkedlist ************* dynamic memory allocation of queue **************//
#include<iostream>
using namespace std;

/* STACk 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Content of file :                                                                                                   ||
1. create queue                                                                                                     ||
2. push()                                                                                                           ||
3. pop()                                                                                                            ||
4. display queue                                                                                                    ||
5. peek()   -- return top element                                                                                   ||
6. isempty()                                                                                                        ||
.                                                                                                                   ||
*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////// 1. create queue ///////////////////////////////////////////////////////////////////////////////////////////////////////

// to create the queue using ll , it must follow FIFO principle
// insert node at end and remove fromo beginning
// not e insertion and deletion need o(1) so we need a ll with head and tail ptrs;
struct qNode{
    int data ;
    qNode* next;
    qNode(){}
    qNode(int x){
        data = x;
        next = NULL;
    }
};
struct Cqueue{

    qNode *front , *rear;
    Cqueue(){
        front = rear = NULL;
    }

////////////////////////////////////////  2. enque()  /////////////////////////////////////////////////////////////////////////////////////////////////
    void nq(int x){
        qNode * newnode = new qNode(x);
        if(rear ==NULL){  // if q is empty assign both f and r to nn
            front=rear=newnode;
            rear->next = front;
        }
        else {
            rear->next = newnode;
            newnode->next = front;
            rear = newnode; 
        }
        
    }


////////////////////////////////////////   3.dequeue()    ////////////////////////////////////////////////////////////////////////////////////////////////
 int dq(){
     if(front ==NULL && rear==NULL){ // underflow 
         return -1;
     }
     qNode *temp = front;
     front = front->next;

     if(front ==NULL)
        rear ==NULL;
    int y = temp->data;
    delete(temp);
    return y;
 }
///////////////////////////////////////   4. peek()   /////////////////////////////////////////////////////////////////////////////////////////////////
int peek(){
    if( front == NULL && rear ==NULL){
        return -1;
    }
    else{
        return front->data;
    }
    return -1;
}

////////////////////////////////////  5. Display  /////////////////////////////////////////////////////////////////////////////////////////////////////

void display(){
    cout<<"the queue is :";
    if(front ==NULL && rear  == NULL){cout<<" empty"<<endl; return;}
    qNode* temp = front;
    while( temp != rear){
        cout<< temp->data <<" ";
        temp= temp->next;
    }
    cout<<temp->data<<endl;;
}

///////////////////////////////////////  6. isempty() ///////////////////////////////////////////////////////////////////////////////////////////////////

bool is_mt(){
    if(front == NULL && rear == NULL)
    return true;
    else
    return false;

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



};

int main(){
    
    int n;
    cout << "enter queue size :";
    cin >> n;
    cout << "enter queue data elements : ";
    int d;
    Cqueue q ;
  
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        q.nq(d);
    }
    
    q.display();
    q.dq();
    cout<<"after deque operation ";
    q.display();
    cout<<"peek value is :"<<q.peek()<<endl;
    q.nq(10);
    cout<<"after enque operation ";
    q.display();
    cout<<"is queue empty : "<<q.is_mt()<<endl;

   return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// output format 
/*
enter queue size :6
enter queue data elements : 1 2 3 4 5 6
the queue is :1 2 3 4 5 6
after deque operation the queue is :2 3 4 5 6
peek value is :2
after enque operation the queue is :2 3 4 5 6 10
is queue empty : 0
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////