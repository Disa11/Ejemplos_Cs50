#include <stdio.h>

void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7, 100, 120, 90, 26, 11, 21};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr, 0, n - 1);

    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

// Función recursiva para dividir y ordenar el arreglo
void mergeSort(int arr[], int left, int right)
{
    if (left < right) //caso base
    {
        int mid = left + (right - left) / 2;

        // Ordenar la mitad izquierda
        mergeSort(arr, left, mid);

        // Ordenar la mitad derecha
        mergeSort(arr, mid + 1, right);

        // Mezclar las dos mitades y ordenearlas
        merge(arr, left, mid, right);
    }
}

// Función para mezclar dos subarreglos ordenados en un arreglo ordenado
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Crear subarreglos temporales
    int L[n1], R[n2];

    // Copiar datos a los subarreglos temporales L[] y R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Mezclar los subarreglos temporales de nuevo en arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si los hay
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/visualize/

// https://visualgo.net/en/sorting