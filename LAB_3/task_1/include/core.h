#ifndef __CORE_H__
#define __CORE_H__

#include <stdlib.h>
#include "responses.h"
#include "utils.h"

RESPONSES convert_decemial_to_2_pow_r(char* result, int number, int r, int* count);
void  print_result(char* res, int count);

#endif