#include <stdio.h>
#include <stdlib.h>

int main(void){
    // Your code here!
    int n = 4;
    
    for (int i = 0; i <= n - 1 && ((i == 0)? 1 : (printf("\n"))); i++){
        for (int j = 1; j < n+1 && printf("%c", (j < abs(n - i) ? ' ' : '#')); j++){}}

    printf("\n");
    return 0;
}
