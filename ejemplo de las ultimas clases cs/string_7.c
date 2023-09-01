#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string word = get_string("palabra: ");

    for (int i = 0; i < strlen(word); i++)
    {
        if (islower(word[i]))
        {
            printf("%c", word[i] - 32);
        }
        else
        {
            printf("%c", word[i]);
        }
    }

    printf("\n");
    return 0;
}