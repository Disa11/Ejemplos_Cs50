#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string word = get_string("palabra: ");
    string word2 = get_string("palabra dos: ");

    if(word == word2)
    {
        printf("Son iguales\n");
    }
    else
    {
        printf("No son iguales\n");
    }
    return 0;
}