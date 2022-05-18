#include <iostream>
using namespace std;

/* Doubly  Circular linked list :

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Content of file :                                                                                                   ||
1. create ll                                                                                                        ||
2. traverse and display ll                                                                                          ||
3. inset element in ll                                                                                              ||
    a. at beginning                                                                                                 ||
    b. at end                                                                                                       ||
    c. after given position                                                                                         ||
4. delete node                                                                                                      ||
    a. at end                                                                                                       ||
    b. at beginning                                                                                                 ||
    c. at given location                                                                                            ||
5. reverse the ll                                                                                                   ||
6. find length of  ll                                                                                               ||
.                                                                                                                   ||
.                                                                                                                   ||
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////// 1. create ll ///////////////////////////////////////////////////////////////////////////////////////////////////////

// basic class struct for linkedlist containing data and address ptr next

// basic class struct for linkedlist containing data and address ptr next
class DCNode
{
public:
    int data; // data element

    DCNode *nextN; // address element of next node
    DCNode *prevN; // addesss element of prev node
};

// function which creates n nodes given size n and array 'arr' specifying n data elements

DCNode *create_nNodes(int n, int arr[])
{

    DCNode *head = NULL, *temp = NULL, *newnode; // creating pointers for accessing the ll

    for (int i = 0; i < n; i++)
    {
        newnode = new DCNode(); // allot memory to newnode
        newnode->data = arr[i];     // get data from user in array format to add in ll
        newnode->nextN = NULL;      // assign newnode with null values to address
        newnode->nextN = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        } // assign the 1st newnode to head pointer and temp ptr
        else
        {
            temp->nextN = newnode; // assign next of temp to newnode
            newnode->prevN = temp; // join newnode to temp in reverse
            temp = newnode;        // update temp
        }
    }
    return head; // entire ll is connected with the help of head pointer
}

////////////////////////// 2. DISPLAY ll ////////////////////////////////////////////////////////////////////////////////////////////////////

// void Display_ll(DoublyNode *HEAD_ptr)
// {
//     cout << "the linked list is : ";
//     while (HEAD_ptr != NULL)
//     {
//         cout << HEAD_ptr->data << " "; // ll is just ptr to head and
//                                        // we access elements of ll by traversing through the address of ptr of each node
//         HEAD_ptr = HEAD_ptr->nextN;
//     }
//     cout << endl;
// }

/////////////////////////////// 3. Insert element //////////////////////////////////////////////////////////////////////////////////////////

// ******************** a. inset at begining ***************

// *head is just value of ll, to call the ll by reference we need to use *(*head) otherwise it will not affect the original ll
// another solution to writing insert function is to return ll as done in create_nNode function but here we are using callbyrefernce

// void insert_at_beg(DoublyNode **HEAD_ptr, int data)
// { //  "call by reference"

//     DoublyNode *newnode = new (DoublyNode); // create new node
//     newnode->data = data;
//     newnode->prevN = NULL;
//     newnode->nextN = NULL; // assigning newnode as null , just a good practice

//     (*HEAD_ptr)->prevN = newnode; // using bracket to ptr wraps the ptr ar dereferenced node  and removes the typecast error
//     newnode->nextN = *HEAD_ptr;
//     *HEAD_ptr = newnode;
// }
// // ******************** b. insert at end *******************

// void insert_at_end(DoublyNode **HEAD_ptr, int data)
// {
//     DoublyNode *newnode = new (DoublyNode);
//     newnode->data = data;
//     newnode->nextN = newnode->prevN = NULL;
//     // note traversing directly head_ptr will affect the ll connections so assign new temp node ptr
//     DoublyNode *last = *HEAD_ptr;

//     while (last->nextN != NULL)
//     {
//         last = last->nextN;
//     }                      // traverse till we get last node and then asssign new node to it's  next value
//     last->nextN = newnode; // note : last points to the last node, to add new node we need to assign the newnode to the next of last
//     newnode->prevN = last; // attach newnode to last node
// }

// // ******************** c. insert at given location ********

// void insert_after_location(DoublyNode **HEAD_ptr, int loc, int data)
// {
//     DoublyNode *newnode = new (DoublyNode);
//     newnode->data = data;
//     newnode->nextN = newnode->prevN = NULL;

//     // assign temp ptr to traverse the list
//     DoublyNode *temp = *HEAD_ptr;
//     int i = 1;
//     while (i < loc)
//     {
//         temp = temp->nextN;
//         i++;
//     }
//     // now temp is pointing to the node at given location , temp->next is connected to next node of ll ,

//     // 1. connect newnode to next node
//     newnode->nextN = temp->nextN; // assign next nodes address to newnode
//     temp->nextN->prevN = newnode; // assign prevNode of next node to newnode

//     // 2. connect newnode to temp node
//     newnode->prevN = temp; // assign prev of newnode to temp
//     temp->nextN = newnode; // assign newnodes address to node at given location

//     cout << "\nthe node is inserted after location " << i << endl;
// }
// ////////////////////////// 4 Delete Node ////////////////////////////////////////////////////////////////////////////////////////////////////

// // ********************* a. at begining ***************************

// void Del_at_beg(DoublyNode **HEAD_ptr)
// {
//     DoublyNode *temp = *HEAD_ptr;

//     *HEAD_ptr = temp->nextN;   // assign newnode value to head
//     temp->nextN->prevN = NULL; //  delete the   reverse connection of 2nd node with first node
//     delete temp;
// }

// // ********************* b. at end ********************************
// void del_at_end(DoublyNode **HEAD_ptr)
// {
//     DoublyNode *temp = *HEAD_ptr;
//     if (temp->nextN == NULL) // for single node
//     {
//         delete temp;
//         return;
//     }
//     while (temp->nextN != NULL)
//     {
//         temp = temp->nextN;
//     }
//     // temp pointing to the last node , temp->next is NULL
//     // while deleting the node all the links attached to the node gets deleted but the address stored in another node stay as it is which need to be deleted
//     // so , make temp->prev->next = null , and then delete temp
//     temp->prevN->nextN = NULL;
//     delete temp;
// }
// // // ********************* c. at given location *********************

// void del_at_loc(DoublyNode **HEAD_ptr, int loc)
// {
//     DoublyNode *temp = *HEAD_ptr;
//     int i = 1;
//     if (loc == 1)
//     {
//         *HEAD_ptr = temp->nextN;
//         temp->nextN->prevN = NULL;
//         delete temp;
//         return;
//     }
//     while (i < loc)
//     {
//         temp = temp->nextN;
//         i++;
//     }
//     // now temp pointing to node at given location , check after deleting which address are being stored adn update them befor deleting the link
//     temp->prevN->nextN = temp->nextN;
//     temp->nextN->prevN = temp->prevN;
//     delete temp;
// }
// // ////////////////////////// 5 reverse the ll ///////////////////////////////////////////////////////////////////////////////////////////////

// // // since we are completely changing the ll we need to return the reverse ll without affecting original ll,i.e no call by reference

// DoublyNode *reverse_ll(DoublyNode *HEAD){
//     DoublyNode *temp ,*next; //next is ptr to   next node 
//     temp = next = HEAD;

//     if(HEAD->nextN ==NULL || HEAD== NULL){return HEAD;}
//     while(temp!=NULL){
//         next = next->nextN;
//         temp->nextN = temp->prevN;
//         temp->prevN = next;
//         if(next==NULL){break;} // for last node if we update temp to next then temp will become null and we can't get head refernce value  
//         temp = next;
//     }
//     HEAD = temp;
//     return HEAD;
// }

// ////////////////////////// 6. count the ll ////////////////////////////////////////////////////////////////////////////////////////////////
// int count_ll(DoublyNode *HEAD_ptr){
//     int count =0 ;
//     DoublyNode *temp;
//     temp = HEAD_ptr;
//     while(temp!=NULL){
//         temp= temp->nextN;
//         count++;
//     }
//     return count;
// }
// ////////////////////////// Driver function ////////////////////////////////////////////////////////////////////////////////////////////////
// int main()
// {
//     int n;
//     cout << "enter ll size :";
//     cin >> n;
//     cout << "enter data elements : ";
//     int data_array[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> data_array[i];
//     }

    // create a singly linked list

    // DoublyNode *d;
    // d = create_nNodes(n, data_array);

    // Display_ll(d);

    // insert_at_beg(&d, 7);
    // cout << "\nafter inserting node at beginning " << endl;
    // Display_ll(d);

    //     insert_at_end(&d, 8);
    //     cout << "\nafter inserting node at end " << endl;
    //     Display_ll(d);

    //     insert_after_location(&d, 3, 9);
    //     Display_ll(d);
    //     cout << "\nafter deleting node at begining " << endl;
    //     Del_at_beg(&d);
    //     Display_ll(d);
    //     cout << "\nafter deleting node at end " << endl;
    //     del_at_end(&d);
    //     Display_ll(d);
    //     cout << "\nafter deleting note at location "<< 3 << endl;
    //     del_at_loc(&d,3);
    //     Display_ll(d);
    //     cout <<"after reversing ";
    //     DoublyNode *rd;
    //     rd =reverse_ll(d);
    //     Display_ll(rd);
    //     cout<<"\nthe size of ll is :"<<count_ll(rd);
        
    //     return 0;
    // //
// }