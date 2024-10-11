#include "functions_9.h"

#define ERROR_MEMORY_ALLOCATE 1
#define ERROR_INCORRECT_SYMBOLS 2

int main (int argc, char** argv)
{
    srand(time(NULL));
    
    if (argc != 3) {
        printf("Usage: %s <a> <b>\n", argv[0]);
        return 1;
    }

    first_task(argv[1], argv[2]);

    if (!second_task())
        return ERROR_MEMORY_ALLOCATE;
    
    return 0;
}