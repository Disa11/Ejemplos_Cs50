#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <cs50.c>

// Definición de la estructura de un nodo en el árbol binario
struct Nodo
{
    int valor;
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

// Función para crear un nuevo nodo
struct Nodo *crearNodo(int valor)
{
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

// Función para insertar un valor en el árbol binario
struct Nodo *insertar(struct Nodo *raiz, int valor)
{
    if (raiz == NULL)
    {
        return crearNodo(valor);
    }

    if (valor < raiz->valor)
    {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->derecha = insertar(raiz->derecha, valor);
    }

    return raiz;
}

// Función para encontrar el nodo con el valor mínimo en un árbol
struct Nodo *encontrarMinimo(struct Nodo *nodo)
{
    while (nodo->izquierda != NULL)
    {
        nodo = nodo->izquierda;
    }
    return nodo;
}

// Función para eliminar un valor del árbol binario
struct Nodo *eliminar(struct Nodo *raiz, int valor)
{
    if (raiz == NULL)
    {
        return raiz;
    }

    if (valor < raiz->valor)
    {
        raiz->izquierda = eliminar(raiz->izquierda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->derecha = eliminar(raiz->derecha, valor);
    }
    else
    {
        if (raiz->izquierda == NULL)
        {
            struct Nodo *temp = raiz->derecha;
            free(raiz);
            return temp;
        }
        else if (raiz->derecha == NULL)
        {
            struct Nodo *temp = raiz->izquierda;
            free(raiz);
            return temp;
        }

        struct Nodo *temp = encontrarMinimo(raiz->derecha);
        raiz->valor = temp->valor;
        raiz->derecha = eliminar(raiz->derecha, temp->valor);
    }

    return raiz;
}

void liberar_arbol(struct Nodo *raiz)
{
    if (raiz == NULL)
        return;
    
    liberar_arbol(raiz->izquierda);
    liberar_arbol(raiz->derecha);
    free(raiz);
}

// Función para realizar un recorrido en orden en el árbol binario
void print_arbol(struct Nodo *raiz)
{
    if (raiz == NULL)
        return;

    printf("%d ", raiz->valor);
    print_arbol(raiz->izquierda);
    print_arbol(raiz->derecha);
}

int main()
{
    struct Nodo *raiz = NULL;
    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 70);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 60);
    raiz = insertar(raiz, 80);

    printf("Arbol en orden: ");
    print_arbol(raiz);
    printf("\n");

    raiz = eliminar(raiz, 30);

    printf("Arbol despues de eliminar el valor 30: ");
    print_arbol(raiz);
    printf("\n");

    liberar_arbol(raiz);
    return 0;
}
