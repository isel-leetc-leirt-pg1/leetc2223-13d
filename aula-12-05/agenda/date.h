#include <stdbool.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;


/**
 * inicia uma nova data a partir dos valores dia, mês, ano
 * Os valores DEVEM representar uma data válida
 */
void date_init(Date *date, int day, int month, int year);
   

/**
 * retorna a data atual
 * Na rrealização desta função é preciso usar fubções espcíficas do Unix
 */
Date date_today();


/**
 * compara duas datas return
 * um valor negativo, nulo ou positivo
 * consoante "d1" for respetivamente menor, igual ou 
 * maior do que "d2"
 */
int date_cmp(Date d1, Date d2);
    
    
/**
 * Mostra uma data no output standard (consola)
 */
void date_show(Date d, char msg[]);


/**
 * Retorna uma data lida da consola
 * A data retornada deve ser válida
 * pelo que pode ter de pedir a data mais do que uma vez ao utilizador
 * Por cada pedido é apresentada a mensagem "msg"
 */
Date date_read(char msg[]);



/**
 * devolve o total de dias no ano "year"
 */
int year_days(int year);


/**
 *  determina se o ano "year" é bissexto
 */
bool is_leap_year(int year);
    

/**
 * retorna os dias do mês "month"
 * Assume que "month" está entre 1 e 12
 */
int month_days(int month, int year);
     


/**
 *  retorna o número de dias do ano
 */
int year_days(int year);
     

/**
 *  retorna o número de dias entre dois anos (year1 < year2)
 */
int days_between_years(int year1, int year2); 


/**
 * retorna os dias que medeiam entre 1 janeiro do ano de "d" e "d"
 */
int date_days_from_jan1(Date d);
    

/** 
 * retorna os dias que medeiam entre a data "d" e o dim do ano de "d" 
 */ 
int date_days_until_dez31(Date d);
    

/**
 * retorna a diferença em dias entre as duas datas (d2 - d1)
 */
int date_diff_days(Date d1, Date d2);



/**
 * retorna true se a data reprsentada por "d", "m" e "y"
 * é válida, "false" caso contrário
 */
bool date_valid(int d, int m, int y);
    

/**
 *  retorna um inteiro entre 0 e 6
 * que representa o dia da semana da data (0 - domingo)
 */
int date_weekday(Date d);
  

/**
 * apresenta no standard output (consola) o nome do dia da semana
 * dado o seu código
 */
void show_weekday(int wd);
     
