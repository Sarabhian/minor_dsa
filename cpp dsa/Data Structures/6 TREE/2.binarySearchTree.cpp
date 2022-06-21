//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  BIARY Search TREE//

#include <iostream>
#include <queue>  //for levelorder traversal
#include <vector> //for levelorder traversal
#include <map>

using namespace std;
/*


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Content of file :                                                                                                   ||
1. create()                                                                                                         ||
2. Insert()                                                                                                         ||
3. Delete()                                                                                                         ||
4. search()                                                                                                         ||
5.                                                                                                                  ||
.                                                                                                                   ||
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////// 1. create tree ///////////////////////////////////////////////////////////////////////////////////////////////////////

class BST
{
     int data;
     BST *left, *right;

public:
     BST()
     {
          data = 0;
          left = right = NULL;
     }
     BST(int x)
     {
          data = x;
          right = left = NULL;
     }

     BST *Insert(int, BST *);
     void Inorder(BST *);
     bool Find(int, BST *);
     BST *Delete(int, BST *);
     BST* findmin(BST*);
};

//////////////////////////////// 2. Insert /////////////////////////////////////////////////////////////////////////////////////////////////////////

BST *BST ::Insert(int val, BST *root)
{
     if (root == NULL)
     {
          return new BST(val); // if root is null insert element directly
     }

     if (val > root->data)
     {
          root->right = Insert(val, root->right);
          // if val is greater than root val then forward that val to right of node,
          //  here insert function return the pointer of node ,
          // after inserting value at certain node the ointer to node will bw linked.
     }
     else
     {
          root->left = Insert(val, root->left);
          // if value is less than root value forward val to left of bst.
     }

     return root;
}

/////////////////////////////// 3. traverse /////////////////////////////////////////////////////////////////////////////////////////////////////////

void BST ::Inorder(BST *root)
{
     if (root == NULL)
          return;

     Inorder(root->left);
     cout << root->data << " ";
     Inorder(root->right);
     return;
}
///////////////////////////// 4. search()/find() ///////////////////////////////////////////////////////////////////////////////////////////////////

bool BST ::Find(int x, BST *root)
{
     if (root == NULL)
          return 0;

     if (root->data == x)
          return 1;

     if (root->data < x)
          return Find(x, root->right);
     return Find(x, root->left);
}
///////////////////////////// 5. Delete() ///////////////////////////////////////////////////////////////////////////////////////////////////
/*
deleting a node is little tricky,
algo :
we need to first find the node whose data is equal to the given key value
then
     if node is leaf node then return null
     if node's left is null then return right node
     if node's right is null then return left

     if no node's immediate  bramch is null then find the next suitable minimum value (inorder successor of root node) to fit in the node;

     assign root val = inorder successor value , and delete the node of the inorder successor. (obviously inorder successor will be leaf node most of the times)
     so deleting inorder successor will take O(1);

*/
BST *BST::Delete(int key, BST *root)
{
     if (root == NULL)
          return root;

     if (root->data < key)
     {
          root->right = Delete(key, root->right);
     }
     else if (root->data > key)
     {
          root->left = Delete(key, root->left);
     }
     else
     {
          if (!root->left && !root->right)
          {
               delete (root);
               return NULL;
          }

          if (!root->left)
          {
               BST *temp = root->right;
               delete root;
               return temp;
          }
          if(!root->right){
               BST * temp = root->left;
               delete root;
               return temp;
          }
          BST*  temp = findmin(root->right);
          root->data = temp->data;
          root->right = Delete(temp->data,root->right);
     }
     return root;
}
///////////////////////////// 5. findmin() ////////////////////////////////////////////////////////////////////////////////////////////////////////
// inorder successor

BST* BST:: findmin(BST* root){
     if(root==NULL) return root;
     while(root->left){
          root = root->left;
     }
     return root;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{

     BST b, *root = NULL;
     root = b.Insert(50, root);
     b.Insert(30, root);
     b.Insert(20, root);
     b.Insert(40, root);
     b.Insert(70, root);
     b.Insert(60, root);
     b.Insert(80, root);
     cout << "the inorder traversal of BST is : ";
     b.Inorder(root);
     cout << endl;
     cout << "is value "<<20<<" found ? ans :" << b.Find(20, root) << endl;
     cout<<"tree after delteting the node with value 30 :";
     b.Delete(30,root);
     b.Inorder(root);
     return 0;
}
