#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "person.h"


#define MAX_CONTACTS 1000

// representa a lista de contactos
typedef struct {
    int ncontacts;
    Person contacts[MAX_CONTACTS];
} ContactsDB;


// lista de contactos
ContactsDB db;


// funções para gerir os contactos

/**
 * Inicia a estrutura com a lista de contactos
 */
void contacts_init() {
    db.ncontacts = 0;
}


/**
 * adiciona uma pessoa à lista de contactos
 * retorna false no caso da lista de contactos já estiver cheia
 */
bool contacts_add(Person *p) {
    if (db.ncontacts == MAX_CONTACTS) return false;
    db.contacts[db.ncontacts] = *p;
    db.ncontacts++;
    return true;
}



/**
 * função auxiliar para iniciar a 
 * agenda com alguns contactos
 */
void contacts_populate() {
    Person p;
    Date d;
    
    // person 1
    date_init(&d, 25, 4, 2002);
    person_init(&p, "Joao", "111111111", d);
    contacts_add(&p);
    
    // person 2
    date_init(&d, 12, 8, 2010);
    person_init(&p, "Maria", "222222222", d);
    
    contacts_add(&p);
    
     // person 3
    date_init(&d, 25, 7, 1980);
    person_init(&p, "Mario", "333333333", d);
    contacts_add(&p);
}

/**
 * Remove da lsita de contactos o contacto
 * cujo número de telefone é igual a "phone"
 * retorna false se o contacto não existir
 */
bool contacts_rem_by_phone(const char phone[]) {
    for(int i=0; i < db.ncontacts; ++i) {
        if (strcmp(phone, db.contacts[i].phone) == 0) {
            for(int j = i +1; j < db.ncontacts; j++) {
                db.contacts[j-1] = db.contacts[j];
            }
            db.ncontacts--;
            return true;
        }
    }
    
    return false;
}

/**
 * adiciona "n" contactos à agenda
 */
void contacts_add_many(int n) {
    for(int i=0; i < n; ++i) {
        Person p;
        printf("Contacto %d:\n", i+1); 
        
        //fflush(stdout);
        person_read(&p);
        contacts_add(&p);
    }
}

/**
 * mostrar os contactos existentes
 */

void contacts_show() {
    printf("Lista de Contactos\n");
    
    for (int i= 0 ; i < db.ncontacts; ++i) {
        person_show(&db.contacts[i]);
        printf("\n");
    }
}


// Comandos

bool cmd_remove() {
    
    printf("Telefone do utilizador a remover? ");
    
    char phone[PHONE_CAPACITY];
    
    readline(phone, PHONE_CAPACITY);
    
    if (!contacts_rem_by_phone(phone)) {
        printf("Contacto inexistente!\n");
        return false;
    }
    
    return true;
}

// adiciona um novo contacto
bool cmd_add_contact() {
    // a completar
    return false;
}

// mostrar os contactos cuja dia de anos
// está no máximo a "ndays" dias da data de hoje
// sendo "ndays" lido do input
bool cmd_show_next_birthday_parties() {
    // a completar
    return false;
}

int main() {
    
    Date d = date_today();
    
    // só para mostrar a utilização fa função date_today
    // esta função deve ser usada no comando cmd_show_next_birthday_parties
    date_show(d, "data de hoje");
    printf("\n");
    
    contacts_init();
    
    
    contacts_populate();
    
    //contacts_add_many(2);
    
    cmd_remove();
    
    contacts_show();
    
    return 0;
}
