#include <stdio.h>

int main()
{
    FILE * file = fopen("texto.txt", "r");
    if(file == NULL)
    {
        printf("Error");
        return 1;
    }
    char arreglo[10];
    fscanf(file, "%s", arreglo);
    printf("%s\n", arreglo);
    fclose(file);
}