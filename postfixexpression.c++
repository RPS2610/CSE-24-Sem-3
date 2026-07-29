#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int evaluatePostfix(string exp)
{
    stack<int> st;
    stringstream ss(exp);
    string token;

    while (ss >> token)
    {
        if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1))
        {
            st.push(stoi(token));
        }
        else
        {
            int val2 = st.top();
            st.pop();

            int val1 = st.top();
            st.pop();

            switch (token[0])
            {
                case '+':
                    st.push(val1 + val2);
                    break;

                case '-':
                    st.push(val1 - val2);
                    break;

                case '*':
                    st.push(val1 * val2);
                    break;

                case '/':
                    st.push(val1 / val2);
                    break;

                case '%':
                    st.push(val1 % val2);
                    break;
            }
        }
    }

    return st.top();
}

int main()
{
    string postfix;

    cout << "Enter Postfix Expression: ";
    getline(cin, postfix);

    cout << "Result = " << evaluatePostfix(postfix);

    return 0;
}