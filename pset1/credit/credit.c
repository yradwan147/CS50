#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int digit, digit1, Esum = 0, Osum = 0;
    string type;
    long number = get_long("Number: ");
    int nDigits = floor(log10(number)) + 1;
    for (int i = 0; i < nDigits; i++)
    {
        long place = pow(10, i + 1);
        long divisor = pow(10, i);
        digit = (number % place) / divisor;
        number = number - (number % place);
        //printf("%i\n", digit);
        if (i == nDigits - 1)
        {
            if (digit == 3)
            {
                type = "AMEX\n";
            }
            else if (digit == 4)
            {
                type = "VISA\n";
            }
            else
            {
                type = "MASTERCARD\n";
            }
        }
        if (i % 2 == 0)
        {
            Esum = Esum + digit;
            //printf("%i\n", Esum);
        }
        else
        {
            int dDigits = floor(log10((digit * 2))) + 1;
            for (int j = 0; j < dDigits; j++)
            {
                long place1 = pow(10, j + 1);
                long divisor1 = pow(10, j);
                long product = digit * 2;
                digit1 = (product % place1) / divisor1;
                //printf("%ld, %i\n", product, digit1);
                product = product - (product % place1);
                Osum = Osum + digit1;
            }
        }
    }
    int sum = Esum + Osum;
    //printf("%i\n", sum);
    if (sum % 10 == 0)
    {
        printf("%s", type);
    }
    else
    {
        printf("INVALID\n");
    }
}
