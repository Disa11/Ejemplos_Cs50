#include <stdio.h>

int main()
{
    int n = 50;
    char c = '!';
    printf("n es igual a %d\nDireccion de la variable n %p\n", n, &n);
    printf("Direccion de la variable c: %p\n", &c);
}