#include <cs50.h>
#include <stdio.h>

void print_numbers(int num);

int main(void)
{
    int number = get_int("Number: ");
    print_numbers(number);
    printf("\n");
    return 0;
}

void print_numbers(int num)
{
    if (num < 1)
        return;

    print_numbers(num - 1);
    printf("%i\t", num);
    return;
}