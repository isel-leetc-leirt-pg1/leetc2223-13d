#include <stdio.h>

/**
 * definição da função max que
 * dados dois valores inteiros
 * devolve o maior dos dois valores
 */
int max(int i1, int i2) {
    if (i1 > i2) return i1;
    return i2;
}
    
int main() {
    // notem que para validar a hora final teríamos de
    // realizar código muito semelhante. Seria melhor criar uma
    // função para validar uma hora...
    
    /*
    int hi, mi, si; // hora inicial
    int hf, mf, sf; // hora final
    
    
    if (hi >= 0 && hi < 24 && mi >= 0 && mi < 60 && 
        si >= 0 && si < 60) 
        printf("hora inicial válida");
    }
    else {
        printf("hora inicial inválida");
    }
    */
    
    int a = 3, b = 7, c= 8;
    
    
    // chamada em cadeia da função max para determinar o maior de três 
    // inteiros
    
    printf("max(a,b, c)= %d\n", max(max(a, b), c));
    
    return 0;
}
    
    
