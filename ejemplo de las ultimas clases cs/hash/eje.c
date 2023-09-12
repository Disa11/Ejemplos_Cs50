 
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <cs50.c>

int main(void)
{
    string name = get_string(NULL,"Name: ");
    printf("Hello, %s\n", name);
}