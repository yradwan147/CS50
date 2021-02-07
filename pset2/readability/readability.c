#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int letters = 0, sentences = 0, words = 0;
    string input = get_string("Text: ");
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        char character = tolower(input[i]);
        if (character == '.' || character == '?' || character == '!')
        {
            sentences++;
        }
        else if (character == ' ')
        {
            words++;
        }
        else if (character <= 'z' && character >= 'a')
        {
            letters++;
        }
    }
    words++;
    //printf("Sentences = %i\nWords = %i\nLetters = %i\n", sentences, words, letters);

    float L = letters / (float) words * 100;
    float S = sentences / (float) words * 100;

    float indexf = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(indexf);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)index);
    }
}