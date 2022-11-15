#include <stdio.h>
#include <stdbool.h>


typedef struct {
    int day;
    int month;
    int year;
} Date;


/**
 *  determina se o ano "year" é bissexto
 */
bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}


/**
 * retorna os dias do mês "month"
 * Assume que "month" está entre 1 e 12
 * e que o ano é valido
 * Utiliza a instrução switch da forma mais comum
 */
int month_days(int month, int year) {
    int dm = 0;
    
    switch(month) {
        case 4: case 6: case 9: case 11:
            dm = 30;
            break;
        case 2:
            if (is_leap_year(year)) dm = 29; else dm = 28;
            break;
        default:
            dm = 31;
            break;
    }
    return dm;
}

/**
 * versão alternativa utilizando a instrução "return" em cada ramo
 * não há mais nada a realizar na função pelo que se pode retornar de imediato
 * fica mais compacta do que a versão anterior
 */
int month_days2(int month, int year) {
    switch(month) {
        case 4: case 6: case 9: case 11:
           return 30;
        case 2:
            if (is_leap_year(year)) return 29; else return 28;
        default:
            return 31;
    }
}


/**
 * versão ainda mais compacta tirando paratido
 * de um array em que cada posiço tem os dias do mês respectivo 
 * (janeiro = 1)
 * A primeira posição (0) do array é ignorada
 */
int month_days3(int month, int year) {
    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    int dm = days[month];
    if (dm == 2 && is_leap_year(year)) dm++;
    return dm;
}

/**
 * retorna true se a data recebida em "d" for válida, "false" caso contrário
 */
bool data_valid(Date d) {
    if ( d.day < 1 || d.day > 31 || d.month < 1 || d.month > 12 || d.year < 0)
        return false;
    return d.day <= month_days(d.month, d.year);
}


int main() {
    Date d1 = { .day = 30, .month = 2, .year = 2000 };
    
    if (data_valid(d1)) printf("data válida\n");
    else printf("data inválida\n");
}
