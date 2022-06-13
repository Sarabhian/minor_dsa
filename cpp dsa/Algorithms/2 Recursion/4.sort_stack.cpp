#include <bits/stdc++.h>
using namespace std;

/*
as usual we will use IBH rule for sorting

algo : 1.first write a hypothesis that our stack can sort first n-1 elements in stack of size n
.       2. find base case for algo where sorting fails
.       3. in induction write a function which will insert the nth element at right position in n-1 sorted stack.
*/
void Insert(int key, stack<int> &s)
{
    if (s.size() == 0 || s.top() <= key)
    {
        s.push(key);
        return;
    }

    int temp = s.top();
    s.pop();
    Insert(key, s);
    s.push(temp);
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

void Sort(stack<int> &st)
{
    if (st.empty() || st.size() == 1)
        return; // base case

    int temp = st.top(); // hypothesis prereequisite 1
    st.pop();            //// hypothesis prereequisite 2

    Sort(st);         // since we can't decrease the size of st from n to n-1 unless we pop element , so we need two prerequisites for hypothesis
    Insert(temp, st); // induction :inserting last element into sorted stack of size n-1.
}
int main()
{
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
    cout << "stack after sorting : ";
    Sort(s);
    display(s);
    cout << endl;

    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// output format
/*
enter stack size :7
enter elements in stack 9 6 3 7 2 5 1
the stack is : 9 6 3 7 2 5 1 
stack after sorting : 1 2 3 5 6 7 9 
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////