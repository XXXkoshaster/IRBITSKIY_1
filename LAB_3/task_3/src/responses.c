#include "../include/responses.h"

RESPONSES create_error_response(STATUS status, const char* message)
{
    RESPONSES response;
    response.status = status;
    response.message = message;
    response.data = NULL;
    return response;
}

RESPONSES create_success_response(void* data)
{
    RESPONSES response;
    response.status = DONE;
    response.message = "Success";
    response.data = data;
    return response;
}