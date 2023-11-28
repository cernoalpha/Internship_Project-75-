#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
using namespace std;
string s[100];
void display(int);
int main()
{
    int choice, i = 0, n = 0;
    bool go = true;
    char ch;
    do
    {
    back:
        system("cls");
        cout << "[1].Add note\n";
        cout << "[2].Delet notes\n";
        cout << "[3].Display list\n";
        cout << "[*].Exit\n";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
        {
            i = 0;
            cout << "[Esc] : exit\nWrite Your note : \n";
            do
            {
                cout << "[" << i + 1 << "] : ";
                cin >> s[i++];
            } while ((ch = getch()) != 27);
            n = i;
        }
        break;
        case 2:
        {
            int choose;
            if (n == 0)
            {
            back_inside:
                cout << "<< NO Thing >>";
                _getch();
                goto back;
            }
            display(n);
            cout << "*****************\n";
            cout << "Enter number for note : ";
            cin >> choose;
            if (choose > n)
                goto back_inside;
            for (int i = 0; i < n - 1; i++)
                s[choose - 1 + i] = s[choose + i];
            n--;
        }
        break;
        case 3:
        {
            if (n == 0)
            {
                cout << "<< NO Thing >>";
                _getch();
                goto back;
            }
            display(n);
            _getch();
        }
        break;
        default:
            go = false;
        }

    } while (go);

    return 0;
}

void display(int n)
{
    for (int i = 0; i < n; i++)
        cout << i + 1 << ")" << s[i] << endl;
}