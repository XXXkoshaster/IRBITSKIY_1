#include "flags_1.h"

#define ERROR_INVALID_NUMBER_OF_ARGUMENTS 1
#define ERROR_INVALID_X 2

int is_number(char* symbol);

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Invalid number of arguments\n");
        return ERROR_INVALID_NUMBER_OF_ARGUMENTS;
    }
    
    /*if (!is_number(argv[1])) {
        printf("Invalid x\n");
        return ERROR_INVALID_X;
    }*/

    execute_flag(argv[2], argv[1]);
    return 0;
}

int is_number(char* symbol)
{
    while(*symbol) {
        if (!isdigit(*symbol))
            return 0;

        symbol++;
    }
    return 1;
}
