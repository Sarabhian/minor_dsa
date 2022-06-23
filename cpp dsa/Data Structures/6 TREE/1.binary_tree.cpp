//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  BIARY TREE//

#include <iostream>
#include <queue>  //for levelorder traversal
#include <vector> //for levelorder traversal
#include <map>

using namespace std;
/*


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Content of file :                                                                                                   ||
1. create()                                                                                                         ||
2. DFS traversal :                                                                                                  ||
        2.1. preorder()                                                                                             ||
        2.2. inorder()                                                                                              ||
        2.3. postorder()                                                                                            ||
3. BFS traversal :                                                                                                  ||
.       3.1. levelorder()                                                                                           ||
4. views of tree :                                                                                                  ||
.       4.1. left view of tree                                                                                      ||
.       4.2. right view of tree                                                                                     ||
.       4.3. top view of tree                                                                                       ||
.       4.4. bottom view of tree                                                                                    ||
.       4.5. mirror view of tree  or mirror of tree                                                                 ||
5. height of tree                                                                                                   ||
6. diameter of tree                                                                                                 ||
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////// 1. create tree ///////////////////////////////////////////////////////////////////////////////////////////////////////

class node
{

public:
    int data;
    node *left;
    node *right;
    node() {} // default constructor
    node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

////////////////////////////////// create() /////////////////////////////////////////////////////////////////////////////////////////////////////////

// creates nodes until user need it

node *create(int lvl = -1)
{
    int val;
    node *temp = new (node);
    //    cout<<"enter -1 to exit else enter data value of new node"<<endl;
    cin >> val;

    if (val == -1)
    {
        lvl--;

        return 0; // terminating condition
    }
    else
    {
        lvl++;
        temp->data = val;

        cout << "level :" << lvl << " left node of " << val << ":";

        temp->left = create(lvl);
        cout << "level :" << lvl << " right node of " << val << ":";

        temp->right = create(lvl);

        return temp;
    }
}

// creates single node
node *createNode(int val)
{
    node *newNode = new (node);
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
///////////////////////////////////////// 2 DFS Traversal ////////////////////////////////////////////////////////////////////////////////////////

/* depth first search of binary tree  consists of 3 types
    1. preorder :            root at pre then left and right i.e.                                                 root->left->right
    2. inorder :             traverse in a way tree looks (i.e. inorder ) ,root is in the middle i.e.             left->root->right
    3. postorder :           root is post the left and right (root at last) i.e.                                  left->right->root
*/

//======================================= 2.1.preorder traversal =================================================================================//

void preorder(node *root)
{
    node *temp = root;
    if (temp == NULL)
    {
        return;
    }

    cout << temp->data << " ";
    preorder(temp->left);
    preorder(temp->right);
}

//========================================== 2.2.inorder traversal ===============================================================================//

void inorder(node *ROOT)
{
    node *temp = ROOT;

    if (temp == NULL)
    {
        return;
    }

    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}

//=========================================== 2.3.postorder traversal =============================================================================//

