#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str1[10], str2[10], str3[10];
    int year;
    FILE *fp;

    fp = fopen("file.txt", "r");



    fscanf(fp, "%s %s %s %d", str1, str2, str3, &year); // de donde, formato, puntero a donde ingresarlo

    printf("String1 |%s|\n", str1);
    printf("String2 |%s|\n", str2);
    printf("String3 |%s|\n", str3);
    printf("Entero  |%d|\n", year);

    fclose(fp);

    return (0);
}