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
        
    // O código anterior é equivalente a este:
    // return sum_proper_divisors(i1) == i2 && sum_proper_divisors(i2) == i1;
}

int sum_proper_divisors(int n) {
   int sum = 0;
   int d = 1;
   
   while ( d < n) {
       if (n % d == 0) sum = sum + d;
       d = d + 1;
   }
   return sum;
}

int main() {
    int n1=220, n2=285;
    bool res = amicable_numbers(n1, n2);
    
    printf("%d e %d ", n1, n2);
    
    if (res == true) printf("são amigos\n");
    else printf("não são amigos\n");
    
    return 0;
} 










