#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{

    // Get the last index
    int lastIndex = 0;
    while (input[lastIndex] != '\0' && lastIndex < 50)
    {
        lastIndex += 1;
    }

    // Check if only \0 left
    if (lastIndex == 0)
    {
        return 0;
    }

    // Get numerical value
    int value = 0;

    value += input[lastIndex - 1] - 48;

    // Shift '\0' to left
    input[lastIndex - 1] = '\0';

    // Call it self
    int new_value = convert(input);

    // Return the calculated value
    return value + 10 * new_value;
}

// start function with string 25
// Get the last index - 2
// Check if only \0 left
// Get numerical value of end value - 5
// Shift '\0' to left - 5 = 0 -> 2
// return value
// start function with string 2
