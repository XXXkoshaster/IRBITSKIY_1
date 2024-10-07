#include "functions_7.h"

char** read_lexemes(FILE* file, int* count)
{
    char** lexemes = NULL;
    char buffer[1024];
    *count = 0;

    while (fscanf(file, "%1023s", buffer) == 1) {
        lexemes = (char**)realloc(lexemes, (*count + 1) * sizeof(char*));
        lexemes[*count] = strdup(buffer);
        (*count)++;
    }

    fclose(file);
    return lexemes;
}

char** merge_lexemes(char** lexemes_1, int count_1, char** lexemes_2, int count_2, int* merged_count)
{
    int max_count = count_1 + count_2;
    char** merged = (char**)malloc(max_count * sizeof(char*));
    *merged_count = 0;

    int i = 0, j = 0;
    while (i < count_1 || j < count_2) {
        if (i < count_1) {
            merged[(*merged_count)++] = strdup(lexemes_1[i++]);
        }
        if (j < count_2) {
            merged[(*merged_count)++] = strdup(lexemes_2[j++]);
        }
    }

    return merged;
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

void to_base_x(char* lexem, char* result, int x)
{
    int index = 0;
    for(int i = 0; lexem[i]; i++) {
        int ascii = (int)(lexem[i]);
        char buffer[10];
        
        sprintf(buffer, "%d", ascii);
        
        for(int j = 0; buffer[j]; j++) {
            result[index++] = buffer[j];
        }
    }
    
    result[index] = '\0';
}

void write_lexemes_a(FILE* file, char** lexemes, int count)
{
    for (int i = 0; i < count; i++) {
        char buffer[1024] = {0};
        if ((i + 1) % 10 == 0) {
            to_lower(lexemes[i]);
            to_base_x(lexemes[i], buffer, 4);
        } else if ((i + 1) % 2 == 0) {
            to_lower(lexemes[i]);
            strcpy(buffer, lexemes[i]);
        } else if ((i + 1) % 5 == 0) {
            to_base_x(lexemes[i], buffer, 8);
        } else {
            strcpy(buffer, lexemes[i]);
        }

        if (i > 0) fprintf(file, " ");
        fprintf(file, "%s", buffer); 
        
        free(lexemes[i]);
    } 
    
    fclose(file);
}