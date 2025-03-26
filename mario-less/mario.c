#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask user for height of mario pyramid
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

}