#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int flag = 0;
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            int count;

            for (int p = 0; p < strlen(argv[1]); p++)
            {
                count = 1;
                if (tolower(argv[1][p]) < 'a' || tolower(argv[1][p]) > 'z')
                {
                    printf("%c\n", tolower(argv[1][p]));
                    flag = 1;
                }
                for (int k = p + 1; k < strlen(argv[1]); k++)
                {
                    if (argv[1][p] == argv[1][k] && argv[1][p] != ' ')
                    {
                        count++;
                        argv[1][k] = '0';
                    }
                }
                if (count > 1 && argv[1][p] != '0')
                {
                    flag  = 2;
                }
            }
            if (flag == 1)
            {
                printf("Key invalid\n");
                return 1;
            }
            else if (flag == 2)
            {
                printf("Key invalid 2\n");
                return 1;
            }
            else
            {
                string key = argv[1];
                string plaintext = get_string("plaintext:  ");
                char ciphertext[] = "";
                printf("ciphertext: ");
                for (int i = 0, n = strlen(plaintext); i < n; i++)
                {
                    char letter = tolower(plaintext[i]);
                    if (letter >= 'a' && letter <= 'z')
                    {
                        char encrypted = key[letter - 97];
                        if (isupper(plaintext[i]))
                        {
                            encrypted = toupper(encrypted);
                        }
                        else
                        {
                            encrypted = tolower(encrypted);
                        }
                        printf("%c", encrypted);

                    }
                    else
                    {
                        printf("%c", letter);
                    }
                }
                printf("\n");
            }

        }
    }
}