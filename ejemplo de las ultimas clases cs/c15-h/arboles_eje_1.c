#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <cs50.c>

//arbol binario
struct nodo
{
    int valor; 
    struct nodo *izquierda;
    struct nodo *derecha;
};

struct nodo *agregar(struct nodo *raiz, int valor);
void recorrer_arbol(struct nodo *raiz);
void liberar_arbol(struct nodo *raiz);
struct nodo *crearNodo(int valor);

int main(void)
{
    struct nodo *raiz = NULL;
    int cantidad_de_nodos  = get_int("Cantidad de nodos: ");

    for (int i = 0; i < cantidad_de_nodos; i++)
    {
        int valor = get_int("Valor del primer nodo: ");
        raiz = agregar(raiz, valor);
    }  

    printf("\n"); 
    recorrer_arbol(raiz);
    printf("\n");
    liberar_arbol(raiz);

    return 0;
}

struct nodo *crearNodo(int valor)
{
    struct nodo *nuevo_nodo = malloc(sizeof(struct nodo));
    if(nuevo_nodo == NULL)
        return NULL;
    
    nuevo_nodo->valor = valor;
    nuevo_nodo->izquierda = NULL;
    nuevo_nodo->derecha = NULL; 
    return nuevo_nodo;
}

struct nodo *agregar(struct nodo *raiz, int valor)
{
    if (raiz == NULL)
        return crearNodo(valor);
    
    if (valor < raiz->valor)
    {
        raiz->izquierda = agregar(raiz->izquierda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->derecha = agregar(raiz->derecha, valor);
    }

    return raiz;
}

void recorrer_arbol(struct nodo *raiz)
{
    if (raiz == NULL)
        return;

    recorrer_arbol(raiz->izquierda);
    printf("%i\n", raiz->valor);
    recorrer_arbol(raiz->derecha);
}

void liberar_arbol(struct nodo *raiz)
{
    if (raiz == NULL)
        return;
    
    liberar_arbol(raiz->izquierda);
    liberar_arbol(raiz->derecha);
    free(raiz);
}
