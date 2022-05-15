#include <iostream>
using namespace std;

/* Circular linked list :

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
class CirNode
{
public:
    int data; // data element

    CirNode *next; // address element
};

// function which creates n nodes given size n and array 'arr' specifying n data elements

CirNode *create_nNodes(int n, int arr[])
{

    CirNode *head = NULL, *temp = NULL, *newnode ,*tail; // creating pointers for accessing the ll

    for (int i = 0; i < n; i++)
    {
        newnode = new CirNode(); // allot memory to newnode
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
    temp->next = head;  // just assign end of ll to head that's it 
    tail = temp;
    return tail ; // entire ll is connected with the help of tail = temp 
}

////////////////////////// 2. DISPLAY ll ////////////////////////////////////////////////////////////////////////////////////////////////////

void Display_ll(CirNode *TAIL_ptr)
{   
    CirNode *head = TAIL_ptr->next ;
    if(head==NULL){cout<<"list is empty"<<endl; return;}

    CirNode *tail_address = TAIL_ptr;
    cout << "the linked list is : ";
    while (head != tail_address)
    {
        cout << head->data << " "; // ll is just ptr to head and
                                       // we access elements of ll by traversing through the address of ptr of each node
        head = head->next;
    }
    cout<<head->data<<endl; //last node was  missing to print in logic :)

}

/////////////////////////////// 3. Insert element //////////////////////////////////////////////////////////////////////////////////////////

// ******************** a. inset at begining ***************

// *head is just value of ll, to call the ll by reference we need to use *(*head) otherwise it will not affect the original ll
// another solution to writing insert function is to return ll as done in create_nNode function but here we are using callbyrefernce

void insert_at_beg(CirNode **TAIL_ptr, int data)
{ //  "call by reference"
    CirNode *newnode;
    newnode = new(CirNode);
    newnode->data = data;
    newnode->next = (*TAIL_ptr)->next ; // attach  next of newnode to head of ll i.e. next of tail
    (*TAIL_ptr)->next = newnode; // assign tail.next to newnode
}
// // ******************** b. insert at end *******************

void insert_at_end(CirNode **TAIL_ptr, int data)
{
    CirNode *newnode = new (CirNode);
    newnode->data = data;
    newnode->next = (*TAIL_ptr)->next ;// attach newnode to head 
    (*TAIL_ptr)->next = newnode;
    // if we don't update tail ptr then the node will be added at beggining so update tail ptr to new node
    *TAIL_ptr = newnode; // NOTE : to assign next and data value of refernce ptr we need to use (* ptr ) but to update the ptr we don't need ( )

}

// // ******************** c. insert at given location ********

void insert_after_location(CirNode **TAIL_ptr, int loc, int data)
{
    CirNode *newnode = new (CirNode);
    newnode->data = data;
    // assign temp ptr to traverse the list
    CirNode *temp = (*TAIL_ptr)->next; // temp pointing at head
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
// ////////////////////////// 4 Delete Node ////////////////////////////////////////////////////////////////////////////////////////////////////

// ********************* a. at begining ***************************

void Del_at_beg(CirNode **TAIL_ptr)
{
    CirNode *temp ,*tail =*TAIL_ptr;  //NOTE while deleting and inserting nodes it is important to create temp nodes and duplicate nodes to avoid unnecessary segment fault
    temp = tail->next; //temp pointing head

    tail->next = temp->next; // assign tail.next to 2nd node 
    delete temp;
    *TAIL_ptr = tail;
}

// // ********************* b. at end ********************************
// void del_at_end(CirNode **TAIL_ptr)
// {
//     CirNode *temp ,*tail = *TAIL_ptr; 
//     temp = tail->next;//temp pointing head
//     if (temp==tail) // for single node 
//     {
//         delete temp;
//         return;
//     }
//     while (temp->next != tail) // while temp is not last 2nd node
//     {
//         temp = temp->next;
//     }
//     // temp pointing to the 2nd last node , temp-next pointing to last node 
//     // first assign temp.next to head,  delete last node 
//     temp->next = tail->next; 
//     tail->next = NULL;
//     delete TAIL_ptr;
// }
// ********************* c. at given location *********************

void del_at_loc(CirNode** TAIL_ptr , int loc ){
    CirNode *temp = (*TAIL_ptr)->next, *prevNode = (*TAIL_ptr)->next;
    int i =1 ;
    if(loc == 1){(*TAIL_ptr)->next = temp->next; delete temp; return;}
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
// ////////////////////////// 5 reverse the ll ///////////////////////////////////////////////////////////////////////////////////////////////

// // since we are completely changing the ll we need to return the reverse ll without affecting original ll,i.e no call by reference

CirNode *reverse_ll(CirNode *TAIL){
    CirNode *prevNode =NULL, *currentNode , *nextNode;
    currentNode = nextNode = TAIL->next;  
    prevNode = TAIL;

    if(TAIL->next ==TAIL){return TAIL;}
    while(nextNode!=TAIL){
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode =currentNode;
        currentNode =nextNode;
    }
    //current and nextnode both present at last node, here tail.next is still pointing the head node update tail to head 
    // now update the address of last node and and point it to prevnode 
    TAIL = TAIL->next; // tail is pointing now head
    currentNode->next = prevNode ; // ll is attached with head being tail and tail being head
    return TAIL;
}

////////////////////////// 6. count the ll ////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////// Driver function ////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int n;
    cout << "enter ll size :";
    cin >> n;
    cout << "enter data elements : ";
    int data_array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> data_array[i];
    }

    // create a Circular linked list

    CirNode *s;
    s = create_nNodes(n, data_array);

    Display_ll(s);

    insert_at_beg(&s, 7);
    cout << "\nafter inserting node at beginning " << endl;
    Display_ll(s);

    insert_at_end(&s, 8);
    cout << "\nafter inserting node at end " << endl;
    Display_ll(s);

    insert_after_location(&s, 3, 9);
    Display_ll(s);
    cout << "\nafter deleting node at begining " << endl;
    Del_at_beg(&s);
    Display_ll(s);
    // cout << "\nafter deleting node at end " << endl;
    // del_at_end(&s);
    // Display_ll(s);
    cout << "\nafter deleting note at location "<< 5 << endl;
    del_at_loc(&s,5);
    Display_ll(s);
    cout <<"after reversing ";
    CirNode *rs;
    rs =reverse_ll(s);
    Display_ll(rs);
    return 0;
}