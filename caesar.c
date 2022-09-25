#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool only_digits (string s);

char rotate (char x, int key);

int main(int argc, string argv[])
{
    if (argc != 2 )
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }

    string keys = argv[1];
    int key = atoi(keys);

    for (int b = 0, c = strlen(keys); b < c; b++)
        {

        if (only_digits (keys))
        {
            string plain = get_string("plaintext: ");
            printf("ciphertext: ");

            for (int j = 0, k = strlen(plain); j < k; j++)

            if (isalpha(plain[j]))
                {
                    char cy = rotate (plain[j], key);
                    printf("%c", cy);

                }
            else
            {
                printf("%c", plain[j]);
            }

            printf("\n");
            return 0;

        }
        else
        {
            printf("Usage: ./ceasar key\n");
            return 1;
        }
        }
}

bool only_digits (string s)
{
    int digit = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]))
        {
            digit = 1;
        }
        else
        {
            digit = 0;
        }
    }
    return digit;
}


char rotate (char x, int key)
{
    char y = 0;

    if (isalpha(x))
    {
        if isupper(x)
        {
            y = ((x - 65) + key) % 26;
            y = y + 65;
        }
        else
        {
            y = ((x - 97) + key) % 26;
            y = y + 97;
        }
    }
    return y;
}