void postorder(node *root)
{
    node *temp = root;
    if (temp == NULL)
    {
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << " ";
}

/////////////////////////////////////////////// 3 BFS (level order) traversal ////////////////////////////////////////////////////////////////////////
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

vector<int> levelorder(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans; // return empty value

    queue<node *> q; // since queue is going to contain nodes we will use node as data type
    q.push(root);

    while (!q.empty())
    {
        vector<int> level;
        int size = q.size(); // note we are initializing size because inside the for loop size of q is changing
                             // so cant use q.size() as condition in for loop
        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);

            level.push_back(temp->data);
        }
        ans.insert(ans.end(), level.begin(), level.end()); // add data of level vector at end of ans vector.
    }
    return ans;
}
////////////////////////////////////////// 4. views of tree ////////////////////////////////////////////////////////////////////////////////////////////
// let's go back to EGD :)
/*
========================================== 4.1. left view of tree ==================================================================================
1. left view of tree :
.                   when we insert projection of light on left side of tree
.                   then the node which is having direct contact  with light will be part of left view of tree

  1.                 --->                    18
.                                         /       \
.                  -->                   15         30
.                                     /     \       /  \
.                  -->               40      50   100   40    //considering verticle line 50 and 100 collide at line 0
.                                          /    \
.                  -->                   16      20          //  30 and 20 collide at line 1
.                                      /   \
.                  -->               44      50
.                                  /
.                   -->          50

here  18 , 15, 40 , 16, 44 and50 are parts of left view of tree

// algo : traverse level by level recursively and look for the left most  node of the level.
// we can use preorder traversal with level attribute in it

trick of the code is , the storing vectors size will increase with increase in level size ,
so induction condition for recursion is : if level == ans.size() add data to answer vector .
*/
void left_traveller(vector<int> &ans, node *root, int level = 0)
{
    if (root == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    left_traveller(ans, root->left, level + 1);

    // first traveller will go to left nodes and level will increase ,
    // so data of right nodes will not be added into ans vector unless the level is more than deepest left node
    left_traveller(ans, root->right, level + 1);
}

vector<int> leftview(node *root)
{
    vector<int> ans;
    left_traveller(ans, root, 0);
    return ans;
}

/*================================================ 4.2. right view ========================================================================================

same as left view only traveller will travel to right node first , and iff level of left is more than right then
only data of left will be added to ans vector

*/
void right_traveller(vector<int> &ans, node *root, int level = 0)
{
    if (root == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    right_traveller(ans, root->right, level + 1);

    // first traveller will go to right nodes and level will increase ,
    // so data of left nodes will not be added into ans vector unless the level is more than deepest right node
    right_traveller(ans, root->left, level + 1);
}

vector<int> rightview(node *root)
{
    vector<int> ans;
    right_traveller(ans, root, 0);
    return ans;
}
/*===============================================  4.3. top view =======================================================================================


 here we will traverse tree  in vertical line level order traversal,

consider tree root as 0th line, then lines in left will  increase by -1 and lines  right to root node will increase by +1 ,

.       line 0
   .     .
   .    10    .
   . /   .  \ .
  20     .   30
   .     .    .
line -1      line 1

we need :

one queue to store pair( node data , line )
one map to store line number and node→ data
ans vector to store the data of  nodes in top view

Algo :

1.we will traverse through each node, first go for root  it's line is 0,add { root data , line } to queue;
2.check untill queue is not empty :
.       a. take front of queue , store node val and line value of front to node and line variables , now pop the front from queue,
.       b. if map of the line does not exist  add node→data  to map[line]
.           ( in this way we will be only adding only first top most nodes data present in that particular line)
.       c. now  check for left and right nodes , if they are not null  push data of left and right into q with thier line info.
.           ( for left node line will decrease by 1 and for right it will increase by 1)
3.after adding all top nodes data to the map, push that data to answer vector.
4.return the ans vector

*/

vector<int> topView(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> mp;
    queue<pair<node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        node *Node = it.first;
        int line = it.second;

        if (mp.find(line) == mp.end())
            mp[line] = Node->data;
        if (Node->left != NULL)
            q.push({Node->left, line - 1});
        if (Node->right != NULL)
            q.push({Node->right, line + 1});
    }
    for (auto i : mp)
        ans.push_back(i.second);

    return ans;
}
//===============================================  4.4. bottom view ======================================================================================

vector<int> BottomView(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> mp;
    queue<pair<node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        node *Node = it.first;
        int line = it.second;

        mp[line] = Node->data;
        if (Node->left != NULL)
            q.push({Node->left, line - 1});
        if (Node->right != NULL)
            q.push({Node->right, line + 1});
    }
    for (auto i : mp)
        ans.push_back(i.second);

    return ans;
}
// ========================================= mirror view ===========================================================

