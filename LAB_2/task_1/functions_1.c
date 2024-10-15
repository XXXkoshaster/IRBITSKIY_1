#include "functions_1.h"

size_t length_string(char* str)
{
    size_t length = 0;
    
    while(*(str++)) {
        length++;
    }

    return length;
}

void revesed_string(char* str, char* revesed_str, size_t len)
{   
    for (size_t i = 0; i < len; i++) {
        revesed_str[i] = str[len - i - 1];
    }

    revesed_str[len] = '\0';
}

void print_string(char* str)
{
    while(*(str++)) {
        printf("%c", *str);
    }

    printf("\n");
}

void u_string(char* origin_str, char* new_str)
{
    int i = 0;
    while(*origin_str) {
        if (i % 2 != 0) {
            new_str[i] = *origin_str;
        } else {
            new_str[i] = toupper(*origin_str);
        }
        
        origin_str++;
        i++;
    }
    new_str[i] = '\0';
}

void n_string(char* origin_str, char* new_str, size_t len_str)
{   
    unsigned int count_letters = 0, count_nums = 0, count_other_symb = 0;
    char* tmp;

    char* letters = (char*)malloc((len_str + 1) * sizeof(char));
    char* numbers = (char*)malloc((len_str + 1) * sizeof(char));
    char* other_symbols = (char*)malloc((len_str + 1) * sizeof(char));
    
    if (!letters || !numbers || !other_symbols) {
        free(letters);
        free(numbers);
        free(other_symbols);
        return;
    }

    numbers[0] = '\0';
    letters[0] = '\0';
    other_symbols[0] = '\0';
    
    while(*(origin_str)) {
        if (isalpha(*origin_str)) {
            letters[count_letters++] = *origin_str;
        } else if (isdigit(*origin_str)) {
            numbers[count_nums++] = *origin_str;
        } else {
            other_symbols[count_other_symb++] = *origin_str;
        }

        origin_str++;
    }

    numbers[count_nums] = '\0';
    letters[count_letters] = '\0';
    other_symbols[count_other_symb] = '\0';

    concatenate_strings(new_str, letters, numbers);
    concatenate_strings(new_str + count_letters + count_nums, new_str, other_symbols);

    new_str[count_letters + count_nums + count_other_symb] = '\0';
    
    free(letters);
    free(numbers);
    free(other_symbols);
}

void c_string(char* new_string, char** argv, int argc)
{
    int index = 0;
    unsigned int count_strings = strtol(argv[3], NULL, 10);

    char** lexemes = (char**)malloc(count_strings * sizeof(char*));
    create_lexemes(argv, lexemes, argc);

    unsigned int seed = strtol(argv[3], NULL, 10);
    srand(seed);

    for (int i = 0; i < count_strings; i++) {
        index = rand() % count_strings;
        char* tmp = (char*)realloc(new_string, length_string(new_string) + length_string(lexemes[index] + 1));

        if (!tmp) {
            free(tmp);
            return;
        }

        new_string = tmp;
        concatenate_strings(new_string, new_string, lexemes[index]);
    }

    free(lexemes);
}

void create_lexemes(char** argv, char** lexemes, int argc)
{   
    int j = 0;

    for (int i = 2; i < argc; i++) {
        if (i == 3) continue;
        lexemes[j] = argv[i];
        j++;
    }
}

void concatenate_strings(char* result, char* f_string, char* s_string)
{
    while(*f_string) {
        *result = *f_string;
        f_string++;
        result++;
    }

    while(*s_string) {
        *result = *s_string;
        s_string++;
        result++;
    }

    *result = '\0';
}