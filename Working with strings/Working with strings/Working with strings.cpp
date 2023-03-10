#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    cout << "Enter the string: ";
    char str[1000], copy_str[1000];
    cin.getline(str, 1000);
    cout << "\nThe total numbers of characters: " << strlen(str) << endl;
    int count_num = 0;
    for (int i = 0; i < int(strlen(str)); i++)
    {
        copy_str[i] = str[i];
        if (isdigit(str[i]))
        {
            count_num++;
        }
    }
    cout << "Of them are digits: " << count_num << endl;
    cout << "Words beginning with a consonant letter: ";
    char alph_sogl[] = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
    int size = strlen(str);
    for (int i = 0; i < strlen(str); i++)
    {
        if (i == 0 || str[i - 1] == ' ')
        {
            for (int j = 0; j < strlen(alph_sogl); j++)
            {

                if (str[i] == alph_sogl[j])
                {
                    int n = 1;
                    for (int k = 0; k < n; k++)
                    {
                        if (str[i + k] != ' ')
                        {
                            cout << str[i + k];
                            n++;
                        }
                        if ((i + k) == size) break;
                    }
                    cout << " ";
                }
            }
        }
    }
    char str_del[1000] = "";
    char* word;
    word = strtok(str, " ");
    while (word != NULL)
    {
        int size = strlen(word);
        if (size >= 2)
        {
            if (tolower(word[0]) != tolower(word[size - 1]))
            {
                strcat(str_del, word);
                strcat(str_del, " ");
            }
        }
        word = strtok(NULL, " ");
    }
    strcat(str_del, "\0");
    cout << "\nA new string without words that start and end with the same letter: " << str_del << endl;
    cout << "The total numbers of characters in new string: " << (int)strlen(str_del) - 1 << endl;
    return 0;
}