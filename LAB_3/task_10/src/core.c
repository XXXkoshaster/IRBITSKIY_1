#include "../include/core.h"

RESPONSES write_tree_into_file(FILE* file_in, FILE* file_out)
{
    int curr_char;
    int indent_level = 0;

    if (!file_in || !file_out)
        return create_error_response(INVALID_INPUT, "input or otput file is NULL");

    while ((curr_char = fgetc(file_in)) != EOF) {
        char char_to_write = curr_char;

        if (curr_char == '(')
            indent_level++;
        else if (curr_char == ')')
            indent_level--;
        else if (curr_char == ' ' || curr_char == ',')
            continue;
        else {
            for (int i = 0; i < indent_level; i++)
                fprintf(file_out, " ");

            fprintf(file_out, "%c\n", char_to_write);
        }   
    }
    
    return create_success_response(NULL);
}   
