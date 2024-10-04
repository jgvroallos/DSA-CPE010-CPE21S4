#include <iostream>
#include <stack>
#include <string>

using namespace std;

void checkExpression(string expression) 
{
    stack<char> string;
    for (char ch : expression)
    {
        if (ch == '(') string.push(')');
        else if (ch == '{') string.push('}');
        else if (ch == '[') string.push(']');
        else if (ch == ')' || ch == '}' || ch == ']') {
            
            if (string.empty())
            {
                cout << "Error: Closing symbol without matching opening symbol" << endl;
                return;
            }
            char top = string.top();
            string.pop();
            if ((ch == ')' && top != ')') || (ch == '}' && top != '}') || (ch == ']' && top != ']'))
            {
                cout << "Start and/or end symbol/s are mismatched." << endl;
                return;
            }
        }
    }
    if (!string.empty())
    {
        cout << "Start and/or end symbol/s does not have a pair." << endl;
        return;
    }
    cout << "Start and/or end symbol/s have the same pair." << endl;
}

int main() {
    string expressions[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B]+[C-D]}"
    };
    for (string expression : expressions)
    {
        cout << "Expression: " << expression << endl;
        checkExpression(expression);
        cout << endl;
    }
    return 0;
}
