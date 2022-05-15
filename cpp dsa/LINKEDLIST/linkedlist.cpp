#include<iostream>
using namespace std;

/*

content of file :
LINKED LIST :
1. creating nodes 
2. assigning memory 
3. assigning values to node
4. traversing node ( accessing values of linked list)
Linked list :
A linked list is represented by a pointer to the first node of the linked list. The first node is called the head. If the linked list is empty, then the value of the head points to NULL. 
Each node in a list consists of at least two parts: 
1) data (we can store integer, strings or any type of data).
2) Pointer (Or Reference) to the next node (connects one node to another)

*/

class Node {
    public:

    int data ;
    Node* next;
};

int main(){
    //  creating first 3 nodes 
    // here we have created three pointers to class

    Node* head =NULL;
    Node* second =NULL;
    Node* third = NULL;
  // allocating memory in the heap 

  head = new Node();
  second = new Node();
  third = new Node();
/* Three blocks have been allocated dynamically.
    We have pointers to these three blocks as head,
    second and third    
    head         second         third
    ___ ____        ____  ____     ____ ____
     D |  N  |     |  D | N  |    |  D |  N  |
    ---- -----      ----- ----    ----- ----- 

    D = data , N = next ( address of next node )

*/

// assigning values to the node 

head->next = second; 
head->data =0;

second->next = third;
second->data = 1;

third->data = 2;

/*
    head             second         third
    ___ ____        ____  ____       ____ _______
     0 |  2nd |--> |  1 | 3rd | --> |  2 |  NULL |
    ---- -----      ----- ----       ----- ----- 
*/

// traversing the linked list 
cout<<"data of head node : "<< head->data<<endl;
cout<<"data of second node : "<< second->data<<endl;
cout<<"data of third node : "<< third->data<<endl;

cout<<"next of head node : "<< head->next<<endl;
cout<<"next of second node : "<< second->next<<endl;
cout<<"next of third node : "<< third->next<<endl;


// printing the data using loop
Node* n =head;
cout<<"values present in linked list : ";
while(n!=NULL){
    cout<<n->data<<" ";
    n=n->next;
}




}