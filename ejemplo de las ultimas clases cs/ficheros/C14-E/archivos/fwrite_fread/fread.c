#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file != NULL)
    {
        char c;
        while (fread(&c, 1, 1, file)) // a donde se van a almacenar los datos, tamaño, cantidad de datos, de donde
        {
                printf("%c \t", c);
        }
        printf("\n");
        fclose(file);
    }
}
