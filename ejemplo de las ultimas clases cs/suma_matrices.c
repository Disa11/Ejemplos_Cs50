#include <stdio.h>
#include <cs50.h>//string

int main(void)
{
    int matriz[3][3] = {{9, 8, 7},{8, 5, 2},{4, 5, 6}};
    int matriz_2[3][3] = {{10, 11, 12},{14, 16, 18},{8, 5, 7}};
    int resultado[3][3];

    for (int i = 0; i< 3; i++) //estos for sirven para sumar las dos matrices
    {
        for (int j = 0; j < 3; j++)
        {
            resultado[i][j] = matriz[i][j] + matriz_2[i][j];
        }
    }

    for (int i = 0; i< 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%i\t", resultado[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}