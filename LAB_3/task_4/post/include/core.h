#ifndef __CORE_H__
#define __CORE_H__

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "responses.h"
#include "utils.h"
#include "strings.h"

typedef struct{
    STRING city;
    STRING street;
    int home_number;
    STRING building;
    int apartment_number;
    STRING index;
} ADDRESS;

typedef struct{
    ADDRESS recipient_address;
    double weight;
    STRING postal_id;
    STRING time_delivery;
    STRING time_creation;
} MAIL;

typedef struct {
    ADDRESS* current_address;
    MAIL* mails;
    int mail_count;
} POST;

RESPONSES create_mail(ADDRESS recipient_address, double weight, const char* postal_id, const char* time_delivery, const char* time_creation);
RESPONSES delete_mail(MAIL* mail);

RESPONSES create_post(ADDRESS* current_address);
RESPONSES delete_post(POST* post);

RESPONSES add_mail_to_post(POST* post, MAIL mail);
RESPONSES remove_mail_from_post(POST* post, const char* postal_id);

RESPONSES find_mail_by_postal_id(POST* post, const char* postal_id);
int comparator_mails(const void* a, const void* b);
RESPONSES sort_mails(POST* post);  

RESPONSES print_mail(const MAIL* mail);
RESPONSES print_all_mails(const POST* post);

#endif