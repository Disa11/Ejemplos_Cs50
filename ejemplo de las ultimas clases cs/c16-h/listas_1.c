#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
//creamos estructura de tipo nodo
typedef struct nodo
{
    int edad;
    string nombre;
    //creamos puntero que almacena la direccion de otro nodo
    struct nodo*siguiente;
}nodo;

//creamos un puntero que almacenara la direccion del primer nodo
nodo*lista = NULL;
void opciones(int opc);
int menu();
void crear_nodo();
void recorrer_lista();
void buscar_lista();
void liberar();

int main()
{
    int opc = menu();
    opciones(opc);
    liberar();
}
//funcion que crea nodos y los agrega a la lista enlazada
void crear_nodo()
{
    //caso de que no haya nodos en la lista enlazada
    if(lista == NULL)
    {
        //1. Creamos nodos usando memoria dinamica
        nodo* n = malloc(sizeof(nodo));
        //2. rellenamos el nodo con informacion
        n -> edad = get_int("Ingrese su edad: ");
        n -> nombre = get_string("Ingrese su nombre: ");
        n -> siguiente = NULL;
        //3. Puntero lista almacena la direccion del primer nodo
        lista = n;
    }
    else
    {
        //1. Creamos nodos usando memoria dinamica
        nodo* n = malloc(sizeof(nodo));
        //2. rellenamos el nodo con informacion
        n -> edad = get_int("Ingrese su edad: ");
        n -> nombre = get_string("Ingrese su nombre: ");
        //2 realizamos insercion por cabeza
        //segundo nodo almacena la direccion del primero
        n -> siguiente = lista;
        lista = n;

    }
}
void recorrer_lista()
{
    //crear un puntero que almacene la direccion del primer puntero
    // nodo* recorrer = lista;
    // while(recorrer != NULL)
    // {
    //     printf("Nombre: %s\nEdad: %d\n", recorrer -> nombre, recorrer -> edad);
    //     //cambiamos el valor del puntero recorrer para que almacene la direccion del segundo
    //     recorrer = recorrer -> siguiente;
    // }
    //recorrer lista enlazada con for
    printf("\n\n");
    for(nodo* i = lista; i != NULL; i = i -> siguiente)
    {
        printf("Nombre: %s\nEdad: %d\n", i -> nombre, i -> edad);
    }
    printf("\n\n");
}
void buscar_lista()
{
    string nombre = get_string("Ingrese nombre de la persona que desea buscar: ");
    printf("\n\n");
    for(nodo* i = lista; i != NULL; i = i -> siguiente)
    {
        if(strcmp(nombre, i -> nombre) == 0)
        {
            printf("ENCONTRADO:\n");
            printf("Nombre: %s\nEdad: %d\n", i -> nombre, i -> edad);
        }
    }
    printf("\n\n");
}
void liberar()
{
    //creamos otro puntero de tipo nodo que almacena la direccion del segundo nodo
    while(lista != NULL)
    {
        nodo*liberar = lista -> siguiente;
        free(lista);
        lista = liberar;

    }
}
int menu()
{
    int opc = get_int("Ingrese que desea realizar:\n1.Ingresar nodo en la lista enlazada\n2.Recorrer lista enlazada\n3.Buscar persona en la lista enlazada\n4.Terminar\nEscoger: ");
    return opc;
}

void opciones(int opc)
{
    do
    {
        switch(opc)
        {
            case 1:
            crear_nodo();
            break;
            case 2:
            recorrer_lista();
            break;
            case 3:
            buscar_lista();
            break;
            case 4:
            break;
        }
        if(opc != 4)
        {
            opc = menu();
        }
    }while(opc != 4);
}