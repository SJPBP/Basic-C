#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

void outPutBinary(int num);

int main(void)
{
    // TODO
    // Get Input from user
    string input = get_string("Message: ");

    // Convert Input into decimal number
    int decimal;
    int input_Length = strlen(input);
    for (int i = 0; i < input_Length; i++)
    {
        // Make char from string into decimal following ASCII Rule
        decimal = input[i];

        outPutBinary(decimal);

    }
}

void outPutBinary(int num)
{
    char Binary[BITS_IN_BYTE + 1]; // +1 for null-terminator

    // Initialize the Binary array with null-terminator to create an empty string
    Binary[BITS_IN_BYTE] = '\0';

    // Convert decimal number to binary and store in the Binary array
    for (int j = BITS_IN_BYTE - 1; j >= 0; j--) {
        Binary[j] = ((num % 2) + '0'); // Convert the remainder to '0' or '1'
        num /= 2; // Get the next quotient
    }

    // Print the binary representation using the print_bulb function
    for (int j = 0; j < BITS_IN_BYTE; j++) {
        print_bulb(Binary[j] - '0'); // Convert character '0'/'1' to integer 0/1
    }
    printf("\n");

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

