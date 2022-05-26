//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ********** queue using linkedlist ************* dynamic memory allocation of queue **************//
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
struct queue{

    qNode *front , *rear;
    queue(){
        front = rear = NULL;
    }

////////////////////////////////////////  2. enque()  /////////////////////////////////////////////////////////////////////////////////////////////////
    void nq(int x){
        qNode * newnode = new qNode(x);
        if(rear ==NULL){  // if q is empty assign both f and r to nn
            front=rear=newnode;
            return;
        }

        rear->next = newnode;
        rear = newnode;
    }


////////////////////////////////////////   3.dequeue()    ////////////////////////////////////////////////////////////////////////////////////////////////
 int dq(){
     if(front ==rear){ // underflow 
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
    while( temp != NULL){
        cout<< temp->data <<" ";
        temp= temp->next;
    }
    cout<<endl;
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
    int data_array[n];
    queue q ;
  
    for (int i = 0; i < n; i++)
    {
        cin >> data_array[i];
        q.nq(data_array[i]);
    }
    
    q.display();
    q.dq();
    cout<<"after pop operation ";
    q.display();
    cout<<"peek value is :"<<q.peek()<<endl;
    cout<<"is queue empty : "<<q.is_mt()<<endl;

   return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// output format 
/*
enter queue size :8
enter queue data elements : 1 2 3 4 5 6 7 8
the queue is :1 2 3 4 5 6 7 8 
after pop operation the queue is :2 3 4 5 6 7 8 
peek value is :2
is queue empty : 0
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////