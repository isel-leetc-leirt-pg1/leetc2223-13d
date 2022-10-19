#include <stdio.h>


// versão inicial de fatorial
int fatorial0(int n) {
    int f = n;
    
    if (n <= 1) return 1;
    
    while(n > 2) {
        n = n - 1;
        f = f * n;
    }
    return f;
}


// versão mais compacta de fatorial
int fatorial(int n) {
    int f = 1;
    
    while(n > 1) {
        f = f * n;
        n = n - 1;
    }
    return f;
}


// esta função serve para testar 
// a função fatorial com vários valores
// para cada teste o resultado é OK ou WRONG consoante o
// resulta esteja ou não correto.
// Notam a ausência de parâmetros nesta função e a ausência de
// retorno, indicado através da palavra "void" no tipo de retorno
void test_fatorial() {
    printf("fatorial(0): ");
    if (fatorial(0) == 1) printf("OK!\n"); else printf("WRONG!\n");
    
    printf("fatorial(1): ");
    if (fatorial(1) == 1) printf("OK!\n"); else printf("WRONG!\n");
    
    printf("fatorial(6): ");
    if (fatorial(6) == 720) printf("OK!\n"); else printf("WRONG!\n");
    
    printf("fatorial(12): ");
    if (fatorial(12) == 479001600) printf("OK!\n"); else printf("WRONG!\n");
    
    // este teste dá um resultado errado. Na próxima aula veremos porquê.
    printf("fatorial(13): ");
    int res;
    if ((res = fatorial(13)) == 6227020800) printf("OK!\n"); else {
        printf("WRONG! ");
        printf("%d\n", res);
    }
}


int main() {
  test_fatorial();
  return 0;
}
    
 
