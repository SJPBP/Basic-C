#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(int k, char letter);

int main(int argc, string argv[])
{

    // True if there is one arg and is a number
    if (argc == 2 && only_digits(argv[1]))
    {
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Get Key from argv[1]
    int Key = atoi(argv[1]);

    // Prompt user for plaintext
    string plainText = get_string("plaintext:  ");

    // Cipher each word from plainText
    for (int i = 0; i < strlen(plainText); i++)
    {

        plainText[i] = rotate(Key, plainText[i]);
    }

    printf("ciphertext: %s\n", plainText);
}

bool only_digits(string s)
{

    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]) == 0)
        {
            return false;
        }
    }

    return true;
}

char rotate(int k, char letter)
{

    // Check if letter is alphabetical
    if (isalpha(letter) != 0)
    {

        // check if letter is upperCase and subtract it by A number to get 0
        if (isupper(letter) != 0)
        {
            letter -= 65;
            letter = (letter + k) % 26;
            letter += 65;
        }
        else
        {
            letter -= 97;
            letter = (letter + k) % 26;
            letter += 97;
        }

        return letter;
    }

    return letter;
}