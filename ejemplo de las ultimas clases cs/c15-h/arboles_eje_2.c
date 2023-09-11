#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <cs50.c>

//Funciones prototipo para la manipulación de nodo
struct nodo *crearNodo(int valor);
struct nodo *insertar_nodo(struct nodo *arbol, int valor);

// Definición de la estructura de un nodo en el árbol binario
struct nodo
{
    int valor;
    struct nodo *izquierda;
    struct nodo *derecha;
};

int main(void)
{
    
}

// Función para crear un nuevo nodo
struct nodo *crearNodo(int valor)
{
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

struct nodo *insertar_nodo(struct nodo *arbol, int valor)
{
    if (arbol == NULL)
    {
        return crearNodo(valor);
    }
    else if (valor < arbol->valor)
    {
        arbol->izquierda = insertar_nodo(arbol->izquierda, valor);
    }
    else if (valor > arbol->valor)
    {
        arbol->derecha = insertar_nodo(arbol->derecha, valor);
    }
    else if (valor == arbol->valor)
    {
        return arbol;
    }
    return arbol;
}

void imprimir(struct nodo *arbol)
{
    if (arbol == NULL)
        return;

    print_tree(arbol->izquierda);
    printf("%i\n", arbol->valor);
    print_tree(arbol->derecha);
}