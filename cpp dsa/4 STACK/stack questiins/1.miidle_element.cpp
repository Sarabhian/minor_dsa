#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    int n;
    cout << "enter stack size:";
    cin >> n;
    cout << "enter stack elements :";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }

    stack<int> stk_copy(s);

    if (s.size() % 2 != 0)
    {
        while (stk_copy.size() > (s.size() / 2 + 1))
        {
            // cout << stk_copy.top() <<" ";
            stk_copy.pop();
        }
        cout << "middle element " << stk_copy.top() << endl;
    }
    else
    {
        while (stk_copy.size() > (s.size() / 2))
        {
            // cout << stk_copy.top() <<" ";
            stk_copy.pop();
        }
        cout << "middle element " << stk_copy.top() << endl;
    }

    return 0;
}
