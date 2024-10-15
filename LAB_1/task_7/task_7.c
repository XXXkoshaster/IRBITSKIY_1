#include "flags_7.h"

#define ERROR_SAME_FILE 1
#define INVALID_COUNT_OF_ARGUMENTS 2

int main(int argc, char* argv[])
{   
    char* in_file_1_name, *in_file_2_name, *out_file_name;
    if (argc == 4) {
        in_file_1_name = (char*)malloc(sizeof(char) * strlen(argv[2]));
        out_file_name = (char*)malloc(sizeof(char) * strlen(argv[3]));
        get_file_name(argv[2], in_file_1_name);
        get_file_name(argv[3], out_file_name);

        if (strcmp(in_file_1_name, out_file_name) == 0) {
            printf("Error: input and output files must be different\n");
            return ERROR_SAME_FILE;
        }
    } else if (argc == 5) {
        in_file_1_name = (char*)malloc(sizeof(char) * strlen(argv[2]));
        in_file_2_name = (char*)malloc(sizeof(char) * strlen(argv[3]));
        out_file_name = (char*)malloc(sizeof(char) * strlen(argv[4]));
        get_file_name(argv[2], in_file_1_name);
        get_file_name(argv[3], in_file_2_name);
        get_file_name(argv[4], out_file_name);

        if (strcmp(in_file_1_name, out_file_name) == 0 || strcmp(in_file_2_name, out_file_name) == 0) {
            printf("Error: input and output files must be different\n");
            return ERROR_SAME_FILE;
        }
    }

    execute_flag(argc, argv);

    return 0;
}

