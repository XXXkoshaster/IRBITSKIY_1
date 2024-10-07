#include "functions_9.h"

int main (int argc, char** argv)
{
    srand(time(NULL));
    
    if (argc != 3) {
        printf("Usage: %s <a> <b>\n", argv[0]);
        return 1;
    }

    first_task(argv[1], argv[2]);
    second_task();
    
    return 0;
}