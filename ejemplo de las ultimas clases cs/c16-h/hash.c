#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <cs50.c>

//Este codigo es de forma local quitar el cs50.c y el NULL de los get_String al estar en el codespace

// Estructura nodo para crear la hash table
typedef struct node
{
    char nombre[50];
    char numero[12];
    struct node *next;
} node;

// prototipo de funcion
void agregar(char* nombre, char* numero);
char *busqueda(char* nombre);
void free_hash_table(void);
int hash(char* nombre);
void print_hash();

// hashtable
node *hash_table[26];

int main(void)
{
    int len = get_int("Ingrese la cantidad de personas: ");

    for (int i = 0; i < len; i++)
    {
        // agregar personas
        string name= get_string(NULL,"Ingrese el nombre: ");
        string numero = get_string(NULL, "Ingrese el numero: ");

        // funcion de agregar a la hash table y crear nodos
        agregar(name, numero);
    }

    // buscar a una persona en la hash table
    string name = get_string(NULL, "Ingrese el nombre a buscar: ");

    // funcion de buscar el numero de una persona en la hash table
    string number = busqueda(name);

    // imprimir numero buscado
    printf("Numero: %s\n", number);

    //imprimir toda la hash table
    print_hash();

    // liberar memoria
    free_hash_table();
}

void print_hash()
{
    //For para recorer la hash table
    for (int i = 0; i < 26; i++)
    {
        while (hash_table[i] != NULL)
        {
            printf("Nombre: %s \t Numero: %s\n", hash_table[i]->nombre, hash_table[i]->numero);
            hash_table[i] = hash_table[i]->next;
        }
    }
}

int hash(char *nombre) // retorna el indice de la hash table
{
    return tolower(nombre[0]) - 'a'; // 0-25
}

char *busqueda(char *nombre)
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
}

void agregar(char *nombre, char *numero)
{
    int indice = hash(nombre);
    node *puntero = hash_table[indice];
    node *nuevo = malloc(sizeof(node));
    if (nuevo == NULL)
    {
        printf("No se pudo alocar memoria\n");
        free(nuevo);
        free(puntero);
        return;
    }
    // copiar los datos del nuevo nodo
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
        // recorrer hasta el final de la lista
        while (puntero->next != NULL)
        {
            puntero = puntero->next;
        }
        // insertar el nuevo nodo
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