void mirrorify(node *root, node **mirror)
{
    if (root == NULL)
    {
        mirror = NULL;
        return;
    }

    // Create new mirror node from original tree node
    *mirror = createNode(root->data);
    mirrorify(root->left, &((*mirror)->right));
    mirrorify(root->right, &((*mirror)->left));
}
///////////////////////////////////////////////// 5. Height of tree /////////////////////////////////////////////////////////////////////////////////////////

int height(node *root)
{
    if (root == NULL)
        return 0;
    return (max(height(root->left), height(root->right)) + 1);
}

///////////////////////////////////////////////// 6. Diameter of tree ///////////////////////////////////////////////////////////////////////////////////////

// diameter of a node is nothing but maximum (left_height + right_height +1 )
// so diameter of tree is , maximum (maximum (diamter of left node , diameter of right node ),currentdiameter) recursively..

int diameter(node *root)
{
    if (root == NULL)
        return 0;
    int currdiameter = height(root->left) + height(root->right) + 1;
    return max(max(diameter(root->left), diameter(root->right)), currdiameter);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printvector(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{

    node *root;
    cout << "enter -1 to exit else enter data value of new node" << endl;
    root = create();
    cout << "preorder traversal :";
    preorder(root);
    cout << endl
         << "inorder traversal :";
    inorder(root);
    cout << endl
         << "postorder traversal :";
    postorder(root);
    vector<int> l;
    l = levelorder(root);
    cout << endl
         << "levelorder traversal :";
    printvector(l);

    cout << "height of a tree is :" << height(root) << endl
         << "Diameter of a tree is :" << diameter(root);
    cout << endl;
    cout << "left view of tree :";
    printvector(leftview(root));
    cout << "right view of tree :";
    printvector(rightview(root));
    cout << "top view of tree :";
    printvector(topView(root));
    cout << "bottom view of tree :";
    printvector(BottomView(root));

    node * mirror;
    mirrorify(root ,&mirror);
    cout << "mirror view of tree :";  //it will be reverse of original inorder 
    inorder(mirror);
    cout<<endl;
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// output format
/*
enter -1 to exit else enter data value of new node
50
level :0 left node of 50:12
level :1 left node of 12:13
level :2 left node of 13:14
level :3 left node of 14:-1
level :3 right node of 14:-1
level :2 right node of 13:40
level :3 left node of 40:-1
level :3 right node of 40:30
level :4 left node of 30:-1
level :4 right node of 30:-1
level :1 right node of 12:14
level :2 left node of 14:-1
level :2 right node of 14:20
level :3 left node of 20:-1
level :3 right node of 20:21
level :4 left node of 21:-1
level :4 right node of 21:-1
level :0 right node of 50:29
level :1 left node of 29:-1
level :1 right node of 29:30
level :2 left node of 30:-1
level :2 right node of 30:40
level :3 left node of 40:122
level :4 left node of 122:123
level :5 left node of 123:-1
level :5 right node of 123:-1
level :4 right node of 122:14
level :5 left node of 14:-1
level :5 right node of 14:-1
level :3 right node of 40:-1
preorder traversal :50 12 13 14 40 30 14 20 21 29 30 40 122 123 14 
inorder traversal :14 13 40 30 12 14 20 21 50 29 30 123 122 14 40 
postorder traversal :14 30 40 13 21 20 14 12 123 14 122 40 30 29 50 
levelorder traversal :50 12 29 13 14 30 14 40 20 40 30 21 122 123 14 
height of a tree is :6
Diameter of a tree is :10
left view of tree :50 12 13 14 30 123 
right view of tree :50 29 30 40 122 14 
top view of tree :14 13 12 50 29 30 40 
bottom view of tree :14 13 40 30 123 122 14 
mirror view of tree :40 14 122 123 30 29 50 21 20 14 12 30 40 13 14 
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////