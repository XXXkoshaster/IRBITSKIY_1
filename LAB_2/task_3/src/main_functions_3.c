#include "../include/functions_2_3.h"

enum ERRORS find_substring_in_file(FILE* input_file, const char* substring, MATCH* matches)
{
    if (input_file == NULL || substring == NULL)
        return NULL_PTR;

    char buffer[BUFFER_SIZE];
    int index_line = 1;
    int match_index = 0;

    while (fgets(buffer, BUFFER_SIZE, input_file)) {
        char* ptr = buffer;
        /*
        printf("\t\tline: %s\n", buffer);
        */
        if ((ptr = my_strstr(ptr, substring)) != NULL)
        {
            matches[match_index].line_number = index_line;
            matches[match_index].position = ptr - buffer + 1;

            match_index++;
        }

        index_line++;
    }

    return DONE;
}

enum ERRORS get_matches(const char* substring, int count_files, ...)
{
    enum ERRORS error = validate_input(substring, count_files);
    
    if (error != DONE)
        return error;

    va_list files;
    va_start(files, count_files);

    for (int i = 0; i < count_files; i++) {
        char* file_name = va_arg(files, char*);

        if (file_name == NULL) {
            va_end(files);
            return WRONG_PARAMETERS;
        }

        error = process_file(file_name, substring);

        if (error != DONE) {
            va_end(files);
            return error;
        }
    }

    va_end(files);
    
    return DONE;
}