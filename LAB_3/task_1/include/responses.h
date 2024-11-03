#ifndef __RESPONSES_H__
#define __RESPONSES_H__

#include <stdio.h>

typedef enum STATUS 
{
    DONE,
    INVALID_INPUT,
    MY_OVERFLOW,
    NULL_PTR,
    INVALID_MEMORY,
    FILE_NOT_FOUND
} STATUS;


typedef struct RESPONSES
{
    STATUS status;
    const char* message;
    void* data;
} RESPONSES;

RESPONSES create_error_response(STATUS status, const char* message);
RESPONSES create_success_response(void* data);

#endif