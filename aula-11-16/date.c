/**
 * não contém a função "main" propositadamente
 * O objetivo é criar um conjunto de funções para manipular datas 
 * que possa ser usado em qualquer programa
 * 
 * Será completado na próxima aula
 */

#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "date.h"


/**
 * retorna a data atual
 * Na rrealização desta função é preciso usar fubções espcíficas do Unix
 */
Date date_today() {
  time_t t = time(NULL);
  struct tm lt = *localtime(&t); 
  
  Date d = { .day = lt.tm_mday, .month = lt.tm_mon+1, .year = lt.tm_year + 1900};
  return d;
}


/**
 * Mostra uma data no output standard (consola)
 */
void date_show(Date d, char msg[]) {
    printf("%s: %d/%d/%d", msg, d.day, d.month, d.year);
}

/**
 * devolve o total de dias no ano "year"
 */
int year_days(int year);


/**
 *  determina se o ano "year" é bissexto
 */
bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

 
/**
 * Retorna os dias do mês "month"
 * Assume que "month" está entre 1 e 12
 * Tira partido de um array em que cada posição tem os dias do mês respectivo 
 * (janeiro = 1)
 * A primeira posição (0) do array é ignorada
 */
int month_days(int month, int year) {
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


bool is_valid_date(int d, int m, int y) {
     if ( d  < 1 || d  > 31 || m < 1 || m > 12 || y < 0)
        return false;
    return d <= month_days(m, y);
}

/**
 * retorna true se a data recebida em "d" for válida, "false" caso contrário
 */
bool date_valid(Date d) {
     
    return  is_valid_date(d.day, d.month, d.year);
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
