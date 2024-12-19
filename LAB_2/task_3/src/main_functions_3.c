#include "../include/functions_2_3.h"

RESULT* get_matches(const char* substr, ...)
{
    if (!substr)
        return NULL;
    
    char* substring = replace_tabs_with_spaces(substr, 4);
    if (!substring) {
        return NULL; 
    }

    int substring_length = my_strlen(substring);
    if (substring_length == 0)
    {
        return NULL; 
    }

    int* prefix_array = (int*)malloc(substring_length * sizeof(int));
    if (!prefix_array)
    {
        return NULL; 
    }

    create_arr_prefix(prefix_array, substring);

    va_list args;
    va_start(args, substr);

    RESULT* results = NULL; // Основной массив результатов
    RESULT* temp_results = NULL;
    int file_count = 0; // Счётчик обработанных файлов

    while (1)
    {
        char *filename = va_arg(args, char*);
        if (!filename)
            break; // Конец списка аргументов

        file_count++;

        temp_results = (RESULT *)realloc(results, file_count * sizeof(RESULT));
        if (!temp_results)
        {
            free(results);
            free(prefix_array);
            return NULL; // Ошибка выделения памяти
        }
        results = temp_results;

        MATCH *matches = NULL; // Для хранения результатов поиска в текущем файле
        int match_count = find_substr(substring, filename, prefix_array, substring_length, &matches);

        results[file_count - 1].file_name = filename;

        if (match_count == FILE_NOT_FOUND)
        {
            results[file_count - 1].status = FILE_NOT_FOUND;
            continue;
        }

        if (match_count == INVALID_MEMORY)
        {
            results[file_count - 1].status = INVALID_MEMORY;
            continue;
        }

        results[file_count - 1].status = DONE;
        results[file_count - 1].match_array = matches;
        results[file_count - 1].match_count = match_count;
    }

    if (file_count > 0)
    {
        results[0].processed_file_count = file_count; // Сохраняем общее количество файлов
    }

    free(prefix_array); 
    va_end(args);
    return results;
}

void create_arr_prefix(int* arr_prefix, const char* image)
{
    if (!image) return;

    arr_prefix[0] = 0;
    int i = 1, j = 0; 

    while (image[i] != '\0') {
        if (image[i] == image[j]) {
            arr_prefix[i] = j + 1;
            ++j;
            ++i;
        } else if (j == 0) {
            arr_prefix[i] = 0;
            ++i;
        } else {
            j = arr_prefix[j - 1];
        }
    }
}

enum ERRORS find_substr(char *substr, const char* file_name, int arr_prefix[], int substr_len, MATCH **matches)
{
    FILE* file = fopen(file_name, "r");
    if (!file)
        return FILE_NOT_FOUND;

    char current_char;
    int substr_line_count = count_lines(substr); // Количество строк в подстроке
    int match_count = 0; // Количество найденных совпадений

    long long file_position = 0; // Позиция в файле
    int line_number = 1; // Номер текущей строки
    int match_length = 0; // Длина текущего совпадения

    int match_start_position = 0; // Начало вхождения подстроки
    
    MATCH* temp_matches;

    while ((current_char = fgetc(file)) != EOF)
    {
        ++file_position;

        // Если символ не совпадает, то двигаем подстроку
        while (match_length > 0 && current_char != substr[match_length])
            match_length = arr_prefix[match_length - 1];
   
        // Если символ совпадает, то увеличиваем совпадение строки и подстроки
        if (current_char == '\n') {
            file_position = 0;
            ++line_number;
        }

        if (match_length == 0 && current_char == substr[match_length])
            match_start_position = file_position;

        if (current_char == substr[match_length])
            ++match_length;

        // Если нашли полное совпадение
        if (match_length == substr_len)
        {
            ++match_count;

            // Перераспределение памяти для хранения совпадений
            temp_matches = (MATCH *)realloc(*matches, sizeof(MATCH) * match_count);
            if (!temp_matches)
                return INVALID_MEMORY;

            *matches = temp_matches;
            temp_matches[match_count - 1].line_number = line_number - substr_line_count; // Номер строки начала совпадения
            temp_matches[match_count - 1].char_position = match_start_position; // Позиция символа начала совпадения
            match_length = arr_prefix[match_length - 1]; // Сброс длины совпадения
        }
    }
    
    fclose(file);
    
    return match_count;
}

int my_strlen(const char* str)
{
    int length = 0;
    
    while(*str) {
        ++length;
        ++str;
    }

    return length;
}

int count_lines(const char *str)
{
    int count_lines = 0;
    while(*str) {
        if (*str == '\n')
            ++count_lines;
        ++str;
    }

    return count_lines;
}

char* replace_tabs_with_spaces(const char* str, int tab_size) {
    int length = my_strlen(str);
    int new_length = length;
    
    for (int i = 0; i < length; i++) {
        if (str[i] == '\t') {
            new_length += (tab_size - 1);
        }
    }

    char* new_str = (char*)malloc(new_length + 1);
    if (!new_str) {
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == '\t') {
            for (int k = 0; k < tab_size; k++)
                new_str[j++] = ' ';
        } else {
            new_str[j++] = str[i];
        }
    }
    
    new_str[j] = '\0';

    return new_str;
}