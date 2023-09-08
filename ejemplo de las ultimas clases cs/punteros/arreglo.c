#include <stdio.h>

int main()
{
    int numero[] = {1, 2, 3, 4};
    printf("Primer elemento: %p\nContenido dentro de la direccion: %d\nSegundo elemento del arreglo: %d\n", numero, *numero, *(numero + 1));
}