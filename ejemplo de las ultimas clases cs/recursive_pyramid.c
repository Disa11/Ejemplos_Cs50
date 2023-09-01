#include <cs50.h>
#include <stdio.h>

void pyramid(int num);

int main(void)
{
    int number = get_int("Height: ");
    pyramid(number);
    printf("\n");
    return 0;
}

void pyramid(int num)
{
    if (num <= 0)
        return;

    pyramid(num - 1);
    for (int i = 0; i < num; i += 1)
    {
        printf("#");
    }
    printf("\n");
    return;
}