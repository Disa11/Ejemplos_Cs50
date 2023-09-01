#include <cs50.h>
#include <stdio.h>

long int factorial(int num);

int main(void)
{
    int number = get_int("Number: ");
    printf("%li\n", factorial(number));
    return 0;
}

long int factorial(int num)
{
    if (num == 0)
        return 1;

    return num * factorial(num - 1);
}