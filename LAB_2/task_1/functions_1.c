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
    
    while(*origin_str) {
        if (isdigit(*origin_str)) {
            numbers[count_nums++] = *origin_str;
        } else if (isalpha(*origin_str)) {
            letters[count_letters++] = *origin_str;
        } else {
            other_symbols[count_other_symb++] = *origin_str;
        }

        origin_str++;
    }

    numbers[count_nums] = '\0';
    letters[count_letters] = '\0';
    other_symbols[count_other_symb] = '\0';

    concatenate_strings(new_str, numbers);
    concatenate_strings(new_str, letters);
    concatenate_strings(new_str, other_symbols);
    
    free(letters);
    free(numbers);
    free(other_symbols);
}

void c_string(char** new_string, char** argv, int argc)
{
    unsigned int count_strings = get_count_strings(argv);

    if (count_strings != argc - 3) {
        printf("Invalid count of strings\n");
        return;
    }

    char** lexemes = allocate_lexemes(count_strings);

    if (!lexemes) {
        return;
    }

    create_lexemes(argv, lexemes, argc);

    initialize_random(count_strings);

    concatenate_random_strings(new_string, lexemes, count_strings);
    free_lexemes(lexemes, count_strings);
}

unsigned int get_count_strings(char** argv) {
    return strtol(argv[3], NULL, 10);
}

char** allocate_lexemes(unsigned int count_strings) {
    char** lexemes = (char**)malloc(count_strings * sizeof(char*));
    if (!lexemes) {
        return NULL;
    }
    return lexemes;
}

void initialize_random(unsigned int seed) {
    srand(seed);
}

void concatenate_random_strings(char** new_string, char** lexemes, unsigned int count_strings) {
    int indexes[count_strings];
    for (int i = 0; i < count_strings; i++) {
        indexes[i] = i;
    }
    
    for (unsigned int i = 0; i < count_strings; i++)
    {
        int j = rand() % count_strings;
        int tmp = indexes[i];
        indexes[i] = indexes[j];
        indexes[j] = tmp;
    }

    for (unsigned int i = 0; i < count_strings; i++) {
        int index = indexes[i];
        size_t new_length = length_string(lexemes[index]) + length_string(*new_string) + 1;

        char* tmp = (char*)realloc(*new_string, new_length * sizeof(char));
        if (!tmp) {
            free(*new_string);
            free_lexemes(lexemes, count_strings);
            return;
        }

        *new_string = tmp;
        concatenate_strings(*new_string, lexemes[index]);
    }
}

void free_lexemes(char** lexemes, unsigned int count_strings) {
    for (int i = 0; i < count_strings; i++) {
        free(lexemes[i]);
    }
    free(lexemes);
}

void create_lexemes(char** argv, char** lexemes, int argc)
{   
    int j = 0;

    for (int i = 2; i < argc; i++) {
        if (i == 3) continue;
        lexemes[j] = strdup(argv[i]);
        j++;
    }
}

char* concatenate_strings(char* dest, const char* src)
{
    if (dest == NULL || src == NULL) {
        return NULL;
    }

    char* dest_start = dest;

    while(*dest)
        dest++;

    while(*src) {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return dest_start;
}

char* strdup(char* str)
{
    if (!str)
        return NULL;

    size_t len = length_string(str);

    char* copy_of_str = (char*)malloc((len + 1) * sizeof(char));

    if (!copy_of_str)
        return NULL;

    for(size_t i = 0; i < len; i++) {
        copy_of_str[i] = str[i];
    }

    copy_of_str[len] = '\0';

    return copy_of_str;
}