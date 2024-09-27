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

void write_lexemes(FILE* file, char** lexemes, int count)
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