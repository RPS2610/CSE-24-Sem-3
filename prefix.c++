#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;

    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

string fun(string infix)
{
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    string prefix = "";
    stack<char> st;

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            prefix += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                prefix += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() &&
                  (precedence(st.top()) > precedence(ch) ||
                  (precedence(st.top()) == precedence(ch) && ch == '^')))
            {
                prefix += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty())
    {
        prefix += st.top();
        st.pop();
    }

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main()
{
    string infix;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    cout << "Prefix Expression: " << fun(infix);

    return 0;
}