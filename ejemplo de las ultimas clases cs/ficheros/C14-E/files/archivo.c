#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.txt", "a");
    if (!file)
        return 1;
    int cantidad = get_int("Cuantas personas ingresará: ");
    for(int i = 0; i < cantidad; i++)
    {

        string name = get_string("Name: ");
        int number = get_int("Number: ");
        fprintf(file, "%s,%d\n", name, number);
    }
    fclose(file);
}
