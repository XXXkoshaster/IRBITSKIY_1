#include "../include/functions_2_3.h"

enum ERRORS find_substring_in_file(FILE* input_file, const char* substring, MATCH** matches, int* max_matches)
{
    if (input_file == NULL || substring == NULL)
        return NULL_PTR;
    
    size_t buffer_size = BUFFER_SIZE;
    char* buffer = (char*)malloc(buffer_size * sizeof(char));

    if (!buffer)
        return INVALID_MEMORY;

    int index_line = 1;
    int match_index = 0;

    while (fgets(buffer, buffer_size, input_file)) {
        while (!strchr(buffer, '\n') && !feof(input_file)) {
            buffer = resize_buffer(buffer, &buffer_size);

            if (buffer == NULL) {
                printf("Invalid memory\n");
                return INVALID_MEMORY;
            }

            fgets(buffer + strlen(buffer), buffer_size - strlen(buffer), input_file);
        }

        char* ptr = buffer;

        while ((ptr = my_strstr(ptr, substring)) != NULL) {

            if (match_index >= *max_matches) {
                *max_matches *= 2;
                *matches = (MATCH*)realloc(*matches, *max_matches * sizeof(MATCH));
                
                if (*matches == NULL)
                    return NULL_PTR;
            }

            (*matches)[match_index].line_number = index_line;
            (*matches)[match_index].position =  ptr - buffer + 1;

            match_index++;
            ptr += strlen(substring);
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