#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string word = get_string("palabra: ");

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] = word[i] - 32;
        }
    }

    printf("%s\n", word);
    return 0;
}