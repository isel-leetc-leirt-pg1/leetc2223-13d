#include <stdio.h>
#include <stdbool.h>

int max(int i1, int i2);





bool hora_valida(int h, int m, int s) {
    /**
     * O código comentado à frente é equivalente ao 
     * troço de código a seguir não comentado. 
     * A utilização de uma ou outra variante é uma questão de gosto pessoal.
     */
    
     /*
       if (h >= 0 && h < 24 && 
         m >= 0 && m < 60 &&
         s >= 0 && s < 60) return true;
       return false;
     */
    
     return (h >= 0 && h < 24 && 
        m >= 0 && m < 60 &&
        s >= 0 && s < 60);
}


int dias_mes(int y, int m) {
    //  to implement
    return 0;
}


bool data_valida(int y, int m, int d) {
    if (y < 1900 || y > 2220) return false;
    if (m < 1 || m > 12) return false;
    if (d < 1 || d > dias_mes(y, m)) return false;
    return true;
}
    
    
int main() {
    // notem que para validar a hora final teríamos de
    // realizar código muito semelhante. Seria melhor criar uma
    // função para validar uma hora...
    
     
    int hi=1, mi=1, si=1; // hora inicial
    int hf=1, mf=1, sf=1; // hora final
    
    
    /*
    if (hi >= 0 && hi < 24 && mi >= 0 && mi < 60 && 
        si >= 0 && si < 60) {
       printf("hora inicial válida"); 
    }
    else {
        printf("hora inicial inválida");
    }
    */
    
    // usando a função hora_valida
    // o código de validação ficaria assim
    
    if (hora_valida(hi, mi, si)) printf("hora inicial válida\n");
    else printf("hora inicial inválida\n");
    
    if (hora_valida(hf, mf, sf) == true) printf("hora final válida\n");
    else printf("hora final inválida\n");
    
    
    int a = 3, b = 7, c= 8;
    
    // chamada em cadeia da função max para determinar o maior de três 
    // inteiros
    
    printf("max(a,b, c)= %d\n", max(max(a, b), c));
    
    return 0;
}
    
/**
 * definição da função max que
 * dados dois valores inteiros
 * devolve o maior dos dois valores
 */
int max(int i1, int i2) {
    if (i1 > i2) return i1;
    return i2;
}
