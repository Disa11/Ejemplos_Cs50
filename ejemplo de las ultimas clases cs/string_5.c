#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string word = get_string("palabra: ");

    int len = strlen(word);

    for (int i = 0; i < len; i++)
    {
        printf("%c\t", word[i]);
    }
    printf("\n");

    return 0;
}