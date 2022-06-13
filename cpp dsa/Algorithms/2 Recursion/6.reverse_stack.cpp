#include<bits/stdc++.h>
using namespace std;

// reverse stack using recursion :
/*
 TC : O(N)
 SC : O(1) no use of extra space

 algo : 1. get the hypothesis function : trust the function that it's recursion will give reversed stack of size n-1
.       2. prerequisites for hypo : make the stack of size n-1 and store nth element 
.       3. find base case : when stack will be of size 1 , return
.       4. induction : insert the nth element at the bottom of stack using insert function

algo for insert ; 1. hypothesis : store top value and trust recursion function that it will push key value at bottom
.                 2. prerequistes for hypo : store top and reduce size
.                 3. base case : if st.size == 0 just push key value
.                 4. induction : just readd nth value at top

*/
void Insert(int key , stack<int>&s){
    if(s.size()==0){s.push(key);return;}

    int temp = s.top();
    s.pop();
    Insert(key,s);
    s.push(temp);
    return;
}
void Reverse(stack<int>&st){
    if(st.size()<=1){return;}

    int temp = st.top();
    st.pop();
    Reverse(st);
    Insert(temp,st);
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

    int n, x;
    cin >> n;

    cout << "enter elements in stack ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.push(x);
    }

    cout << "the stack is : ";
    display(s);
    cout << "stack after reversing : ";
    Reverse(s);
    display(s);
    cout << endl;
   return 0;
}