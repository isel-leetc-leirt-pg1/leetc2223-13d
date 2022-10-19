#include <stdio.h>
#include <stdbool.h>

 

// retorna a soma de todos os divisores do número "n"
// excepto o próprio "n"
int sum_proper_divisors(int n);


bool amicable_numbers(int i1, int i2)  {
    if (sum_proper_divisors(i1) == i2 && sum_proper_divisors(i2) == i1)
        return true;
    else
        return false;
        
        
    // return sum_proper_divisors(i1) == i2 && sum_proper_divisors(i2) == i1;
}



int sum_proper_divisors(int n) {
   int sum = 0;
   int d = 1;
   
   while ( d <= n/2) {
       if (n % d == 0) sum = sum + d;
       d = d + 1;
   }
   return sum;
}


/**
 * apresentação os pares de números amigos no
 * intervalo fechado [li,ls] com uma solução de força bruta,
 * calculando todas as combinações dois a dois desses números,
 * resultando numa solução muito ineficiente
 */
void show_amicable_numbers(int li, int ls) {
    
    printf("listagem dos pares de amigos entre %d e %d:\n", li, ls);
    
    int i1 = li;
    
    while(i1 < ls) {
        int i2 = i1 + 1;
        while(i2 <= ls) {
            if (amicable_numbers(i1,i2))
                printf("(%d,%d)\n", i1, i2);
            i2 = i2+1;
        }
        i1 = i1 + 1;
    }
}

int main() {
    
    int n1=220, n2=284;
    bool res = amicable_numbers(n1, n2);
    
    printf("%d e %d ", n1, n2);
    
    if (res == true) printf("são amigos\n");
    else printf("não são amigos\n");
  
    // esta chamada é demorada...
    show_amicable_numbers(1, 10000);
    
    return 0;
} 










