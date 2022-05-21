// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution
{
    public:

    struct node *reverse (struct node *head, int k)
    { 
        node* curr, *prev , *Next  ;
        curr = Next = head;prev = NULL;
        int count =0 ;
        if(head->next == NULL) return head;
        while(Next!=NULL&&count<k){
            
            Next = Next->next;
            curr->next = prev;
            prev= curr;
            curr = Next; 
            count++;
        }
        
         if (Next != NULL) 
         head->next = reverse(Next, k);
       return prev;
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cout<<"total test case number :";
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cout<<"enter list size :";
        cin >> n;
        cout<<"enter list elements :";
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cout<<" enter k value :";
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //output format 
  /*
total test case number :3
enter list size :2
enter list elements :1 2
enter k value :3
2 1 
enter list size :9
enter list elements :1 2 3 4 5 6 7 8 9
enter k value :4
4 3 2 1 8 7 6 5 9 
enter list size :8
enter list elements :0 9 8 7 6 5 4 3
enter k value :2
9 0 7 8 5 6 3 4 
  */
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////