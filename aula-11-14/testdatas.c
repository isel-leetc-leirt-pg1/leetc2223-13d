/**
 * Este ficheiro dá erros de compilação pois faltam as definições
 * dos tipos e as declarações (assinaturas) das funções usads para
 * manipular datas. 
 * Na próxima aula será criado um ficheiro de include com esse objetivo
 * 
 */

#include <stdbool.h>
#include <stdio.h>



int main() {
    Date d1 = { .day = 1, .month = 1, .year = 1900 };
    
    if (date_valid(d1)) printf("data válida\n");
    else printf("data inválida\n");
    
    
    Date d2 = { .day = 8, .month = 1, .year = 1901 };
    
    int wd = date_weekday(d2);
    
    
    printf("dias 1900 = %d\n", date_days_from_jan1(d2)+
                               date_days_until_dez31(d2));
    printf("diff days=%d\n", date_diff_days(d1, d2));
    printf("dia da semana de 8/1/1901: ");
    show_weekday(wd);
    printf("\n");
    return 0;
    
}
