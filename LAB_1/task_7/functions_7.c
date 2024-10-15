#include "functions_7.h"

#define BUFFER_SIZE 256

char** read_lexemes(FILE* file, int* count)
{
    char** lexemes = NULL;
    char buffer[BUFFER_SIZE];
    *count = 0;

    while (fscanf(file, "%255s", buffer) == 1) {
        if (!add_lexemes(&lexemes, count, buffer)) {
            for (int i = 0; i < *count; i++) 
                free(lexemes[i]);

            free(lexemes);
            fclose(file);
            *count = 0;
            return NULL;
        }
    }

    fclose(file);
    return lexemes;
}

int add_lexemes(char*** lexemes, int* count, char* buffer)
{
        char** tmp  = (char**)realloc(*lexemes, (*count + 1) * sizeof(char*));
        if (tmp == NULL) 
            return 0;
        
        *lexemes = tmp;

        (*lexemes)[*count] = strdup(buffer);
        if ((*lexemes)[*count] == NULL) 
            return 0;

        (*count)++;

        return 1;
}

char** merge_lexemes(char** lexemes_1, int count_1, char** lexemes_2, int count_2, int* merged_count)
{
    if (lexemes_1 == NULL || lexemes_2 == NULL || merged_count == NULL || count_1 < 0 || count_2 < 0)
        return NULL;

    int max_count = count_1 + count_2;
    char** merged = (char**)malloc(max_count * sizeof(char*));

    if (merged == NULL)
        return NULL;
    

    *merged_count = 0;

    int i = 0, j = 0;
    while (i < count_1 || j < count_2) {
        if (i < count_1) {
            if (!copy_lexeme(merged, lexemes_1[i++], *merged_count)) 
                return NULL;

            (*merged_count)++;
        }

        if (j < count_2) {
            if (!copy_lexeme(merged, lexemes_2[j++], *merged_count)) 
                return NULL;

            (*merged_count)++;
        }
    }

    return merged;
}

int copy_lexeme(char** merged, char* lexeme, int merged_count) {
    merged[merged_count] = strdup(lexeme);

    if (merged[merged_count] == NULL) {
        for (int k = 0; k < merged_count; k++) {
            free(merged[k]);
        }
        free(merged);
        return 0; 
    }
    return 1; 
}

void write_lexemes_r(FILE* file, char** lexemes, int count)
{
    for (int i = 0; i < count; i++) {
        if (i > 0) 
            fprintf(file, " ");
        fprintf(file, "%s", lexemes[i]);
        free(lexemes[i]);
    }

    free(lexemes);

    fclose(file);
}

void to_lower(char* lexem)
{
    for (int i = 0; lexem[i]; i++) {
        lexem[i] = tolower(lexem[i]);
    }
}

void to_base_4(char* lexem, char* result)
{
    int index = 0;
    for (int i = 0; lexem[i];i++) {
        int ascii = (int)(lexem[i]);
        char buffer[256] = {0};

        int buffer_index = 255;
        buffer[buffer_index--] = '\0';
        
        if (ascii == 0) {
            buffer[buffer_index--] = '0';
        } else {
            while (ascii > 0) {
                buffer[buffer_index--] = '0' + (ascii % 4);
                ascii /= 4;
            }
        }

        do {
            buffer_index++;
        } while (buffer[buffer_index] == '0');
        
        for (int j = buffer_index; buffer[j]; j++) 
            result[index++] = buffer[j];
    }
    result[index] = '\0';
}       


void to_base_8(char* lexem, char* result, size_t result_size)
{
    int index = 0;
    for(int i = 0; lexem[i]; i++) {
        int ascii = (int)(lexem[i]);
        char buffer[10];
        
        sprintf(buffer, "%03o", ascii);
        
        for(int j = 0; buffer[j]; j++) {
            if (index < result_size) {
                result[index++] = buffer[j];
            } else {
                result[index] = '\0';
                return;
            }  
        }
    }

    result[index] = '\0';
}

void get_file_name(char* file_path, char* name)
{
    char* last_slash = strrchr(file_path, '/');
    if (last_slash == NULL) last_slash = strrchr(file_path, '\\');
    if (last_slash == NULL) last_slash = file_path - 1;
    
    char* last_point = strrchr(file_path, '.');
    if (last_point == NULL) last_point = file_path + strlen(file_path);

    char* point = last_slash + 1;
    int i = 0;

    while (point != last_point) {
        name[i++] = *point++;
    }
    
    name[i] = '\0';
}

void write_lexemes_a(FILE* file, char** lexemes, int count)
{
    for (int i = 0; i < count; i++) {
        char buffer[256] = {0};
        if ((i + 1) % 10 == 0) {
            to_lower(lexemes[i]);
            to_base_4(lexemes[i], buffer);
        } else if ((i + 1) % 2 == 0) {
            to_lower(lexemes[i]);
            strcpy(buffer, lexemes[i]);
        } else if ((i + 1) % 5 == 0) {
            to_base_8(lexemes[i], buffer, sizeof(buffer));
        } else {
            strcpy(buffer, lexemes[i]);
        }

        if (i > 0) fprintf(file, " ");
        fprintf(file, "%s", buffer); 
        
        free(lexemes[i]);
    } 
    
    fclose(file);
}

