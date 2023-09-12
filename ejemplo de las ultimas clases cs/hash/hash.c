#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <cs50.c>

// estructura de la hash table
typedef struct node
{
    char nombre[50];
    char numero[50];
    struct node *next;
} node;

// funciones protoripo
void agregar(string nombre, string numero);
char *busqueda(string nombre);
void free_hash_table(void);
int hash(string nombre);

// hash table (arreglo de punteros que apuntan a listas enlazadas)
node *hash_table[26];

int main(void)
{
    agregar("Juan", "123");
    agregar("David", "1234");
    agregar("Maria", "12345");
    agregar("Juano", "123456");
    agregar("Juana", "1234567");

    string numero = busqueda("Juan");
    printf("%s\n", numero);

    free_hash_table();
    return 0;
}

// funcion hash para conocer el indice que ocupara ese nombre dentro de la hash table
int hash(string nombre)
{
    return tolower(nombre[0]) - 'a'; // 0-25
}

char *busqueda(string nombre)
{
    int indice = hash(nombre);

    // recorrer la lista enlazada en ese indice de la hash table
    for (node *nodo = hash_table[indice]; nodo != NULL; nodo = nodo->next)
    {
        if (strcmp(nodo->nombre, nombre) == 0) // comparar los strings buscando ese nombre
        {
            return nodo->numero; // retornar el numero de la persona
        }
    }

    printf("No se encontro el numero de la persona\n"); // si no se encontro el numero de la persona
    return NULL;
}

void agregar(string nombre, string numero)
{
    int indice = hash(nombre);
    // puntero a la estructura en ese indice
    node *puntero = hash_table[indice];
    // crear un nuevo nodo el cual se anexará a la lista (Hash table)
    node *nuevo = malloc(sizeof(node));
    // verificar si se pudo reservar memoria
    if (nuevo == NULL)
    {
        printf("No se pudo reservar memoria\n");
        free(nuevo);
        free(puntero);
        return;
    }
    // copiar los strings en las variables de la estructura
    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo->numero, numero);
    nuevo->next = NULL;

    // insercion por cola
    if (puntero == NULL)
    {
        hash_table[indice] = nuevo;
    }
    else
    {
        while (puntero->next != NULL)
        {
            puntero = puntero->next;
        }
        puntero->next = nuevo;
    }
}

void free_hash_table(void)
{
    for (int i = 0; i < 26; i++) // for para recorrer la hash table
    {
        node *puntero = hash_table[i];
        while (puntero != NULL) // while para recorrer la lista enlazada de cada nodo de la hash
        {
            node *aux = puntero->next; // guardamos el nodo a borrar
            free(puntero);             // liberamos la memoria
            puntero = aux;             // avanzamos el puntero
        }
    }
    printf("Hash table liberada\n");
}