#include<bits/stdc++.h>
#include</home/abhijeet/Desktop/minor/cpp dsa/3 LINKEDLIST/1.singlyll.cpp>
using namespace std;

SinglyNode* rotateby1( SinglyNode *s){
    SinglyNode *head ,*temp;
    head = s;
    temp = s;
    while(temp->next->next!=nullptr){
        temp = temp->next;
    }
    temp->next->next = head; //attach last node to head node
    head = temp->next; // assign head to last node
    temp->next = NULL; // assign null to last but 1's next

    return head;
}

int main(){
   SinglyNode * s;
   int arr[]={1,2,3,4,5,6};
   s =create_nNodes(6 ,arr );
   Display_ll(s);
   s= rotateby1(s);
   Display_ll(s);

   return 0;
}