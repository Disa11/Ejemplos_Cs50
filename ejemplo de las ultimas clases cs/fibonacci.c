#include <stdio.h>
#include <cs50.h>
int fibonacci(int posi);

int main(void)
{
    int n = get_int("Ingrese un numero: ");

    printf("En la posicion %i de la succesion el valor es: %i\n", n, fibonacci(n));
    return 0;
}

int fibonacci(int posi)
{
    if (posi <= 0)
    {
        return 0;
    }
    else if(posi == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(posi - 1) +fibonacci(posi - 2);
    }
}