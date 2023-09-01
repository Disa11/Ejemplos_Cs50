#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool binary_search(int num[], int element, int left, int right);

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 20, 26, 50, 55, 78, 100};

    int len = sizeof(numbers) / sizeof(numbers[0]);

    int search = get_int("Number: ");
    bool result = binary_search(numbers, search, 0, len);

    if (result == true)
    {
        printf("Si esta en el arreglo\n");
    }
    else
    {
        printf("No esta en el arreglo\n");
    }

    return 0;
}

bool binary_search(int num[], int element, int left, int right)
{
    if(right >= left)
    {
        int mid = (int) floor((left + right) / 2);

        if(num[mid] == element)
        {
            return true;
        }
        else if (num[mid] > element) // busca en la izquierda
        {
            return binary_search(num, element, left, mid - 1);
        }
        else // busca en la derecha
        {
            return binary_search(num, element, mid + 1, right);
        }
    }
    else
        return false;
}