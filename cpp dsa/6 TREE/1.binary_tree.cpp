//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  BIARY TREE//

#include<iostream>
using namespace std;
/*


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Content of file :                                                                                                   ||
1. create()                                                                                                         ||
2. inorder()                                                                                                        ||
3. postorder()                                                                                                      ||
4. preorder()                                                                                                       ||
5. insert()                                                                                                         ||
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

///////////////////////////////////////////////// preorder traversal ////////////////////////////////////////////////////////////////////////////

void preorder(node * root){
    node* temp = root;
    if(temp == NULL){
        return;}
    
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
   
}


////////////////////////////////////////////////// inorder traversal /////////////////////////////////////////////////////////////////////////////

void inorder(node * ROOT){
    node* temp = ROOT ;
   
    if(temp == NULL){
        return;}
   
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}

/////////////////////////////////////////////////// postorder traversal /////////////////////////////////////////////////////////////////////////
void postorder(node* root){
    node* temp = root;
    if( temp ==NULL){
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->data<<" ";
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
    cout<<endl;
    return 0;
}