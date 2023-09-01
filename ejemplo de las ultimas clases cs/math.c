#include <stdio.h>
#include <math.h>
#include <cs50.h>

float operaciones(int num, int opcion);

int main(void)
{
    printf("OP 1 para elevar al cuadrado y OP 2 para sacar raiz cuadrada\n\n");
    int n = get_int("x: ");
    int opcion = get_int("opcion: ");

    float res = operaciones(n, opcion);
    printf("El resultado es: %.4f", res);

}

float operaciones(int num, int opcion)
{
    float resultado;
    switch(opcion)
    {
        case 1:
             resultado = pow(num, 2);
            return resultado;
            break;
        case 2:
            resultado = sqrt(num);
            return resultado;
            break;
    }
}