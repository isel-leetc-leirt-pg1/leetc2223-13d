/**
 * Apresentação da tabuada de um número lido da consola
 */

#include <stdio.h>


int main() {
    int num;
      
    printf("número entre 1 e 10: ");
    scanf("%d", &num);
    
    int i = 1;
    
    while ( i <= 10) {
        printf("%d x %2d = %d\n", num, i, num*i);
        i = i + 1;
    }
    return 0;
}
