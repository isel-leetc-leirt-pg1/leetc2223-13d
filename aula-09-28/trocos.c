#include <stdio.h>

int main() {
    int change;
    int ncoins;
    
    printf("Valor do troco em cêntimos: ");
    scanf("%d", &change);
    ncoins = change / 200; // moedas de 2 euros
    
    if ( ncoins > 0 ) {
        printf("verificar se é uma ou mais moedas a mostrar \n");
        if (ncoins == 1)
            printf("1 moeda de 2 euros\n");
        else
            printf("%d moedas de 2 euros\n", ncoins);
    }
    
    change = change % 200; // troco restante
    
    ncoins = change / 100; // moedas de 1 euro
    
    if ( ncoins > 0 )
        printf("%d moedas de 1 euro\n", ncoins);
    
    change = change % 100; // troco restante
   
    ncoins = change / 50; // moedas de 1 euro
    if ( ncoins > 0 )
        printf("%d moedas de 50 cêntimos\n", ncoins);
    
    change = change % 50; // troco restante
    
    ncoins = change / 20; // moedas de 1 euro
    
    if ( ncoins > 0 )
        printf("%d moedas de 20 cêntimos\n", ncoins);
    
    change = change % 20; // troco restante
    
    ncoins = change / 10; // moedas de 1 euro
    if ( ncoins > 0 )
        printf("%d moedas de 10 cêntimos\n", ncoins);
    change = change % 10; // troco restante
    
    ncoins = change / 5; // moedas de 1 euro
    
    if ( ncoins > 0 )
        printf("%d moedas de 5 cêntimos\n", ncoins);
    change = change % 5; // troco restante
    
    ncoins = change / 2; // moedas de 1 euro
    
    if ( ncoins > 0 )
        printf("%d moedas de 2 cêntimos\n", ncoins);
    change = change % 2; // troco restante
    
    if (change > 0)
        printf("%d moedas de 1 cêntimo\n", change);
    return 0; // terminar com sucesso
}
