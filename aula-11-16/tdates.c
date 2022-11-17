/**
 * strtests.c
 * Este programa contém um conjunto de testes para validar as implementações
 * presentes no ficheiro "strutils.c".
 * 
 * ISEL, outubro de 2022
 * 
 * Build : gcc -Wall  -o strtests strtests.c strutils.c  
 * Execute : strtests
 *---------------------------------------------------------------------------*/

#include <stdbool.h>
#include <string.h>

#include "tstutils.h"
#include <limits.h>
#include "date.h"


// Toupper, tolower tests

void diff_consecutive_days() {
    Date d1 = { .day = 31, .month = 8, .year = 2022 };
    Date d2 = { .day = 1, .month = 9, .year = 2022  };
     
    ASSERT_EQUAL_INT(1, date_diff_days(d1, d2));
}

void date_weekday_of_first_day_2023() {
    Date d = { .day = 1, .month = 1, .year = 2023 };
    ASSERT_EQUAL_INT(0, date_weekday(d));
}

int main() {
    
    // Diff days
    TEST(diff_consecutive_days);
 
    // Weekdays
    TEST(date_weekday_of_first_day_2023);
	return 0;
}
	


