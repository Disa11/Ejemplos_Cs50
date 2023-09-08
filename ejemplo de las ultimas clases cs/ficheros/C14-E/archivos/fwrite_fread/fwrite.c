#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE *file = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "w");
    if (file == NULL)
    {
        printf("archivo no existe");
        return 1;
    }

    char c;
    while(fread(&c, 1, 1, file))
    {
        fwrite(&c, 1,1, file2);
    }
    fclose(file);
    fclose(file2);
    remove("texto.txt");
}
