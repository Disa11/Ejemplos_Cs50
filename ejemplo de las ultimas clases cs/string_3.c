#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Nombre: ");

    int i = 0;
    while(name[i] != '\0')
    {
        i+=1;
    }

    printf("%i\n", i);
    return 0;
}