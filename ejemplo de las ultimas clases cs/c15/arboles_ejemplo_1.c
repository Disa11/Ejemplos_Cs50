#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <cs50.c>

struct nodo 
{
    int valor;
    struct nodo *izquierda;
    struct nodo *derecha;
};

struct nodo *crearNodo(int valor)
{
    struct nodo *nuevo_nodo = malloc(sizeof(struct nodo));
    nuevo_nodo->valor = valor;
    nuevo_nodo->izquierda = NULL;
    nuevo_nodo->derecha = NULL;
    return nuevo_nodo;
}

struct nodo *agregar(struct nodo *arbol, int valor)
{
    if (arbol == NULL)
    {
        return crearNodo(valor);
    }
    else if (valor < arbol->valor)
    {
        arbol->izquierda = agregar(arbol->izquierda, valor);
    }
    else if (valor > arbol->valor)
    {
        arbol->derecha = agregar(arbol->derecha, valor);
    }
    else if (valor == arbol->valor)
    {
        return arbol;
    }
    return arbol;
}


int main(void)
{

}