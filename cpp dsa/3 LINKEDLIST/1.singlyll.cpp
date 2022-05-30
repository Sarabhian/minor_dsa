#include <iostream>
using namespace std;

/* Singly linked list :

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
class SinglyNode
{
public:
    int data; // data element

    SinglyNode *next; // address element
};

// function which creates n nodes given size n and array 'arr' specifying n data elements

SinglyNode *create_nNodes(int n, int arr[])
{

    SinglyNode *head = NULL, *temp = NULL, *newnode; // creating pointers for accessing the ll

    for (int i = 0; i < n; i++)
    {
        newnode = new SinglyNode(); // allot memory to newnode
        newnode->data = arr[i];     // get data from user in array format to add in ll

        if (head == NULL)
        {
            head = temp = newnode;
        } // assign the 1st newnode to head pointer and temp ptr
        else
        {
            temp->next = newnode; // initially temp is pointing 1st node , attach the 2nd new node to 1st one
                                  // by adding address of 2nd node to 1st node's address ptr i.e. temp-next
            temp = newnode;       // after new node is attached to first node update temp to 2nd node and so on
        }
    }
    return head; // entire ll is connected with the help of head pointer
}

////////////////////////// 2. DISPLAY ll ////////////////////////////////////////////////////////////////////////////////////////////////////

void Display_ll(SinglyNode *HEAD_ptr)
{
    cout << "the linked list is : ";
    while (HEAD_ptr != NULL)
    {
        cout << HEAD_ptr->data << " "; // ll is just ptr to head and
                                       // we access elements of ll by traversing through the address of ptr of each node
        HEAD_ptr = HEAD_ptr->next;
    }
    cout << endl;
}

/////////////////////////////// 3. Insert element //////////////////////////////////////////////////////////////////////////////////////////

// ******************** a. inset at begining ***************

// *head is just value of ll, to call the ll by reference we need to use *(*head) otherwise it will not affect the original ll
// another solution to writing insert function is to return ll as done in create_nNode function but here we are using callbyrefernce

void insert_at_beg(SinglyNode **HEAD_ptr, int data)
{ //  "call by reference"

    SinglyNode *newnode = new (SinglyNode); // create new node
    newnode->data = data;
    newnode->next = *HEAD_ptr; // assign next of newnode to head ... will attach newnode to 1st node
    *HEAD_ptr = newnode;       // update head pointing to newnode from 1st node
}
// ******************** b. insert at end *******************

void insert_at_end(SinglyNode **HEAD_ptr, int data)
{
    SinglyNode *newnode = new (SinglyNode);
    newnode->data = data;
    // note traversing directly head_ptr will affect the ll connections so assign new temp node ptr
    SinglyNode *last = *HEAD_ptr;

    while (last->next != NULL)
    {
        last = last->next;
    }                     // traverse till we get last node and then asssign new node to it's  next value
    last->next = newnode; // note : last points to the last node, to add new node we need to assign the newnode to the next of last
}

// ******************** c. insert at given location ********

void insert_after_location(SinglyNode **HEAD_ptr, int loc, int data)
{
    SinglyNode *newnode = new (SinglyNode);
    newnode->data = data;
    // assign temp ptr to traverse the list
    SinglyNode *temp = *HEAD_ptr;
    int i = 1;
    while (i < loc)
    {
        temp = temp->next;
        i++;
    }
    // now temp is pointing to the node at given location , temp->next is connected to next node of ll ,

    newnode->next = temp->next; // assign next nodes address to newnode
    temp->next = newnode;       // assign newnodes address to node at given location

    cout << "\nthe node is inserted after location " << i << endl;
}
////////////////////////// 4 Delete Node ////////////////////////////////////////////////////////////////////////////////////////////////////

// ********************* a. at begining ***************************

void Del_at_beg(SinglyNode **HEAD_ptr)
{
    SinglyNode *temp = *HEAD_ptr;

    *HEAD_ptr = temp->next;
    delete temp;
}

// ********************* b. at end ********************************
void del_at_end(SinglyNode **HEAD_ptr)
{
    SinglyNode *temp = *HEAD_ptr;
    if (temp->next == NULL) // for single node 
    {
        delete temp;
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    // temp pointing to the 2nd last node , temp-next pointing to last node and temp-next-next is null 
    // first  delete last node and then assign addess of 2nd last node to be null 
    delete temp->next;
    temp->next = NULL ;
}
// ********************* c. at given location *********************

void del_at_loc(SinglyNode** HEAD_ptr , int loc ){
    SinglyNode *temp = *HEAD_ptr, *prevNode = *HEAD_ptr;
    int i =1 ;
    if(loc == 1){*HEAD_ptr = temp->next; delete temp; return;}
    while(i<loc){
        prevNode = temp; 
        temp = temp->next;
        i++;
    }
    // now temp pointing to node at given location , prevNode point to (loc-1)th node,
    // assign address of (loc+1)tth node's address to prev node , and delete temp node
    prevNode->next = temp->next;
    delete temp;

}
////////////////////////// 5 reverse the ll ///////////////////////////////////////////////////////////////////////////////////////////////

// since we are completely changing the ll we need to return the reverse ll without affecting original ll,i.e no call by reference

SinglyNode *reverse_ll(SinglyNode *HEAD){
    SinglyNode *prevNode =NULL, *currentNode , *nextNode;
    currentNode = nextNode = HEAD;  

    if(HEAD->next ==NULL){return HEAD;}
    while(nextNode!=NULL){
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode =currentNode;
        currentNode =nextNode;
    }
    HEAD = prevNode;
    return HEAD;
}

////////////////////////// 6. count the ll ////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////// Driver function ////////////////////////////////////////////////////////////////////////////////////////////////
//  int main()
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

//     // create a singly linked list

//     SinglyNode *s;
//     s = create_nNodes(n, data_array);

//     Display_ll(s);

//     insert_at_beg(&s, 7);
//     cout << "\nafter inserting node at beginning " << endl;
//     Display_ll(s);

//     insert_at_end(&s, 8);
//     cout << "\nafter inserting node at end " << endl;
//     Display_ll(s);

//     insert_after_location(&s, 3, 9);
//     Display_ll(s);
//     cout << "\nafter deleting node at begining " << endl;
//     Del_at_beg(&s);
//     Display_ll(s);
//     cout << "\nafter deleting node at end " << endl;
//     del_at_end(&s);
//     Display_ll(s);
//     cout << "\nafter deleting note at location "<< 5 << endl;
//     del_at_loc(&s,5);
//     Display_ll(s);
//     cout <<"after reversing ";
//     SinglyNode *rs;
//     rs =reverse_ll(s);
//     Display_ll(rs);
//     return 0;
// }