#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cmath>
#include <ctime>
#include <windows.h>
using namespace std;

void SetColor(int text, int bg)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

template<int txt = 7, int bg = 0>
ostream& color(ostream& text)
{
    SetColor(txt, bg);
    return text;
}

void CompleteTask()
{
    cout << "\nPress any key to continue. ";
    _getch();
    system("cls");
}

double FirstPart(double xn, double xk, double h)
{
    srand(time(NULL));
    double a, b, c, F;
    cout << "Enter a, b, c ";
    cin >> a >> b >> c;
    double arr[10000];
    int count = 0;
    bool InputValidation = false;
    if (xk >= xn && h > 0 && h < (xk - xn) && c != 0)
    {
        while (xn <= xk)
        {
            if (xn < 1 && b != 0)
            {
                F = -a * pow(xn, 2) + b / c;
            }
            if (xn > 1.5 && b == 0)
            {
                F = (xn - a) / pow((xn - c), 2);
            }
            else
            {
                F = pow(xn, 2) / pow(c, 2);
            }
            xn += h;
            cout << "F[" << count << "] = " << F << endl;
            arr[count] = F;
            count++;
        }
        InputValidation = true;
    }
    if (xk <= xn && h < 0 && abs(h) < xn - xk && c != 0)
    {
        while (xn >= xk)
        {
            if (xn < 1 && b != 0)
            {
                F = -a * pow(xn, 2) + b / c;
            }
            if (xn > 1.5 && b == 0)
            {
                F = (xn - a) / pow((xn - c), 2);
            }
            else
            {
                F = pow(xn, 2) / pow(c, 2);
            }
            xn += h;
            cout << "F[" << count << "] = " << F << endl;
            arr[count] = F;
            count++;
        }
        InputValidation = true;
    }
    if (InputValidation == false)
    {
        cout << "Error! A finite value x less than the original value x with increments greater than 0 OR a finite value x greater than the original value x with a step less than 0 OR c = 0 which does not satisfy the scope of permissible argument values.";
        return 0;
    }
    if (count != 0)
    {
        int number = rand() % count;
        cout << "Number of random element: " << number << endl;
        return arr[number];
    }
}

void SecondPart()
{
    int m, n, k;
    cout << "Enter values of m, n, k, if 3 <= k >= 10:" << endl;
    cout << "m = ";
    cin >> m;
    while (m < 1)
    {
        cout << "Condition m > 0 should be perfomed. Enter m: m = ";
        cin >> m;
    }
    cout << "n = ";
    cin >> n;
    while (n < 1)
    {
        cout << "Condition n > 0 should be perfomed. Enter n: n = ";
        cin >> n;
    }
    bool K_value = false;
    do
    {
        cout << "k = ";
        cin >> k;
        if (k >= 3 && k <= 10)
        {
            K_value = true;
        }
        else
        {
            cout << "The specified number k does not match the condition of the task. Enter k:" << endl;
        }
    } while (K_value == false);
    cout << "================================\nInteger generator:\n" << endl;
    int integer_number;
    for (int i = 0; i < m; i++)
    {
        if (i % k == 0)
        {
            cout << endl;
        }
        integer_number = rand() % 121 - 11;
        cout << integer_number << " ";
    }
    cout << "\n================================\nDouble generator (precision 0.001):\n" << endl;
    double real_number;
    for (int i = 0; i < n; i++)
    {
        if (i % k == 0)
        {
            cout << endl;
        }
        real_number = (double)rand() / RAND_MAX * 4 + 2;
        cout << round(real_number * 1000) / 1000 << " ";
    }
}

void ThirdPart()
{
    int const N = 100;
    int const M = 100;
    int n, m;
    cout << "Enter n: n = ";
    cin >> n;
    while (n > N)
    {
        cout << "The entered value n is greater than the maximum value N. Enter n: n = ";
        cin >> n;
    }
    cout << "Enter m: m = ";
    cin >> m;
    while (m > M)
    {
        cout << "The entered value m is greater than the maximum value M. Enter m: m = ";
        cin >> m;
    }
    int a, b;
    cout << "Enter a: a = ";
    cin >> a;
    cout << "Enter b: b = ";
    cin >> b;
    while (b <= a)
    {
        cout << "Condition a < b should be perfomed. Enter b: b = ";
        cin >> b;
    }
    int first_arr[N][M], second_arr[N][M], third_arr[N][M];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            first_arr[i][j] = rand() % (b - a) + a;
            second_arr[i][j] = rand() % (b - a) + a;
            third_arr[i][j] = first_arr[i][j] * second_arr[i][j];
        }
    }
    cout << "Elements of the first array:\n==========================\n" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << first_arr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "\nElements of the second array:\n==========================\n" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << second_arr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "\nElements of the third array:\n==========================\n" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << third_arr[i][j] << "  ";
        }
        cout << endl;
    }
}

void Menu()
{
    SetColor(6, 0);
    cout << "MENU:\n\n";
    SetColor(7, 0);
    char operation;
    cout << "Choose task: \n\n1) Task 1 \n2) Task 2 \n3) Task 3 \n\nPress any key to finish." << endl;
    cout << "Enter number of task: ";
    cin >> operation;
    switch (operation)
    {
    case '1':
    {
        double xn, xk, h;
        cout << "Enter xn, xk, h ";
        cin >> xn >> xk >> h;
        cout << "Result of execution: " << FirstPart(xn, xk, h);
        CompleteTask();
        Menu();
    }
    case '2':
    {
        SecondPart();
        CompleteTask();
        Menu();
    }
    case '3':
    {
        ThirdPart();
        CompleteTask();
        Menu();
    }
    default:
    {
        cout << "\nThe end of the program." << endl;
        break;
    }
    }
}

int main()
{
    Menu();
    return 0;
}