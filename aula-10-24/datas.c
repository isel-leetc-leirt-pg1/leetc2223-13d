/**-----------------------------------------
 * Mais exemplos com ponteiros
 * 
 * definição e utilização da função "day_next",
 * que tem 3 parâmetros (de entrada/saída), ponteiros para inteiro (int *),
 * que referem repetivamente o dia, o mês e o ano de uma data.
 * 
 * À saída da função, os valores referidos pelos ponteiros 
 * representam o dia seguinte ao dos valores de entrada
 */

#include <stdio.h>
#include <stdbool.h>

// retorna true ou false consoante o ano recebido no parâmetro seja ou 
// não bissexto
bool is_leap_year(int a) {
    if (a % 400 == 0 || (a %4 == 0 && a % 100 != 0)) return true;
    return false;
}

// retorna o número de dias do mês "m", para o ano "a"
int month_days(int m, int a) {
    if (m== 4 || m == 6 || m == 9 || m == 11) return 30;
    if (m == 2) {
        if (is_leap_year(a)) return 29;
        else return 28;
    }
    return 31;
}


void day_next(int *d, int *m, int *a) {
    if (*d < month_days(*m, *a)) *d = *d + 1;
    else {
        *d = 1;
        if (*m < 12) *m = *m + 1;
        else {
            *m = 1;
            *a = *a + 1;
        }
    }
}

int main() {
    int d = 28, m = 2, a = 2003;
    
    printf("data (d/m/a)? ");
    while(scanf("%d/%d/%d", &d, &m, &a) == 3) {
        // após a chamada à função os inteiros d, m e a 
        // representam a data do dia seguinte à dos valores 
        // de chamada
        day_next(&d, &m, &a);
        
        printf("dia seguinte: %d/%d/%d\n", d, m, a);
        printf("data (d/m/a)? ");
    }
    return 0;
}

