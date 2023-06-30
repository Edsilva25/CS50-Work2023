#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // Get size of grid
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Print pyramid
    for (int i = 1; i <= height; i++)
    {
        // Print spaces
        for (int j = 1; j <= height - i; j++)
        {
            printf(" ");
        }

        // Print left side
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }

        //print space in between
        printf("  ");

        //print right half
        for (int l = 1; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}