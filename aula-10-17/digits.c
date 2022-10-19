#include <stdio.h>
#include <stdbool.h>

// calcula o dígito de verificação 
// do número de cartão de cidadão
int bi_ver_dig(int bi) {
    int sum = 0;
    int weight = 2;
    
    while ( bi >  0) {
        sum = sum + ( bi % 10) * weight;
        bi = bi / 10;
        weight = weight + 1;
    }
    
    return 11 - sum % 11;
}


// calcula a soma dos dígitos de um número
int sum_digits(int n) {
    int sum = 0;
    
    while(n > 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    
    return sum;
}

void test_sum_dig() {
    int val = 0;
    
    printf("val ? ");
    scanf("%d", &val);
    
    while(val >= 0) {
        printf("soma dos digitos de %d é %d\n", 
                val, sum_digits(val));
        printf("val ? ");
        scanf("%d", &val);        
    }
}


void test_bi() {
    
    int bi;
    
    while(true) {
        printf("indique o bi? ");
        scanf("%d", &bi);
        if (bi < 0) return;
        
        printf("digito verificação do bi %d é %d\n", bi, bi_ver_dig(bi)); 
    }
}


 
int main() {
   test_sum_dig();
   test_bi();
}
