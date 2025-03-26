#include <cs50.h>
#include <stdio.h>

// Focus
// Practice using for loops
// Using modulo
// Creating a Boolean function

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // Return false if number is lower than 2
    if (number < 2)
    {
        return false;
    }
    // Go through n from 2 to number return false if number divide by any even n
    for (int n = 2; n < number; n++)
        if (number % n == 0)
        {
            return false;
        }
        
    return true;
}
