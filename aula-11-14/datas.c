/**
 * não contém a função "main" propositadamente
 * O objetivo é criar um conjunto de funções para manipular datas 
 * que possa ser usado em qualquer programa
 * 
 * Será completado na próxima aula
 */

#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;


/**
 *  determina se o ano "year" é bissexto
 */
int year_days(int year);


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
 *  retorna o número de dias do ano
 */
int year_days(int year) {
    if (is_leap_year(year)) return 366;
    else return 365;
}


/**
 *  retorna o número de dias entre dois anos (year1 < year2)
 */
int days_between_years(int year1, int year2) {
    int days = 0;
    for(int y = year1; y < year2; y++)
        days = days + year_days(y);
    return days;
}


/**
 * retorna os dias que medeiam entre 1 janeiro do ano de "d" e "d"
 */
int date_days_from_jan1(Date d) {
    int days = 0;
    for (int m = 1; m < d.month; ++m) {
        days = days + month_days(m, d.year);
        // days += month_days(m, d.year)
    }
    return days + d.day;
}

/** 
 * retorna os dias que medeiam entre a data "d" e o dim do ano de "d" 
 */ 
int date_days_until_dez31(Date d) {
    
    int days = 0;
    for (int m = d.month + 1; m <= 12; ++m)
        days += month_days(m, d.year);
    
    return days + month_days(d.month, d.year) - d.day;
    
    // também podia ser como está abaixo
    // return year_days(d.year) - date_days_from_jan1(d);
}


/**
 * retorna a diferença em dias entre as duas datas (d2 - d1)
 */
int date_diff_days(Date d1, Date d2) {
    
    if (d1.year == d2.year) { // datas no mesmo ano
        return year_days(d1.year) - 
        date_days_from_jan1(d1)  -
        date_days_until_dez31(d2);
    }
    
    // datas de anos distintos
    int days1 = date_days_until_dez31(d1);
    int days2 = days_between_years(d1.year+1, d2.year);
    int days3 = date_days_from_jan1(d2);
    
    return days1 + days2 + days3;
}

/**
 * retorna true se a data recebida em "d" for válida, "false" caso contrário
 */
bool date_valid(Date d) {
    if ( d.day < 1 || d.day > 31 || d.month < 1 || d.month > 12 || d.year < 0)
        return false;
    return d.day <= month_days(d.month, d.year);
}

/**
 *  retorna um inteiro entre 0 e 6
 * que representa o dia da semana da data (0 - domingo)
 */
int date_weekday(Date d) {
   Date refDate = { .day = 1, .month = 1, .year = 1900 };
   int refWeekDay = 1;
   
   
   int ndays = date_diff_days(refDate, d);
   
   int wd = (ndays + refWeekDay) % 7;
   return wd;
}


/**
 * apresenta no standard output (consola) o nome do dia da semana
 * dado o seu código
 */
void show_weekday(int wd) {
    switch(wd) {
        case 0 : printf("domingo"); break;
        case 1 : printf("segunda"); break;
        case 2 : printf("terça"); break;
        case 3 : printf("quarta"); break;
        case 4 : printf("quinta"); break;
        case 5 : printf("sexta"); break;
        case 6 : printf("sábado"); break;
        default:
            printf("dia inválido"); break;
    }
}
