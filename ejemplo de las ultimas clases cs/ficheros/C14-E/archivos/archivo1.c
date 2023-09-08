#include <stdio.h>
#include <cs50.h>

int main(void)
{
    FILE *file = NULL;
    file = fopen("hello.txt", "a");
    if(file != NULL)
    {
        fprintf(file, "Hola mundo");
        fclose(file);
    }
}