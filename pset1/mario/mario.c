#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n, x = 0;
    do
    {
        n = get_int("Height: ");
    }
    while (n > 8 || n < 1);

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n * 2 + 3; j++)
        {
            if (n - x <= j && j <= n)
            {
                //printf("%i, %i", j, n - x);
                printf("#");
            }
            else if (n + 3 <= j && j <= n + 3 + x)
            {
                printf("#");
            }
            else if (j > 0 && j < n + 4 + x)
            {
                printf(" ");
            }
        }
        x = x + 1;
        printf("\n");
    }

}