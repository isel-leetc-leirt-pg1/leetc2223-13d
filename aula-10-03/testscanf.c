#include <stdio.h>


/**
 * executar o programa com valores não númericos e observar o resultado
 */
 
int main() {
    int h=0, m=0, s=-1;
    
    printf("hora (h:m:s): ");
    
    int res ;
    
    if ((res = scanf("%d:%d:%d", &h, &m, &s)) != 3) {
        printf("erro no input!\n");
        printf("res = %d\n", res);
        return 1;
    }
    
    printf("%02d:%02d:%02d\n", h, m, s);
    printf("res = %d\n", res);
    return 0;
}
