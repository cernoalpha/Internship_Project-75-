#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<int> num;
    vector<char> operated;

    while (true)
    {
        double n;
        cout << "Enter an number: ";
        cin >> n;
        num.push_back(n);

        char op;
        cout << "Enter an operator (+, -, *, /): ";
        cin >> op;
        operated.push_back(op);

        if (op == '=' || cin.fail())
        {
            break;
        }
    }

    for (int i = 0; i < operated.size(); i++)
    {
        if (operated[i] == '*' || operated[i] == '/')
        {
            switch (operated[i])
            {
            case '*':
                num[i] *= num[i + 1];
                break;
            case '/':
                if (num[i + 1] != 0)
                {
                    num[i] /= num[i + 1];
                }
                else
                {
                    cout << "Error: Division by zero" << endl;
                    return 1;
                }
                break;
            }
            num.erase(num.begin() + i + 1);
            operated.erase(operated.begin() + i);
            i--;
        }
    }

    for (int i = 0; i < operated.size(); i++)
    {
        if (operated[i] == '+' || operated[i] == '-')
        {
            switch (operated[i])
            {
            case '+':
                num[i] += num[i + 1];
                break;
            case '-':
                num[i] -= num[i + 1];
                break;
            }
            num.erase(num.begin() + i + 1);
            operated.erase(operated.begin() + i);
            i--;
        }
    }

    double result = num[0];
    cout << "result = " << result;
    return 0;
}