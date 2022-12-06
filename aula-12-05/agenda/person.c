#include <stdio.h>
#include <string.h>
#include "person.h"


void person_init(Person *p, const char name[], const char phone[], Date d) {
    strcpy(p-> name, name);
    strcpy(p->phone, phone);
    p->birthday = d;
}


void readline(char line[], int capacity) {
   fgets(line, capacity, stdin);
   
   int last_pos = strlen(line) - 1;
   if (line[last_pos] == '\n')  
        line[last_pos] = 0;
}

void person_show(Person *p) {
    // printf("nome: %s\n", (*p).name );
    printf("nome: %s\n", p->name );
    printf("telefone: %s\n", p->phone );
    
    date_show(p->birthday, "data nascimento");
    
    putchar('\n');
}


void person_read(Person *p) {
    printf("name? "); 
    readline(p->name, NAME_CAPACITY);
    printf("telefone? "); 
    readline(p->phone, PHONE_CAPACITY);
    
    p->birthday = date_read("data nascimento?");
    
    
}
    
    
