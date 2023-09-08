#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    printf("Ingresa un numero: ");
    scanf("%i",&numero);
    //char *nombre = malloc(sizeof(char)*20);
    //printf("Ingresa un nombre: ");
    //scanf("%s",nombre);
    //scanf("%[^\n]",nombre);


    //scanf("%20[^\n]",nombre);

    printf("El numero es: %i \n", numero);
    printf("La direccion del numero es: %p \n", &numero);
    //printf("El nombre es: %s \n", nombre);

    //free(nombre);


}