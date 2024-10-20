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
    if (substring == NULL || count_files < 1)  
        return INVALID_INPUT;

    int i;
    va_list files;

    va_start(files, count_files);

    for (i = 0; i < count_files; i++) {
        char* file_name = va_arg(files, char*);

        if (file_name == NULL) {
            va_end(files);
            return WRONG_PARAMETERS;
        }

        FILE* file = fopen(file_name, "r");

        if (file == NULL) {
            va_end(files);
            return FILE_NOT_FOUND;
        }

        int max_matches = count_lines(file);

        if (max_matches == -1) {
            fclose(file);
            va_end(files);
            return INVALID_INPUT;
        }

        MATCH* matches = (MATCH*)malloc(max_matches * sizeof(MATCH));

        if (matches == NULL) {
            va_end(files);
            return NULL_PTR;
        }

        if (find_substring_in_file(file, substring, matches) == NULL_PTR) {
            free(matches);
            va_end(files);
            return INVALID_MEMORY;
        }

        if (matches[0].line_number != 0) {
            printf("File %s:\n", file_name);

            for (int j = 0; j < max_matches; j++) {
                if (matches[j].line_number != 0)
                    printf("\tline: %d, position: %d\n", matches[j].line_number, matches[j].position);
            }
        }

        free(matches);
        fclose(file);   
    }

    return DONE;
}