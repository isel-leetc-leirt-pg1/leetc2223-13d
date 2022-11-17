#include "date.h"


#define NAME_MAX 100
#define NAME_CAPACITY (NAME_MAX+1)

#define PHONE_MAX 20*
#define PHONE_CAPACITY (PHONE_MAX+1)


typedef struct {
    char name[NAME_CAPACITY];
    char phone[PHONE_CAPACITY];
    Date birthday;
}

void person_show(Person *p);

void person_read(Person *p);
