#include <stdio.h>
#include <cs50.h>

int main(void)
{
    FILE *file = NULL;
    char archivo[20];
    sprintf(archivo, "hello.c");
    file = fopen(archivo, "w");
    fprintf(file, "hola mundo");
    fclose(file);
}