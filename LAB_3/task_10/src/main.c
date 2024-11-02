#include "../include/core.h"

#define INVALID_USAGE 1
#define INVALID_FLAG 2
#define SUCCESS 0

int main(int argc, char** argv)
{
    if (argc != 3) {
        printf ("Usage: %s <input_file> <output_file>\n", argv[0]);
        return INVALID_USAGE;

    }
    RESPONSES response;

    response = files_name_equial(argv[1], argv[2]);
    
    if (response.status != DONE) {
        printf("Error: %s\n", response.message);
        return INVALID_USAGE;
    }

    FILE* file_in;
    FILE* file_out;

    response = decarator_fopen(argv[1], "r", &file_in);
    
    if (response.status != DONE) {
        printf("Error: %s\n", response.message);
        return INVALID_USAGE;
    }

    response = decarator_fopen(argv[2], "w", &file_out);
    
    if (response.status != DONE) {
        printf("Error: %s\n", response.message);
        return INVALID_USAGE;
    }

    
    response = write_tree_into_file(file_in, file_out);

    if (response.status != DONE) {
        printf("Error: %s\n", response.message);
        return INVALID_USAGE;
    }
    
    fclose(file_in);
    fclose(file_out);
}
