#include "../include/functions_2_3.h"

char* my_strstr(const char* src, const char* origin)
{
    char* src_ptr = NULL, * origin_ptr = NULL;

    if (src == NULL || origin == NULL)
        return NULL;

    while(*src  != '\0') {
        if(*src == *origin) {
            int trigger_out = 1;

            src_ptr = (char*)src;
            origin_ptr = (char*)origin;   

            while(*src && *origin) {
                trigger_out = trigger_out && (*src == *origin);
                src++;
                origin++;
            }

            if(trigger_out && *origin == '\0')
                return src_ptr;
            
            origin = origin_ptr;
            src = src_ptr;
        }
        src++;
    }
    return NULL;
}

int count_lines(FILE* file)
{
    if (file == NULL)
        return -1;

    int count = 0;
    char buffer[BUFFER_SIZE];

    while(fgets(buffer, BUFFER_SIZE, file))
        count++;

    rewind(file);
    return count;
}

enum ERRORS validate_input(const char* substring, int count_files)
{
    if (substring == NULL || count_files < 1)  
        return INVALID_INPUT;

    return DONE;
}

enum ERRORS process_file(char* file_name, const char* substring)
{
    FILE* file = fopen(file_name, "r");

    if (file == NULL)
        return FILE_NOT_FOUND;

    int max_count_matches = count_lines(file);
    
    if (max_count_matches == -1) {
        fclose(file);
        return INVALID_INPUT;
    }

    MATCH* matches = (MATCH*)malloc(max_count_matches * sizeof(MATCH));

    if (matches == NULL) {
        fclose(file);
        return NULL_PTR;
    }

    memset(matches, 0, max_count_matches * sizeof(MATCH));
    
    enum ERRORS result = find_substring_in_file(file, substring, &matches, &max_count_matches);

    if (result == NULL_PTR) {
        free(matches);
        fclose(file);
        return INVALID_MEMORY;
    }

    if (matches[0].line_number != 0)
        print_matches(file_name, matches, max_count_matches);


    free(matches);
    fclose(file);   

    return DONE;
}

void print_matches(char* file_name, MATCH* matches, int max_count_matches)
{
    printf("File %s:\n", file_name);

    for (int j = 0; j < max_count_matches; j++) {
        if (matches[j].line_number <= 0)
            break;
        
        printf("\tline: %d, position: %d\n", matches[j].line_number, matches[j].position);
    }
}

char* resize_buffer(char* buffer, size_t* buffer_size)
{
    *buffer_size *= 2;
    buffer = (char*)realloc(buffer, *buffer_size * sizeof(char));

    if (buffer == NULL)
        return NULL;

    return buffer;
}