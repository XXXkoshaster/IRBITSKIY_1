#ifndef __CORE_H__
#define __CORE_H__

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "responses.h"
#include "unidirectional_list.h"

typedef struct MODIFICATION
{
    int type;
    size_t position;
    LIVER liver;
} MODIFICATION, *P_MODIFICATION;

RESPONSES read_from_file(const char *filename, p_unidirectional_list list);
RESPONSES write_to_file(const char *filename, p_unidirectional_list list);
RESPONSES add_liver(p_unidirectional_list list, LIVER liver);
RESPONSES find_liver(p_unidirectional_list list, const char *surname, const char *name, const char *patronymic, LIVER *result);
RESPONSES update_liver(p_unidirectional_list list, const char *surname, const char *name, const char *patronymic, LIVER new_data);
RESPONSES delete_liver(p_unidirectional_list list, const char *surname, const char *name, const char *patronymic);

#endif