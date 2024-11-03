#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <limits.h>
#include <stdlib.h> 

#include "responses.h"

int my_strcmp(const char* a, const char* b);
int my_strlen(const char* a);
char* my_strcpy(char* dest, const char* src);
char* my_strcat(char* dest, const char* src);
RESPONSES files_name_equial(const char* a, const char* b);
RESPONSES decarator_fopen(const char* path, const char* mode, FILE** file);

#endif