//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  BIARY TREE//

#include<iostream>
#include<queue> //for levelorder traversal
#include<vector> //for levelorder traversal

using namespace std;
/*


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Content of file :                                                                                                   ||
1. create()                                                                                                         ||
2. DFS traversal :                                                                                                  ||
        2.1. preorder()                                                                                             ||
        2.2. inorder()                                                                                              ||
        2.3. postorder()                                                                                            ||
3. BFS traversal :
.       3.1. levelorder()                                                                                           ||
6. delete()                                                                                                         ||
7.                                                                                                                  ||
.                                                                                                                   ||
*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////// 1. create tree ///////////////////////////////////////////////////////////////////////////////////////////////////////

 class node{
    
    public: 
    int data ;
    node* left;
    node* right;
    node(){}  //default constructor 
    node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

////////////////////////////////// create() /////////////////////////////////////////////////////////////////////////////////////////////////////////

// creates nodes until user need it 

node* create(int lvl =-1){
    int val ;
    node * temp = new (node);
//    cout<<"enter -1 to exit else enter data value of new node"<<endl;
   cin>>val;
  
   if(val == -1){
       lvl--;
       
       return 0;    // terminating condition
   }
   else{
       lvl++;
       temp->data = val;
       
       cout<<"level :"<<lvl <<" left node of "<<val<<":";
   
       temp->left = create(lvl);
       cout<<"level :"<<lvl<<" right node of "<<val<<":";
  
       temp->right = create(lvl);
       
       return temp;
   }
}
///////////////////////////////////////// DFS Traversal ////////////////////////////////////////////////////////////////////////////////////////

/* depth first search of binary tree  consists of 3 types
    1. preorder :            root at pre then left and right i.e.                                                 root->left->right
    2. inorder :             traverse in a way tree looks (i.e. inorder ) ,root is in the middle i.e.             left->root->right
    3. postorder :           root is post the left and right (root at last) i.e.                                  left->right->root         
*/

//======================================= 1.preorder traversal =================================================================================//

void preorder(node * root){
    node* temp = root;
    if(temp == NULL){
        return;}
    
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
   
}

//========================================== 2.inorder traversal ===============================================================================//

void inorder(node * ROOT){
    node* temp = ROOT ;
   
    if(temp == NULL){
        return;}
   
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}

//=========================================== 3.postorder traversal =============================================================================//

void postorder(node* root){
    node* temp = root;
    if( temp ==NULL){
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->data<<" ";
}

/////////////////////////////////////////////// BFS (level order) traversal ////////////////////////////////////////////////////////////////////////
/*
// traversing a tree in horizontal way , i.e. levelwise traversal of the tree
// we need  :
.            queue :  store left, right and roots
.            vector ans : to store final data
.            level vector : to tempararily  store roots of each level

 
Algo :  create a queue and inssert root of tree into it.
        while( queue is not empty)
             initiate lebvel vector
             for(  itr  0: size of queue)
                take out front of queue and convert it as node of tree
                now check the node is having left or right , if exist add to queue
                in end add node.data to level vector;
             after one for loop complition add data of level vector to ans vector 
        return ans  
*/

  vector<int> levelorder(node *root){
      vector<int>ans;
      if(root ==NULL) return ans; //return empty value

      queue<node*> q;   // since queue is going to contain nodes we will use node as data type 
      q.push(root);

      while(!q.empty()){
          vector<int> level;
          int size = q.size(); //note we are initializing size because inside the for loop size of q is changing 
                              //so cant use q.size() as condition in for loop
          for(int i=0 ; i<size; i++){
              node* temp = q.front();
              q.pop();

              if(temp->left!=NULL) q.push(temp->left);
              if(temp->right!=NULL) q.push(temp->right);

              level.push_back(temp->data);
          }
          ans.insert(ans.end(),level.begin(),level.end());  // add data of level vector at end of ans vector.

      }
      return ans;
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int height(node* root){
        if(root==NULL) return 0;
        return (max(height(root->left),height(root->right))+1);
    }
    // diameter of a node is nothing but maximum (left_height + right_height +1 )
    // so diameter of tree is , maximum (diamter of left node , diameter of right node ) recursively..
 int diameter(node* root){
        if(root == NULL) return 0;
        int currdiameter = height(root->left) + height(root->right) +1;
         return max(max(diameter(root->left) , diameter(root->right)), currdiameter);
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){

    node * root;
    cout<<"enter -1 to exit else enter data value of new node"<<endl;
    root = create();
    cout<< "preorder traversal :";
    preorder(root);
    cout<<endl<<"inorder traversal :";
    inorder(root);
    cout<<endl<<"postorder traversal :";
    postorder(root);
    vector<int> l;
    l = levelorder(root);
    cout<<endl<<"levelorder traversal :";
    for(int i =0 ; i< l.size(); i++){cout<<l[i]<<" ";}
    cout<<endl;
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//output format 
/*
enter -1 to exit else enter data value of new node
1
level :0 left node of 1:2
level :1 left node of 2:4
level :2 left node of 4:-1
level :2 right node of 4:-1
level :1 right node of 2:5
level :2 left node of 5:-1
level :2 right node of 5:-1
level :0 right node of 1:3
level :1 left node of 3:6
level :2 left node of 6:-1
level :2 right node of 6:-1
level :1 right node of 3:7
level :2 left node of 7:-1
level :2 right node of 7:-1
preorder traversal :1 2 4 5 3 6 7 
inorder traversal :4 2 5 1 6 3 7 
postorder traversal :4 5 2 6 7 3 1 
levelorder traversal :1 2 3 4 5 6 7 
*/