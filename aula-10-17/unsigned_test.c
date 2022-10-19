#include <stdio.h>


int main() {
    unsigned int val;
    printf("limite ? ");
    
    scanf("%u", &val);
    
    int nevens = 0;
    // este while nunca termina pois val é unsigned!...
    // cuidado!
    while (val >= 0) {
        if (val %2 == 0) nevens = nevens + 1;
        val = val - 1;
    }
    printf("total de pares = %d\n", nevens);
    return 0;
}
    
