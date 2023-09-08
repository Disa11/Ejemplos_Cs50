#include <stdio.h>

void cambio(int *n);
int main()
{
    int n = 50;
    cambio(&n);
    printf("Valor de n en main %d\n", n);
}
//pasar la direccion
void cambio(int *n)
{
    //aplica desreferencia para cambiar el contenido de la variable en main
    *n = 10;
    return;
}