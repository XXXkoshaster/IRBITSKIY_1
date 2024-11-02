#include "../include/core.h"

#define INVALID_USAGE 1
#define INVALID_FLAG 2
#define SUCCESS 0

int main(int argc, char** argv)
{
    if (argc != 4) {
        printf ("Usage: %s <input_file> <-a|-d> <output_file>\n", argv[0]);
        return INVALID_USAGE;
    }

    RESPONSES response = files_name_equial(argv[1], argv[3]);
    if (response.status != DONE) {
        printf("Error: %s\n", response.message);
        return response.status;
    }

    const char* input_file = argv[1];
    const char* flag = argv[2];
    const char* output_file = argv[3];

    int count = 0;
    
    response = read_employees(input_file, &count);
    
    if (response.status != DONE) {
        printf("Error: %s\n", response.message);
        return response.status;
    }

    if (my_strcmp(flag, "-a") == 0 || my_strcmp(flag, "/a") == 0)
        qsort(response.data, count, sizeof(EMPLOYEE), ascending_comparator);
    else if (my_strcmp(flag, "-d") == 0 || my_strcmp(flag, "/d") == 0)
        qsort(response.data, count, sizeof(EMPLOYEE), descending_comparator);
    else {
        printf("Invalid flag: %s\n", flag);
        free(response.data);
        return INVALID_FLAG;
    }
    
    response = write_employees(output_file, response.data, count);
    
    if (response.status != DONE) {
        printf("Error: %s\n", response.message);
        free(response.data);
        return response.status;
    }
    free(response.data);

    return SUCCESS;
}