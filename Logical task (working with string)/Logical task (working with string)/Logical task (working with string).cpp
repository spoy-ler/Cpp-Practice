#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <clocale>
#include <ctype.h>
#include <cstring>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char lat_1 = 'y';
    char kir_1 = 'у';
    char lat_2 = 'i';
    char kir_2 = 'и';
    int k = 7;
    int l = 2;
    char str[1000] = "";
    char new_str[1000] = "";
    cout << "Enter the encypted message: ";
    cin.getline(str, 1000);
    char alph_sogl[] = "БВГДЖЗЙКЛМНПРСТФХЦЧШЩбвгджзйклмнпрстфхцчшщ";
    char alph_glas[] = "АЕИІОУЯЮЄЇаеиіоуяюєї";
    //char alph_sogl[] = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
    //char alph_glas[] = "AEIOUaeiou";
    int sogl_num = 0;
    int glas_num = 0;
    int counter = 0;
    int sum = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        int j = 0;
        int m = 0;
        for (; j < strlen(alph_sogl); j++)
        {
            if (str[i] == alph_sogl[j])
            {
                sogl_num++;
                if (sogl_num == l)
                {
                    new_str[counter] = str[i];
                    counter++;
                    sogl_num = 0;
                }
            }
        }
        for (; m < strlen(alph_glas); m++)
        {
            if (str[i] == lat_1)
            {
                str[i] = kir_1;
                sum += 10;
            }
            if (str[i] == lat_2)
            {
                str[i] = kir_2;
                sum += 1;
            }
            if (str[i] == alph_glas[m])
            {
                glas_num++;
                if (glas_num == k)
                {
                    new_str[counter] = str[i];
                    counter++;
                    glas_num = 0;
                }
            }
        }

    }
    new_str[counter + 1] = '\0';
    cout << "Decrypted message: " << new_str << endl;
    cout << "Add to the amount of the gift " << sum << " UAH." << endl;
    return 0;
}

//рпхiиеоyиодоаоаоyаиеоєiхрyуіниночоуооакк