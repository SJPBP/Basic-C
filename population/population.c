#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int starter_size;
    do
    {
        starter_size = get_int("Start size: ");
    }
    while (starter_size < 9);

    // TODO: Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < starter_size);

    // TODO: Calculate number of years until we reach threshold
    int num_of_years = 0;
    while (starter_size < end_size)
    {
        starter_size = starter_size + (starter_size / 3) - (starter_size / 4);
        num_of_years ++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", num_of_years);
}
