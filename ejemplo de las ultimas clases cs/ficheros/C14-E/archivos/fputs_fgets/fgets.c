#include <stdio.h>

int main(void)
{
    FILE *file;
    file = fopen("text.txt", "r");
    FILE *file2;
    file2 = fopen("text2.txt", "w");

    if (!file)
        return 1;

    char palabra[60]; //buffer
    fgets(palabra, 70, file);
    printf("%s ", palabra);
    fputs(palabra, file2);

    printf("\n");
    fclose(file2);
    fclose(file);
}