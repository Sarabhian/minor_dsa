#include<bits/stdc++.h>
using namespace std;

// delete kth element in stack and return stack 
// or delete middle element in stack and return stack

/*
algo : 1. use recursion hypothesis : trust that delete_k function will delete k-1 th element in n-1 stack
.      2. hypothesis need two prerequisites : get stack of size n-1 , and store nth element
.      3. find base condition : when size of k =1  just pop the kth element and return;
.      4. induction ; push the nth element in stack after deleteing kth element

. to delete middle value just use k=st.size()/2 + 1  .. valid for even and odd both cases. 
*/
void delete_k(stack<int>&st ,int k){
    if(k==1){st.pop(); return;}  // base condition

    int temp = st.top();
    st.pop();
    delete_k(st,k-1);
    st.push(temp);
    return;
}

void display(stack<int> s)
{
    stack<int> s_;
    if (s.empty())
        return;
    while (!s.empty())
    {
        s_.push(s.top());
        s.pop();
    }
    while (!s_.empty())
    {
        cout << s_.top() << " ";
        s_.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> s;
    cout << "enter stack size :";

    int n, x,k;
    cin >> n;

    cout << "enter elements in stack ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.push(x);
    }
    cout<<"enter k to be deleted from top : ";
    cin>>k;
    cout << "the stack is : ";
    display(s);
    cout << "stack after deleting "<<k<<"th element from top : ";
    delete_k(s,k);
    display(s);
    cout << endl;
   
   return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//output format
/*
enter stack size :7
enter elements in stack 1 2 3 4 5 6 7
enter k to be deleted from top : 4
the stack is : 1 2 3 4 5 6 7 
stack after deleting 4th element from top : 1 2 3 5 6 7 
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////