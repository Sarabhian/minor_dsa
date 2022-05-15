#include<iostream>
using namespace std; 
/*
A node can be added in three ways 
1) At the front of the linked list 
2) After a given node. 
3) At the end of the linked list.

            head         second         third           
        ___ ____        ____  ____         ____ ____
-->    | D |  N  |     |  D | N  | <-    |  D |  N  |<--
|       ---- -----      ----- ----   |   ----- -----   |
--------------------------------------------------------
            |
    new Node 
     ____ ____ 
    |  D  | N   |
    ----- -----
*/
class Node{
    public:
    int data ;
    Node* next;

};

// adding node at front of LL 
/*
initially pointer of head_reference points to head node , 
 1. create a node  and add data to node
 2. add next of new node as pointer to head node 
 3. add pointer of head_reference to new node 


to call the function that adds at the front of the list is add_to_start().
The add_to_start() must receive a pointer to the head pointer, 
because add_to_start must change the head pointer to point to the new node

 
 **head represent *(*head) i.e pointer to pointer 
here **head_ref is assigned , it takes &head as input which means *(&head) 
**(&head) == pointer which reads address of first node
*(head_ref) == pointer which reads the values of first node 

*/

void add_to_start (Node **head_ref,int data){  


    Node* new_Node = new Node();

    new_Node-> data = data;
    new_Node->next =  *head_ref; // head_ref referes to heaed node 
    *head_ref = new_Node; // now change head_ref to new_node
}

// add after given node 
// 1. create node and add data to it 
// 2. assign next of new node == next of prev node
// 3. assign next of prev  node == new_node

void add_after_node(Node* prev_node , int new_data){
     Node* new_Node = new Node();
     new_Node->data = new_data;
     new_Node->next = prev_node->next;
     prev_node->next = new_Node;
}
// 1.  create node and add data to it 
// 2. assign next of node as null 
// 3. assign next of last node to new node 
// 4. but first ,to get last node we need to iterate through head node to last node 

void add_to_end(Node **head_ref ,int data){
     Node* new_Node = new Node();
     new_Node->data = data;
     new_Node->next = NULL;
// if ll is empty then one new node is created and return that node only 
    if (*head_ref ==NULL){
        *head_ref = new_Node;
        return;
    }
    Node *last = *head_ref; // assigning last node pointer to head_ref and 
    // iterating last till we get null 
    while(last->next != NULL){
        last= last->next;
    }

    // NOW  we are at the last node of linked list where last represents the pointer to last node

    last->next = new_Node;
    return;

     
}
int main(){
    // creating 4 new nodes 
    Node  *head = new Node();
    Node *second = new Node();
    Node  *third = new Node();
    Node  *forth = new Node();

    // assigning values to nodes

head->next = second; 
head->data =0;

second->next = third;
second->data = 1;

third->data = 2; 
third->next = forth;

forth->data =3;
forth->next = NULL;

add_to_start(&head , 7);
add_to_end(&head , 6);
add_after_node(second,10);
Node* n =head;
cout<<"values present in linked list : ";
while(n!=NULL){
    cout<<n->data<<" ";
    n=n->next;

}

}
// ** means use & while calling the pointer in main function, 
//* means just use name not the address.