#include <cs50.h>
#include <stdio.h>

int main(void)
{
float x = get_float("x: ");
float y = get_float("y: ");
float z = x / y ;

printf("%.50f\n", z);
return 0;
}
