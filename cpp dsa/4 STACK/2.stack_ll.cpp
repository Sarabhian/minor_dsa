//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ********** STACK using linkedlist ************* dynamic memory allocation of stack **************//
#include</home/abhijeet/Desktop/minor/cpp dsa/3 LINKEDLIST/1.singlyll.cpp>
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
.                                                                                                                   ||
*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////// 1. create stack ///////////////////////////////////////////////////////////////////////////////////////////////////////

// to create the stack using ll , it must follow LIFO principle
// insert node at beginning 
class Stack_ll{
    int data; 
    Stack_ll *next;
    public:
    Stack_ll(){
        data = 0;
        next = NULL;}
    
    
    void push(int x , Stack_ll **head);
    int pop(Stack_ll**head);
    int peek(Stack_ll *head);
    bool isempty(Stack_ll *head);
    void display(Stack_ll *head);
};
////////////////////////////////////////  2. push()  /////////////////////////////////////////////////////////////////////////////////////////////////

void Stack_ll::push(int x , Stack_ll **head){
    Stack_ll* newnode = new(Stack_ll);
    newnode->data = x;
    newnode->next = *head;
    *head = newnode;
}
 

////////////////////////////////////////   3.pop()    ////////////////////////////////////////////////////////////////////////////////////////////////

int Stack_ll::pop(Stack_ll **head){
    if((*head)->next==NULL) {
        cout<<"underflow condition"<<endl;
        return -1;
    }
    int x = (*head)->data;
    (*head) = (*head)->next;
    return x;
}
///////////////////////////////////////   4. peek()   /////////////////////////////////////////////////////////////////////////////////////////////////

int Stack_ll::peek(Stack_ll *head){
    if (head->next==NULL) {
        cout<<"list is empty"<<endl;
        return -1;
    }
    int x = head->data;
    return x;
}
////////////////////////////////////  5. Display  /////////////////////////////////////////////////////////////////////////////////////////////////////
void Stack_ll::display(Stack_ll *head){
cout << "the linked list is : ";
    while (head->next != NULL)
    {
        cout << head->data << " "; // ll is just ptr to head and
                                       // we access elements of ll by traversing through the address of ptr of each node
        head= head->next;
    }
    cout << endl;
}
///////////////////////////////////////  6. isempty() ///////////////////////////////////////////////////////////////////////////////////////////////////
bool Stack_ll::isempty(Stack_ll *head){
    if(head->next = NULL)return true;
    else 
    return false;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main(){
    
    int n;
    cout << "enter ll size :";
    cin >> n;
    cout << "enter data elements : ";
    int data_array[n];
    Stack_ll s ,*head;
    head = &s;
    for (int i = 0; i < n; i++)
    {
        cin >> data_array[i];
        s.push(data_array[i],&head);
    }
    
    s.display(head);
    s.pop(&head);
    cout<<"after pop operation ";
    s.display(head);
    cout<<"peek value is :"<<s.peek(head)<<endl;
    cout<<"is stack empty : "<<s.isempty(head)<<endl;

   return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// output format 
/*
enter ll size :5
enter data elements : 1 2 3 4 5
the linked list is : 5 4 3 2 1 
after pop operation the linked list is : 4 3 2 1 
peek value is :4
is stack empty : 0
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////