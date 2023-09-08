#include <stdio.h>

int main()
{
    FILE * file = fopen("texto.txt", "a");
    if(file == NULL)
    {
        printf("Error");
        return 1;
    }
    fprintf(file, "holis\n");
}