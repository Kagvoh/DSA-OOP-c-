#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == ':') return 2;
    return 0;
}

double applyOp(double a, double b, char op)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == ':') return a / b;
    return 0;
}

int main()
{
    string s;
    cin >> s;
    stack<double> values;
    stack<char> ops;

    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
        {
            int val = 0;
            while (i < n && isdigit(s[i])) val = val * 10 + (s[i] - '0'), i++;
            values.push(val);
            i--;
        }
        else if (s[i] == '(') ops.push(s[i]);
        else if (s[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(a, b, op));
            }
            if (!ops.empty()) ops.pop();
        }
        else
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(s[i]))
            {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(a, b, op));
            }
            ops.push(s[i]);
        }
    }

    while (!ops.empty())
    {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(a, b, op));
    }

    cout << values.top();
}