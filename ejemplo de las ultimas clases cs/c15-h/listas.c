#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <cs50.c>

// Definición de la estructura de un nodo en la lista enlazada
struct nodo
{
    int valor;
    struct nodo *siguiente;
};

void insertarAlFinal(struct nodo **cabeza, int valor);
void freeList(struct nodo *cabeza);
void imprimirLista(struct nodo *cabeza);
struct nodo *crearNodo(int valor);


int main()
{
    struct nodo *cabeza = NULL;

    insertarAlFinal(&cabeza, 10);
    insertarAlFinal(&cabeza, 20);
    insertarAlFinal(&cabeza, 30);
    insertarAlFinal(&cabeza, 40);

    printf("Lista enlazada: ");
    imprimirLista(cabeza);

    freeList(cabeza);
    return 0;
}

// Función para crear un nuevo nodo
struct nodo *crearNodo(int valor)
{
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
    if (nuevoNodo == NULL)
    {
        return NULL;
    }

    (*nuevoNodo).valor = valor;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al final de la lista
void insertarAlFinal(struct nodo **cabeza, int valor)
{
    struct nodo *nuevoNodo = crearNodo(valor);
    if (*cabeza == NULL)
    {
        *cabeza = nuevoNodo;
    }
    else
    {
        struct nodo *temp = *cabeza;
        while (temp->siguiente != NULL)
        {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

// Función para imprimir la lista enlazada
void imprimirLista(struct nodo *cabeza)
{
    struct nodo *actual = cabeza;

    while (actual != NULL)
    {
        printf("%d -> ", actual->valor);
        actual = actual->siguiente;
    }

    printf("NULL\n");
}

//es leyxd
void freeList(struct nodo *cabeza)
{
    while (cabeza != NULL)
    {
        struct nodo *tmp = cabeza->siguiente;
        free(cabeza);
        cabeza = tmp;
    }
}
