#include <stdio.h>

int main()
{
    int n = 50;
    //creamos puntero que almacene direccion de la variable n
    int * punteroN = &n; //referencia

    //desreferencia o indireccion, permite manipular o acceder a el valor que contiene la direccion
    //almacenada en punteroN
    *punteroN = 10;
    //printf("Valor de la variable n: %d\nDireccion en la memoria de la variable n: %p\n", n, punteroN);
   // printf("Direccion de la memoria del punteroN: %p", &punteroN);
   printf("Valor de la variable n: %d\n%d\n", n, *punteroN);
}