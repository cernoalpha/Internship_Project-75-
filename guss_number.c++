#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <time.h>
using namespace std;
int main()
{
    int choice, count = 0, number, hint, power;
    srand(time(0));
    number = rand() % 100;
    // cout << number << endl;
    power = log10(number) + 1;
back:
    cout << "\nguessing the number [" << ++count << "] : ";
    cin >> choice;
    if (choice == number)
        cout << " << Congratulations  {" << number << "} >>\n";
    else if (count < 3)
    {
        cout << "\nThe long number is " << power;
        if (count < power)
        {

            cout << "\n The Simple hint is : ";
            hint = number / (int)pow(10, power - count);
            cout << hint;
            for (int i = 0; i < power - count; i++)
                cout << "_ ";
        }
        else
        {
            cout << "\n The Simple hint is : ";
            cout << hint;
            for (int i = 0; i < power - count + 1; i++)
                cout << "_ ";
        }
        goto back;
    }
    else
        cout << "\nG A M E  O V E R\n";
    return 0;
}