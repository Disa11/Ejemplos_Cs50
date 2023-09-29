#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n = 4;
    for (int i = 0; i <= n - 1 && ((i != 0)? (printf("\n")) : 1); i++){
        for (int j = 1; j < n+1 && printf("%c", (j < abs(n - i) ? ' ' : '#')); j++){}
        printf("  ");
        for (int k = n+1; k > n -i && printf("#"); k--){}
    }
    printf("\n");
}