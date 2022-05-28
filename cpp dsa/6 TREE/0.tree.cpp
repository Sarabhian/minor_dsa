//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

TREE :   it has root , edges , nodes , and branches to the node , leaf or leaves , 

    root : it is the base node of the tree
    edges: the connection link between one node to other node is edge
    nodes: it is the storage element of the tree { genarally node consists data , address to next adjacent nodes}
    branches to the node: one node can be connected to multiple child nodes but can have only one parent , 
    .                       this coonection between node to node is called branch/edge
    leaf or leaves: the node at the last of tree who is havung no child node  is leaf

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    .                                A             lvl 0                                                                                            +
    .                              /   \
    .                             B     C           lvl 1                                                                                           +
    .                           / | \   / \
    .                          D  E  F  G  H        lvl 2                                                                                           +
    .                         /           / \ 
    .                        I           J   K      lvl 3   ... I ,J , K , E ,F, G ==> are leaves since they are not having any child nodes         +

 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 properties of tree : height of node , height of tree , depth of  node, depth of tree , level of tree , maximum nodes of tree , maximum branches of tree ,

        Depth: Depth of the node is the distance from the root node to that particular node.
        Height: The height of the node is the distance from that node to the deepest node of the tree.
        Height of tree: Height of the tree is the maximum height of any node.

 functions of tree : traversal , insertion , deletion , find min max node ,

///////////////////////////////////////////////          BINARY TREE             ////////////////////////////////////////////////////////////////////////////
TYPES of TREE :

Binary Tree:
.              A tree whose elements have at most 2 children is called a binary tree. Since each element in a binary tree can have only 2 children,
.              we typically name them the left and right child. 


Binary Tree Representation: 
.                           A tree is represented by a pointer to the topmost node in tree. If the tree is empty, then value of root is NULL. 

A Tree node contains following parts. 
1. Data 
2. Pointer to left child 
3. Pointer to right child
In C, we can represent a tree node using structures. In other languages we can use classes as part of their OOP feature.
*/
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

// or 
class Node
{
  public:
    int data;
    Node* left;
    Node* right;
};
/*

Basic Operation On Binary Tree:

Inserting an element.
Removing an element.
Searching for an element.
Traversing an element. 

///////////////////////////////////////////         BINARY TREE  TRAVERSAL         ////////////////////////////////////////////////////////////////////////////


There are three types of traversals in binary tree 

PreOrder Traversal: root – left child – right child. It means that the root node is traversed first then its left child and finally the right child.
InOrder Traversal: left child – root – right child.  It means that the left child is traversed first then its root node and finally the right child.
PostOrder Traversal: left child – right child – root.  It means that the left child is traversed first then the right child and finally its root node.

  
///////////////////////////////////////////        Appications of BInary tree      /////////////////////////////////////////////////////////////////////////////
Auxiliary Operation On Binary Tree:

Finding the height of the tree
Find the level of the tree
Finding the size of the entire tree.


Applications of Binary Tree:

In compilers, Expression Trees are used which is an application of binary tree.
Huffman coding trees are used in data compression algorithms.
Priority Queue is another application of binary tree that is used for searching maximum or minimum in O(logn) time complexity.

///////////////////////////////////////          TYPES OF BINARY  TREE            ///////////////////////////////////////////////////////////////////////////////

1. Full Binary Tree 

--  if every node has 0 or 2 children

.  1.           18
.          /        \  
.         15         30  
.        /  \        /  \
.      40    50    100   40
.
.             18
.           /    \   
.         15     20    
.        /  \       
.      40    50   
.    /   \
.   30   50
. _________________________________________________
.   
.   2.         18
.            /    \  
.          40       30  
.                   /  \
.                 100   40

==========================================================================================================================

2.  Complete Binary Tree

--  all the levels are completely filled except possibly the last level and the last level has all keys as left as possible 

.  1.          18
.           /       \  
.         15         30  
.        /  \        /  \
.      40    50    100   40
.
._____________________________________________________

.  2.           18
.           /       \  
.         15         30  
.        /  \        /  \
.     40    50    100   40
.     /  \   /
.    8   7  9 

============================================================================================================================

3. Perfect Binary Tree

-- all the internal nodes have two children and all leaf nodes are at the same level. 

.  1.           18
.           /       \  
.         15         30  
.        /  \        /  \
.      40    50    100   40

________________________________________________________

.  2.           18
.           /       \  
.         15         30  

===============================================================================================================================

4.Balanced Binary Tree 
.                    A binary tree is balanced if the height of the tree is O(Log n) where n is the number of nodes.

 For Example,
 1. AVL tree maintains O(Log n) height by making sure that the difference between the heights of the left and right subtrees 
    is at most 1.
 2. Red-Black trees maintain O(Log n) height by making sure that the number of Black nodes on every root to leaf paths is the 
    same and there are no adjacent red nodes.
 
 Balanced Binary Search trees are performance-wise good as they provide O(log n) time for search, insert and delete. 

================================================================================================================================

A degenerate (or pathological) tree


-- A Tree where every internal node has one child.
    Such trees are performance-wise same as linked list. 

.

.      10
.      /
.    20
.     \
.     30
.      \
.      40     

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




































































*/