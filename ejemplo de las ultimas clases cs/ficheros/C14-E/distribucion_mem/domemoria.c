#include <stdio.h>

void swap(int *a, int *b);

int main()
{
    int x = 1;
    int y = 2;
    swap(&x,&y);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}